#ifndef TDHT22_H
#define TDHT22_H

#include <wiringPi.h>

struct TSenData
{
    float Temp  = 0.0;
    float Hum   = 0.0;
    bool  Valid = false;

    void operator = (const TSenData &a){
        Temp =a.Temp;
        Hum  =a.Hum;
        Valid=a.Valid;
    }
};

class TDHT22:public TSenData
{
public:
    TDHT22(int pinNumber, bool fahrenheit = false);
    virtual ~TDHT22();

    bool Init();
    void Fetch();

private:
    bool fh;
    bool Init_ok;
    int  wPin;
    int  data[5];

    void StartSignal();
};

#endif // TDHT22_H
