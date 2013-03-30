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

#include "manager.h"
#include "manager_p.h"

const QString Systemd::SystemdPrivate::SD_DBUS_SERVICE(QString::fromLatin1("org.freedesktop.systemd1"));
const QString Systemd::SystemdPrivate::SD_DBUS_DAEMON_PATH(QString::fromLatin1("org/freedesktop/systemd1"));
const QString Systemd::SystemdPrivate::LD_DBUS_SERVICE(QString::fromLatin1("org.freedesktop.login1"));
const QString Systemd::SystemdPrivate::LD_DBUS_DAEMON_PATH(QString::fromLatin1("org/freedesktop/login1"));

Systemd::SystemdPrivate::SystemdPrivate() :
    isdface( Systemd::SystemdPrivate::SD_DBUS_SERVICE, Systemd::SystemdPrivate::SD_DBUS_DAEMON_PATH, QDBusConnection::systemBus()),
    ildface( Systemd::SystemdPrivate::LD_DBUS_SERVICE, Systemd::SystemdPrivate::LD_DBUS_DAEMON_PATH, QDBusConnection::systemBus())
{
    init();
}

void Systemd::SystemdPrivate::init()
{

}