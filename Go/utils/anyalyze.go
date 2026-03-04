package utils

import (
	"bytes"
	"encoding/json"
	"fmt"
	"io"
	"net/http"
	"os"
	"strings"
)

type Message struct {
	Role    string `json:"role"`
	Content string `json:"content"`
}

type AIRequestBody struct {
	Model       string    `json:"model"`
	Input       []Message `json:"input"`
	Temperature float64   `json:"temperature"`
}

// This struct matches ONLY the parts of the response we care about
type AIResponse struct {
	Output []struct {
		Type    string `json:"type"`
		Role    string `json:"role"`
		Content []struct {
			Type string `json:"type"`
			Text string `json:"text"`
		} `json:"content"`
	} `json:"output"`
}

func AnalyzeMedicalReport(text string) (string, error) {

	systemPrompt := `You are friend to the user, so just respond to him in the nicest way possble.
`

	userPrompt := fmt.Sprintf(`
Here is the query text:

%s

Please answer the following question
`, text)

	requestBody := AIRequestBody{
		Model: "openai.gpt-oss-120b",
		Input: []Message{
			{
				Role:    "system",
				Content: systemPrompt,
			},
			{
				Role:    "user",
				Content: userPrompt,
			},
		},
		Temperature: 0.0,
	}

	bodyBytes, err := json.Marshal(requestBody)
	if err != nil {
		return "", err
	}

	req, err := http.NewRequest("POST", os.Getenv("OPENAI_BASE_URL"), bytes.NewBuffer(bodyBytes))
	if err != nil {
		return "", err
	}
	req.Header.Set("Content-Type", "application/json")
	req.Header.Set("Authorization", "Bearer "+os.Getenv("OPENAI_API_KEY"))

	client := &http.Client{}

	resp, err := client.Do(req)

	if resp.StatusCode != http.StatusOK {
		errorBody, _ := io.ReadAll(resp.Body)
		return "", fmt.Errorf("status: %d, body: %s", resp.StatusCode, string(errorBody))
	}

	if err != nil {
		return "", err
	}
	defer resp.Body.Close()

	body, _ := io.ReadAll(resp.Body)

	var aiResp AIResponse
	err = json.Unmarshal(body, &aiResp)
	if err != nil {
		return "", err
	}
	// Extract assistant text
	var result strings.Builder

	for _, item := range aiResp.Output {
		if item.Type == "message" && item.Role == "assistant" {
			for _, content := range item.Content {
				if content.Type == "output_text" {
					result.WriteString(content.Text)
				}
			}
		}
	}

	if result.Len() == 0 {
		return "", fmt.Errorf("no assistant text found in response")
	}
	return result.String(), nil
}
