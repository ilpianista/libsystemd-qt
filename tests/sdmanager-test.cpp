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

using namespace Systemd;

class SDManagerTest
{
public:
    static void disableUnitFiles()
    {
        const QString unitName("lm_sensors.service");

        QStringList f;
        f << unitName;

        qDebug() << "Disabling units:" << f;
        Systemd::disableUnitFiles(Systemd::System, f, false);

        qDebug() << "State:" << Systemd::getUnit(Systemd::System, unitName).data()->activeState();
    }

    static void enableUnitFiles()
    {
        const QString unitName("lm_sensors.service");

        QStringList f;
        f << unitName;

        qDebug() << "Enabling units:" << f;
        Systemd::enableUnitFiles(Systemd::System, f, false, false);

        qDebug() << "State:" << Systemd::getUnit(Systemd::System, unitName).data()->activeState();
    }

    static void getUnit()
    {
        const QString unitName("lm_sensors.service");

        qDebug() << "Got unit, id:" << Systemd::getUnit(Systemd::System, unitName)->id();
    }

    static void getUnitFileState()
    {
        const QString unitName("lm_sensors.service");

        qDebug() << "lm_sesnsors unit file state:" << Systemd::getUnitFileState(Systemd::System, unitName);
    }

    static void getUnitByPID()
    {
        qDebug() << Systemd::getUnitByPID(Systemd::System, 1)->id();
    }

    static void listJobs()
    {
        qDebug() << "Listing jobs:";
        Q_FOREACH (const Job::Ptr &job, Systemd::listJobs(Systemd::System)) {
            qDebug() << "\t" << job->id();
        }
    }

    static void listUnits()
    {
        qDebug() << "Listing units:";
        Q_FOREACH (const Unit::Ptr &unit, Systemd::listUnits(Systemd::System)) {
            qDebug() << "\t" << unit->id();
        }
    }

    static void listUnitFiles()
    {
        qDebug() << "Listing unit files:";

        Q_FOREACH (const QString &unitFile, Systemd::listUnitFiles(Systemd::System)) {
            qDebug() << "\t" << unitFile;
        }
    }

    static void loadUnit()
    {
        const QString unitName("lm_sensors.service");

        qDebug() << "Loading unit:" << unitName;
        qDebug() << "State:" << Systemd::loadUnit(Systemd::System, unitName)->loadState();
    }

    static void reloadUnit()
    {
        const QString unitName("lm_sensors.service");

        qDebug() << "Reloading unit:" << unitName;
        qDebug() << Systemd::reloadUnit(Systemd::System, unitName, Unit::Replace);
    }

    static void restartUnit()
    {
        const QString unitName("lm_sensors.service");

        qDebug() << "Restaring unit:" << unitName;
        qDebug() << Systemd::restartUnit(Systemd::System, unitName, Unit::Replace);
    }

    static void startUnit()
    {
        const QString unitName("lm_sensors.service");

        qDebug() << "Starting unit:" << unitName;
        qDebug() << Systemd::startUnit(Systemd::System, unitName, Unit::Replace);
    }

    static void stopUnit()
    {
        const QString unitName("lm_sensors.service");

        qDebug() << "Stopping unit:" << unitName;
        qDebug() << Systemd::stopUnit(Systemd::System, unitName, Unit::Replace);
    }
};

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);

//     SDManagerTest::disableUnitFiles();

//     SDManagerTest::enableUnitFiles();

    SDManagerTest::getUnit();

    SDManagerTest::getUnitFileState();

//     SDManagerTest::getUnitByPID();

    SDManagerTest::listJobs();

    SDManagerTest::listUnits();

    SDManagerTest::listUnitFiles();

//     SDManagerTest::loadUnit();

//     SDManagerTest::reloadUnit();

//     SDManagerTest::restartUnit();

//     SDManagerTest::startUnit();

//     SDManagerTest::stopUnit();
}
