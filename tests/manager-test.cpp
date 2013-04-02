#include <QDebug>

#include "../manager.h"

class ManagerTest {
public:
    ManagerTest()
    {
    }

    static void enableUnitFiles()
    {
        QStringList f;
        f << QLatin1String("mysqld.service");

        qDebug() << f;
        bool ret = Systemd::enableUnitFiles(f, false, false);
        qDebug() << ret;
    }

    static void disableUnitFiles()
    {
        QStringList f;
        f << QLatin1String("upower.service");

        qDebug() << f;
        bool ret = Systemd::disableUnitFiles(f, false);;
        qDebug() << ret;
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
    ManagerTest::enableUnitFiles();

    ManagerTest::disableUnitFiles();

    ManagerTest::startUnit();

    ManagerTest::stopUnit();
}