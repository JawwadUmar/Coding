from openai import OpenAI 
from dotenv import load_dotenv
import os

load_dotenv()
client = OpenAI()  

response = client.responses.create( 
    model="openai.gpt-oss-120b", 
    input=[ 
        {"role": "user", "content": "Generate a random JSON data"} 
    ] 
)  

print(response.output_text)