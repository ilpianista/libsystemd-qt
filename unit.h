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

#ifndef SD_UNIT_H
#define SD_UNIT_H

#include <QObject>

namespace Systemd {

class UnitPrivate;

class Unit : public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(Unit)

    Q_PROPERTY(QString id READ id)
    Q_PROPERTY(QString loadState READ activeState)
    Q_PROPERTY(QString activeState READ activeState)

public:
    explicit Unit(const QString &path, QObject *parent = 0);
    Unit(UnitPrivate &unit, QObject *parent = 0);
    virtual ~Unit();

    QString id() const;
    QString description() const;
    QString loadState() const;
    QString activeState() const;
    QString subState() const;
    QString following() const;
    QString jobId() const;

protected:
    UnitPrivate *d_ptr;
};
}

#endif