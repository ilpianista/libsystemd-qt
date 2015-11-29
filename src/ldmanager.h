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
#include "session.h"
#include "user.h"

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
    Challenge,
    Na,
    No,
    Yes
};

class SDQT_EXPORT Notifier : public QObject
{
    Q_OBJECT

Q_SIGNALS:
    void prepareForSleep(const bool active);
    void prepareForShutdown(const bool active);
    void seatNew(const Seat::Ptr &seat);
    void seatRemoved(const Seat::Ptr &seat);
    void sessionNew(const Session::Ptr &session);
    void sessionRemoved(const Session::Ptr &session);
    void userNew(const User::Ptr &user);
    void userRemoved(const User::Ptr &user);
};

/*
 * Tests whether the system supports hibernation.
 */
SDQT_EXPORT Permission canHibernate();

/*
 * Tests whether the system supports hibernation + suspension.
 */
SDQT_EXPORT Permission canHybridSleep();

/*
 * Tests whether the system can be powered off.
 */
SDQT_EXPORT Permission canPowerOff();

/*
 * Tests whether the system supports reboot.
 */
SDQT_EXPORT Permission canReboot();

/*
 * Tests whether the system supports suspension.
 */
SDQT_EXPORT Permission canSuspend();

/**
  * May be used to get a Seat for the given id.
  */
SDQT_EXPORT Seat::Ptr getSeat(const QString &id);

/**
  * May be used to get a Session for the given id.
  */
SDQT_EXPORT Session::Ptr getSession(const QString &id);

/**
  * May be used to get a Session for the given process id.
  */
SDQT_EXPORT Session::Ptr getSessionByPID(const uint &pid);

/**
  * May be used to get a User for the given user id.
  */
SDQT_EXPORT User::Ptr getUser(const uint &uid);

/**
  * May be used to get a User for the given process id.
  */
SDQT_EXPORT User::Ptr getUserByPID(const uint &pid);

/**
  * Results in the system being hibernated.
  */
SDQT_EXPORT void hibernate(const bool interactive);

/**
  * Results in the system being hibernated + suspended.
  */
SDQT_EXPORT void hybridSleep(const bool interactive);

/**
  * Returns an array with all currently available seats.
  */
SDQT_EXPORT QList<Seat::Ptr> listSeats();

/**
  * Returns an array with all currently available sessions.
  */
SDQT_EXPORT QList<Session::Ptr> listSessions();

/**
  * Returns an array with all currently available users.
  */
SDQT_EXPORT QList<User::Ptr> listUsers();

/**
  * Results in the system being powered off.
  */
SDQT_EXPORT void powerOff(const bool interactive);

/**
  * Results in the system being rebooted.
  */
SDQT_EXPORT void reboot(const bool interactive);

/**
  * Results in the system being suspended.
  */
SDQT_EXPORT void suspend(const bool interactive);

SDQT_EXPORT Notifier* notifier();
}
}

#endif
