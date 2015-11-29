/*
 * Copyright (C) 2015  Andrea Scarpino <me@andreascarpino.it>
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

#include "user_p.h"
#include "ldmanager_p.h"

Systemd::Logind::UserPrivate::UserPrivate(const QString &path) :
    userIface(Systemd::Logind::LogindPrivate::LD_DBUS_SERVICE, path, QDBusConnection::systemBus())
{
    //display = userIface.display();
    gid = userIface.uID();
    idleHint = userIface.idleHint();
    idleSinceHint = userIface.idleSinceHint();
    idleSinceHintMonotonic = userIface.idleSinceHintMonotonic();
    linger = userIface.linger();
    name = userIface.name();
    runtimePath = userIface.runtimePath();
    //sessions = userIface.sessions();
    service = userIface.service();
    slice = userIface.slice();
    state = userIface.state();
    timestamp = userIface.timestamp();
    timestampMonotonic = userIface.timestampMonotonic();
    uid = userIface.uID();
}

Systemd::Logind::UserPrivate::~UserPrivate()
{
}

Systemd::Logind::User::User(const QString &path, QObject *parent) :
    QObject(parent), d_ptr(new UserPrivate(path))
{
}

Systemd::Logind::User::User(UserPrivate &user, QObject *parent) :
    QObject(parent), d_ptr(&user)
{
}

Systemd::Logind::User::~User()
{
    delete d_ptr;
}

uint Systemd::Logind::User::gid() const
{
    Q_D(const User);
    return d->gid;
}

bool Systemd::Logind::User::idleHint() const
{
    Q_D(const User);
    return d->idleHint;
}

qulonglong Systemd::Logind::User::idleSinceHint() const
{
    Q_D(const User);
    return d->idleSinceHint;
}

qulonglong Systemd::Logind::User::idleSinceHintMonotonic() const
{
    Q_D(const User);
    return d->idleSinceHintMonotonic;
}

bool Systemd::Logind::User::linger() const
{
    Q_D(const User);
    return d->linger;
}

QString Systemd::Logind::User::name() const
{
    Q_D(const User);
    return d->name;
}

QString Systemd::Logind::User::runtimePath() const
{
    Q_D(const User);
    return d->runtimePath;
}

QString Systemd::Logind::User::service() const
{
    Q_D(const User);
    return d->service;
}

QString Systemd::Logind::User::slice() const
{
    Q_D(const User);
    return d->slice;
}

QString Systemd::Logind::User::state() const
{
    Q_D(const User);
    return d->state;
}

qulonglong Systemd::Logind::User::timestamp() const
{
    Q_D(const User);
    return d->timestamp;
}

qulonglong Systemd::Logind::User::timestampMonotonic() const
{
    Q_D(const User);
    return d->timestampMonotonic;
}

uint Systemd::Logind::User::uid() const
{
    Q_D(const User);
    return d->uid;
}

