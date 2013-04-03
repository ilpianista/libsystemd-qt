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

#ifndef SD_MANAGER_P_H
#define SD_MANAGER_P_H

#include "dbus/managerinterface.h"
#include "dbus/login1interface.h"

#include "manager.h"

namespace Systemd {

    class SystemdPrivate : public QObject
    {
    Q_OBJECT

    public:
        static const QString SD_DBUS_SERVICE;
        static const QString SD_DBUS_DAEMON_PATH;
        static const QString LD_DBUS_SERVICE;
        static const QString LD_DBUS_DAEMON_PATH;

        SystemdPrivate();
        ~SystemdPrivate();
        OrgFreedesktopSystemd1ManagerInterface isdface;
        OrgFreedesktopLogin1ManagerInterface ildface;

        bool disableUnitFiles(const QStringList &files, bool runtime);
        bool enableUnitFiles(const QStringList &files, bool runtime, bool force);
        QString getUnit(const QString &name);
        QString getUnitByPID(const uint pid);
        QList<Systemd::Job*> listJobs();
        QList<Systemd::Unit*> listUnits();
        QString loadUnit(const QString &name);
        bool reloadUnit(const QString &name, const Systemd::Mode mode);
        bool restartUnit(const QString &name, const Systemd::Mode mode);
        bool startUnit(const QString &name, const Systemd::Mode mode);
        bool stopUnit(const QString &name, const Systemd::Mode mode);

    private:
        QString modeToString(const Systemd::Mode mode);
    };
}

#endif
