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

#ifndef GENERIC_TYPES_H
#define GENERIC_TYPES_H

#include <QDBusArgument>

Q_DECLARE_METATYPE(QVariantMap)

typedef QList<uint> UIntList;
Q_DECLARE_METATYPE(UIntList)

typedef struct
{
    QString id;
    QString description;
    QString loadState;
    QString activeState;
    QString subState;
    QString following;
    QDBusObjectPath path;
    uint jobId;
    QString jobType;
    QDBusObjectPath jobPath;
} ManagerDBusUnit;
Q_DECLARE_METATYPE(ManagerDBusUnit)

QDBusArgument &operator<<(QDBusArgument &argument, const ManagerDBusUnit &unit);
const QDBusArgument &operator>>(const QDBusArgument &argument, ManagerDBusUnit &unit);

typedef struct
{
    uint id;
    QString unitId;
    QString type;
    QString state;
    QDBusObjectPath path;
    QDBusObjectPath unitPath;
} ManagerDBusJob;
Q_DECLARE_METATYPE(ManagerDBusJob)

QDBusArgument &operator<<(QDBusArgument &argument, const ManagerDBusJob &job);
const QDBusArgument &operator>>(const QDBusArgument &argument, ManagerDBusJob &job);


typedef struct
{
    QString path;
    QString state;
} DBusUnitFileList;
Q_DECLARE_METATYPE(DBusUnitFileList)

QDBusArgument &operator<<(QDBusArgument &argument, const DBusUnitFileList &unitFileList);
const QDBusArgument &operator>>(const QDBusArgument &argument, DBusUnitFileList &unitFileList);

typedef struct
{
    QString type;
    QString path;
    QString source;
} DBusUnitFileChange;
Q_DECLARE_METATYPE(DBusUnitFileChange)

QDBusArgument &operator<<(QDBusArgument &argument, const DBusUnitFileChange &unitFileChange);
const QDBusArgument &operator>>(const QDBusArgument &argument, DBusUnitFileChange &unitFileChange);

typedef struct
{
    QString id;
    QDBusObjectPath unit;
} JobDBusUnit;
Q_DECLARE_METATYPE(JobDBusUnit)

QDBusArgument &operator<<(QDBusArgument &argument, const JobDBusUnit &unit);
const QDBusArgument &operator>>(const QDBusArgument &argument, JobDBusUnit &unit);

typedef struct
{
    QString path;
    QList<QString> argv;
    bool ignore;
    qulonglong startTimestamp;
    qulonglong exitTimestamp;
    uint pid;
    int exitCode;
    int exitStatus;
} MountDBusExecCommand;
Q_DECLARE_METATYPE(MountDBusExecCommand)

QDBusArgument &operator<<(QDBusArgument &argument, const MountDBusExecCommand &execCommand);
const QDBusArgument &operator>>(const QDBusArgument &argument, MountDBusExecCommand &execCommand);

typedef struct
{
    QString controller;
    QString name;
    QString value;
} MountDBusCGroupAttrs;
Q_DECLARE_METATYPE(MountDBusCGroupAttrs)

QDBusArgument &operator<<(QDBusArgument &argument, const MountDBusCGroupAttrs &cGroupAttrs);
const QDBusArgument &operator>>(const QDBusArgument &argument, MountDBusCGroupAttrs &cGroupAttrs);

typedef struct
{
    QString id;
    uint uid;
    QString name;
    QString seatId;
    QDBusObjectPath session;
} LoginDBusSession;
Q_DECLARE_METATYPE(LoginDBusSession)

QDBusArgument &operator<<(QDBusArgument &argument, const LoginDBusSession &session);
const QDBusArgument &operator>>(const QDBusArgument &argument, LoginDBusSession &session);

typedef struct
{
    uint uid;
    QString name;
    QDBusObjectPath user;
} LoginDBusUser;
Q_DECLARE_METATYPE(LoginDBusUser)

QDBusArgument &operator<<(QDBusArgument &argument, const LoginDBusUser &user);
const QDBusArgument &operator>>(const QDBusArgument &argument, LoginDBusUser &user);

typedef struct
{
    QString id;
    QDBusObjectPath seat;
} LoginDBusSeat;
Q_DECLARE_METATYPE(LoginDBusSeat)

QDBusArgument &operator<<(QDBusArgument &argument, const LoginDBusSeat &seat);
const QDBusArgument &operator>>(const QDBusArgument &argument, LoginDBusSeat &seat);

typedef struct
{
    QString what;
    QString who;
    QString why;
    QString mode;
    uint uid;
    uint pid;
} LoginDBusInhibitor;
Q_DECLARE_METATYPE(LoginDBusInhibitor)

QDBusArgument &operator<<(QDBusArgument &argument, const LoginDBusInhibitor &inhibitors);
const QDBusArgument &operator>>(const QDBusArgument &argument, LoginDBusInhibitor &inhibitors);

typedef struct
{
    QString type;
    QString path;
} PathDBusPath;
Q_DECLARE_METATYPE(PathDBusPath)

QDBusArgument &operator<<(QDBusArgument &argument, const PathDBusPath &path);
const QDBusArgument &operator>>(const QDBusArgument &argument, PathDBusPath &path);

#endif // GENERIC_TYPES_H