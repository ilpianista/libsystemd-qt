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

typedef struct
{
    uint id;
    QDBusObjectPath path;
} DBusUIntObject;
Q_DECLARE_METATYPE(DBusUIntObject)

QDBusArgument &operator<<(QDBusArgument &argument, const DBusUIntObject &object);
const QDBusArgument &operator>>(const QDBusArgument &argument, DBusUIntObject &object);

typedef struct
{
    QString id;
    QDBusObjectPath path;
} DBusStringObject;
Q_DECLARE_METATYPE(DBusStringObject)
typedef QList<DBusStringObject> DBusStringObjectList;
Q_DECLARE_METATYPE(DBusStringObjectList)

QDBusArgument &operator<<(QDBusArgument &argument, const DBusStringObject &object);
const QDBusArgument &operator>>(const QDBusArgument &argument, DBusStringObject &object);

typedef struct
{
    QString path;
    qulonglong weight;
} CGroupDBusBlockIODeviceWeight;
Q_DECLARE_METATYPE(CGroupDBusBlockIODeviceWeight)
typedef QList<CGroupDBusBlockIODeviceWeight> CGroupDBusBlockIODeviceWeightList;
Q_DECLARE_METATYPE(CGroupDBusBlockIODeviceWeightList)

QDBusArgument &operator<<(QDBusArgument &argument, const CGroupDBusBlockIODeviceWeight &cGroupBlockIODeviceWeight);
const QDBusArgument &operator>>(const QDBusArgument &argument, CGroupDBusBlockIODeviceWeight &cGroupBlockIODeviceWeight);

typedef struct
{
    QString path;
    QString rwm;
} CGroupDBusDeviceAllow;
Q_DECLARE_METATYPE(CGroupDBusDeviceAllow)
typedef QList<CGroupDBusDeviceAllow> CGroupDBusDeviceAllowList;
Q_DECLARE_METATYPE(CGroupDBusDeviceAllowList)

QDBusArgument &operator<<(QDBusArgument &argument, const CGroupDBusDeviceAllow &cGroupDeviceAllow);
const QDBusArgument &operator>>(const QDBusArgument &argument, CGroupDBusDeviceAllow &cGroupDeviceAllow);

typedef struct
{
    QString fileName;
    bool dash;
} ExecuteDBusEnvironmentFile;
Q_DECLARE_METATYPE(ExecuteDBusEnvironmentFile)
typedef QList<ExecuteDBusEnvironmentFile> ExecuteDBusEnvironmentFileList;
Q_DECLARE_METATYPE(ExecuteDBusEnvironmentFileList)

QDBusArgument &operator<<(QDBusArgument &argument, const ExecuteDBusEnvironmentFile &environmentFile);
const QDBusArgument &operator>>(const QDBusArgument &argument, ExecuteDBusEnvironmentFile &environmentFile);

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
} ExecuteDBusExecCommand;
Q_DECLARE_METATYPE(ExecuteDBusExecCommand)
typedef QList<ExecuteDBusExecCommand> ExecuteDBusExecCommandList;
Q_DECLARE_METATYPE(ExecuteDBusExecCommandList)

QDBusArgument &operator<<(QDBusArgument &argument, const ExecuteDBusExecCommand &execCommand);
const QDBusArgument &operator>>(const QDBusArgument &argument, ExecuteDBusExecCommand &execCommand);

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

QDBusArgument &operator<<(QDBusArgument &argument, const LoginDBusInhibitor &inhibitor);
const QDBusArgument &operator>>(const QDBusArgument &argument, LoginDBusInhibitor &inhibitor);

typedef struct
{
    QString name;
    QVariant value;
} LoginDBusScopeProperty;
Q_DECLARE_METATYPE(LoginDBusScopeProperty)
typedef QList<LoginDBusScopeProperty> LoginDBusScopePropertyList;
Q_DECLARE_METATYPE(LoginDBusScopePropertyList)

QDBusArgument &operator<<(QDBusArgument &argument, const LoginDBusScopeProperty &scopeProperty);
const QDBusArgument &operator>>(const QDBusArgument &argument, LoginDBusScopeProperty &scopeProperty);

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
    QString path;
    QString state;
} ManagerDBusUnitFile;
Q_DECLARE_METATYPE(ManagerDBusUnitFile)
typedef QList<ManagerDBusUnitFile> ManagerDBusUnitFileList;
Q_DECLARE_METATYPE(ManagerDBusUnitFileList)

QDBusArgument &operator<<(QDBusArgument &argument, const ManagerDBusUnitFile &unitFile);
const QDBusArgument &operator>>(const QDBusArgument &argument, ManagerDBusUnitFile &unitFile);

typedef struct
{
    QString type;
    QString path;
    QString source;
} ManagerDBusUnitFileChange;
Q_DECLARE_METATYPE(ManagerDBusUnitFileChange)
typedef QList<ManagerDBusUnitFileChange> ManagerDBusUnitFileChangeList;
Q_DECLARE_METATYPE(ManagerDBusUnitFileChangeList)

QDBusArgument &operator<<(QDBusArgument &argument, const ManagerDBusUnitFileChange &unitFileChange);
const QDBusArgument &operator>>(const QDBusArgument &argument, ManagerDBusUnitFileChange &unitFileChange);

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
    QString name;
    QString message;
} UnitDBusLoadError;
Q_DECLARE_METATYPE(UnitDBusLoadError)

QDBusArgument &operator<<(QDBusArgument &argument, const UnitDBusLoadError &loadError);
const QDBusArgument &operator>>(const QDBusArgument &argument, UnitDBusLoadError &loadError);

typedef struct
{
    QString name;
    QVariant value;
} UnitDBusProperty;
Q_DECLARE_METATYPE(UnitDBusProperty)
typedef QList<UnitDBusProperty> UnitDBusPropertyList;
Q_DECLARE_METATYPE(UnitDBusPropertyList);

QDBusArgument &operator<<(QDBusArgument &argument, const UnitDBusProperty &property);
const QDBusArgument &operator>>(const QDBusArgument &argument, UnitDBusProperty &property);

typedef struct
{
    QString name;
    UnitDBusPropertyList properties;
} ManagerDBusAux;
Q_DECLARE_METATYPE(ManagerDBusAux)
typedef QList<ManagerDBusAux> ManagerDBusAuxList;
Q_DECLARE_METATYPE(ManagerDBusAuxList)

QDBusArgument &operator<<(QDBusArgument &argument, const ManagerDBusAux &aux);
const QDBusArgument &operator>>(const QDBusArgument &argument, ManagerDBusAux &aux);

#endif // GENERIC_TYPES_H