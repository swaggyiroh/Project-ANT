/**
 * Read data (Temperature & Relative Humidity) from DHT22 sensor.
 * Data is transmitted bit by bit.  Start of bit is signaled by line going LOW,
 * then value of bit is determined by how long the line stays HIGH.
 * Based on code found at http://www.uugear.com/portfolio/read-dht1122-temperature-humidity-sensor-from-raspberry-pi/
 * Writen by Chris Wolcott.
 * Adapted by Q-engineering 7-6-2021
 */

#include <iostream>
#include <fstream>      // std::ofstream
#include "DHT22.h"

#define DHT_PIN     26                   // WiringPi 26 = BCM 12 = connector pin 32

int main( void ) {
    int t=0;

    TDHT22 *MySensor = new TDHT22(DHT_PIN);

    MySensor->Init();                   //calls the wiringPiSetup

    //<Ctrl>+<C> to stop the loop of this example
    while(1){
        MySensor->Fetch();
        std::cout << "Temp : " <<  MySensor->Temp << " °C  Humidity : " << MySensor->Hum << " %" << std::endl;
        delay(3000);                    // Wait 3 seconds between readings.
        t++;
    }

    delete MySensor;

    return(0);
}
