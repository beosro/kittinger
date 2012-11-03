#ifndef GPSMANAGER_H
#define GPSMANAGER_H

#include <QObject>
#include <libgpsmm.h>
#include <QTimer>

struct gps_data_t;

typedef int GpsStatus;

class GPSManager : public QObject
{
    Q_OBJECT
public:
    explicit GPSManager(QObject *parent = 0);
    ~GPSManager();
    void openGps();
signals:
    void statusChanged(GpsStatus status);
    void latitudeChanged(double lat);
    void longitudeChanged(double lon);
    void altitudeChanged(double alt);
public slots:
    
private slots:
    void pollGps();
private:
    void processData(gps_data_t *data);
    gpsmm *gps_rec;
    QTimer pollTimer;
    int lastStatus;
    double lastLatitude;
    double lastLongitude;
    double lastAltitude;
};

#endif // GPS_H
