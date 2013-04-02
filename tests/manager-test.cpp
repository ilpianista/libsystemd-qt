#include <QDebug>
#include <QCoreApplication>

#include "../manager.h"

class ManagerTest {
public:
    ManagerTest()
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

    static void listUnits()
    {
        qDebug() << Systemd::listUnits();
    }

    static void loadUnit()
    {
        qDebug() << Systemd::loadUnit("mysqld.service");
    }

    static void startUnit()
    {
        bool ret = Systemd::startUnit(QLatin1String("mysqld.service"), QLatin1String("replace"));
        qDebug() << ret;
    }

    static void stopUnit()
    {
        bool ret = Systemd::stopUnit(QLatin1String("mysqld.service"), QLatin1String("replace"));
        qDebug() << ret;
    }
};

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);
//     ManagerTest::disableUnitFiles();

//     ManagerTest::enableUnitFiles();

//     ManagerTest::getUnit();

//     ManagerTest::getUnitByPID();

//     ManagerTest::listUnits();

    ManagerTest::loadUnit();

//     ManagerTest::startUnit();

//     ManagerTest::stopUnit();
}