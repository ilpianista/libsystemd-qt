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

#include "ldmanager.h"
#include "ldmanager_p.h"

const QString Systemd::LogindPrivate::LD_DBUS_SERVICE(QString::fromLatin1("org.freedesktop.login1"));
const QString Systemd::LogindPrivate::LD_DBUS_DAEMON_PATH(QString::fromLatin1("/org/freedesktop/login1"));

Q_GLOBAL_STATIC(Systemd::LogindPrivate, globalLogind)

Systemd::LogindPrivate::LogindPrivate() :
ildface( Systemd::LogindPrivate::LD_DBUS_SERVICE, Systemd::LogindPrivate::LD_DBUS_DAEMON_PATH, QDBusConnection::systemBus())
{
}

Systemd::LogindPrivate::~LogindPrivate()
{
}
