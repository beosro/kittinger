#include <QtGui/QApplication>
#include "mainwindow.h"
#include "gpsmanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    GPSManager gpsManager;
    w.connect(&gpsManager, SIGNAL(latitudeChanged(double)), &w, SLOT(latitudeChanged(double)));
    w.connect(&gpsManager, SIGNAL(longitudeChanged(double)), &w, SLOT(longitudeChanged(double)));
    w.connect(&gpsManager, SIGNAL(altitudeChanged(double)), &w, SLOT(altitudeChanged(double)));
    w.connect(&gpsManager, SIGNAL(statusChanged(GpsStatus)), &w, SLOT(statusChanged(GpsStatus)));
    w.show();
    gpsManager.openGps();
    return a.exec();
}