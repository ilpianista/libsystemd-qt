/*
 * Copyright (C) 2013  Andrea Scarpino <me@andreascarpino.it>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#include <QDebug>
#include <QCoreApplication>

#include "../src/sdmanager.h"

class SDManagerTest {
public:
    SDManagerTest()
    {
    }

    static void disableUnitFiles()
    {
        qDebug();

        QStringList f;
        f << QLatin1String("upower.service");

        qDebug() << f;
        bool ret = Systemd::disableUnitFiles(f, false);;
        qDebug() << ret;
    }

    static void enableUnitFiles()
    {
        qDebug();

        QStringList f;
        f << QLatin1String("mysqld.service");

        qDebug() << f;
        bool ret = Systemd::enableUnitFiles(f, false, false);
        qDebug() << ret;
    }

    static void getUnit()
    {
        qDebug();

        qDebug() << Systemd::getUnit("mysqld.service");
    }

    static void getUnitByPID()
    {
        qDebug();

        qDebug() << Systemd::getUnitByPID(31493);
    }

    static void listJobs()
    {
        qDebug();

        Q_FOREACH(const Systemd::Job::Ptr job, Systemd::listJobs()) {
            qDebug() << job->id();
        }
    }

    static void listUnits()
    {
        qDebug();

        Q_FOREACH(const Systemd::Unit::Ptr unit, Systemd::listUnits()) {
            qDebug() << unit->id();
        }
    }

    static void listUnitFiles()
    {
        qDebug();

        Q_FOREACH(const QString unit, Systemd::listUnitFiles()) {
            qDebug() << unit;
        }
    }

    static void loadUnit()
    {
        qDebug();

        qDebug() << Systemd::loadUnit("mysqld.service");
    }

    static void reloadUnit()
    {
        qDebug();

        bool ret = Systemd::reloadUnit(QLatin1String("mysqld.service"), Systemd::Replace);
        qDebug() << ret;
    }

    static void restartUnit()
    {
        qDebug();

        bool ret = Systemd::restartUnit(QLatin1String("mysqld.service"), Systemd::Replace);
        qDebug() << ret;
    }

    static void startUnit()
    {
        qDebug();

        bool ret = Systemd::startUnit(QLatin1String("mysqld.service"), Systemd::Replace);
        qDebug() << ret;
    }

    static void stopUnit()
    {
        qDebug();

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

//    SDManagerTest::listJobs();

    SDManagerTest::listUnits();

    SDManagerTest::listUnitFiles();

//     SDManagerTest::loadUnit();

//     SDManagerTest::reloadUnit();

//     SDManagerTest::restartUnit();

//     SDManagerTest::startUnit();

//     SDManagerTest::stopUnit();
}
