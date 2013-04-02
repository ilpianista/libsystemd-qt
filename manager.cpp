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

#include "manager.h"
#include "manager_p.h"

const QString Systemd::SystemdPrivate::SD_DBUS_SERVICE(QString::fromLatin1("org.freedesktop.systemd1"));
const QString Systemd::SystemdPrivate::SD_DBUS_DAEMON_PATH(QString::fromLatin1("/org/freedesktop/systemd1"));
const QString Systemd::SystemdPrivate::LD_DBUS_SERVICE(QString::fromLatin1("org.freedesktop.login1"));
const QString Systemd::SystemdPrivate::LD_DBUS_DAEMON_PATH(QString::fromLatin1("/org/freedesktop/login1"));

Q_GLOBAL_STATIC(Systemd::SystemdPrivate, globalSystemd)

Systemd::SystemdPrivate::SystemdPrivate() :
    isdface( Systemd::SystemdPrivate::SD_DBUS_SERVICE, Systemd::SystemdPrivate::SD_DBUS_DAEMON_PATH, QDBusConnection::systemBus()),
    ildface( Systemd::SystemdPrivate::LD_DBUS_SERVICE, Systemd::SystemdPrivate::LD_DBUS_DAEMON_PATH, QDBusConnection::systemBus())
{
}

Systemd::SystemdPrivate::~SystemdPrivate()
{
}

bool Systemd::SystemdPrivate::enableUnitFiles(const QStringList &files, bool runtime, bool force)
{
    qDBusRegisterMetaType<DBusUnitFileChange>();
    qDBusRegisterMetaType<DBusUnitFileChangeList>();
    QDBusPendingReply<bool, DBusUnitFileChangeList> reply = isdface.EnableUnitFiles(files, runtime, force);
    reply.waitForFinished();

    if (reply.isError()) {
        qDebug() << reply.error();
        return false;
    }

    return true;
}

bool Systemd::SystemdPrivate::disableUnitFiles(const QStringList &files, bool runtime)
{
    qDBusRegisterMetaType<DBusUnitFileChange>();
    qDBusRegisterMetaType<DBusUnitFileChangeList>();
    QDBusPendingReply<DBusUnitFileChangeList> reply = isdface.DisableUnitFiles(files, runtime);
    reply.waitForFinished();

    if (reply.isError()) {
        qDebug() << reply.error();
        return false;
    }

    return true;
}

QStringList Systemd::SystemdPrivate::listUnits()
{
    qDBusRegisterMetaType<ManagerDBusUnit>();
    qDBusRegisterMetaType<ManagerDBusUnitList>();
    QDBusPendingReply<ManagerDBusUnitList> reply = isdface.ListUnits();
    reply.waitForFinished();

    if (reply.isError()) {
        qDebug() << reply.error();
        return QStringList();
    }

    QStringList loaded;
    const QDBusMessage message = reply.reply();
    if (message.type() == QDBusMessage::ReplyMessage) {
        const ManagerDBusUnitList units = qdbus_cast<ManagerDBusUnitList>(message.arguments().first());
        Q_FOREACH(const ManagerDBusUnit unit, units) {
            loaded << unit.id;
        }
    }

    return loaded;
}

bool Systemd::SystemdPrivate::startUnit(const QString &name, const QString &mode)
{
    QDBusPendingReply<QDBusObjectPath> reply = isdface.StartUnit(name, mode);
    reply.waitForFinished();

    if (reply.isError()) {
        qDebug() << reply.error();
        return false;
    }

    if (reply.reply().arguments().isEmpty())
        return false;

    return true;
}

bool Systemd::SystemdPrivate::stopUnit(const QString &name, const QString &mode)
{
    QDBusPendingReply<QDBusObjectPath> reply = isdface.StopUnit(name, mode);
    reply.waitForFinished();

    if (reply.isError()) {
        qDebug() << reply.error();
        return false;
    }

    if (reply.reply().arguments().isEmpty())
        return false;

    return true;
}

bool Systemd::enableUnitFiles(const QStringList &files, bool runtime, bool force)
{
    return globalSystemd()->enableUnitFiles(files, runtime, force);
}

bool Systemd::disableUnitFiles(const QStringList &files, bool runtime)
{
    return globalSystemd()->disableUnitFiles(files, runtime);
}

QStringList Systemd::listUnits()
{
    return globalSystemd()->listUnits();
}

bool Systemd::startUnit(const QString& name, const QString& mode)
{
    globalSystemd()->startUnit(name, mode);
}

bool Systemd::stopUnit(const QString& name, const QString& mode)
{
    globalSystemd()->stopUnit(name, mode);
}
