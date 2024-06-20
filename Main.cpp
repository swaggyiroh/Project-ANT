//
// Created by dominik 
//

#include "CameraController.h"
#include "dht.h"

#include <iostream>

int main() {
    CameraController controller;


    std::cout<<controller.getlevel();<<std::endl;
    
	if ( wiringPiSetup() == -1 )
		std::cout<<" error in wiringPiSetup"<<std::endl;
	

	read_dht_data();

    
    return 0;
}