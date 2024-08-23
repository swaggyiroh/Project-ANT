#include "DHT22.h"
#include <time.h>

#define MAX_TIMINGS 85                  // Takes 84 state changes to transmit data

// Function to calculate the duration in microseconds between two timespec values
static int calculateDuration(struct timespec start, struct timespec end) {
    return ((end.tv_sec - start.tv_sec) * 1000000) + ((end.tv_nsec - start.tv_nsec) / 1000);
}

TDHT22::TDHT22(int pinNumber, bool fahrenheit)
{
    wPin = pinNumber;
    fh = fahrenheit;
}

TDHT22::~TDHT22(){	//not needed
}

bool TDHT22::Init() {
    Init_ok = (wiringPiSetup() >= 0);
    if (Init_ok) {
        pinMode(wPin, INPUT);
    }
    return Init_ok;
}

// Function to start communication with the sensor
// Signal Sensor we're ready to read by pulling pin UP for 10 mS.
// pulling pin down for 18 mS and then back up for 40 µS.
void TDHT22::StartSignal() {
    pinMode(wPin, OUTPUT);
    digitalWrite(wPin, HIGH);
    delay(10);
    digitalWrite(wPin, LOW);
    delay(18);
    digitalWrite(wPin, HIGH);
    delayMicroseconds(40);
    pinMode(wPin, INPUT);
}


// Function to fetch data from the sensor
void TDHT22::Fetch() {
    if (!Init_ok) return;

    struct timespec startTime, currentTime;
    int duration = 0;
    int toggleCount = 0;
    int bitCount = 0;
    int lastState = HIGH;

    // Clear data array
    for (int i = 0; i < 5; i++) data[i] = 0;

    StartSignal();

    // Read data from sensor
    for (toggleCount = 0; (toggleCount < MAX_TIMINGS) && (duration < 255); toggleCount++) {
        clock_gettime(CLOCK_REALTIME, &startTime);
        while ((digitalRead(wPin) == lastState) && (duration < 255)) {
            clock_gettime(CLOCK_REALTIME, &currentTime);
            duration = calculateDuration(startTime, currentTime);
        }

        lastState = digitalRead(wPin);

        // First 2 state changes are sensor signaling ready to send, ignore them.
        // Each bit is preceeded by a state change to mark its beginning, ignore it too.
        if ((toggleCount > 2) && (toggleCount % 2 == 0)) {
            data[bitCount / 8] <<= 1;  // Shift left to make space for the new bit
            if (duration > 35) {
                data[bitCount / 8] |= 1;  // Set the bit if duration indicates a '1'
            }
            bitCount++;
        }
    }

    // Read 40 bits. (Five elements of 8 bits each)  Last element is a checksum.
    if((bitCount >= 40) && (data[4] == ((data[0] + data[1] + data[2] + data[3]) & 0xFF)) ) {
        Valid= true;
        Hum  = (float)((data[0] << 8) + data[1]) / 10.0;
        Temp = (float)((data[2] << 8) + data[3]) / 10.0;
        if(data[2] & 0x80)  Temp *= -1;         // Check for negative temperature
        if(fh) {				// Convert to Fahrenheit
	Temp *= 1.8; Temp += 32.0; 
	}
    }
    else {                                      // Bad read
        Valid= false;
        Hum  = 0.0;
        Temp = 0.0;
    }
}

