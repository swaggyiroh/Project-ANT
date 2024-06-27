//
// Created by dominik
//

#include "CameraController.h"

#include "DHT22.h"

#include <iostream>

int main()
{
    CameraController controller;
    TDHT22 *MySensor = new TDHT22(DHT_PIN);

    MySensor->Fetch();
    std::cout << "Temp : " << MySensor->Temp << " °C  Humidity : " << MySensor->Hum << " %" << std::endl;
    std::cout << controller.getlevel() << std::endl;

    delete MySensor;

    delete controller;

    return 0;
}
