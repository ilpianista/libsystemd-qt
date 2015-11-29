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

#include "session_p.h"
#include "ldmanager_p.h"

Systemd::Logind::SessionPrivate::SessionPrivate(const QString &path) :
    sessionIface(Systemd::Logind::LogindPrivate::LD_DBUS_SERVICE, path, QDBusConnection::systemBus())
{
    active = sessionIface.active();
    audit = sessionIface.audit();
    desktop = sessionIface.desktop();
    display = sessionIface.display();
    id = sessionIface.id();
    idleHint = sessionIface.idleHint();
    idleSinceHint = sessionIface.idleSinceHint();
    idleSinceHintMonotonic = sessionIface.idleSinceHintMonotonic();
    leader = sessionIface.leader();
    name = sessionIface.name();
    remote = sessionIface.remote();
    remoteHost = sessionIface.remoteHost();
    remoteUser = sessionIface.remoteUser();
    scope = sessionIface.scope();
    seat = sessionIface.seat().id;
    service = sessionIface.service();
    state = sessionIface.state();
    tty = sessionIface.tTY();
    timestamp = sessionIface.timestamp();
    timestampMonotonic = sessionIface.timestampMonotonic();
    type = sessionIface.type();
    user = sessionIface.user().id;
    vtNr = sessionIface.vTNr();
    _class = sessionIface._Class();
}

Systemd::Logind::SessionPrivate::~SessionPrivate()
{
}

Systemd::Logind::Session::Session(const QString &path, QObject *parent) :
    QObject(parent), d_ptr(new SessionPrivate(path))
{
}

Systemd::Logind::Session::Session(SessionPrivate &session, QObject *parent) :
    QObject(parent), d_ptr(&session)
{
}

Systemd::Logind::Session::~Session()
{
    delete d_ptr;
}

bool Systemd::Logind::Session::active() const
{
    Q_D(const Session);
    return d->active;
}

uint Systemd::Logind::Session::audit() const
{
    Q_D(const Session);
    return d->audit;
}

QString Systemd::Logind::Session::desktop() const
{
    Q_D(const Session);
    return d->desktop;
}

QString Systemd::Logind::Session::display() const
{
    Q_D(const Session);
    return d->display;
}

QString Systemd::Logind::Session::id() const
{
    Q_D(const Session);
    return d->id;
}

bool Systemd::Logind::Session::idleHint() const
{
    Q_D(const Session);
    return d->idleHint;
}

qulonglong Systemd::Logind::Session::idleSinceHint() const
{
    Q_D(const Session);
    return d->idleSinceHint;
}

qulonglong Systemd::Logind::Session::idleSinceHintMonotonic() const
{
    Q_D(const Session);
    return d->idleSinceHintMonotonic;
}

uint Systemd::Logind::Session::leader() const
{
    Q_D(const Session);
    return d->leader;
}

QString Systemd::Logind::Session::name() const
{
    Q_D(const Session);
    return d->name;
}

bool Systemd::Logind::Session::remote() const
{
    Q_D(const Session);
    return d->remote;
}

QString Systemd::Logind::Session::remoteHost() const
{
    Q_D(const Session);
    return d->remoteHost;
}

QString Systemd::Logind::Session::remoteUser() const
{
    Q_D(const Session);
    return d->remoteUser;
}

QString Systemd::Logind::Session::seat() const
{
    Q_D(const Session);
    return d->seat;
}

QString Systemd::Logind::Session::scope() const
{
    Q_D(const Session);
    return d->scope;
}

QString Systemd::Logind::Session::service() const
{
    Q_D(const Session);
    return d->service;
}

QString Systemd::Logind::Session::state() const
{
    Q_D(const Session);
    return d->state;
}

QString Systemd::Logind::Session::tty() const
{
    Q_D(const Session);
    return d->tty;
}

qulonglong Systemd::Logind::Session::timestamp() const
{
    Q_D(const Session);
    return d->timestamp;
}

qulonglong Systemd::Logind::Session::timestampMonotonic() const
{
    Q_D(const Session);
    return d->timestampMonotonic;
}

QString Systemd::Logind::Session::type() const
{
    Q_D(const Session);
    return d->type;
}

uint Systemd::Logind::Session::user() const
{
    Q_D(const Session);
    return d->user;
}

uint Systemd::Logind::Session::vtNr() const
{
    Q_D(const Session);
    return d->vtNr;
}

QString Systemd::Logind::Session::_class() const
{
    Q_D(const Session);
    return d->_class;
}
