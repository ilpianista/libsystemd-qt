#include <QCoreApplication>

#include "../sdmanager.h"

class SDManagerTest {
public:
    SDManagerTest()
    {
    }

    static void disableUnitFiles()
    {
        QStringList f;
        f << QLatin1String("upower.service");

        qDebug() << f;
        bool ret = Systemd::disableUnitFiles(f, false);;
        qDebug() << ret;
    }

    static void enableUnitFiles()
    {
        QStringList f;
        f << QLatin1String("mysqld.service");

        qDebug() << f;
        bool ret = Systemd::enableUnitFiles(f, false, false);
        qDebug() << ret;
    }

    static void getUnit()
    {
        qDebug() << Systemd::getUnit("mysqld.service");
    }

    static void getUnitByPID()
    {
        qDebug() << Systemd::getUnitByPID(31493);
    }

    static void listJobs()
    {
        const QList<Systemd::Job*> jobs = Systemd::listJobs();
        for (int i=0; i < jobs.size(); i++) {
            qDebug() << jobs.at(i)->id();
        }
    }

    static void listUnits()
    {
        const QList<Systemd::Unit*> units = Systemd::listUnits();
        for (int i=0; i < units.size(); i++) {
            qDebug() << units.at(i)->id();
        }
    }

    static void loadUnit()
    {
        qDebug() << Systemd::loadUnit("mysqld.service");
    }

    static void reloadUnit()
    {
        bool ret = Systemd::reloadUnit(QLatin1String("mysqld.service"), Systemd::Replace);
        qDebug() << ret;
    }

    static void restartUnit()
    {
        bool ret = Systemd::restartUnit(QLatin1String("mysqld.service"), Systemd::Replace);
        qDebug() << ret;
    }

    static void startUnit()
    {
        bool ret = Systemd::startUnit(QLatin1String("mysqld.service"), Systemd::Replace);
        qDebug() << ret;
    }

    static void stopUnit()
    {
        bool ret = Systemd::stopUnit(QLatin1String("mysqld.service"), Systemd::Replace);
        qDebug() << ret;
    }
};

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);

//     SDManagerTest::disableUnitFiles();

//     SDManagerTest::enableUnitFiles();

//     SDManagerTest::getUnit();

//     SDManagerTest::getUnitByPID();

    SDManagerTest::listJobs();

    SDManagerTest::listUnits();

//     SDManagerTest::loadUnit();

//     SDManagerTest::reloadUnit();

//     SDManagerTest::restartUnit();

//     SDManagerTest::startUnit();

//     SDManagerTest::stopUnit();
}