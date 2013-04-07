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

#ifndef LD_MANAGER_P_H
#define LD_MANAGER_P_H

#include "dbus/login1interface.h"

#include "ldmanager.h"

namespace Systemd {

class LogindPrivate : public Systemd::LDNotifier
{
Q_OBJECT

public:
    static const QString LD_DBUS_SERVICE;
    static const QString LD_DBUS_DAEMON_PATH;

    LogindPrivate();
    ~LogindPrivate();
    OrgFreedesktopLogin1ManagerInterface ildface;

    Systemd::Permission canHibernate();
    Systemd::Permission canHybridSleep();
    Systemd::Permission canPowerOff();
    Systemd::Permission canReboot();
    Systemd::Permission canSuspend();
    void hibernate(const bool interactive);
    void hybridSleep(const bool interactive);
    void powerOff(const bool interactive);
    void reboot(const bool interactive);
    void suspend(const bool interactive);

protected Q_SLOTS:
    void onSeatNew(const QString &id, const QDBusObjectPath &path);
    void onSeatRemoved(const QString &id, const QDBusObjectPath &path);

private:
    Systemd::Permission stringToPermission(const QString &permission);
};
}

#endif
