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

#ifndef GENERIC_TYPES_H
#define GENERIC_TYPES_H

#include <QDBusArgument>

Q_DECLARE_METATYPE(QVariantMap)

typedef QList<quint32> UIntList;
Q_DECLARE_METATYPE(UIntList)

typedef struct
{
    QString path;
    quint64 weight;
} CGroupBlockIODeviceWeight;
Q_DECLARE_METATYPE(CGroupBlockIODeviceWeight)
typedef QList<CGroupBlockIODeviceWeight> CGroupBlockIODeviceWeightList;
Q_DECLARE_METATYPE(CGroupBlockIODeviceWeightList)

QDBusArgument &operator<<(QDBusArgument &argument, const CGroupBlockIODeviceWeight &cGroupBlockIODeviceWeight);
const QDBusArgument &operator>>(const QDBusArgument &argument, CGroupBlockIODeviceWeight &cGroupBlockIODeviceWeight);

typedef struct
{
    QString path;
    QString rwm;
} CGroupDeviceAllow;
Q_DECLARE_METATYPE(CGroupDeviceAllow)
typedef QList<CGroupDeviceAllow> CGroupDeviceAllowList;
Q_DECLARE_METATYPE(CGroupDeviceAllowList)

QDBusArgument &operator<<(QDBusArgument &argument, const CGroupDeviceAllow &cGroupDeviceAllow);
const QDBusArgument &operator>>(const QDBusArgument &argument, CGroupDeviceAllow &cGroupDeviceAllow);

typedef struct
{
    QString fileName;
    bool dash;
} DBusEnvironmentFile;
Q_DECLARE_METATYPE(DBusEnvironmentFile)
typedef QList<DBusEnvironmentFile> DBusEnvironmentFileList;
Q_DECLARE_METATYPE(DBusEnvironmentFileList)

QDBusArgument &operator<<(QDBusArgument &argument, const DBusEnvironmentFile &environmentFile);
const QDBusArgument &operator>>(const QDBusArgument &argument, DBusEnvironmentFile &environmentFile);

typedef struct
{
    QString path;
    QList<QString> argv;
    bool ignore;
    qlonglong startTimestamp;
    qlonglong exitTimestamp;
    quint32 pid;
    qint32 exitCode;
    qint32 exitStatus;
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
    QString name;
    QVariant value;
} DBusUnitFileProperty;
Q_DECLARE_METATYPE(DBusUnitFileProperty)
typedef QList<DBusUnitFileProperty> DBusUnitFilePropertyList;
Q_DECLARE_METATYPE(DBusUnitFilePropertyList);

QDBusArgument &operator<<(QDBusArgument &argument, const DBusUnitFileProperty &unitFileProperty);
const QDBusArgument &operator>>(const QDBusArgument &argument, DBusUnitFileProperty &unitFileProperty);

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
    quint32 uid;
    quint32 pid;
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
    quint32 uid;
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
    quint32 uid;
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
    QString name;
    DBusUnitFilePropertyList properties;
} ManagerDBusAux;
Q_DECLARE_METATYPE(ManagerDBusAux)
typedef QList<ManagerDBusAux> ManagerDBusAuxList;
Q_DECLARE_METATYPE(ManagerDBusAuxList)

QDBusArgument &operator<<(QDBusArgument &argument, const ManagerDBusAux &aux);
const QDBusArgument &operator>>(const QDBusArgument &argument, ManagerDBusAux &aux);

typedef struct
{
    quint32 id;
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
    quint32 jobId;
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
    QString id;
    QDBusObjectPath path;
} SeatDBusSession;
Q_DECLARE_METATYPE(SeatDBusSession)
typedef QList<SeatDBusSession> SeatDBusSessionList;
Q_DECLARE_METATYPE(SeatDBusSessionList)

QDBusArgument &operator<<(QDBusArgument &argument, const SeatDBusSession &session);
const QDBusArgument &operator>>(const QDBusArgument &argument, SeatDBusSession &session);

typedef struct
{
    QString id;
    QDBusObjectPath path;
} SessionDBusSeat;
Q_DECLARE_METATYPE(SessionDBusSeat)

QDBusArgument &operator<<(QDBusArgument &argument, const SessionDBusSeat &seat);
const QDBusArgument &operator>>(const QDBusArgument &argument, SessionDBusSeat &seat);

typedef struct
{
    QString id;
    QDBusObjectPath path;
} SessionDBusUser;
Q_DECLARE_METATYPE(SessionDBusUser)

QDBusArgument &operator<<(QDBusArgument &argument, const SessionDBusUser &user);
const QDBusArgument &operator>>(const QDBusArgument &argument, SessionDBusUser &user);

typedef struct
{
    QString type;
    QString address;
} SocketDBusSocket;
Q_DECLARE_METATYPE(SocketDBusSocket)
typedef QList<SocketDBusSocket> SocketDBusSocketList;
Q_DECLARE_METATYPE(SocketDBusSocketList)

QDBusArgument &operator<<(QDBusArgument &argument, const SocketDBusSocket &socket);
const QDBusArgument &operator>>(const QDBusArgument &argument, SocketDBusSocket &socket);

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
    QString name;
    bool trigger;
    bool negate;
    QString param;
    qint32 state;
} UnitDBusCondition;
Q_DECLARE_METATYPE(UnitDBusCondition)
typedef QList<UnitDBusCondition> UnitDBusConditionList;
Q_DECLARE_METATYPE(UnitDBusConditionList)

QDBusArgument &operator<<(QDBusArgument &argument, const UnitDBusCondition &condition);
const QDBusArgument &operator>>(const QDBusArgument &argument, UnitDBusCondition &condition);

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

typedef struct
{
    QString id;
    QDBusObjectPath path;
} UserDBusSession;
Q_DECLARE_METATYPE(UserDBusSession)
typedef QList<UserDBusSession> UserDBusSessionList;
Q_DECLARE_METATYPE(UserDBusSessionList)

QDBusArgument &operator<<(QDBusArgument &argument, const UserDBusSession &session);
const QDBusArgument &operator>>(const QDBusArgument &argument, UserDBusSession &session);

#endif // GENERIC_TYPES_H