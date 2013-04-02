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

        bool ret = Systemd::enableUnitFiles(f, false, false);
        qDebug() << ret;
    }
};

int main(int argc, char* argv[])
{
    ManagerTest::enableUnitFiles();
}