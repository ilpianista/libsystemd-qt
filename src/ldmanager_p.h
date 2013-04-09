/*
 * Copyright (C) 2013  Andrea Scarpino <me@andreascarpino.it>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#ifndef LD_MANAGER_P_H
#define LD_MANAGER_P_H

#include "ldmanagerinterface.h"

#include "ldmanager.h"

namespace Systemd
{
namespace Logind
{
class LogindPrivate : public Notifier
{
    Q_OBJECT

public:
    static const QString LD_DBUS_SERVICE;
    static const QString LD_DBUS_DAEMON_PATH;

    LogindPrivate();
    ~LogindPrivate();
    OrgFreedesktopLogin1ManagerInterface ildface;

    Permission canHibernate();
    Permission canHybridSleep();
    Permission canPowerOff();
    Permission canReboot();
    Permission canSuspend();
    void hibernate(const bool interactive);
    void hybridSleep(const bool interactive);
    QList<Seat*> listSeats();
    void powerOff(const bool interactive);
    void reboot(const bool interactive);
    void suspend(const bool interactive);

protected Q_SLOTS:
    void onSeatNew(const QString &id, const QDBusObjectPath &seat);
    void onSeatRemoved(const QString &id, const QDBusObjectPath &seat);

private:
    Permission stringToPermission(const QString &permission);
    void init();
};
}
}

#endif
