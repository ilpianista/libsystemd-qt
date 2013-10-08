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

#include "sdmanager.h"
#include "sdmanager_p.h"

using namespace Systemd;

const QString SystemdPrivate::SD_DBUS_SERVICE(QString::fromLatin1("org.freedesktop.systemd1"));
const QString SystemdPrivate::SD_DBUS_DAEMON_PATH(QString::fromLatin1("/org/freedesktop/systemd1"));

Q_GLOBAL_STATIC(Systemd::SystemdPrivate, globalSystemd)

Systemd::SystemdPrivate::SystemdPrivate() :
    isdface(SystemdPrivate::SD_DBUS_SERVICE, SystemdPrivate::SD_DBUS_DAEMON_PATH,
            QDBusConnection::systemBus())
{
    connect(&isdface, SIGNAL(UnitNew(QString,QDBusObjectPath)), this,
            SLOT(onUnitNew(QString,QDBusObjectPath)));
    connect(&isdface, SIGNAL(UnitRemoved(QString,QDBusObjectPath)), this,
            SLOT(onUnitRemoved(QString,QDBusObjectPath)));
    connect(&isdface, SIGNAL(UnitFilesChanged()), this,
            SLOT(onUnitFilesChanged()));

    init();
}

Systemd::SystemdPrivate::~SystemdPrivate()
{
}

void Systemd::SystemdPrivate::init()
{
    qDBusRegisterMetaType<UnitDBusJob>();
}

bool Systemd::SystemdPrivate::disableUnitFiles(const QStringList &files, const bool runtime)
{
    qDBusRegisterMetaType<DBusUnitFileChange>();
    qDBusRegisterMetaType<DBusUnitFileChangeList>();
    QDBusPendingReply<DBusUnitFileChangeList> reply = isdface.DisableUnitFiles(files, runtime);
    reply.waitForFinished();

    if (reply.isError()) {
        qDebug() << reply.error().message();
        return false;
    }

    return true;
}

bool Systemd::SystemdPrivate::enableUnitFiles(const QStringList &files, const bool runtime, const bool force)
{
    qDBusRegisterMetaType<DBusUnitFileChange>();
    qDBusRegisterMetaType<DBusUnitFileChangeList>();
    QDBusPendingReply<bool, DBusUnitFileChangeList> reply = isdface.EnableUnitFiles(files, runtime, force);
    reply.waitForFinished();

    if (reply.isError()) {
        qDebug() << reply.error().message();
        return false;
    }

    return true;
}

Job::Ptr Systemd::SystemdPrivate::getJob(const uint id)
{
    Job::Ptr job;

    QDBusPendingReply<QDBusObjectPath> reply = isdface.GetJob(id);
    reply.waitForFinished();

    if (reply.isError()) {
        qDebug() << reply.error().message();
    } else if (! reply.reply().arguments().isEmpty()) {
        QString jobPath = qdbus_cast<QDBusObjectPath>(reply.reply().arguments().first()).path();
        job = Job::Ptr(new Job(jobPath), &QObject::deleteLater);
    }

    return job;
}

Unit::Ptr Systemd::SystemdPrivate::getUnit(const QString &name)
{
    Unit::Ptr unit;

    QDBusPendingReply<QDBusObjectPath> reply = isdface.GetUnit(name);
    reply.waitForFinished();

    if (reply.isError()) {
        qDebug() << reply.error().message();
    } else if (! reply.reply().arguments().isEmpty()) {
        QString unitPath = qdbus_cast<QDBusObjectPath>(reply.reply().arguments().first()).path();
        unit = Unit::Ptr(new Unit(unitPath), &QObject::deleteLater);
    }

    return unit;
}

Unit::Ptr Systemd::SystemdPrivate::getUnitByPID(const uint pid)
{
    Unit::Ptr unit;

    QDBusPendingReply<QDBusObjectPath> reply = isdface.GetUnitByPID(pid);
    reply.waitForFinished();

    if (reply.isError()) {
        qDebug() << reply.error().message();
    } else if (! reply.reply().arguments().isEmpty()) {
        QString unitPath = qdbus_cast<QDBusObjectPath>(reply.reply().arguments().first()).path();
        unit = Unit::Ptr(new Unit(unitPath), &QObject::deleteLater);
    }

    return unit;
}

QList<Job::Ptr> Systemd::SystemdPrivate::listJobs()
{
    QList<Job::Ptr> jobs;

    qDBusRegisterMetaType<ManagerDBusJob>();
    qDBusRegisterMetaType<ManagerDBusJobList>();
    QDBusPendingReply<ManagerDBusJobList> reply = isdface.ListJobs();
    reply.waitForFinished();

    if (reply.isError()) {
        qDebug() << reply.error().message();
    } else {
        const QDBusMessage message = reply.reply();
        if (message.type() == QDBusMessage::ReplyMessage) {
            const ManagerDBusJobList queued = qdbus_cast<ManagerDBusJobList>(message.arguments().first());
            Q_FOREACH(const ManagerDBusJob job, queued) {
                jobs.append(Job::Ptr(new Job(job.path.path()), &QObject::deleteLater));
            }
        }
    }

    return jobs;
}

QList<Unit::Ptr> Systemd::SystemdPrivate::listUnits()
{
    QList<Unit::Ptr> units;

    qDBusRegisterMetaType<ManagerDBusUnit>();
    qDBusRegisterMetaType<ManagerDBusUnitList>();
    QDBusPendingReply<ManagerDBusUnitList> reply = isdface.ListUnits();
    reply.waitForFinished();

    if (reply.isError()) {
        qDebug() << reply.error().message();
    } else {
        const QDBusMessage message = reply.reply();
        if (message.type() == QDBusMessage::ReplyMessage) {
            const ManagerDBusUnitList loaded = qdbus_cast<ManagerDBusUnitList>(message.arguments().first());
            Q_FOREACH(const ManagerDBusUnit unit, loaded) {
                units.append(Unit::Ptr(new Unit(unit.path.path()), &QObject::deleteLater));
            }
        }
    }

    return units;
}

QStringList Systemd::SystemdPrivate::listUnitFiles()
{
    QStringList unitFiles;

    qDBusRegisterMetaType<ManagerDBusUnitFile>();
    qDBusRegisterMetaType<ManagerDBusUnitFileList>();
    QDBusPendingReply<ManagerDBusUnitFileList> reply = isdface.ListUnitFiles();
    reply.waitForFinished();

    if (reply.isError()) {
        qDebug() << reply.error().message();
    } else {
        const QDBusMessage message = reply.reply();
        if (message.type() == QDBusMessage::ReplyMessage) {
            const ManagerDBusUnitFileList files = qdbus_cast<ManagerDBusUnitFileList>(message.arguments().first());
            Q_FOREACH(const ManagerDBusUnitFile file, files) {
                unitFiles.append(file.path);
            }
        }
    }

    return unitFiles;
}

Unit::Ptr Systemd::SystemdPrivate::loadUnit(const QString &name)
{
    Unit::Ptr unit;

    QDBusPendingReply<QDBusObjectPath> reply = isdface.LoadUnit(name);
    reply.waitForFinished();

    if (reply.isError()) {
        qDebug() << reply.error().message();
    } else if (! reply.reply().arguments().isEmpty()) {
        QString unitPath = qdbus_cast<QDBusObjectPath>(reply.reply().arguments().first()).path();
        unit = Unit::Ptr(new Unit(unitPath), &QObject::deleteLater);
    }

    return unit;
}

void Systemd::SystemdPrivate::onUnitNew(const QString &id, const QDBusObjectPath &unit)
{
    emit Notifier::unitNew(unit.path());
}

void Systemd::SystemdPrivate::onUnitRemoved(const QString &id, const QDBusObjectPath &unit)
{
    emit Notifier::unitRemoved(unit.path());
}

void Systemd::SystemdPrivate::onUnitFilesChanged()
{
    emit Notifier::unitFilesChanged();
}

Job::Ptr Systemd::SystemdPrivate::reloadUnit(const QString &name, const Systemd::Mode mode)
{
    Job::Ptr job;

    QDBusPendingReply<QDBusObjectPath> reply = isdface.ReloadUnit(name, modeToString(mode));
    reply.waitForFinished();

    if (reply.isError()) {
        qDebug() << reply.error().message();
    } else if (! reply.reply().arguments().isEmpty()) {
        QString jobPath = qdbus_cast<QDBusObjectPath>(reply.reply().arguments().first()).path();
        job = Job::Ptr(new Job(jobPath), &QObject::deleteLater);
    }

    return job;
}

Job::Ptr Systemd::SystemdPrivate::restartUnit(const QString &name, const Systemd::Mode mode)
{
    Job::Ptr job;

    QDBusPendingReply<QDBusObjectPath> reply = isdface.RestartUnit(name, modeToString(mode));
    reply.waitForFinished();

    if (reply.isError()) {
        qDebug() << reply.error().message();
    } else if (! reply.reply().arguments().isEmpty()) {
        QString jobPath = qdbus_cast<QDBusObjectPath>(reply.reply().arguments().first()).path();
        job = Job::Ptr(new Job(jobPath), &QObject::deleteLater);
    }

    return job;
}

Job::Ptr Systemd::SystemdPrivate::startUnit(const QString &name, const Systemd::Mode mode)
{
    Job::Ptr job;

    QDBusPendingReply<QDBusObjectPath> reply = isdface.StartUnit(name, modeToString(mode));
    reply.waitForFinished();

    if (reply.isError()) {
        qDebug() << reply.error().message();
    } else if (! reply.reply().arguments().isEmpty()) {
        QString jobPath = qdbus_cast<QDBusObjectPath>(reply.reply().arguments().first()).path();
        job = Job::Ptr(new Job(jobPath), &QObject::deleteLater);
    }

    return job;
}

Job::Ptr Systemd::SystemdPrivate::stopUnit(const QString &name, const Systemd::Mode mode)
{
    Job::Ptr job;

    QDBusPendingReply<QDBusObjectPath> reply = isdface.StopUnit(name, modeToString(mode));
    reply.waitForFinished();

    if (reply.isError()) {
        qDebug() << reply.error().message();
    } else if (! reply.reply().arguments().isEmpty()) {
        QString jobPath = qdbus_cast<QDBusObjectPath>(reply.reply().arguments().first()).path();
        job = Job::Ptr(new Job(jobPath), &QObject::deleteLater);
    }

    return job;
}

QString Systemd::SystemdPrivate::modeToString(const Systemd::Mode mode)
{
    switch(mode) {
        case Fail: return "fail";
        case IgnoreDependencies: return "ignore-dependencies";
        case IgnoreRequirements: return "ignore-requirements";
        case Isolate: return "isolate";
        case Replace: return "replace";
        default: return QString();
    }
}

bool Systemd::disableUnitFiles(const QStringList &files, const bool runtime)
{
    return globalSystemd()->disableUnitFiles(files, runtime);
}

bool Systemd::enableUnitFiles(const QStringList &files, const bool runtime, const bool force)
{
    return globalSystemd()->enableUnitFiles(files, runtime, force);
}

Job::Ptr Systemd::getJob(const uint id)
{
    return globalSystemd()->getJob(id);
}

Unit::Ptr Systemd::getUnit(const QString &name)
{
    return globalSystemd()->getUnit(name);
}

Unit::Ptr Systemd::getUnitByPID(const uint pid)
{
    return globalSystemd()->getUnitByPID(pid);
}

QList<Job::Ptr> Systemd::listJobs()
{
    return globalSystemd()->listJobs();
}

QList<Unit::Ptr> Systemd::listUnits()
{
    return globalSystemd()->listUnits();
}

QStringList Systemd::listUnitFiles()
{
    return globalSystemd()->listUnitFiles();
}

Unit::Ptr Systemd::loadUnit(const QString &name)
{
    return globalSystemd()->loadUnit(name);
}

Job::Ptr Systemd::reloadUnit(const QString &name, const Systemd::Mode mode)
{
    return globalSystemd()->reloadUnit(name, mode);
}

Job::Ptr Systemd::restartUnit(const QString &name, const Systemd::Mode mode)
{
    return globalSystemd()->restartUnit(name, mode);
}

Job::Ptr Systemd::startUnit(const QString &name, const Systemd::Mode mode)
{
    return globalSystemd()->startUnit(name, mode);
}

Job::Ptr Systemd::stopUnit(const QString &name, const Systemd::Mode mode)
{
    return globalSystemd()->stopUnit(name, mode);
}

Notifier *Systemd::notifier()
{
    return globalSystemd();
}