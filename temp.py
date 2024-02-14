import easyocr

# Create an OCR reader
reader = easyocr.Reader(['en'], gpu=True)  # Specify the language and use GPU if available

# Perform OCR on an image
result = reader.readtext('room2.jpeg')

# Display the result
for detection in result:
    print(detection[1])  # The text detected
