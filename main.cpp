#include <QApplication>
#include "src/source/Window.h"
#include "src/source/ImageProcessing.h"
#include "src/source/DHT22.h"
#include <iostream>
#include <QTimer>
#include <string>

using namespace std;

#define DHT_PIN     26

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    MainWindow app;
    app.showFullScreen();


    QTimer timer;
    QObject::connect(&timer,&QTimer::timeout,[&app]()
    {

        TDHT22 *Sensor = new TDHT22(DHT_PIN); // Initialize the DHT22 sensor
        //to change to fahrenheit do this:
        //TDHT22 *Sensor = new TDHT22(DHT_PIN, true);
        
        Sensor->Init(); // Initialize the DHT22 sensor

        ImageProcessing imgProcessor; // Create an instance of ImageProcessing

        bool processImage = true; // Boolean to determine when to process image

        if (processImage) {
            system("./src/script/capture_image.sh"); // Capture an image
            string image = "assets/image.jpg"; // Image file path
            app.setImage(QString::fromStdString(image)); //Displays new Image
            string fillLevel = imgProcessor.processCapturedImage(image); // Process the captured image
            app.setFood(QString::fromStdString(fillLevel)); // Update GUI with processed image result
        }
        processImage = !processImage; // Toggle processImage flag

        // Fetch Sensor Data
        Sensor->Fetch();
        
        int temp = Sensor->Temp;
        int hum = Sensor->Hum;

        // Ensure valid sensor data
        while (temp == 0 || hum == 0) {
            Sensor->Fetch();
            temp = Sensor->Temp;
            hum = Sensor->Hum;
        }

        // Update GUI with sensor data
        app.setTemperature(QString::fromStdString(to_string(temp)));
        app.setHumidity(QString::fromStdString(to_string(hum)));

        delete Sensor; // Clean up allocated memory for DHT22 sensor


    });
    timer.start(10000);
   
    return a.exec(); // Execute the Qt application event loop
}
