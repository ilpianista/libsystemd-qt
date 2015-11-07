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

#include "../src/ldmanager.h"

class LDManagerTest {
public:
    LDManagerTest()
    {
    }

    static void canHibernate() {
        qDebug() << "Can hibernate?";
        Systemd::Logind::Permission perm = Systemd::Logind::canHibernate();
        switch (perm)
        {
            case Systemd::Logind::Challenge:
                qDebug() << "Challenge";
                break;
            case Systemd::Logind::Na:
                qDebug() << "Na";
                break;
            case Systemd::Logind::No:
                qDebug() << "No";
                break;
            case Systemd::Logind::Yes:
                qDebug() << "Yes";
                break;
        }
    }

    static void canHybridSleep() {
        qDebug() << "Can hybrid sleep?";
        Systemd::Logind::Permission perm = Systemd::Logind::canHybridSleep();
        switch (perm)
        {
            case Systemd::Logind::Challenge:
                qDebug() << "Challenge";
                break;
            case Systemd::Logind::Na:
                qDebug() << "Na";
                break;
            case Systemd::Logind::No:
                qDebug() << "No";
                break;
            case Systemd::Logind::Yes:
                qDebug() << "Yes";
                break;
        }
    }

    static void canPowerOff() {
        qDebug() << "Can power off?";
        Systemd::Logind::Permission perm = Systemd::Logind::canPowerOff();
        switch (perm)
        {
            case Systemd::Logind::Challenge:
                qDebug() << "Challenge";
                break;
            case Systemd::Logind::Na:
                qDebug() << "Na";
                break;
            case Systemd::Logind::No:
                qDebug() << "No";
                break;
            case Systemd::Logind::Yes:
                qDebug() << "Yes";
                break;
        }
    }

    static void canReboot() {
        qDebug() << "Can reboot?";
        Systemd::Logind::Permission perm = Systemd::Logind::canReboot();
        switch (perm)
        {
            case Systemd::Logind::Challenge:
                qDebug() << "Challenge";
                break;
            case Systemd::Logind::Na:
                qDebug() << "Na";
                break;
            case Systemd::Logind::No:
                qDebug() << "No";
                break;
            case Systemd::Logind::Yes:
                qDebug() << "Yes";
                break;
        }
    }

    static void canSuspend() {
        qDebug() << "Can suspend?";
        Systemd::Logind::Permission perm = Systemd::Logind::canSuspend();
        switch (perm)
        {
            case Systemd::Logind::Challenge:
                qDebug() << "Challenge";
                break;
            case Systemd::Logind::Na:
                qDebug() << "Na";
                break;
            case Systemd::Logind::No:
                qDebug() << "No";
                break;
            case Systemd::Logind::Yes:
                qDebug() << "Yes";
                break;
        }
    }
};

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);

    LDManagerTest::canHibernate();

    LDManagerTest::canHybridSleep();

    LDManagerTest::canPowerOff();

    LDManagerTest::canReboot();

    LDManagerTest::canSuspend();
}
