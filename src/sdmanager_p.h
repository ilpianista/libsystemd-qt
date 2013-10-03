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
    QString getJob(const uint id);
    QString getUnit(const QString &name);
    QString getUnitByPID(const uint pid);
    QList<Job*> listJobs();
    QList<Unit*> listUnits();
    QStringList listUnitFiles();
    Unit* loadUnit(const QString &name);
    bool reloadUnit(const QString &name, const Mode mode);
    bool restartUnit(const QString &name, const Mode mode);
    bool startUnit(const QString &name, const Mode mode);
    bool stopUnit(const QString &name, const Mode mode);

protected Q_SLOTS:
    void onUnitNew(const QString &id, const QDBusObjectPath &unit);
    void onUnitRemoved(const QString &id, const QDBusObjectPath &unit);
    void onUnitFilesChanged();

private:
    QString modeToString(const Mode mode);
    void init();
};
}

#endif
