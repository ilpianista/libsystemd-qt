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

#ifndef SD_USER_P_H
#define SD_USER_P_H

#include "userinterface.h"

#include "user.h"

namespace Systemd
{
namespace Logind
{
class UserPrivate
{

public:
    explicit UserPrivate(const QString &path);
    virtual ~UserPrivate();

    OrgFreedesktopLogin1UserInterface userIface;

    uint gid;
    bool idleHint;
    qulonglong idleSinceHint;
    qulonglong idleSinceHintMonotonic;
    bool linger;
    QString name;
    QString runtimePath;
    QString service;
    QString slice;
    QString state;
    qulonglong timestamp;
    qulonglong timestampMonotonic;
    uint uid;
};
}
}

#endif
