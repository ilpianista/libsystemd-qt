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

#ifndef SD_MANAGER_P_H
#define SD_MANAGER_P_H

#include "managerinterface.h"

#include "sdmanager.h"

namespace Systemd {

class SystemdPrivate : public Notifier
{
    Q_OBJECT

public:
    static const QString SD_DBUS_SERVICE;
    static const QString SD_DBUS_DAEMON_PATH;

    SystemdPrivate();
    ~SystemdPrivate();
    OrgFreedesktopSystemd1ManagerInterface isdface;

    bool disableUnitFiles(const QStringList &files, const bool runtime);
    bool enableUnitFiles(const QStringList &files, const bool runtime, const bool force);
    Job::Ptr getJob(const uint id);
    Unit::Ptr getUnit(const QString &name);
    Unit::Ptr getUnitByPID(const uint pid);
    QString getUnitFileState(const QString &file);
    void killUnit(const QString &name, const Who who, const int signal);
    QList<Job::Ptr> listJobs();
    QList<Unit::Ptr> listUnits();
    QStringList listUnitFiles();
    Unit::Ptr loadUnit(const QString &name);
    Job::Ptr reloadUnit(const QString &name, const Mode mode);
    Job::Ptr restartUnit(const QString &name, const Mode mode);
    Job::Ptr startUnit(const QString &name, const Mode mode);
    Job::Ptr stopUnit(const QString &name, const Mode mode);

protected Q_SLOTS:
    void onUnitNew(const QString &id, const QDBusObjectPath &unit);
    void onUnitRemoved(const QString &id, const QDBusObjectPath &unit);
    void onUnitFilesChanged();

private:
    QString modeToString(const Mode mode);
    QString whoToString(const Who mode);
    void init();
};
}

#endif
