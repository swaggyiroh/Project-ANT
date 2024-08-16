#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QKeyEvent> // Include for handling key events

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void setPercentage(const QString &percentage);
    void setTemperature(const QString &temperature);
    void setHumidity(const QString &humidity);
    void setImage(const QString &imagePath);

protected:
    void keyPressEvent(QKeyEvent *event) override; // Override key press event

private:
    QLabel *imageLabel;
    QLabel *percentageLabel;
    QLabel *temperatureLabel;
    QLabel *humidityLabel;
};

#endif // MAINWINDOW_H
