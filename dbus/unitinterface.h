/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp -N -m -i generic-types.h -p unitinterface /home/ndr/projects/libsystemd-qt/dbus/introspection/org.freedesktop.systemd1.Unit.xml
 *
 * qdbusxml2cpp is Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef UNITINTERFACE_H_1364907522
#define UNITINTERFACE_H_1364907522

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>
#include "generic-types.h"

/*
 * Proxy class for interface org.freedesktop.systemd1.Unit
 */
class OrgFreedesktopSystemd1UnitInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.freedesktop.systemd1.Unit"; }

public:
    OrgFreedesktopSystemd1UnitInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~OrgFreedesktopSystemd1UnitInterface();

    Q_PROPERTY(qulonglong ActiveEnterTimestamp READ activeEnterTimestamp)
    inline qulonglong activeEnterTimestamp() const
    { return qvariant_cast< qulonglong >(property("ActiveEnterTimestamp")); }

    Q_PROPERTY(qulonglong ActiveEnterTimestampMonotonic READ activeEnterTimestampMonotonic)
    inline qulonglong activeEnterTimestampMonotonic() const
    { return qvariant_cast< qulonglong >(property("ActiveEnterTimestampMonotonic")); }

    Q_PROPERTY(qulonglong ActiveExitTimestamp READ activeExitTimestamp)
    inline qulonglong activeExitTimestamp() const
    { return qvariant_cast< qulonglong >(property("ActiveExitTimestamp")); }

    Q_PROPERTY(qulonglong ActiveExitTimestampMonotonic READ activeExitTimestampMonotonic)
    inline qulonglong activeExitTimestampMonotonic() const
    { return qvariant_cast< qulonglong >(property("ActiveExitTimestampMonotonic")); }

    Q_PROPERTY(QString ActiveState READ activeState)
    inline QString activeState() const
    { return qvariant_cast< QString >(property("ActiveState")); }

    Q_PROPERTY(QStringList After READ after)
    inline QStringList after() const
    { return qvariant_cast< QStringList >(property("After")); }

    Q_PROPERTY(bool AllowIsolate READ allowIsolate)
    inline bool allowIsolate() const
    { return qvariant_cast< bool >(property("AllowIsolate")); }

    Q_PROPERTY(QStringList Before READ before)
    inline QStringList before() const
    { return qvariant_cast< QStringList >(property("Before")); }

    Q_PROPERTY(QStringList BindsTo READ bindsTo)
    inline QStringList bindsTo() const
    { return qvariant_cast< QStringList >(property("BindsTo")); }

    Q_PROPERTY(QStringList BoundBy READ boundBy)
    inline QStringList boundBy() const
    { return qvariant_cast< QStringList >(property("BoundBy")); }

    Q_PROPERTY(bool CanIsolate READ canIsolate)
    inline bool canIsolate() const
    { return qvariant_cast< bool >(property("CanIsolate")); }

    Q_PROPERTY(bool CanReload READ canReload)
    inline bool canReload() const
    { return qvariant_cast< bool >(property("CanReload")); }

    Q_PROPERTY(bool CanStart READ canStart)
    inline bool canStart() const
    { return qvariant_cast< bool >(property("CanStart")); }

    Q_PROPERTY(bool CanStop READ canStop)
    inline bool canStop() const
    { return qvariant_cast< bool >(property("CanStop")); }

    Q_PROPERTY(bool ConditionResult READ conditionResult)
    inline bool conditionResult() const
    { return qvariant_cast< bool >(property("ConditionResult")); }

    Q_PROPERTY(qulonglong ConditionTimestamp READ conditionTimestamp)
    inline qulonglong conditionTimestamp() const
    { return qvariant_cast< qulonglong >(property("ConditionTimestamp")); }

    Q_PROPERTY(qulonglong ConditionTimestampMonotonic READ conditionTimestampMonotonic)
    inline qulonglong conditionTimestampMonotonic() const
    { return qvariant_cast< qulonglong >(property("ConditionTimestampMonotonic")); }

    Q_PROPERTY(QStringList ConflictedBy READ conflictedBy)
    inline QStringList conflictedBy() const
    { return qvariant_cast< QStringList >(property("ConflictedBy")); }

    Q_PROPERTY(QStringList Conflicts READ conflicts)
    inline QStringList conflicts() const
    { return qvariant_cast< QStringList >(property("Conflicts")); }

    Q_PROPERTY(QStringList ConsistsOf READ consistsOf)
    inline QStringList consistsOf() const
    { return qvariant_cast< QStringList >(property("ConsistsOf")); }

    Q_PROPERTY(bool DefaultDependencies READ defaultDependencies)
    inline bool defaultDependencies() const
    { return qvariant_cast< bool >(property("DefaultDependencies")); }

    Q_PROPERTY(QString Description READ description)
    inline QString description() const
    { return qvariant_cast< QString >(property("Description")); }

    Q_PROPERTY(QStringList Documentation READ documentation)
    inline QStringList documentation() const
    { return qvariant_cast< QStringList >(property("Documentation")); }

    Q_PROPERTY(QString Following READ following)
    inline QString following() const
    { return qvariant_cast< QString >(property("Following")); }

    Q_PROPERTY(QString FragmentPath READ fragmentPath)
    inline QString fragmentPath() const
    { return qvariant_cast< QString >(property("FragmentPath")); }

    Q_PROPERTY(QString Id READ id)
    inline QString id() const
    { return qvariant_cast< QString >(property("Id")); }

    Q_PROPERTY(bool IgnoreOnIsolate READ ignoreOnIsolate)
    inline bool ignoreOnIsolate() const
    { return qvariant_cast< bool >(property("IgnoreOnIsolate")); }

    Q_PROPERTY(bool IgnoreOnSnapshot READ ignoreOnSnapshot)
    inline bool ignoreOnSnapshot() const
    { return qvariant_cast< bool >(property("IgnoreOnSnapshot")); }

    Q_PROPERTY(qulonglong InactiveEnterTimestamp READ inactiveEnterTimestamp)
    inline qulonglong inactiveEnterTimestamp() const
    { return qvariant_cast< qulonglong >(property("InactiveEnterTimestamp")); }

    Q_PROPERTY(qulonglong InactiveEnterTimestampMonotonic READ inactiveEnterTimestampMonotonic)
    inline qulonglong inactiveEnterTimestampMonotonic() const
    { return qvariant_cast< qulonglong >(property("InactiveEnterTimestampMonotonic")); }

    Q_PROPERTY(qulonglong InactiveExitTimestamp READ inactiveExitTimestamp)
    inline qulonglong inactiveExitTimestamp() const
    { return qvariant_cast< qulonglong >(property("InactiveExitTimestamp")); }

    Q_PROPERTY(qulonglong InactiveExitTimestampMonotonic READ inactiveExitTimestampMonotonic)
    inline qulonglong inactiveExitTimestampMonotonic() const
    { return qvariant_cast< qulonglong >(property("InactiveExitTimestampMonotonic")); }

    Q_PROPERTY(UnitDBusJob Job READ job)
    inline UnitDBusJob job() const
    { return qvariant_cast< UnitDBusJob >(property("Job")); }

    Q_PROPERTY(qulonglong JobTimeoutUSec READ jobTimeoutUSec)
    inline qulonglong jobTimeoutUSec() const
    { return qvariant_cast< qulonglong >(property("JobTimeoutUSec")); }

    Q_PROPERTY(UnitDBusLoadError LoadError READ loadError)
    inline UnitDBusLoadError loadError() const
    { return qvariant_cast< UnitDBusLoadError >(property("LoadError")); }

    Q_PROPERTY(QString LoadState READ loadState)
    inline QString loadState() const
    { return qvariant_cast< QString >(property("LoadState")); }

    Q_PROPERTY(QStringList Names READ names)
    inline QStringList names() const
    { return qvariant_cast< QStringList >(property("Names")); }

    Q_PROPERTY(bool NeedDaemonReload READ needDaemonReload)
    inline bool needDaemonReload() const
    { return qvariant_cast< bool >(property("NeedDaemonReload")); }

    Q_PROPERTY(QStringList OnFailure READ onFailure)
    inline QStringList onFailure() const
    { return qvariant_cast< QStringList >(property("OnFailure")); }

    Q_PROPERTY(bool OnFailureIsolate READ onFailureIsolate)
    inline bool onFailureIsolate() const
    { return qvariant_cast< bool >(property("OnFailureIsolate")); }

    Q_PROPERTY(QStringList PartOf READ partOf)
    inline QStringList partOf() const
    { return qvariant_cast< QStringList >(property("PartOf")); }

    Q_PROPERTY(QStringList PropagatesReloadTo READ propagatesReloadTo)
    inline QStringList propagatesReloadTo() const
    { return qvariant_cast< QStringList >(property("PropagatesReloadTo")); }

    Q_PROPERTY(bool RefuseManualStart READ refuseManualStart)
    inline bool refuseManualStart() const
    { return qvariant_cast< bool >(property("RefuseManualStart")); }

    Q_PROPERTY(bool RefuseManualStop READ refuseManualStop)
    inline bool refuseManualStop() const
    { return qvariant_cast< bool >(property("RefuseManualStop")); }

    Q_PROPERTY(QStringList ReloadPropagatedFrom READ reloadPropagatedFrom)
    inline QStringList reloadPropagatedFrom() const
    { return qvariant_cast< QStringList >(property("ReloadPropagatedFrom")); }

    Q_PROPERTY(QStringList RequiredBy READ requiredBy)
    inline QStringList requiredBy() const
    { return qvariant_cast< QStringList >(property("RequiredBy")); }

    Q_PROPERTY(QStringList RequiredByOverridable READ requiredByOverridable)
    inline QStringList requiredByOverridable() const
    { return qvariant_cast< QStringList >(property("RequiredByOverridable")); }

    Q_PROPERTY(QStringList Requires READ requires)
    inline QStringList requires() const
    { return qvariant_cast< QStringList >(property("Requires")); }

    Q_PROPERTY(QStringList RequiresMountsFor READ requiresMountsFor)
    inline QStringList requiresMountsFor() const
    { return qvariant_cast< QStringList >(property("RequiresMountsFor")); }

    Q_PROPERTY(QStringList RequiresOverridable READ requiresOverridable)
    inline QStringList requiresOverridable() const
    { return qvariant_cast< QStringList >(property("RequiresOverridable")); }

    Q_PROPERTY(QStringList Requisite READ requisite)
    inline QStringList requisite() const
    { return qvariant_cast< QStringList >(property("Requisite")); }

    Q_PROPERTY(QStringList RequisiteOverridable READ requisiteOverridable)
    inline QStringList requisiteOverridable() const
    { return qvariant_cast< QStringList >(property("RequisiteOverridable")); }

    Q_PROPERTY(QString SourcePath READ sourcePath)
    inline QString sourcePath() const
    { return qvariant_cast< QString >(property("SourcePath")); }

    Q_PROPERTY(bool StopWhenUnneeded READ stopWhenUnneeded)
    inline bool stopWhenUnneeded() const
    { return qvariant_cast< bool >(property("StopWhenUnneeded")); }

    Q_PROPERTY(QString SubState READ subState)
    inline QString subState() const
    { return qvariant_cast< QString >(property("SubState")); }

    Q_PROPERTY(QStringList TriggeredBy READ triggeredBy)
    inline QStringList triggeredBy() const
    { return qvariant_cast< QStringList >(property("TriggeredBy")); }

    Q_PROPERTY(QStringList Triggers READ triggers)
    inline QStringList triggers() const
    { return qvariant_cast< QStringList >(property("Triggers")); }

    Q_PROPERTY(QString UnitFileState READ unitFileState)
    inline QString unitFileState() const
    { return qvariant_cast< QString >(property("UnitFileState")); }

    Q_PROPERTY(QStringList WantedBy READ wantedBy)
    inline QStringList wantedBy() const
    { return qvariant_cast< QStringList >(property("WantedBy")); }

    Q_PROPERTY(QStringList Wants READ wants)
    inline QStringList wants() const
    { return qvariant_cast< QStringList >(property("Wants")); }

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<> Kill(const QString &who, int signal)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(who) << QVariant::fromValue(signal);
        return asyncCallWithArgumentList(QLatin1String("Kill"), argumentList);
    }

    inline QDBusPendingReply<QDBusObjectPath> Reload(const QString &mode)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(mode);
        return asyncCallWithArgumentList(QLatin1String("Reload"), argumentList);
    }

    inline QDBusPendingReply<QDBusObjectPath> ReloadOrRestart(const QString &mode)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(mode);
        return asyncCallWithArgumentList(QLatin1String("ReloadOrRestart"), argumentList);
    }

    inline QDBusPendingReply<QDBusObjectPath> ReloadOrTryRestart(const QString &mode)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(mode);
        return asyncCallWithArgumentList(QLatin1String("ReloadOrTryRestart"), argumentList);
    }

    inline QDBusPendingReply<> ResetFailed()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("ResetFailed"), argumentList);
    }

    inline QDBusPendingReply<QDBusObjectPath> Restart(const QString &mode)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(mode);
        return asyncCallWithArgumentList(QLatin1String("Restart"), argumentList);
    }

    inline QDBusPendingReply<QDBusObjectPath> Start(const QString &mode)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(mode);
        return asyncCallWithArgumentList(QLatin1String("Start"), argumentList);
    }

    inline QDBusPendingReply<QDBusObjectPath> Stop(const QString &mode)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(mode);
        return asyncCallWithArgumentList(QLatin1String("Stop"), argumentList);
    }

    inline QDBusPendingReply<QDBusObjectPath> TryRestart(const QString &mode)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(mode);
        return asyncCallWithArgumentList(QLatin1String("TryRestart"), argumentList);
    }

Q_SIGNALS: // SIGNALS
};

#endif