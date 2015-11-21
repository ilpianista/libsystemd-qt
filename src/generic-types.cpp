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

#include "generic-types.h"
#include <QDBusMetaType>

static int dbus_types[] = {
    qDBusRegisterMetaType<DBusUnit>(),
    qDBusRegisterMetaType<DBusJob>(),
    qDBusRegisterMetaType<UnitDBusProperty>(),
    qDBusRegisterMetaType<UnitDBusPropertyList>(),
    qDBusRegisterMetaType<ManagerDBusAux>(),
    qDBusRegisterMetaType<ManagerDBusAuxList>(),
    qDBusRegisterMetaType<UnitDBusExecCommand>(),
    qDBusRegisterMetaType<UnitDBusExecCommandList>(),
    qDBusRegisterMetaType<ManagerDBusUnitFileChange>(),
    qDBusRegisterMetaType<ManagerDBusUnitFileChangeList>(),
    qDBusRegisterMetaType<ManagerDBusJob>(),
    qDBusRegisterMetaType<ManagerDBusJobList>(),
    qDBusRegisterMetaType<ManagerDBusUnit>(),
    qDBusRegisterMetaType<ManagerDBusUnitList>(),
    qDBusRegisterMetaType<ManagerDBusUnitFile>(),
    qDBusRegisterMetaType<ManagerDBusUnitFileList>(),
    qDBusRegisterMetaType<DBusSession>(),
    qDBusRegisterMetaType<DBusSessionList>(),
    qDBusRegisterMetaType<DBusSeat>(),
    qDBusRegisterMetaType<DBusSeatList>(),

};

QDBusArgument& operator<<(QDBusArgument &argument, const DBusJob &job)
{
    argument.beginStructure();
    argument << job.id << job.path;
    argument.endStructure();
    return argument;
}

const QDBusArgument& operator>>(const QDBusArgument &argument, DBusJob &job)
{
    argument.beginStructure();
    argument >> job.id >> job.path;
    argument.endStructure();
    return argument;
}

QDBusArgument& operator<<(QDBusArgument &argument, const DBusSeat &seat)
{
    argument.beginStructure();
    argument << seat.id << seat.path;
    argument.endStructure();
    return argument;
}

const QDBusArgument& operator>>(const QDBusArgument &argument, DBusSeat &seat)
{
    argument.beginStructure();
    argument >> seat.id >> seat.path;
    argument.endStructure();
    return argument;
}

QDBusArgument& operator<<(QDBusArgument &argument, const DBusSession &session)
{
    argument.beginStructure();
    argument << session.id << session.path;
    argument.endStructure();
    return argument;
}

const QDBusArgument& operator>>(const QDBusArgument &argument, DBusSession &session)
{
    argument.beginStructure();
    argument >> session.id >> session.path;
    argument.endStructure();
    return argument;
}

QDBusArgument& operator<<(QDBusArgument &argument, const DBusUnit &unit)
{
    argument.beginStructure();
    argument << unit.id << unit.path;
    argument.endStructure();
    return argument;
}

const QDBusArgument& operator>>(const QDBusArgument &argument, DBusUnit &unit)
{
    argument.beginStructure();
    argument >> unit.id >> unit.path;
    argument.endStructure();
    return argument;
}

QDBusArgument& operator<<(QDBusArgument &argument, const DBusUser &user)
{
    argument.beginStructure();
    argument << user.id << user.path;
    argument.endStructure();
    return argument;
}

const QDBusArgument& operator>>(const QDBusArgument &argument, DBusUser &user)
{
    argument.beginStructure();
    argument >> user.id >> user.path;
    argument.endStructure();
    return argument;
}

QDBusArgument& operator<<(QDBusArgument &argument, const CGroupDBusBlockIODeviceWeight &cGroupBlockIODeviceWeight)
{
    argument.beginStructure();
    argument << cGroupBlockIODeviceWeight.path << cGroupBlockIODeviceWeight.weight;
    argument.endStructure();
    return argument;
}

const QDBusArgument& operator>>(const QDBusArgument &argument, CGroupDBusBlockIODeviceWeight &cGroupBlockIODeviceWeight)
{
    argument.beginStructure();
    argument >> cGroupBlockIODeviceWeight.path >> cGroupBlockIODeviceWeight.weight;
    argument.endStructure();
    return argument;
}

QDBusArgument& operator<<(QDBusArgument &argument, const CGroupDBusDeviceAllow &cGroupDeviceAllow)
{
    argument.beginStructure();
    argument << cGroupDeviceAllow.path << cGroupDeviceAllow.rwm;
    argument.endStructure();
    return argument;
}

const QDBusArgument& operator>>(const QDBusArgument &argument, CGroupDBusDeviceAllow &cGroupDeviceAllow)
{
    argument.beginStructure();
    argument >> cGroupDeviceAllow.path >> cGroupDeviceAllow.rwm;
    argument.endStructure();
    return argument;
}

QDBusArgument& operator<<(QDBusArgument &argument, const ExecuteDBusAddressFamilies &addressFamilies)
{
    argument.beginStructure();
    argument << addressFamilies.whitelist << addressFamilies.names;
    argument.endStructure();
    return argument;
}

const QDBusArgument& operator>>(const QDBusArgument &argument, ExecuteDBusAddressFamilies &addressFamilies)
{
    argument.beginStructure();
    argument >> addressFamilies.whitelist >> addressFamilies.names;
    argument.endStructure();
    return argument;
}

QDBusArgument& operator<<(QDBusArgument &argument, const ExecuteDBusAppArmorProfile &appArmorProfile)
{
    argument.beginStructure();
    argument << appArmorProfile.ignore << appArmorProfile.profile;
    argument.endStructure();
    return argument;
}

const QDBusArgument& operator>>(const QDBusArgument &argument, ExecuteDBusAppArmorProfile &appArmorProfile)
{
    argument.beginStructure();
    argument >> appArmorProfile.ignore >> appArmorProfile.profile;
    argument.endStructure();
    return argument;
}

QDBusArgument& operator<<(QDBusArgument &argument, const ExecuteDBusSmackProcessLabel &smackProcessLabel)
{
    argument.beginStructure();
    argument << smackProcessLabel.ignore << smackProcessLabel.profile;
    argument.endStructure();
    return argument;
}

const QDBusArgument& operator>>(const QDBusArgument &argument, ExecuteDBusSmackProcessLabel &smackProcessLabel)
{
    argument.beginStructure();
    argument >> smackProcessLabel.ignore >> smackProcessLabel.profile;
    argument.endStructure();
    return argument;
}

QDBusArgument& operator<<(QDBusArgument &argument, const ExecuteDBusEnvironmentFile &environmentFile)
{
    argument.beginStructure();
    argument << environmentFile.fileName << environmentFile.dash;
    argument.endStructure();
    return argument;
}

const QDBusArgument& operator>>(const QDBusArgument &argument, ExecuteDBusEnvironmentFile &environmentFile)
{
    argument.beginStructure();
    argument >> environmentFile.fileName >> environmentFile.dash;
    argument.endStructure();
    return argument;
}

QDBusArgument& operator<<(QDBusArgument &argument, const ExecuteDBusExecCommand &execCommand)
{
    argument.beginStructure();
    argument << execCommand.path << execCommand.argv << execCommand.ignore;
    argument << execCommand.startTimestamp << execCommand.exitTimestamp << execCommand.pid;
    argument << execCommand.exitCode << execCommand.exitStatus;
    argument.endStructure();
    return argument;
}

const QDBusArgument& operator>>(const QDBusArgument &argument, ExecuteDBusExecCommand &execCommand)
{
    argument.beginStructure();
    argument >> execCommand.path >> execCommand.argv >> execCommand.ignore;
    argument >> execCommand.startTimestamp >> execCommand.exitTimestamp >> execCommand.pid;
    argument >> execCommand.exitCode >> execCommand.exitStatus;
    argument.endStructure();
    return argument;
}

QDBusArgument& operator<<(QDBusArgument &argument, const ExecuteDBusSELinuxContext &seLinuxContext)
{
    argument.beginStructure();
    argument << seLinuxContext.ignore << seLinuxContext.context;
    argument.endStructure();
    return argument;
}

const QDBusArgument& operator>>(const QDBusArgument &argument, ExecuteDBusSELinuxContext &seLinuxContext)
{
    argument.beginStructure();
    argument >> seLinuxContext.ignore >> seLinuxContext.context;
    argument.endStructure();
    return argument;
}

QDBusArgument& operator<<(QDBusArgument &argument, const ExecuteDBusSystemCall &systemCall)
{
    argument.beginStructure();
    argument << systemCall.whitelist << systemCall.names;
    argument.endStructure();
    return argument;
}

const QDBusArgument& operator>>(const QDBusArgument &argument, ExecuteDBusSystemCall &systemCall)
{
    argument.beginStructure();
    argument >> systemCall.whitelist >> systemCall.names;
    argument.endStructure();
    return argument;
}

QDBusArgument& operator<<(QDBusArgument &argument, const LoginDBusInhibitor &inhibitor)
{
    argument.beginStructure();
    argument << inhibitor.what << inhibitor.who << inhibitor.why << inhibitor.mode;
    argument << inhibitor.uid << inhibitor.pid;
    argument.endStructure();
    return argument;
}

const QDBusArgument& operator>>(const QDBusArgument &argument, LoginDBusInhibitor &inhibitor)
{
    argument.beginStructure();
    argument >> inhibitor.what >> inhibitor.who >> inhibitor.why >> inhibitor.mode;
    argument >> inhibitor.uid >> inhibitor.pid;
    argument.endStructure();
    return argument;
}

QDBusArgument& operator<<(QDBusArgument &argument, const LoginDBusScheduledShutdown &scheduledShutdown)
{
    argument.beginStructure();
    argument << scheduledShutdown.type << scheduledShutdown.timeout;
    argument.endStructure();
    return argument;
}

const QDBusArgument& operator>>(const QDBusArgument &argument, LoginDBusScheduledShutdown &scheduledShutdown)
{
    argument.beginStructure();
    argument >> scheduledShutdown.type >> scheduledShutdown.timeout;
    argument.endStructure();
    return argument;
}

QDBusArgument& operator<<(QDBusArgument &argument, const LoginDBusScopeProperty &scopeProperty)
{
    argument.beginStructure();
    argument << scopeProperty.name << scopeProperty.value.toString();
    argument.endStructure();
    return argument;
}

const QDBusArgument& operator>>(const QDBusArgument &argument, LoginDBusScopeProperty &scopeProperty)
{
    argument.beginStructure();
    argument >> scopeProperty.name >> scopeProperty.value;
    argument.endStructure();
    return argument;
}

QDBusArgument& operator<<(QDBusArgument &argument, const LoginDBusSession &session)
{
    argument.beginStructure();
    argument << session.id << session.uid << session.name << session.seatId;
    argument << session.path;
    argument.endStructure();
    return argument;
}

const QDBusArgument& operator>>(const QDBusArgument &argument, LoginDBusSession &session)
{
    argument.beginStructure();
    argument >> session.id >> session.uid >> session.name >> session.seatId;
    argument >> session.path;
    argument.endStructure();
    return argument;
}

QDBusArgument& operator<<(QDBusArgument &argument, const LoginDBusUser &user)
{
    argument.beginStructure();
    argument << user.uid << user.name << user.path;
    argument.endStructure();
    return argument;
}

const QDBusArgument& operator>>(const QDBusArgument &argument, LoginDBusUser &user)
{
    argument.beginStructure();
    argument >> user.uid >> user.name >> user.path;
    argument.endStructure();
    return argument;
}

QDBusArgument& operator<<(QDBusArgument &argument, const ManagerDBusJob &job)
{
    argument.beginStructure();
    argument << job.id << job.unitId << job.type << job.state << job.path;
    argument << job.unitPath;
    argument.endStructure();
    return argument;
}

const QDBusArgument& operator>>(const QDBusArgument &argument, ManagerDBusJob &job)
{
    argument.beginStructure();
    argument >> job.id >> job.unitId >> job.type >> job.state >> job.path;
    argument >> job.unitPath;
    argument.endStructure();
    return argument;
}

QDBusArgument& operator<<(QDBusArgument &argument, const ManagerDBusUnit &unit)
{
    argument.beginStructure();
    argument << unit.id << unit.description << unit.loadState << unit.activeState;
    argument << unit.subState << unit.following << unit.path << unit.jobId;
    argument << unit.jobType << unit.jobPath;
    argument.endStructure();
    return argument;
}

const QDBusArgument& operator>>(const QDBusArgument &argument, ManagerDBusUnit &unit)
{
    argument.beginStructure();
    argument >> unit.id >> unit.description >> unit.loadState >> unit.activeState;
    argument >> unit.subState >> unit.following >> unit.path >> unit.jobId;
    argument >> unit.jobType >> unit.jobPath;
    argument.endStructure();
    return argument;
}

QDBusArgument& operator<<(QDBusArgument &argument, const ManagerDBusUnitFile &unitFile)
{
    argument.beginStructure();
    argument << unitFile.path << unitFile.state;
    argument.endStructure();
    return argument;
}

const QDBusArgument& operator>>(const QDBusArgument &argument, ManagerDBusUnitFile &unitFile)
{
    argument.beginStructure();
    argument >> unitFile.path >> unitFile.state;
    argument.endStructure();
    return argument;
}

QDBusArgument& operator<<(QDBusArgument &argument, const ManagerDBusUnitFileChange &unitFileChange)
{
    argument.beginStructure();
    argument << unitFileChange.type << unitFileChange.path << unitFileChange.source;
    argument.endStructure();
    return argument;
}

const QDBusArgument& operator>>(const QDBusArgument &argument, ManagerDBusUnitFileChange &unitFileChange)
{
    argument.beginStructure();
    argument >> unitFileChange.type >> unitFileChange.path >> unitFileChange.source;
    argument.endStructure();
    return argument;
}

QDBusArgument& operator<<(QDBusArgument &argument, const PathDBusPath &path)
{
    argument.beginStructure();
    argument << path.type << path.path;
    argument.endStructure();
    return argument;
}

const QDBusArgument& operator>>(const QDBusArgument &argument, PathDBusPath &path)
{
    argument.beginStructure();
    argument >> path.type >> path.path;
    argument.endStructure();
    return argument;
}

QDBusArgument& operator<<(QDBusArgument &argument, const SocketDBusSocket &socket)
{
    argument.beginStructure();
    argument << socket.type << socket.address;
    argument.endStructure();
    return argument;
}

const QDBusArgument& operator>>(const QDBusArgument &argument, SocketDBusSocket &socket)
{
    argument.beginStructure();
    argument >> socket.type >> socket.address;
    argument.endStructure();
    return argument;
}

QDBusArgument& operator<<(QDBusArgument &argument, const TimerDBusCalendarTimer &calendarTimer)
{
    argument.beginStructure();
    argument << calendarTimer.timerBase << calendarTimer.calendarSpec << calendarTimer.nextElapse;
    argument.endStructure();
    return argument;
}

const QDBusArgument& operator>>(const QDBusArgument &argument, TimerDBusCalendarTimer &calendarTimer)
{
    argument.beginStructure();
    argument >> calendarTimer.timerBase >> calendarTimer.calendarSpec >> calendarTimer.nextElapse;
    argument.endStructure();
    return argument;
}

QDBusArgument& operator<<(QDBusArgument &argument, const TimerDBusMonotonicTimer &monotonicTimer)
{
    argument.beginStructure();
    argument << monotonicTimer.timerBase << monotonicTimer.value << monotonicTimer.nextElapse;
    argument.endStructure();
    return argument;
}

const QDBusArgument& operator>>(const QDBusArgument &argument, TimerDBusMonotonicTimer &monotonicTimer)
{
    argument.beginStructure();
    argument >> monotonicTimer.timerBase >> monotonicTimer.value >> monotonicTimer.nextElapse;
    argument.endStructure();
    return argument;
}

QDBusArgument& operator<<(QDBusArgument &argument, const UnitDBusCondition &condition)
{
    argument.beginStructure();
    argument << condition.name << condition.trigger << condition.negate << condition.param;
    argument << condition.state;
    argument.endStructure();
    return argument;
}

const QDBusArgument& operator>>(const QDBusArgument &argument, UnitDBusCondition &condition)
{
    argument.beginStructure();
    argument >> condition.name >> condition.trigger >> condition.negate >> condition.param;
    argument >> condition.state;
    argument.endStructure();
    return argument;
}

QDBusArgument& operator<<(QDBusArgument &argument, const UnitDBusAssert &assert)
{
    argument.beginStructure();
    argument << assert.name << assert.trigger << assert.negate << assert.param;
    argument << assert.state;
    argument.endStructure();
    return argument;
}

const QDBusArgument& operator>>(const QDBusArgument &argument, UnitDBusAssert &assert)
{
    argument.beginStructure();
    argument >> assert.name >> assert.trigger >> assert.negate >> assert.param;
    argument >> assert.state;
    argument.endStructure();
    return argument;
}

QDBusArgument& operator<<(QDBusArgument &argument, const UnitDBusLoadError &loadError)
{
    argument.beginStructure();
    argument << loadError.name << loadError.message;
    argument.endStructure();
    return argument;
}

const QDBusArgument& operator>>(const QDBusArgument &argument, UnitDBusLoadError &loadError)
{
    argument.beginStructure();
    argument >> loadError.name >> loadError.message;
    argument.endStructure();
    return argument;
}

QDBusArgument& operator<<(QDBusArgument &argument, const UnitDBusProperty &property)
{
    argument.beginStructure();
    argument << property.name << QDBusVariant(property.value);
    argument.endStructure();
    return argument;
}

const QDBusArgument& operator>>(const QDBusArgument &argument, UnitDBusProperty &property)
{
    QDBusVariant value;
    argument.beginStructure();
    argument >> property.name >> value;
    argument.endStructure();

    property.value = value.variant();
    return argument;
}

QDBusArgument& operator<<(QDBusArgument &argument, const ManagerDBusAux&aux)
{
    argument.beginStructure();
    argument << aux.name << aux.properties;
    argument.endStructure();
    return argument;
}

const QDBusArgument& operator>>(const QDBusArgument &argument, ManagerDBusAux &aux)
{
    argument.beginStructure();
    argument >> aux.name >> aux.properties;
    argument.endStructure();
    return argument;
}


QDBusArgument &operator<<(QDBusArgument &argument, const UnitDBusExecCommand &execCommand)
{
    argument.beginStructure();
    argument << execCommand.path << execCommand.argv << execCommand.ignore;
    argument.endStructure();
    return argument;
}


const QDBusArgument &operator>>(const QDBusArgument &argument, UnitDBusExecCommand &execCommand)
{
    argument.beginStructure();
    argument >> execCommand.path >> execCommand.argv >> execCommand.ignore;
    argument.endStructure();
    return argument;
}
