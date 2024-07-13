#include <QApplication>
#include "src/source/mainwindow.h"
#include "src/source/process_image.h"
#include "src/source/DHT22.h"
using namespace std;

#define DHT_PIN     26

int main() {
    process_image img;
    TDHT22 *Sensor = new TDHT22(DHT_PIN);

    QApplication a(argc, argv);
    MainWindow app;
    app.showFullScreen();

    Sensor->Init();
    
    bool prcim = true;

    while(1){
        if(prcim){
            system("./src/script/capture_image.sh");
            string image = "assets/image.jpg";
            app.setPercentage(img.processCapturedImage(image)+"");     
        }
        // Turning value, so it only fetches the image every secound time.
        prcim = !prcim;

        // Fetching Sensor Data;
        Sensor->Fetch();
        
        int temp = Sensor->Temp;
        int hum = Sensor->Hum;
        // sometimes Fetching the Sensor return 0°C and 0% then refetch,
        while(tmp == 0 || hum == 0){
            int temp = Sensor->Temp;
            int hum = Sensor->Hum;
        }
        // place values into app window
        app.setTemperature(temp+"");
        app.setHumidity(hum+"");
        delay(10000);
    }




    // Example of updating values
    w.setPercentage("75%");
    w.setTemperature("30");
    w.setHumidity("80");

    return a.exec();
}
