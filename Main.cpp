#include "CameraController.h"


#include <iostream>
#include <string>
#include <vector>

void displayInformation(const std::vector<std::string>& info) {
    for (const auto& item : info) {
        std::cout << item << std::endl;
    }
}

int main() {
   
    CameraController CamCon;
    int green_lvl = CamCon.getLevel();
    std::vector<std::string> info = {
        "ANT STATUS:",
        "green lvl" + green_lvl 
    };

    // Display the information
    displayInformation(info);

    return 0;
}


