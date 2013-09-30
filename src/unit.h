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

#ifndef SD_UNIT_H
#define SD_UNIT_H

#include <QObject>

namespace Systemd {

class UnitPrivate;

class Unit : public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(Unit)

    Q_PROPERTY(QString id READ id CONSTANT)
    Q_PROPERTY(QString type READ type CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)
    Q_PROPERTY(QString loadState READ loadState NOTIFY loadStateChanged)
    Q_PROPERTY(QString activeState READ activeState NOTIFY activeStateChanged)
    Q_PROPERTY(QString jobId READ jobId NOTIFY jobIdChanged)
    Q_PROPERTY(QString unitFileState READ unitFileState NOTIFY unitFileStateChanged)

public:
    explicit Unit(const QString &path, QObject *parent = 0);
    Unit(UnitPrivate &unit, QObject *parent = 0);
    Unit(QObject *parent = 0);
    virtual ~Unit();

    QString id() const;
    QString type() const;
    QString description() const;
    QString loadState() const;
    QString activeState() const;
    QString subState() const;
    QString following() const;
    QString jobId() const;
    QString unitFileState() const;

Q_SIGNALS:
    void loadStateChanged();
    void activeStateChanged();
    void jobIdChanged();
    void unitFileStateChanged();

protected:
    UnitPrivate *d_ptr;

private:
    void init();
};
}

#endif