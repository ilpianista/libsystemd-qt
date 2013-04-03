/***************************************************************************
 * Copyright (c) 2013 Andrea Scarpino <andrea@archlinux.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the
 * Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 ***************************************************************************/

#include <QDebug>
#include <QCoreApplication>

#include "../ldmanager.h"

class LDManagerTest {
public:
    LDManagerTest()
    {
    }

    static void canHibernate() {
        Systemd::Permission perm = Systemd::canHibernate();
        if (perm == Systemd::Yes) {
            qDebug() << "Yes";
        } else {
            qDebug() << "Some other value";
        }
    }

    static void canHybridSleep() {
        Systemd::Permission perm = Systemd::canHybridSleep();
        if (perm == Systemd::Yes) {
            qDebug() << "Yes";
        } else {
            qDebug() << "Some other value";
        }
    }

    static void canPowerOff() {
        Systemd::Permission perm = Systemd::canPowerOff();
        if (perm == Systemd::Yes) {
            qDebug() << "Yes";
        } else {
            qDebug() << "Some other value";
        }
    }

    static void canReboot() {
        Systemd::Permission perm = Systemd::canReboot();
        if (perm == Systemd::Yes) {
            qDebug() << "Yes";
        } else {
            qDebug() << "Some other value";
        }
    }

    static void canSuspend() {
        Systemd::Permission perm = Systemd::canSuspend();
        if (perm == Systemd::Yes) {
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
