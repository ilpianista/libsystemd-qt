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

#ifndef SD_SESSION_P_H
#define SD_SESSION_P_H

#include "sessioninterface.h"

#include "session.h"

namespace Systemd
{
namespace Logind
{
class SessionPrivate
{

public:
    explicit SessionPrivate(const QString &path);
    virtual ~SessionPrivate();

    OrgFreedesktopLogin1SessionInterface sessionIface;

    bool active;
    uint audit;
    QString desktop;
    QString display;
    QString id;
    bool idleHint;
    qulonglong idleSinceHint;
    qulonglong idleSinceHintMonotonic;
    uint leader;
    QString name;
    bool remote;
    QString remoteHost;
    QString remoteUser;
    QString seat;
    QString scope;
    QString service;
    QString state;
    QString tty;
    qulonglong timestamp;
    qulonglong timestampMonotonic;
    QString type;
    uint user;
    uint vtNr;
    QString _class;
};
}
}

#endif
