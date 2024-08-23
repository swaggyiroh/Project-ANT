QT += widgets concurrent  # Add concurrent module here if it's not already present

TARGET = ../ProjectANT  # Adjusted TARGET name
TEMPLATE = app

# Include paths for Qt and OpenCV
unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += opencv4

# Additional include paths
INCLUDEPATH += /usr/include/opencv4

# Library paths for Qt and OpenCV (replace with actual paths)
LIBS += -L/usr/lib -lopencv_core -lopencv_imgproc -lopencv_highgui
LIBS += -L$$[QT_INSTALL_PREFIX]/lib -lQt5Widgets -lQt5Gui -lQt5Core

# Additional libraries
LIBS += -lwiringPi
LIBS += -lGL -lpthread

# Source files
SOURCES += \
    main.cpp \
    src/source/Window.cpp \
    src/source/ImageProcessing.cpp \
    src/source/DHT22.cpp

# Header files
HEADERS += \
    src/source/Window.h \
    src/source/ImageProcessing.h \
    src/source/DHT22.h
