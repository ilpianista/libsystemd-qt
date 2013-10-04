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

#ifndef SD_SEAT_H
#define SD_SEAT_H

#include <QObject>

#include "QtSystemd-export.h"

namespace Systemd
{
namespace Logind
{
class SeatPrivate;

class SDQT_EXPORT Seat : public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(Seat)

    Q_PROPERTY(QString activeSession READ activeSession)
    Q_PROPERTY(bool canGraphical READ canGraphical)
    Q_PROPERTY(bool canMultiSession READ canMultiSession)
    Q_PROPERTY(bool canTTY READ canTTY)
    Q_PROPERTY(QString id READ id)
    Q_PROPERTY(bool idleHint READ idleHint)
    Q_PROPERTY(qulonglong idleSinceHint READ idleSinceHint)
    Q_PROPERTY(qulonglong idleSinceHintMonotonic READ idleSinceHintMonotonic)
    Q_PROPERTY(QStringList sessions READ sessions)

public:
    explicit Seat(const QString &path, QObject *parent = 0);
    explicit Seat(SeatPrivate &seat, QObject *parent = 0);
    virtual ~Seat();

    QString activeSession() const;
    bool canGraphical() const;
    bool canMultiSession() const;
    bool canTTY() const;
    QString id() const;
    bool idleHint() const;
    qulonglong idleSinceHint() const;
    qulonglong idleSinceHintMonotonic() const;
    QStringList sessions() const;

protected:
    SeatPrivate *d_ptr;
};
}
}

#endif