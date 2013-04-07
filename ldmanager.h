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

#ifndef LD_MANAGER_H
#define LD_MANAGER_H

#include "QtSystemd-export.h"

#include <QObject>

/**
 * This class allows querying the underlying system.
 *
 * It is the unique entry point for logind.
 *
 * Note that it is implemented as a singleton
 */
namespace Systemd {

    enum Permission {
        Na,
        Yes,
        No,
        Challenge,
        Unknown
    };

    class SDQT_EXPORT LDNotifier : public QObject
    {
    Q_OBJECT
    Q_SIGNALS:
        void seatNew(const QString &id);
        void seatRemoved(const QString &id);
    };

    SDQT_EXPORT Systemd::Permission canHibernate();

    SDQT_EXPORT Systemd::Permission canHybridSleep();

    SDQT_EXPORT Systemd::Permission canPowerOff();

    SDQT_EXPORT Systemd::Permission canReboot();

    SDQT_EXPORT Systemd::Permission canSuspend();

    SDQT_EXPORT void hibernate(const bool interactive);

    SDQT_EXPORT void hybridSleep(const bool interactive);

    SDQT_EXPORT void powerOff(const bool interactive);

    SDQT_EXPORT void reboot(const bool interactive);

    SDQT_EXPORT void suspend(const bool interactive);

    SDQT_EXPORT LDNotifier* ldnotifier();
}

#endif
