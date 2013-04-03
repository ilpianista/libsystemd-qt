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

#include "ldmanager.h"
#include "ldmanager_p.h"

const QString Systemd::LogindPrivate::LD_DBUS_SERVICE(QString::fromLatin1("org.freedesktop.login1"));
const QString Systemd::LogindPrivate::LD_DBUS_DAEMON_PATH(QString::fromLatin1("/org/freedesktop/login1"));

Q_GLOBAL_STATIC(Systemd::LogindPrivate, globalLogind)

Systemd::LogindPrivate::LogindPrivate() :
ildface( Systemd::LogindPrivate::LD_DBUS_SERVICE, Systemd::LogindPrivate::LD_DBUS_DAEMON_PATH, QDBusConnection::systemBus())
{
}

Systemd::LogindPrivate::~LogindPrivate()
{
}

Systemd::Permission Systemd::LogindPrivate::canHibernate()
{
    QDBusPendingReply<QString> reply = ildface.CanHibernate();
    reply.waitForFinished();

    if (reply.isError()) {
        qDebug() << reply.error().message();
        return Systemd::Unknown;
    }

    const QString permission = qdbus_cast<QString>(reply.reply().arguments().first());

    return stringToPermission(permission);
}

Systemd::Permission Systemd::LogindPrivate::canHybridSleep()
{
    QDBusPendingReply<QString> reply = ildface.CanHybridSleep();
    reply.waitForFinished();

    if (reply.isError()) {
        qDebug() << reply.error().message();
        return Systemd::Unknown;
    }

    const QString permission = qdbus_cast<QString>(reply.reply().arguments().first());

    return stringToPermission(permission);
}

Systemd::Permission Systemd::LogindPrivate::canPowerOff()
{
    QDBusPendingReply<QString> reply = ildface.CanPowerOff();
    reply.waitForFinished();

    if (reply.isError()) {
        qDebug() << reply.error().message();
        return Systemd::Unknown;
    }

    const QString permission = qdbus_cast<QString>(reply.reply().arguments().first());

    return stringToPermission(permission);
}

Systemd::Permission Systemd::LogindPrivate::canReboot()
{
    QDBusPendingReply<QString> reply = ildface.CanReboot();
    reply.waitForFinished();

    if (reply.isError()) {
        qDebug() << reply.error().message();
        return Systemd::Unknown;
    }

    const QString permission = qdbus_cast<QString>(reply.reply().arguments().first());

    return stringToPermission(permission);
}

Systemd::Permission Systemd::LogindPrivate::canSuspend()
{
    QDBusPendingReply<QString> reply = ildface.CanSuspend();
    reply.waitForFinished();

    if (reply.isError()) {
        qDebug() << reply.error().message();
        return Systemd::Unknown;
    }

    const QString permission = qdbus_cast<QString>(reply.reply().arguments().first());

    return stringToPermission(permission);
}

Systemd::Permission Systemd::LogindPrivate::stringToPermission(const QString &permission)
{
    if (permission == QLatin1String("na")) {
        return Systemd::Na;
    } else if (permission == QLatin1String("yes")) {
        return Systemd::Yes;
    } else if (permission == QLatin1String("no")) {
        return Systemd::No;
    } else if (permission == QLatin1String("challenge")) {
        return Systemd::Challenge;
    } else {
        return Systemd::Unknown;
    }
}

Systemd::Permission Systemd::canHibernate()
{
    return globalLogind()->canHibernate();
}

Systemd::Permission Systemd::canHybridSleep()
{
    return globalLogind()->canHybridSleep();
}

Systemd::Permission Systemd::canPowerOff()
{
    return globalLogind()->canPowerOff();
}

Systemd::Permission Systemd::canReboot()
{
    return globalLogind()->canReboot();
}

Systemd::Permission Systemd::canSuspend()
{
    return globalLogind()->canSuspend();
}
