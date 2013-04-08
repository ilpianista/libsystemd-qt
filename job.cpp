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

#include "job.h"
#include "job_p.h"
#include "ldmanager_p.h"

Systemd::JobPrivate::JobPrivate(const QString &path, QObject *parent) :
    jobIface(Systemd::LogindPrivate::LD_DBUS_SERVICE, path, QDBusConnection::systemBus())
{
    id = jobIface.id();
    type = jobIface.jobType();
    state = jobIface.state();
    unitId = jobIface.unit().id;
}

Systemd::JobPrivate::~JobPrivate()
{
}

Systemd::Job::Job(const QString &path, QObject *parent) :
                  QObject(parent), d_ptr(new JobPrivate(path, this))
{
    init();
}

Systemd::Job::Job(JobPrivate &job, QObject *parent) :
                  QObject(parent), d_ptr(&job)
{
    init();
}

void Systemd::Job::init()
{
    Q_D(Job);
    qDBusRegisterMetaType<JobDBusUnit>();
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

QString Systemd::Job::type() const
{
    Q_D(const Job);
    return d->type;
}

QString Systemd::Job::state() const
{
    Q_D(const Job);
    return d->state;
}

QString Systemd::Job::unitId() const
{
    Q_D(const Job);
    return d->unitId;
}
