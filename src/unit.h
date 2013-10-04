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

#ifndef SD_UNIT_H
#define SD_UNIT_H

#include <QStringList>
#include <QSharedPointer>

namespace Systemd {

class UnitPrivate;

class Unit : public QObject
{
    Q_OBJECT

    Q_PROPERTY(qulonglong activeEnterTimestamp READ activeEnterTimestamp)
    Q_PROPERTY(qulonglong activeEnterTimestampMonotonic READ activeEnterTimestampMonotonic)
    Q_PROPERTY(qulonglong activeExitTimestamp READ activeExitTimestamp)
    Q_PROPERTY(qulonglong activeExitTimestampMonotonic READ activeExitTimestampMonotonic)
    Q_PROPERTY(QString activeState READ activeState NOTIFY activeStateChanged)
    Q_PROPERTY(QStringList after READ after)
    Q_PROPERTY(bool allowIsolate READ allowIsolate)
    Q_PROPERTY(QStringList before READ before)
    Q_PROPERTY(QStringList bindsTo READ bindsTo)
    Q_PROPERTY(QStringList boundBy READ boundBy)
    Q_PROPERTY(bool canIsolate READ canIsolate)
    Q_PROPERTY(bool canReload READ canReload)
    Q_PROPERTY(bool canStart READ canStart)
    Q_PROPERTY(bool canStop READ canStop)
    Q_PROPERTY(bool conditionResult READ conditionResult)
    Q_PROPERTY(qulonglong conditionTimestamp READ conditionTimestamp)
    Q_PROPERTY(qulonglong conditionTimestampMonotonic READ conditionTimestampMonotonic)
    Q_PROPERTY(QStringList conflictedBy READ conflictedBy)
    Q_PROPERTY(QStringList conflicts READ conflicts)
    Q_PROPERTY(QStringList consistsOf READ consistsOf)
    Q_PROPERTY(bool defaultDependencies READ defaultDependencies)
    Q_PROPERTY(QString description READ description NOTIFY descriptionChanged)
    Q_PROPERTY(QStringList documentation READ documentation)
    Q_PROPERTY(QStringList dropInPaths READ dropInPaths)
    Q_PROPERTY(QString following READ following)
    Q_PROPERTY(QString fragmentPath READ fragmentPath)
    Q_PROPERTY(QString id READ id CONSTANT)
    Q_PROPERTY(bool ignoreOnIsolate READ ignoreOnIsolate)
    Q_PROPERTY(bool ignoreOnSnapshot READ ignoreOnSnapshot)
    Q_PROPERTY(qulonglong inactiveEnterTimestamp READ inactiveEnterTimestamp)
    Q_PROPERTY(qulonglong inactiveEnterTimestampMonotonic READ inactiveEnterTimestampMonotonic)
    Q_PROPERTY(qulonglong inactiveExitTimestamp READ inactiveExitTimestamp)
    Q_PROPERTY(qulonglong inactiveExitTimestampMonotonic READ inactiveExitTimestampMonotonic)
    Q_PROPERTY(uint job READ job)
    Q_PROPERTY(qulonglong jobTimeoutUSec READ jobTimeoutUSec)
    Q_PROPERTY(QString loadState READ loadState NOTIFY loadStateChanged)
    Q_PROPERTY(QStringList names READ names)
    Q_PROPERTY(bool needDaemonReload READ needDaemonReload)
    Q_PROPERTY(QStringList onFailure READ onFailure)
    Q_PROPERTY(bool onFailureIsolate READ onFailureIsolate)
    Q_PROPERTY(QStringList partOf READ partOf)
    Q_PROPERTY(QStringList propagatesReloadTo READ propagatesReloadTo)
    Q_PROPERTY(bool refuseManualStart READ refuseManualStart)
    Q_PROPERTY(bool refuseManualStop READ refuseManualStop)
    Q_PROPERTY(QStringList reloadPropagatedFrom READ reloadPropagatedFrom)
    Q_PROPERTY(QStringList requiredBy READ requiredBy)
    Q_PROPERTY(QStringList requiredByOverridable READ requiredByOverridable)
    Q_PROPERTY(QStringList requires READ requires)
    Q_PROPERTY(QStringList requiresMountsFor READ requiresMountsFor)
    Q_PROPERTY(QStringList requiresOverridable READ requiresOverridable)
    Q_PROPERTY(QStringList requisite READ requisite)
    Q_PROPERTY(QStringList requisiteOverridable READ requisiteOverridable)
    Q_PROPERTY(QString sourcePath READ sourcePath)
    Q_PROPERTY(bool stopWhenUnneeded READ stopWhenUnneeded)
    Q_PROPERTY(QString subState READ subState NOTIFY subStateChanged)
    Q_PROPERTY(bool transient READ transient)
    Q_PROPERTY(QStringList triggeredBy READ triggeredBy)
    Q_PROPERTY(QStringList triggers READ triggers)
    Q_PROPERTY(QString unitFileState READ unitFileState NOTIFY unitFileStateChanged)
    Q_PROPERTY(QStringList wantedBy READ wantedBy)
    Q_PROPERTY(QStringList wants READ wants)

public:
    typedef QSharedPointer<Unit> Ptr;

    explicit Unit(const QString &path, QObject *parent = 0);
    explicit Unit(UnitPrivate &unit, QObject *parent = 0);
    virtual ~Unit();

    qulonglong activeEnterTimestamp() const;
    qulonglong activeEnterTimestampMonotonic() const;
    qulonglong activeExitTimestamp() const;
    qulonglong activeExitTimestampMonotonic() const;
    QString activeState() const;
    QStringList after() const;
    bool allowIsolate() const;
    QStringList before() const;
    QStringList bindsTo() const;
    QStringList boundBy() const;
    bool canIsolate() const;
    bool canReload() const;
    bool canStart() const;
    bool canStop() const;
    bool conditionResult() const;
    qulonglong conditionTimestamp() const;
    qulonglong conditionTimestampMonotonic() const;
    QStringList conflictedBy() const;
    QStringList conflicts() const;
    QStringList consistsOf() const;
    bool defaultDependencies() const;
    QString description() const;
    QStringList documentation() const;
    QStringList dropInPaths() const;
    QString following() const;
    QString fragmentPath() const;
    QString id() const;
    bool ignoreOnIsolate() const;
    bool ignoreOnSnapshot() const;
    qulonglong inactiveEnterTimestamp() const;
    qulonglong inactiveEnterTimestampMonotonic() const;
    qulonglong inactiveExitTimestamp() const;
    qulonglong inactiveExitTimestampMonotonic() const;
    uint job() const;
    qulonglong jobTimeoutUSec() const;
    QString loadState() const;
    QStringList names() const;
    bool needDaemonReload() const;
    QStringList onFailure() const;
    bool onFailureIsolate() const;
    QStringList partOf() const;
    QStringList propagatesReloadTo() const;
    bool refuseManualStart() const;
    bool refuseManualStop() const;
    QStringList reloadPropagatedFrom() const;
    QStringList requiredBy() const;
    QStringList requiredByOverridable() const;
    QStringList requires() const;
    QStringList requiresMountsFor() const;
    QStringList requiresOverridable() const;
    QStringList requisite() const;
    QStringList requisiteOverridable() const;
    QString sourcePath() const;
    bool stopWhenUnneeded() const;
    QString subState() const;
    bool transient() const;
    QStringList triggeredBy() const;
    QStringList triggers() const;
    QString unitFileState() const;
    QStringList wantedBy() const;
    QStringList wants() const;

Q_SIGNALS:
    void activeStateChanged();
    void descriptionChanged();
    void loadStateChanged();
    void subStateChanged();
    void unitFileStateChanged();

protected:
    UnitPrivate *d_ptr;

private:
    void init();

    Q_DECLARE_PRIVATE(Unit)
};
}

#endif