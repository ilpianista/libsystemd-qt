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

#ifndef SD_JOB_H
#define SD_JOB_H

#include <QObject>

namespace Systemd {

class JobPrivate;

class Job : public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(Job)

public:
    explicit Job(const QString &path, QObject *parent = 0);
    Job(JobPrivate &job, QObject *parent = 0);
    virtual ~Job();

    uint id() const;
    QString unitId() const;
    QString type() const;
    QString state() const;

protected:
    JobPrivate *d_ptr;

private:
    void init();
};
}

#endif