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

typedef QList<uint> UIntList;
Q_DECLARE_METATYPE(UIntList)

typedef struct
{
    QString name;
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

QDBusArgument &operator<<(QDBusArgument &argument, const ManagerDBusUnit &units);
const QDBusArgument &operator>>(const QDBusArgument &argument, ManagerDBusUnit &units);

typedef struct
{
    uint id;
    QString unitName;
    QString type;
    QString state;
    QDBusObjectPath jobPath;
    QDBusObjectPath unitPath;
} ManagerDBusJob;
Q_DECLARE_METATYPE(ManagerDBusJob)

QDBusArgument &operator<<(QDBusArgument &argument, const ManagerDBusJob &jobs);
const QDBusArgument &operator>>(const QDBusArgument &argument, ManagerDBusJob &jobs);


typedef struct
{
    QString path;
    QString state;
} DBusUnitFileList;
Q_DECLARE_METATYPE(DBusUnitFileList)

QDBusArgument &operator<<(QDBusArgument &argument, const DBusUnitFileList &changes);
const QDBusArgument &operator>>(const QDBusArgument &argument, DBusUnitFileList &changes);

typedef struct
{
    QString type;
    QString path;
    QString source;
} DBusUnitFileChange;
Q_DECLARE_METATYPE(DBusUnitFileChange)

QDBusArgument &operator<<(QDBusArgument &argument, const DBusUnitFileChange &changes);
const QDBusArgument &operator>>(const QDBusArgument &argument, DBusUnitFileChange &changes);

typedef struct
{
    QString unitName;
    QDBusObjectPath objectPath;
} JobDBusUnit;
Q_DECLARE_METATYPE(JobDBusUnit)

QDBusArgument &operator<<(QDBusArgument &argument, const JobDBusUnit &unit);
const QDBusArgument &operator>>(const QDBusArgument &argument, JobDBusUnit &unit);

typedef struct
{
    QString binary;
    QList<QString> args;
    bool failure;
    qulonglong realtime;
    qulonglong monotonic;
    uint pid;
    int exitStatus;
    int lastStatus;
} MountDBusExecStructure;
Q_DECLARE_METATYPE(MountDBusExecStructure)

QDBusArgument &operator<<(QDBusArgument &argument, const MountDBusExecStructure &structure);
const QDBusArgument &operator>>(const QDBusArgument &argument, MountDBusExecStructure &structure);

typedef struct
{
    QString name;
    QString field;
    QString value;
} MountDBusControlGroupAttributes;
Q_DECLARE_METATYPE(MountDBusControlGroupAttributes)

QDBusArgument &operator<<(QDBusArgument &argument, const MountDBusControlGroupAttributes &attributes);
const QDBusArgument &operator>>(const QDBusArgument &argument, MountDBusControlGroupAttributes &attributes);

typedef struct
{
    QString condition;
    QString watch;
} PathDBusPaths;
Q_DECLARE_METATYPE(PathDBusPaths)

QDBusArgument &operator<<(QDBusArgument &argument, const PathDBusPaths &paths);
const QDBusArgument &operator>>(const QDBusArgument &argument, PathDBusPaths &paths);

#endif // GENERIC_TYPES_H