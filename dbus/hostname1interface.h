/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp -N -m -i generic-types.h -p hostname1interface /home/ndr/projects/libsystemd-qt/dbus/introspection/org.freedesktop.hostname1.xml
 *
 * qdbusxml2cpp is Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef HOSTNAME1INTERFACE_H_1364657297
#define HOSTNAME1INTERFACE_H_1364657297

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
 * Proxy class for interface org.freedesktop.hostname1
 */
class OrgFreedesktopHostname1Interface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.freedesktop.hostname1"; }

public:
    OrgFreedesktopHostname1Interface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~OrgFreedesktopHostname1Interface();

    Q_PROPERTY(QString Chassis READ chassis)
    inline QString chassis() const
    { return qvariant_cast< QString >(property("Chassis")); }

    Q_PROPERTY(QString Hostname READ hostname)
    inline QString hostname() const
    { return qvariant_cast< QString >(property("Hostname")); }

    Q_PROPERTY(QString IconName READ iconName)
    inline QString iconName() const
    { return qvariant_cast< QString >(property("IconName")); }

    Q_PROPERTY(QString PrettyHostname READ prettyHostname)
    inline QString prettyHostname() const
    { return qvariant_cast< QString >(property("PrettyHostname")); }

    Q_PROPERTY(QString StaticHostname READ staticHostname)
    inline QString staticHostname() const
    { return qvariant_cast< QString >(property("StaticHostname")); }

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<> SetChassis(const QString &name, bool user_interaction)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(name) << QVariant::fromValue(user_interaction);
        return asyncCallWithArgumentList(QLatin1String("SetChassis"), argumentList);
    }

    inline QDBusPendingReply<> SetHostname(const QString &name, bool user_interaction)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(name) << QVariant::fromValue(user_interaction);
        return asyncCallWithArgumentList(QLatin1String("SetHostname"), argumentList);
    }

    inline QDBusPendingReply<> SetIconName(const QString &name, bool user_interaction)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(name) << QVariant::fromValue(user_interaction);
        return asyncCallWithArgumentList(QLatin1String("SetIconName"), argumentList);
    }

    inline QDBusPendingReply<> SetPrettyHostname(const QString &name, bool user_interaction)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(name) << QVariant::fromValue(user_interaction);
        return asyncCallWithArgumentList(QLatin1String("SetPrettyHostname"), argumentList);
    }

    inline QDBusPendingReply<> SetStaticHostname(const QString &name, bool user_interaction)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(name) << QVariant::fromValue(user_interaction);
        return asyncCallWithArgumentList(QLatin1String("SetStaticHostname"), argumentList);
    }

Q_SIGNALS: // SIGNALS
};

#endif
