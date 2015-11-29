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

#include "seat_p.h"
#include "ldmanager_p.h"

Systemd::Logind::SeatPrivate::SeatPrivate(const QString &path) :
    seatIface(Systemd::Logind::LogindPrivate::LD_DBUS_SERVICE, path, QDBusConnection::systemBus())
{
    qDBusRegisterMetaType<DBusSession>();
    qDBusRegisterMetaType<DBusSessionList>();

    activeSession = seatIface.activeSession();
    canGraphical = seatIface.canGraphical();
    canMultiSession = seatIface.canMultiSession();
    canTTY = seatIface.canTTY();
    id = seatIface.id();
    Q_FOREACH (const DBusSession &seatSession, seatIface.sessions()) {
        sessions << seatSession.path.path();
    }
}

Systemd::Logind::SeatPrivate::~SeatPrivate()
{
}

Systemd::Logind::Seat::Seat(const QString &path, QObject *parent) :
    QObject(parent), d_ptr(new SeatPrivate(path))
{
}

Systemd::Logind::Seat::Seat(SeatPrivate &seat, QObject *parent) :
    QObject(parent), d_ptr(&seat)
{
}

Systemd::Logind::Seat::~Seat()
{
    delete d_ptr;
}

QString Systemd::Logind::Seat::activeSession() const
{
    Q_D(const Seat);
    return d->activeSession.id;
}

bool Systemd::Logind::Seat::canGraphical() const
{
    Q_D(const Seat);
    return d->canGraphical;
}

bool Systemd::Logind::Seat::canMultiSession() const
{
    Q_D(const Seat);
    return d->canMultiSession;
}

bool Systemd::Logind::Seat::canTTY() const
{
    Q_D(const Seat);
    return d->canTTY;
}

QString Systemd::Logind::Seat::id() const
{
    Q_D(const Seat);
    return d->id;
}

QStringList Systemd::Logind::Seat::sessions() const
{
    Q_D(const Seat);
    return d->sessions;
}
