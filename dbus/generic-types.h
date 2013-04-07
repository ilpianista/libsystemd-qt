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
    QString controller;
    QString name;
    QString value;
} DBusCGroupAttrs;
Q_DECLARE_METATYPE(DBusCGroupAttrs)
typedef QList<DBusCGroupAttrs> DBusCGroupAttrsList;
Q_DECLARE_METATYPE(DBusCGroupAttrsList)

QDBusArgument &operator<<(QDBusArgument &argument, const DBusCGroupAttrs &cGroupAttrs);
const QDBusArgument &operator>>(const QDBusArgument &argument, DBusCGroupAttrs &cGroupAttrs);

typedef struct
{
    QString path;
    QList<QString> argv;
    bool ignore;
    qlonglong startTimestamp;
    qlonglong exitTimestamp;
    uint pid;
    int exitCode;
    int exitStatus;
} DBusExecCommand;
Q_DECLARE_METATYPE(DBusExecCommand)
typedef QList<DBusExecCommand> DBusExecCommandList;
Q_DECLARE_METATYPE(DBusExecCommandList)

QDBusArgument &operator<<(QDBusArgument &argument, const DBusExecCommand &execCommand);
const QDBusArgument &operator>>(const QDBusArgument &argument, DBusExecCommand &execCommand);

typedef struct
{
    QString type;
    QString path;
    QString source;
} DBusUnitFileChange;
Q_DECLARE_METATYPE(DBusUnitFileChange)
typedef QList<DBusUnitFileChange> DBusUnitFileChangeList;
Q_DECLARE_METATYPE(DBusUnitFileChangeList)

QDBusArgument &operator<<(QDBusArgument &argument, const DBusUnitFileChange &unitFileChange);
const QDBusArgument &operator>>(const QDBusArgument &argument, DBusUnitFileChange &unitFileChange);

typedef struct
{
    QString path;
    QString state;
} DBusUnitFileList;
Q_DECLARE_METATYPE(DBusUnitFileList)
typedef QList<DBusUnitFileList> DBusUnitFileListList;
Q_DECLARE_METATYPE(DBusUnitFileListList);

QDBusArgument &operator<<(QDBusArgument &argument, const DBusUnitFileList &unitFileList);
const QDBusArgument &operator>>(const QDBusArgument &argument, DBusUnitFileList &unitFileList);

typedef struct
{
    QString id;
    QDBusObjectPath path;
} JobDBusUnit;
Q_DECLARE_METATYPE(JobDBusUnit)

QDBusArgument &operator<<(QDBusArgument &argument, const JobDBusUnit &unit);
const QDBusArgument &operator>>(const QDBusArgument &argument, JobDBusUnit &unit);

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
typedef QList<LoginDBusInhibitor> LoginDBusInhibitorList;
Q_DECLARE_METATYPE(LoginDBusInhibitorList)

QDBusArgument &operator<<(QDBusArgument &argument, const LoginDBusInhibitor &inhibitors);
const QDBusArgument &operator>>(const QDBusArgument &argument, LoginDBusInhibitor &inhibitors);

typedef struct
{
    QString id;
    QDBusObjectPath path;
} LoginDBusSeat;
Q_DECLARE_METATYPE(LoginDBusSeat)
typedef QList<LoginDBusSeat> LoginDBusSeatList;
Q_DECLARE_METATYPE(LoginDBusSeatList)

QDBusArgument &operator<<(QDBusArgument &argument, const LoginDBusSeat &seat);
const QDBusArgument &operator>>(const QDBusArgument &argument, LoginDBusSeat &seat);

typedef struct
{
    QString id;
    uint uid;
    QString name;
    QString seatId;
    QDBusObjectPath path;
} LoginDBusSession;
Q_DECLARE_METATYPE(LoginDBusSession)
typedef QList<LoginDBusSession> LoginDBusSessionList;
Q_DECLARE_METATYPE(LoginDBusSessionList)

QDBusArgument &operator<<(QDBusArgument &argument, const LoginDBusSession &session);
const QDBusArgument &operator>>(const QDBusArgument &argument, LoginDBusSession &session);

typedef struct
{
    uint uid;
    QString name;
    QDBusObjectPath path;
} LoginDBusUser;
Q_DECLARE_METATYPE(LoginDBusUser)
typedef QList<LoginDBusUser> LoginDBusUserList;
Q_DECLARE_METATYPE(LoginDBusUserList)

QDBusArgument &operator<<(QDBusArgument &argument, const LoginDBusUser &user);
const QDBusArgument &operator>>(const QDBusArgument &argument, LoginDBusUser &user);

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
typedef QList<ManagerDBusJob> ManagerDBusJobList;
Q_DECLARE_METATYPE(ManagerDBusJobList)

QDBusArgument &operator<<(QDBusArgument &argument, const ManagerDBusJob &job);
const QDBusArgument &operator>>(const QDBusArgument &argument, ManagerDBusJob &job);

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
typedef QList<ManagerDBusUnit> ManagerDBusUnitList;
Q_DECLARE_METATYPE(ManagerDBusUnitList)

QDBusArgument &operator<<(QDBusArgument &argument, const ManagerDBusUnit &unit);
const QDBusArgument &operator>>(const QDBusArgument &argument, ManagerDBusUnit &unit);

typedef struct
{
    QString type;
    QString path;
} PathDBusPath;
Q_DECLARE_METATYPE(PathDBusPath)
typedef QList<PathDBusPath> PathDBusPathList;
Q_DECLARE_METATYPE(PathDBusPathList)

QDBusArgument &operator<<(QDBusArgument &argument, const PathDBusPath &path);
const QDBusArgument &operator>>(const QDBusArgument &argument, PathDBusPath &path);

typedef struct
{
    QString timerBase;
    QString calendarSpec;
    qlonglong nextElapse;
} TimerDBusCalendarTimer;
Q_DECLARE_METATYPE(TimerDBusCalendarTimer)
typedef QList<TimerDBusCalendarTimer> TimerDBusCalendarTimerList;
Q_DECLARE_METATYPE(TimerDBusCalendarTimerList)

QDBusArgument &operator<<(QDBusArgument &argument, const TimerDBusCalendarTimer &calendarTimer);
const QDBusArgument &operator>>(const QDBusArgument &argument, TimerDBusCalendarTimer &calendarTimer);

typedef struct
{
    QString timerBase;
    qlonglong value;
    qlonglong nextElapse;
} TimerDBusMonotonicTimer;
Q_DECLARE_METATYPE(TimerDBusMonotonicTimer)
typedef QList<TimerDBusMonotonicTimer> TimerDBusMonotonicTimerList;
Q_DECLARE_METATYPE(TimerDBusMonotonicTimerList)

QDBusArgument &operator<<(QDBusArgument &argument, const TimerDBusMonotonicTimer &monotonicTimer);
const QDBusArgument &operator>>(const QDBusArgument &argument, TimerDBusMonotonicTimer &monotonicTimer);

typedef struct
{
    QString id;
    QDBusObjectPath path;
} UnitDBusJob;
Q_DECLARE_METATYPE(UnitDBusJob)

QDBusArgument &operator<<(QDBusArgument &argument, const UnitDBusJob &job);
const QDBusArgument &operator>>(const QDBusArgument &argument, UnitDBusJob &job);

typedef struct
{
    QString name;
    QString message;
} UnitDBusLoadError;
Q_DECLARE_METATYPE(UnitDBusLoadError)

QDBusArgument &operator<<(QDBusArgument &argument, const UnitDBusLoadError &loadError);
const QDBusArgument &operator>>(const QDBusArgument &argument, UnitDBusLoadError &loadError);

#endif // GENERIC_TYPES_H