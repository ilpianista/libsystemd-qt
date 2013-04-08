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

#include "seat.h"
#include "seat_p.h"
#include "ldmanager_p.h"

Systemd::SeatPrivate::SeatPrivate(const QString &path, QObject *parent) :
    seatIface(Systemd::LogindPrivate::LD_DBUS_SERVICE, path, QDBusConnection::systemBus())
{
    canGraphical = seatIface.canGraphical();
}

Systemd::SeatPrivate::~SeatPrivate()
{
}

Systemd::Seat::Seat(const QString &path, QObject *parent) :
                    QObject(parent), d_ptr(new SeatPrivate(path, this))
{
}

Systemd::Seat::Seat(SeatPrivate &seat,  QObject *parent) :
                    QObject(parent), d_ptr(&seat)
{
}

Systemd::Seat::~Seat()
{
    delete d_ptr;
}

bool Systemd::Seat::canGraphical() const
{
    Q_D(const Seat);
    return d->canGraphical;
}
