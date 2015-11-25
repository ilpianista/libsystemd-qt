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

#include "job_p.h"
#include "sdmanager_p.h"

Systemd::JobPrivate::JobPrivate(const QString &path, const QDBusConnection &connection) :
    jobIface(Systemd::SystemdPrivate::SD_DBUS_SERVICE, path, connection)
{
    id = jobIface.id();
    jobType = jobIface.jobType();
    state = jobIface.state();
    unit = jobIface.unit().path.path();
}

Systemd::JobPrivate::~JobPrivate()
{
}

Systemd::Job::Job(const QString &path, const QDBusConnection &connection, QObject *parent) :
    QObject(parent), d_ptr(new JobPrivate(path, connection))
{
}

Systemd::Job::Job(JobPrivate &job, QObject *parent) :
    QObject(parent), d_ptr(&job)
{
}

Systemd::Job::~Job()
{
    delete d_ptr;
}

uint Systemd::Job::id() const
{
    Q_D(const Job);
    return d->id;
}

QString Systemd::Job::jobType() const
{
    Q_D(const Job);
    return d->jobType;
}

QString Systemd::Job::state() const
{
    Q_D(const Job);
    return d->state;
}

QString Systemd::Job::unit() const
{
    Q_D(const Job);
    return d->unit;
}
