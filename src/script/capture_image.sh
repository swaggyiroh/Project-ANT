#!/bin/bash

# Set the output file path
output_file="assets/image.jpg"

# Capture image with libcamera-still, suppressing output
libcamera-still -n -o "$output_file"  >/dev/null 2>&1

# Check if the image was captured successfully
if [ $? -ne 0 ]; then
    echo "Failed to capture image!"
    exit 1
fi

echo "Image captured successfully: $output_file"
