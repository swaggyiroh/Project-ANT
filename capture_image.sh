#!/bin/bash

rpicam-still -n --output image.jpg 
# Check if the image was captured successfully
if [ $? -ne 0 ]; then
    echo "Failed to capture image!"
    exit 1
fi

echo "Image captured successfully: captured_image.jpg"

