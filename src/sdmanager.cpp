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
#include <QDBusConnection>

using namespace Systemd;

const QString SystemdPrivate::SD_DBUS_SERVICE(QLatin1String("org.freedesktop.systemd1"));
const QString SystemdPrivate::SD_DBUS_DAEMON_PATH(QLatin1String("/org/freedesktop/systemd1"));


Q_GLOBAL_STATIC(Systemd::ManagerSystemSession, globalSystemSession)
Q_GLOBAL_STATIC(Systemd::ManagerUserSession, globalUserSession)

static SystemdPrivate *globalSession(const SessionType &session)
{
    if ( session == SystemSession ) {
        return globalSystemSession();
    } else {
        return globalUserSession();
    }
}

SystemdPrivate::SystemdPrivate(const QDBusConnection &connection) :
    isdface(SystemdPrivate::SD_DBUS_SERVICE, SystemdPrivate::SD_DBUS_DAEMON_PATH,
            connection)
{
    connect(&isdface, SIGNAL(JobNew(uint,QDBusObjectPath,QString)), this,
            SLOT(onJobNew(uint,QDBusObjectPath,QString)));
    connect(&isdface, SIGNAL(JobRemoved(uint,QDBusObjectPath,QString,QString)), this,
            SLOT(onJobRemoved(uint,QDBusObjectPath,QString,QString)));
    connect(&isdface, SIGNAL(UnitNew(QString,QDBusObjectPath)), this,
            SLOT(onUnitNew(QString,QDBusObjectPath)));
    connect(&isdface, SIGNAL(UnitRemoved(QString,QDBusObjectPath)), this,
            SLOT(onUnitRemoved(QString,QDBusObjectPath)));
    connect(&isdface, SIGNAL(UnitFilesChanged()), this,
            SLOT(onUnitFilesChanged()));

    init();
}

SystemdPrivate::~SystemdPrivate()
{
}

void SystemdPrivate::init()
{

}

void SystemdPrivate::disableUnitFiles(const QStringList &files, const bool runtime)
{
    QDBusPendingReply<ManagerDBusUnitFileChangeList> reply = isdface.DisableUnitFiles(files, runtime);
    reply.waitForFinished();

    if (reply.isError()) {
        qDebug() << reply.error().message();
    }
}

void SystemdPrivate::enableUnitFiles(const QStringList &files, const bool runtime, const bool force)
{
    QDBusPendingReply<bool, ManagerDBusUnitFileChangeList> reply = isdface.EnableUnitFiles(files, runtime, force);
    reply.waitForFinished();

    if (reply.isError()) {
        qDebug() << reply.error().message();
    }
}

Job::Ptr SystemdPrivate::getJob(const uint id)
{
    Job::Ptr job;

    QDBusPendingReply<QDBusObjectPath> reply = isdface.GetJob(id);
    reply.waitForFinished();

    if (reply.isError()) {
        qDebug() << reply.error().message();
    } else if (! reply.reply().arguments().isEmpty()) {
        QString jobPath = qdbus_cast<QDBusObjectPath>(reply.reply().arguments().first()).path();
        job = Job::Ptr(new Job(jobPath, isdface.connection()), &QObject::deleteLater);
    }

    return job;
}

Unit::Ptr SystemdPrivate::getUnit(const QString &name)
{
    Unit::Ptr unit;

    QDBusPendingReply<QDBusObjectPath> reply = isdface.GetUnit(name);
    reply.waitForFinished();

    if (reply.isError()) {
        qDebug() << reply.error().message();
    } else if (! reply.reply().arguments().isEmpty()) {
        QString unitPath = qdbus_cast<QDBusObjectPath>(reply.reply().arguments().first()).path();
        unit = Unit::Ptr(new Unit(unitPath, isdface.connection()), &QObject::deleteLater);
    }

    return unit;
}

Unit::Ptr SystemdPrivate::getUnitByPID(const uint pid)
{
    Unit::Ptr unit;

    QDBusPendingReply<QDBusObjectPath> reply = isdface.GetUnitByPID(pid);
    reply.waitForFinished();

    if (reply.isError()) {
        qDebug() << reply.error().message();
    } else if (! reply.reply().arguments().isEmpty()) {
        QString unitPath = qdbus_cast<QDBusObjectPath>(reply.reply().arguments().first()).path();
        unit = Unit::Ptr(new Unit(unitPath, isdface.connection()), &QObject::deleteLater);
    }

    return unit;
}

QString SystemdPrivate::getUnitFileState(const QString& file)
{
    QDBusPendingReply<QString> reply = isdface.GetUnitFileState(file);
    reply.waitForFinished();

    if (reply.isError()) {
        qDebug() << reply.error().message();
    }

    return qdbus_cast<QString>(reply.reply().arguments().first());
}

void SystemdPrivate::killUnit(const QString& name, const Who who, const int signal)
{
    QDBusPendingReply<void> reply = isdface.KillUnit(name, whoToString(who), signal);
    reply.waitForFinished();

    if (reply.isError()) {
        qDebug() << reply.error().message();
    }
}

QList<Job::Ptr> SystemdPrivate::listJobs()
{
    QList<Job::Ptr> jobs;

    QDBusPendingReply<ManagerDBusJobList> reply = isdface.ListJobs();
    reply.waitForFinished();

    if (reply.isError()) {
        qDebug() << reply.error().message();
    } else {
        const QDBusMessage message = reply.reply();
        if (message.type() == QDBusMessage::ReplyMessage) {
            const ManagerDBusJobList queued = qdbus_cast<ManagerDBusJobList>(message.arguments().first());
            Q_FOREACH(const ManagerDBusJob job, queued) {
                jobs.append(Job::Ptr(new Job(job.path.path(), isdface.connection()), &QObject::deleteLater));
            }
        }
    }

    return jobs;
}

QList<Unit::Ptr> SystemdPrivate::listUnits()
{
    QList<Unit::Ptr> units;

    QDBusPendingReply<ManagerDBusUnitList> reply = isdface.ListUnits();
    reply.waitForFinished();

    if (reply.isError()) {
        qDebug() << reply.error().message();
    } else {
        const QDBusMessage message = reply.reply();
        if (message.type() == QDBusMessage::ReplyMessage) {
            const ManagerDBusUnitList loaded = qdbus_cast<ManagerDBusUnitList>(message.arguments().first());
            Q_FOREACH(const ManagerDBusUnit unit, loaded) {
                units.append(Unit::Ptr(new Unit(unit.path.path(), isdface.connection()), &QObject::deleteLater));
            }
        }
    }

    return units;
}

QStringList SystemdPrivate::listUnitFiles()
{
    QStringList unitFiles;

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

Unit::Ptr SystemdPrivate::loadUnit(const QString &name)
{
    Unit::Ptr unit;

    QDBusPendingReply<QDBusObjectPath> reply = isdface.LoadUnit(name);
    reply.waitForFinished();

    if (reply.isError()) {
        qDebug() << reply.error().message();
    } else if (! reply.reply().arguments().isEmpty()) {
        QString unitPath = qdbus_cast<QDBusObjectPath>(reply.reply().arguments().first()).path();
        unit = Unit::Ptr(new Unit(unitPath, isdface.connection()), &QObject::deleteLater);
    }

    return unit;
}

void SystemdPrivate::onJobNew(const uint id, const QDBusObjectPath &job, const QString &unit)
{
    emit Notifier::jobNew(job.path(), unit);
}

void SystemdPrivate::onJobRemoved(const uint id, const QDBusObjectPath &job, const QString &unit, const QString &result)
{
    emit Notifier::jobRemoved(job.path(), unit, stringToResult(result));
}

void SystemdPrivate::onUnitNew(const QString &id, const QDBusObjectPath &unit)
{
    emit Notifier::unitNew(unit.path());
}

void SystemdPrivate::onUnitRemoved(const QString &id, const QDBusObjectPath &unit)
{
    emit Notifier::unitRemoved(unit.path());
}

void SystemdPrivate::onUnitFilesChanged()
{
    emit Notifier::unitFilesChanged();
}

Job::Ptr SystemdPrivate::reloadUnit(const QString &name, const Systemd::Mode mode)
{
    Job::Ptr job;

    QDBusPendingReply<QDBusObjectPath> reply = isdface.ReloadUnit(name, modeToString(mode));
    reply.waitForFinished();

    if (reply.isError()) {
        qDebug() << reply.error().message();
    } else if (! reply.reply().arguments().isEmpty()) {
        QString jobPath = qdbus_cast<QDBusObjectPath>(reply.reply().arguments().first()).path();
        job = Job::Ptr(new Job(jobPath, isdface.connection()), &QObject::deleteLater);
    }

    return job;
}

Job::Ptr SystemdPrivate::restartUnit(const QString &name, const Systemd::Mode mode)
{
    Job::Ptr job;

    QDBusPendingReply<QDBusObjectPath> reply = isdface.RestartUnit(name, modeToString(mode));
    reply.waitForFinished();

    if (reply.isError()) {
        qDebug() << reply.error().message();
    } else if (! reply.reply().arguments().isEmpty()) {
        QString jobPath = qdbus_cast<QDBusObjectPath>(reply.reply().arguments().first()).path();
        job = Job::Ptr(new Job(jobPath, isdface.connection()), &QObject::deleteLater);
    }

    return job;
}

Job::Ptr SystemdPrivate::startUnit(const QString &name, const Systemd::Mode mode)
{
    Job::Ptr job;

    QDBusPendingReply<QDBusObjectPath> reply = isdface.StartUnit(name, modeToString(mode));
    reply.waitForFinished();

    if (reply.isError()) {
        qDebug() << reply.error().message();
    } else if (! reply.reply().arguments().isEmpty()) {
        QString jobPath = qdbus_cast<QDBusObjectPath>(reply.reply().arguments().first()).path();
        job = Job::Ptr(new Job(jobPath, isdface.connection()), &QObject::deleteLater);
    }

    return job;
}

Job::Ptr SystemdPrivate::startTransientUnit(const QString &name, const Mode mode, const QMultiMap<QString, QVariant> &properties)
{
    //method QDBusObjectPath org.freedesktop.systemd1.Manager.StartTransientUnit(QString, QString, {D-Bus type "a(sv)"}, {D-Bus type "a(sa(sv))"})
//signature=ssa(sv)a(sa(sv))]

    UnitDBusPropertyList propertyList;
    QMapIterator<QString,QVariant> itr(properties);
    while (itr.hasNext()) {
        itr.next();
        UnitDBusProperty prop = { itr.key(), itr.value() };
        propertyList << prop;
    }

    Job::Ptr job;

    QDBusPendingReply<QDBusObjectPath> reply = isdface.StartTransientUnit(name, modeToString(mode), propertyList, ManagerDBusAuxList());
    reply.waitForFinished();

    if (reply.isError()) {
        qDebug() << Q_FUNC_INFO << reply.error().message();
    } else if (! reply.reply().arguments().isEmpty()) {
        QString jobPath = qdbus_cast<QDBusObjectPath>(reply.reply().arguments().first()).path();
        job = Job::Ptr(new Job(jobPath, isdface.connection()), &QObject::deleteLater);
    }

    return job;
}

Job::Ptr SystemdPrivate::stopUnit(const QString &name, const Systemd::Mode mode)
{
    Job::Ptr job;

    QDBusPendingReply<QDBusObjectPath> reply = isdface.StopUnit(name, modeToString(mode));
    reply.waitForFinished();

    if (reply.isError()) {
        qDebug() << reply.error().message();
    } else if (! reply.reply().arguments().isEmpty()) {
        QString jobPath = qdbus_cast<QDBusObjectPath>(reply.reply().arguments().first()).path();
        job = Job::Ptr(new Job(jobPath, isdface.connection()), &QObject::deleteLater);
    }

    return job;
}

void SystemdPrivate::resetFailedUnit(const QString& name)
{
    QDBusPendingReply<QDBusObjectPath> reply = isdface.ResetFailedUnit(name);
    reply.waitForFinished();

    if (reply.isError())
        qDebug() << reply.error().message();
}

QString SystemdPrivate::modeToString(const Systemd::Mode mode)
{
    switch(mode) {
        case Systemd::Fail: return "fail";
        case Systemd::IgnoreDependencies: return "ignore-dependencies";
        case Systemd::IgnoreRequirements: return "ignore-requirements";
        case Systemd::Isolate: return "isolate";
        case Systemd::Replace: return "replace";
        default: return QString();
    }
}

QString SystemdPrivate::whoToString(const Systemd::Who who)
{
    switch(who) {
        case Systemd::All: return "all";
        case Systemd::Control: return "control";
        case Systemd::Main: return "main";
        default: return QString();
    }
}

Systemd::Result SystemdPrivate::stringToResult(const QString &result)
{
    if ( result == "canceled" ) {
        return Systemd::Canceled;
    } else if ( result == "dependency" ) {
        return Systemd::Dependency;
    } else if ( result == "failed" ) {
        return Systemd::Failed;
    } else if ( result == "skipped" ) {
        return Systemd::Skipped;
    } else if ( result == "timeout" ) {
        return Systemd::Timeout;
    } else { // "done"
        return Systemd::Done;
    }
}

void Systemd::disableUnitFiles( const SessionType &session, const QStringList &files, const bool runtime)
{
    globalSession(session)->disableUnitFiles(files, runtime);
}

void Systemd::enableUnitFiles( const SessionType &session, const QStringList &files, const bool runtime, const bool force)
{
    globalSession(session)->enableUnitFiles(files, runtime, force);
}

Job::Ptr Systemd::getJob( const SessionType &session, const uint id)
{
    return globalSession(session)->getJob(id);
}

Unit::Ptr Systemd::getUnit( const SessionType &session, const QString &name)
{
    return globalSession(session)->getUnit(name);
}

Unit::Ptr Systemd::getUnitByPID( const SessionType &session, const uint pid)
{
    return globalSession(session)->getUnitByPID(pid);
}

QString getUnitFileState( const SessionType &session, const QString& file)
{
    return globalSession(session)->getUnitFileState(file);
}

void Systemd::killUnit( const SessionType &session, const QString& name, const Systemd::Who who, const int signal)
{
    return globalSession(session)->killUnit(name, who, signal);
}

QList<Job::Ptr> Systemd::listJobs( const SessionType &session )
{
    return globalSession(session)->listJobs();
}

QList<Unit::Ptr> Systemd::listUnits(  const SessionType &session )
{
    return globalSession(session)->listUnits();
}

QStringList Systemd::listUnitFiles(  const SessionType &session )
{
    return globalSession(session)->listUnitFiles();
}

Unit::Ptr Systemd::loadUnit( const SessionType &session, const QString &name)
{
    return globalSession(session)->loadUnit(name);
}

Job::Ptr Systemd::reloadUnit( const SessionType &session, const QString &name, const Systemd::Mode mode)
{
    return globalSession(session)->reloadUnit(name, mode);
}

Job::Ptr Systemd::restartUnit( const SessionType &session, const QString &name, const Systemd::Mode mode)
{
    return globalSession(session)->restartUnit(name, mode);
}

Job::Ptr Systemd::startUnit( const SessionType &session, const QString &name, const Systemd::Mode mode)
{
    return globalSession(session)->startUnit(name, mode);
}

Job::Ptr Systemd::startTransientUnit( const SessionType &session, const QString &name, const Mode mode, const QMultiMap<QString,QVariant> &properties)
{
    return globalSession(session)->startTransientUnit(name, mode, properties);
}

Job::Ptr Systemd::stopUnit( const SessionType &session, const QString &name, const Systemd::Mode mode)
{
    return globalSession(session)->stopUnit(name, mode);
}

void Systemd::resetFailedUnit( const SessionType &session, const QString &name)
{
    return globalSession(session)->resetFailedUnit(name);
}


Notifier* Systemd::notifier(const SessionType &session)
{
    return globalSession( session );
}

ManagerUserSession::ManagerUserSession() : SystemdPrivate(QDBusConnection::sessionBus()) {;}


ManagerSystemSession::ManagerSystemSession() : SystemdPrivate(QDBusConnection::systemBus()) {;}
