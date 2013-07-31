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
        Q_FOREACH(Systemd::Job *j, Systemd::listJobs()) {
            qDebug() << j->id();
        }
    }

    static void listUnits()
    {
        Q_FOREACH(Systemd::Unit *u, Systemd::listUnits()) {
            qDebug() << u->id();
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