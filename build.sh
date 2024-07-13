#!/bin/bash


rm -rf .git
# Function to check if a package is installed
is_package_installed() {
    dpkg -s "$1" &> /dev/null
}

# Check if WiringPi is installed
if ! is_package_installed wiringpi; then
    echo "WiringPi is not installed. Installing..."
    sudo apt-get update
    sudo apt-get install -y wiringpi
    if [ $? -ne 0 ]; then
        echo "Failed to install WiringPi. Exiting."
        exit 1
    fi
    echo "WiringPi installed successfully."
else
    echo "WiringPi is already installed."
fi

# Check if OpenCV is installed
if ! is_package_installed libopencv-dev; then
    echo "OpenCV is not installed. Installing..."
    sudo apt-get update
    sudo apt-get install -y libopencv-dev
    if [ $? -ne 0 ]; then
        echo "Failed to install OpenCV. Exiting."
        exit 1
    fi
    echo "OpenCV installed successfully."
else
    echo "OpenCV is already installed."
fi

echo "Installation check completed."


mkdir build
qmake ..
make
cd ..
