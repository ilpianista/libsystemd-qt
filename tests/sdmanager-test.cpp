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
#include "../src/generic-types.h"

using namespace Systemd;

class SDManagerTest {
public:
    static void disableUnitFiles()
    {
        QStringList f;
        f << QLatin1String("upower.service");

        qDebug() << f;
        Systemd::disableUnitFiles(Systemd::SystemSession, f, false);;
    }

    static void enableUnitFiles()
    {
        QStringList f;
        f << QLatin1String("mysqld.service");

        qDebug() << f;
        Systemd::enableUnitFiles(Systemd::SystemSession, f, false, false);
    }

    static void getUnit()
    {
        qDebug() << Systemd::getUnit(Systemd::SystemSession, "mysqld.service")->id();
    }

    static void getUnitByPID()
    {
        qDebug() << Systemd::getUnitByPID(Systemd::SystemSession, 31493)->id();
    }

    static void listJobs()
    {
        Q_FOREACH(const Job::Ptr &job, Systemd::listJobs(Systemd::SystemSession)) {
            qDebug() << job->id();
        }
    }

    static void listUnits()
    {
        Q_FOREACH(const Unit::Ptr &unit, Systemd::listUnits(Systemd::SystemSession)) {
            qDebug() << unit->id();
        }
    }

    static void listUnitFiles()
    {
        Q_FOREACH(const QString &unit, Systemd::listUnitFiles(Systemd::SystemSession)) {
            qDebug() << unit;
        }
    }

    static void loadUnit()
    {
        qDebug() << Systemd::loadUnit(Systemd::SystemSession, "mysqld.service")->loadState();
    }

    static void reloadUnit()
    {
        qDebug() << Systemd::reloadUnit(Systemd::SystemSession, QLatin1String("mysqld.service"), Systemd::Replace);
    }

    static void restartUnit()
    {
        qDebug() << Systemd::restartUnit(Systemd::SystemSession, QLatin1String("mysqld.service"), Systemd::Replace);
    }

    static void startUnit()
    {
        qDebug() << Systemd::startUnit(Systemd::SystemSession, QLatin1String("mysqld.service"), Systemd::Replace);
    }

    static void startTransientUnit()
    {
        QMultiMap<QString,QVariant> props;
        UnitDBusExecCommand xterm = {0};
        xterm.path = QLatin1String("/usr/sbin/xterm");
        xterm.argv << QLatin1String("/usr/sbin/xterm");
        xterm.ignore = false;

        UnitDBusExecCommandList args;
        args << xterm;

        props.insert(QLatin1String("Description"), QLatin1String("Test scope") );
        props.insert(QLatin1String("RemainAfterExit"), true );
        props.insert(QLatin1String("Environment"), QStringList(QLatin1String("DISPLAY=:0")));
        props.insert(QLatin1String("ExecStart"), QVariant::fromValue(args));

        qDebug() << Systemd::startTransientUnit(Systemd::UserSession, QLatin1String("mycool.service"), Systemd::Fail, props);


    }

    static void stopUnit()
    {
        qDebug() << Systemd::stopUnit(Systemd::SystemSession, QLatin1String("mysqld.service"), Systemd::Replace);
    }
};

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);

//     SDManagerTest::disableUnitFiles();

//     SDManagerTest::enableUnitFiles();

//     SDManagerTest::getUnit();

//     SDManagerTest::getUnitByPID();

//     SDManagerTest::listJobs();

//     SDManagerTest::listUnits();

//     SDManagerTest::listUnitFiles();

//     SDManagerTest::loadUnit();

//     SDManagerTest::reloadUnit();

//     SDManagerTest::restartUnit();

//     SDManagerTest::startUnit();

       SDManagerTest::startTransientUnit();

//     SDManagerTest::stopUnit();
}
