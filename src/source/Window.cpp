#include "Window.h"
#include <QVBoxLayout>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      imageLabel(new QLabel(this)),
      percentageLabel(new QLabel("Futterstand: 0%", this)),
      temperatureLabel(new QLabel("Temperatur: 0°C", this)),
      humidityLabel(new QLabel("Feuchtigkeits: 0%", this)) {
    
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Load the image
    QPixmap originalPixmap("assets/image.jpg");
    
    // Scale the image to 100x100 pixels
    QPixmap scaledPixmap = originalPixmap.scaled(250, 300, Qt::KeepAspectRatio);

    // Set up the image label with the scaled pixmap
    imageLabel->setPixmap(scaledPixmap);
    imageLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(imageLabel);

    // Set up the percentage label
    percentageLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(percentageLabel);

    // Set up the temperature label
    temperatureLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(temperatureLabel);

    // Set up the humidity label
    humidityLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(humidityLabel);

    // Set the layout for the central widget
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);


    
}

MainWindow::~MainWindow() {
    // Destructor implementation
}

void MainWindow::setFood(const QString &percentage) {
    percentageLabel->setText("Futter: " + percentage);
}

void MainWindow::setTemperature(const QString &temperature) {
    temperatureLabel->setText("Temperatur: " + temperature + "°C");
}

void MainWindow::setHumidity(const QString &humidity) {
    humidityLabel->setText("Feuchtigkeits: " + humidity + "%");
}

void MainWindow::setImage(const QString &imagePath) {
    QPixmap originalPixmap(imagePath);
    QPixmap scaledPixmap = originalPixmap.scaled(250, 300, Qt::KeepAspectRatio);
    imageLabel->setPixmap(scaledPixmap);
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Escape) {
        qDebug() << "Esc key pressed. Closing application.";
        close(); // Close the main window (and thus exit the application)
    } else {
        QMainWindow::keyPressEvent(event); // Handle other key events
    }
}
