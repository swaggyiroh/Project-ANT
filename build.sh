#!/bin/bash

# Function to check if a package is installed
is_package_installed() {
    dpkg -s "$1" &> /dev/null
}

# General update and upgrade
cd
sudo apt-get update && sudo apt-get upgrade -y

# Check if Git is installed
if ! is_package_installed git; then
    echo "Git is not installed. Installing..."
    sudo apt-get install -y git
    if [ $? -ne 0 ]; then
        echo "Failed to install Git. Exiting."
        exit 1
    fi
    echo "Git installed successfully."
else
    echo "Git is already installed."
fi

# Check if WiringPi is installed
if ! is_package_installed wiringpi; then
    echo "WiringPi is not installed. Installing..."
    git clone https://github.com/WiringPi/WiringPi.git
    cd WiringPi
    ./build
    cd
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

# Check if Qt is installed
if ! is_package_installed qtbase5-dev; then
    echo "Qt is not installed. Installing..."
    sudo apt-get install -y build-essential libgl1-mesa-dev
    sudo apt-get install -y qtbase5-dev qt5-qmake qtbase5-dev-tools
    if [ $? -ne 0 ]; then
        echo "Failed to install Qt. Exiting."
        exit 1
    fi
    echo "Qt installed successfully."
else
    echo "Qt is already installed."
fi

echo "Installation check completed."

cd Project-ANT*
mkdir build
cd build
qmake ..
make
cd ..
