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
#include <QDBusConnection>
#include "unit_p.h"
#include "sdmanager_p.h"

Systemd::UnitPrivate::UnitPrivate(const QString &path, const QDBusConnection &connection) :
    unitIface(Systemd::SystemdPrivate::SD_DBUS_SERVICE, path, connection)
{
    activeEnterTimestamp = unitIface.activeEnterTimestamp();
    activeEnterTimestampMonotonic = unitIface.activeEnterTimestampMonotonic();
    activeExitTimestamp = unitIface.activeExitTimestamp();
    activeExitTimestampMonotonic = unitIface.activeExitTimestampMonotonic();
    activeState = unitIface.activeState();
    after = unitIface.after();
    allowIsolate = unitIface.allowIsolate();
    assertResult = unitIface.assertResult();
    assertTimestamp = unitIface.assertTimestamp();
    assertTimestampMonotonic = unitIface.assertTimestampMonotonic();
    //asserts = unitIface.asserts();
    before = unitIface.before();
    bindsTo = unitIface.bindsTo();
    boundBy = unitIface.boundBy();
    canIsolate = unitIface.canIsolate();
    canReload = unitIface.canReload();
    canStart = unitIface.canStart();
    canStop = unitIface.canStop();
    conditionResult = unitIface.conditionResult();
    conditionTimestamp = unitIface.conditionTimestamp();
    conditionTimestampMonotonic = unitIface.conditionTimestampMonotonic();
    //conditions = unitIface.conditions();
    conflictedBy = unitIface.conflictedBy();
    conflicts = unitIface.conflicts();
    consistsOf = unitIface.consistsOf();
    defaultDependencies = unitIface.defaultDependencies();
    description = unitIface.description();
    documentation = unitIface.documentation();
    dropInPaths = unitIface.dropInPaths();
    following = unitIface.following();
    fragmentPath = unitIface.fragmentPath();
    id = unitIface.id();
    ignoreOnIsolate = unitIface.ignoreOnIsolate();
    inactiveEnterTimestamp = unitIface.inactiveEnterTimestamp();
    inactiveEnterTimestampMonotonic = unitIface.inactiveEnterTimestampMonotonic();
    inactiveExitTimestamp = unitIface.inactiveExitTimestamp();
    inactiveExitTimestampMonotonic = unitIface.inactiveExitTimestampMonotonic();
    job = unitIface.job().id;
    jobTimeoutAction = unitIface.jobTimeoutAction();
    jobTimeoutRebootArgument = unitIface.jobTimeoutRebootArgument();
    jobTimeoutUSec = unitIface.jobTimeoutUSec();
    joinsNamespaceOf = unitIface.joinsNamespaceOf();
    //loadError = unitIface.loadError();
    loadState = unitIface.loadState();
    names = unitIface.names();
    needDaemonReload = unitIface.needDaemonReload();
    netClass = unitIface.netClass();
    onFailure = unitIface.onFailure();
    onFailureJobMode = unitIface.onFailureJobMode();
    partOf = unitIface.partOf();
    propagatesReloadTo = unitIface.propagatesReloadTo();
    refuseManualStart = unitIface.refuseManualStart();
    refuseManualStop = unitIface.refuseManualStop();
    reloadPropagatedFrom = unitIface.reloadPropagatedFrom();
    requiredBy = unitIface.requiredBy();
    requires = unitIface.requires();
    requiresMountsFor = unitIface.requiresMountsFor();
    requisite = unitIface.requisite();
    requisiteOf = unitIface.requisiteOf();
    sourcePath = unitIface.sourcePath();
    stopWhenUnneeded = unitIface.stopWhenUnneeded();
    subState = unitIface.subState();
    transient = unitIface.transient();
    triggeredBy = unitIface.triggeredBy();
    triggers = unitIface.triggers();
    unitFileState = unitIface.unitFileState();
    wantedBy = unitIface.wantedBy();
    wants = unitIface.wants();
}

Systemd::UnitPrivate::~UnitPrivate()
{
}

Systemd::Unit::Unit(const QString &path, const QDBusConnection &connection, QObject *parent) :
                    QObject(parent), d_ptr(new UnitPrivate(path,connection))
{
}

Systemd::Unit::Unit(UnitPrivate &unit, QObject *parent) :
                    QObject(parent), d_ptr(&unit)
{
}

Systemd::Unit::~Unit()
{
    delete d_ptr;
}

qulonglong Systemd::Unit::activeEnterTimestamp() const
{
    Q_D(const Unit);
    return d->activeEnterTimestamp;
}

qulonglong Systemd::Unit::activeEnterTimestampMonotonic() const
{
    Q_D(const Unit);
    return d->activeEnterTimestampMonotonic;
}

qulonglong Systemd::Unit::activeExitTimestamp() const
{
    Q_D(const Unit);
    return d->activeExitTimestamp;
}

qulonglong Systemd::Unit::activeExitTimestampMonotonic() const
{
    Q_D(const Unit);
    return d->activeExitTimestampMonotonic;
}

QString Systemd::Unit::activeState() const
{
    Q_D(const Unit);
    return d->activeState;
}

QStringList Systemd::Unit::after() const
{
    Q_D(const Unit);
    return d->after;
}

bool Systemd::Unit::allowIsolate() const
{
    Q_D(const Unit);
    return d->allowIsolate;
}

bool Systemd::Unit::assertResult() const
{
    Q_D(const Unit);
    return d->assertResult;
}

qulonglong Systemd::Unit::assertTimestamp() const
{
    Q_D(const Unit);
    return d->assertTimestamp;
}

qulonglong Systemd::Unit::assertTimestampMonotonic() const
{
    Q_D(const Unit);
    return d->assertTimestampMonotonic;
}

QStringList Systemd::Unit::before() const
{
    Q_D(const Unit);
    return d->before;
}

QStringList Systemd::Unit::bindsTo() const
{
    Q_D(const Unit);
    return d->bindsTo;
}

QStringList Systemd::Unit::boundBy() const
{
    Q_D(const Unit);
    return d->boundBy;
}

bool Systemd::Unit::canIsolate() const
{
    Q_D(const Unit);
    return d->canIsolate;
}

bool Systemd::Unit::canReload() const
{
    Q_D(const Unit);
    return d->canReload;
}

bool Systemd::Unit::canStart() const
{
    Q_D(const Unit);
    return d->canStart;
}

bool Systemd::Unit::canStop() const
{
    Q_D(const Unit);
    return d->canStop;
}

bool Systemd::Unit::conditionResult() const
{
    Q_D(const Unit);
    return d->conditionResult;
}

qulonglong Systemd::Unit::conditionTimestamp() const
{
    Q_D(const Unit);
    return d->conditionTimestamp;
}

qulonglong Systemd::Unit::conditionTimestampMonotonic() const
{
    Q_D(const Unit);
    return d->conditionTimestampMonotonic;
}

QStringList Systemd::Unit::conflictedBy() const
{
    Q_D(const Unit);
    return d->conflictedBy;
}

QStringList Systemd::Unit::conflicts() const
{
    Q_D(const Unit);
    return d->conflicts;
}

QStringList Systemd::Unit::consistsOf() const
{
    Q_D(const Unit);
    return d->consistsOf;
}

bool Systemd::Unit::defaultDependencies() const
{
    Q_D(const Unit);
    return d->defaultDependencies;
}

QString Systemd::Unit::description() const
{
    Q_D(const Unit);
    return d->description;
}

QStringList Systemd::Unit::documentation() const
{
    Q_D(const Unit);
    return d->documentation;
}

QStringList Systemd::Unit::dropInPaths() const
{
    Q_D(const Unit);
    return d->dropInPaths;
}

QString Systemd::Unit::following() const
{
    Q_D(const Unit);
    return d->following;
}

QString Systemd::Unit::fragmentPath() const
{
    Q_D(const Unit);
    return d->fragmentPath;
}

QString Systemd::Unit::id() const
{
    Q_D(const Unit);
    return d->id;
}

bool Systemd::Unit::ignoreOnIsolate() const
{
    Q_D(const Unit);
    return d->ignoreOnIsolate;
}

qulonglong Systemd::Unit::inactiveEnterTimestamp() const
{
    Q_D(const Unit);
    return d->inactiveEnterTimestamp;
}

qulonglong Systemd::Unit::inactiveEnterTimestampMonotonic() const
{
    Q_D(const Unit);
    return d->inactiveEnterTimestampMonotonic;
}

qulonglong Systemd::Unit::inactiveExitTimestamp() const
{
    Q_D(const Unit);
    return d->inactiveExitTimestamp;
}

qulonglong Systemd::Unit::inactiveExitTimestampMonotonic() const
{
    Q_D(const Unit);
    return d->inactiveExitTimestampMonotonic;
}

uint Systemd::Unit::job() const
{
    Q_D(const Unit);
    return d->job;
}

QString Systemd::Unit::jobTimeoutAction() const
{
    Q_D(const Unit);
    return d->jobTimeoutAction;
}

QString Systemd::Unit::jobTimeoutRebootArgument() const
{
    Q_D(const Unit);
    return d->jobTimeoutRebootArgument;
}

qulonglong Systemd::Unit::jobTimeoutUSec() const
{
    Q_D(const Unit);
    return d->jobTimeoutUSec;
}

QStringList Systemd::Unit::joinsNamespaceOf() const
{
    Q_D(const Unit);
    return d->joinsNamespaceOf;
}

QString Systemd::Unit::loadState() const
{
    Q_D(const Unit);
    return d->loadState;
}

QStringList Systemd::Unit::names() const
{
    Q_D(const Unit);
    return d->names;
}

bool Systemd::Unit::needDaemonReload() const
{
    Q_D(const Unit);
    return d->needDaemonReload;
}

uint Systemd::Unit::netClass() const
{
    Q_D(const Unit);
    return d->netClass;
}

QStringList Systemd::Unit::onFailure() const
{
    Q_D(const Unit);
    return d->onFailure;
}

QString Systemd::Unit::onFailureJobMode() const
{
    Q_D(const Unit);
    return d->onFailureJobMode;
}

QStringList Systemd::Unit::partOf() const
{
    Q_D(const Unit);
    return d->partOf;
}

QStringList Systemd::Unit::propagatesReloadTo() const
{
    Q_D(const Unit);
    return d->propagatesReloadTo;
}

bool Systemd::Unit::refuseManualStart() const
{
    Q_D(const Unit);
    return d->refuseManualStart;
}

bool Systemd::Unit::refuseManualStop() const
{
    Q_D(const Unit);
    return d->refuseManualStop;
}

QStringList Systemd::Unit::reloadPropagatedFrom() const
{
    Q_D(const Unit);
    return d->reloadPropagatedFrom;
}

QStringList Systemd::Unit::requiredBy() const
{
    Q_D(const Unit);
    return d->requiredBy;
}

QStringList Systemd::Unit::requires() const
{
    Q_D(const Unit);
    return d->requires;
}

QStringList Systemd::Unit::requiresMountsFor() const
{
    Q_D(const Unit);
    return d->requiresMountsFor;
}

QStringList Systemd::Unit::requisite() const
{
    Q_D(const Unit);
    return d->requisite;
}

QStringList Systemd::Unit::requisiteOf() const
{
    Q_D(const Unit);
    return d->requisiteOf;
}

QString Systemd::Unit::sourcePath() const
{
    Q_D(const Unit);
    return d->sourcePath;
}

bool Systemd::Unit::stopWhenUnneeded() const
{
    Q_D(const Unit);
    return d->stopWhenUnneeded;
}

QString Systemd::Unit::subState() const
{
    Q_D(const Unit);
    return d->subState;
}

bool Systemd::Unit::transient() const
{
    Q_D(const Unit);
    return d->transient;
}

QStringList Systemd::Unit::triggeredBy() const
{
    Q_D(const Unit);
    return d->triggeredBy;
}

QStringList Systemd::Unit::triggers() const
{
    Q_D(const Unit);
    return d->triggers;
}

QString Systemd::Unit::unitFileState() const
{
    Q_D(const Unit);
    return d->unitFileState;
}

QStringList Systemd::Unit::wantedBy() const
{
    Q_D(const Unit);
    return d->wantedBy;
}

QStringList Systemd::Unit::wants() const
{
    Q_D(const Unit);
    return d->wants;
}
