// package main

// import (
// 	"fmt"

// 	"github.com/joho/godotenv"
// 	"test.com/utils"
// )

// func main() {
// 	godotenv.Load()
// 	text := "Benefits of banana"
// 	str, err := utils.AnalyzeMedicalReport(text)

// 	if err != nil {
// 		fmt.Printf("Found error %v", err)
// 	} else {
// 		fmt.Println(str)
// 	}

// }

package main

import (
	"context"
	"encoding/json"
	"fmt"
	"log"

	"github.com/aws/aws-sdk-go-v2/aws"
	"github.com/aws/aws-sdk-go-v2/config"
	"github.com/aws/aws-sdk-go-v2/service/bedrockruntime"
)

// OpenAI GPT request structure
type OpenAIRequest struct {
	Messages    []Message `json:"messages"`
	MaxTokens   int       `json:"max_tokens"`
	Temperature float64   `json:"temperature"`
}

type Message struct {
	Role    string `json:"role"`
	Content string `json:"content"`
}

// OpenAI GPT response structure
type OpenAIResponse struct {
	Choices []Choice `json:"choices"`
}

type Choice struct {
	Message Message `json:"message"`
}

func main() {
	// Load AWS configuration
	ctx := context.Background()
	cfg, err := config.LoadDefaultConfig(ctx, config.WithRegion("us-east-1"))
	if err != nil {
		log.Fatalf("Failed to load AWS config: %v", err)
	}

	// Create Bedrock Runtime client
	client := bedrockruntime.NewFromConfig(cfg)

	// Prepare the request payload
	request := OpenAIRequest{
		Messages: []Message{
			{
				Role:    "system",
				Content: "You are a helpful AI assistant specialized in providing concise and accurate answers. Always be polite and informative.",
			},
			{
				Role:    "user",
				Content: "How many free responses do i have",
			},
		},
		MaxTokens:   512,
		Temperature: 0.7,
	}

	// Marshal the request to JSON
	body, err := json.Marshal(request)
	if err != nil {
		log.Fatalf("Failed to marshal request: %v", err)
	}

	// Invoke the OpenAI GPT model
	result, err := client.InvokeModel(ctx, &bedrockruntime.InvokeModelInput{
		ModelId:     aws.String("openai.gpt-oss-120b-1:0"),
		ContentType: aws.String("application/json"),
		Body:        body,
	})
	if err != nil {
		log.Fatalf("Failed to invoke model: %v", err)
	}

	// Parse the response
	var response OpenAIResponse
	err = json.Unmarshal(result.Body, &response)
	if err != nil {
		log.Fatalf("Failed to unmarshal response: %v", err)
	}

	// Print the result
	if len(response.Choices) > 0 {
		fmt.Printf("Response: %s\n", response.Choices[0].Message.Content)
	}
}
