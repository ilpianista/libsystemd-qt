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

#ifndef SD_SESSION_H
#define SD_SESSION_H

#include <QObject>
#include <QSharedPointer>

#include "QtSystemd-export.h"

namespace Systemd
{
namespace Logind
{
class SessionPrivate;

class SDQT_EXPORT Session : public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(Session)

public:
    typedef QSharedPointer<Session> Ptr;

    explicit Session(const QString &path, QObject *parent = 0);
    explicit Session(SessionPrivate &session, QObject *parent = 0);
    virtual ~Session();

    bool active() const;
    uint audit() const;
    QString desktop() const;
    QString display() const;
    QString id() const;
    bool idleHint() const;
    qulonglong idleSinceHint() const;
    qulonglong idleSinceHintMonotonic() const;
    uint leader() const;
    QString name() const;
    bool remote() const;
    QString remoteHost() const;
    QString remoteUser() const;
    QString seat() const;
    QString scope() const;
    QString service() const;
    QString state() const;
    QString tty() const;
    qulonglong timestamp() const;
    qulonglong timestampMonotonic() const;
    QString type() const;
    uint user() const;
    uint vtNr() const;
    QString _class() const;

protected:
    SessionPrivate *d_ptr;
};
}
}

#endif
