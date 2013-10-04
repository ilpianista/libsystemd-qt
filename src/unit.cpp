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

#include "unit.h"
#include "unit_p.h"
#include "sdmanager_p.h"

Systemd::UnitPrivate::UnitPrivate(const QString &path, QObject *parent) :
    unitIface(Systemd::SystemdPrivate::SD_DBUS_SERVICE, path, QDBusConnection::systemBus())
{
    id = unitIface.id();
    description = unitIface.description();
    loadState = unitIface.loadState();
    activeState = unitIface.activeState();
    subState = unitIface.subState();
    following = unitIface.following();
    jobId = unitIface.job().id;
    unitFileState = unitIface.unitFileState();
}

Systemd::UnitPrivate::~UnitPrivate()
{
}

Systemd::Unit::Unit(const QString &path, QObject *parent) :
                    QObject(parent), d_ptr(new UnitPrivate(path, this))
{
    init();
}

Systemd::Unit::Unit(UnitPrivate &unit, QObject *parent) :
                    QObject(parent), d_ptr(&unit)
{
    init();
}

Systemd::Unit::Unit(QObject *parent) : QObject(parent)
{
    init();
}

void Systemd::Unit::init()
{
    Q_D(Unit);
    qDBusRegisterMetaType<UnitDBusJob>();
}

Systemd::Unit::~Unit()
{
    delete d_ptr;
}

QString Systemd::Unit::id() const
{
    Q_D(const Unit);
    return d->id;
}

QString Systemd::Unit::description() const
{
    Q_D(const Unit);
    return d->description;
}

QString Systemd::Unit::loadState() const
{
    Q_D(const Unit);
    return d->loadState;
}

QString Systemd::Unit::activeState() const
{
    Q_D(const Unit);
    return d->activeState;
}

QString Systemd::Unit::subState() const
{
    Q_D(const Unit);
    return d->subState;
}

QString Systemd::Unit::following() const
{
    Q_D(const Unit);
    return d->following;
}

QString Systemd::Unit::jobId() const
{
    Q_D(const Unit);
    return d->jobId;
}

QString Systemd::Unit::unitFileState() const
{
    Q_D(const Unit);
    return d->unitFileState;
}
