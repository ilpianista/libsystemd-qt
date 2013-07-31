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
        Systemd::Logind::Permission perm = Systemd::Logind::canHibernate();
        if (perm == Systemd::Logind::Yes) {
            qDebug() << "Yes";
        } else {
            qDebug() << "Some other value";
        }
    }

    static void canHybridSleep() {
        Systemd::Logind::Permission perm = Systemd::Logind::canHybridSleep();
        if (perm == Systemd::Logind::Yes) {
            qDebug() << "Yes";
        } else {
            qDebug() << "Some other value";
        }
    }

    static void canPowerOff() {
        Systemd::Logind::Permission perm = Systemd::Logind::canPowerOff();
        if (perm == Systemd::Logind::Yes) {
            qDebug() << "Yes";
        } else {
            qDebug() << "Some other value";
        }
    }

    static void canReboot() {
        Systemd::Logind::Permission perm = Systemd::Logind::canReboot();
        if (perm == Systemd::Logind::Yes) {
            qDebug() << "Yes";
        } else {
            qDebug() << "Some other value";
        }
    }

    static void canSuspend() {
        Systemd::Logind::Permission perm = Systemd::Logind::canSuspend();
        if (perm == Systemd::Logind::Yes) {
            qDebug() << "Yes";
        } else {
            qDebug() << "Some other value";
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
