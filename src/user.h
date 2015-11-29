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

#ifndef SD_USER_H
#define SD_USER_H

#include <QObject>
#include <QSharedPointer>

#include "QtSystemd-export.h"

namespace Systemd
{
namespace Logind
{
class UserPrivate;

class SDQT_EXPORT User : public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(User)

public:
    typedef QSharedPointer<User> Ptr;

    explicit User(const QString &path, QObject *parent = 0);
    explicit User(UserPrivate &user, QObject *parent = 0);
    virtual ~User();

    QString display() const;
    uint gid() const;
    bool idleHint() const;
    qulonglong idleSinceHint() const;
    qulonglong idleSinceHintMonotonic() const;
    bool linger() const;
    QString name() const;
    QString runtimePath() const;
    QString service() const;
    QStringList sessions() const;
    QString slice() const;
    QString state() const;
    qulonglong timestamp() const;
    qulonglong timestampMonotonic() const;
    uint uid() const;

protected:
    UserPrivate *d_ptr;
};
}
}

#endif
