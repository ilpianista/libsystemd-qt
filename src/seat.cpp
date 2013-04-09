/*
 * Copyright (C) 2013  Andrea Scarpino <me@andreascarpino.it>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#include "seat.h"
#include "seat_p.h"
#include "ldmanager_p.h"

Systemd::Logind::SeatPrivate::SeatPrivate(const QString &path, QObject *parent) :
    seatIface(Systemd::Logind::LogindPrivate::LD_DBUS_SERVICE, path, QDBusConnection::systemBus())
{
    canGraphical = seatIface.canGraphical();
}

Systemd::Logind::SeatPrivate::~SeatPrivate()
{
}

Systemd::Logind::Seat::Seat(const QString &path, QObject *parent) :
                    QObject(parent), d_ptr(new SeatPrivate(path, this))
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

bool Systemd::Logind::Seat::canGraphical() const
{
    Q_D(const Seat);
    return d->canGraphical;
}
