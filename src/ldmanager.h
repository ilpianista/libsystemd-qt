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

#ifndef LD_MANAGER_H
#define LD_MANAGER_H

#include <QObject>

#include "QtSystemd-export.h"
#include "seat.h"

/**
 * This class allows querying the underlying system.
 *
 * It is the unique entry point for logind.
 *
 * Note that it is implemented as a singleton
 */
namespace Systemd
{
namespace Logind
{
    enum Permission {
        Na,
        Yes,
        No,
        Challenge,
        Unknown
    };

    class SDQT_EXPORT Notifier : public QObject
    {
        Q_OBJECT

    Q_SIGNALS:
        void prepareForSleep(const bool active);
        void prepareForShutdown(const bool active);
        void seatNew(const QString &seatPath);
        void seatRemoved(const QString &seatPath);
    };

    SDQT_EXPORT Permission canHibernate();

    SDQT_EXPORT Permission canHybridSleep();

    SDQT_EXPORT Permission canPowerOff();

    SDQT_EXPORT Permission canReboot();

    SDQT_EXPORT Permission canSuspend();

    SDQT_EXPORT void hibernate(const bool interactive);

    SDQT_EXPORT void hybridSleep(const bool interactive);

    SDQT_EXPORT QList<Seat *> listSeats();

    SDQT_EXPORT void powerOff(const bool interactive);

    SDQT_EXPORT void reboot(const bool interactive);

    SDQT_EXPORT void suspend(const bool interactive);

    SDQT_EXPORT Notifier* notifier();
}
}

#endif
