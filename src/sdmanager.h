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

#ifndef SD_MANAGER_H
#define SD_MANAGER_H

#include <QStringList>

#include "QtSystemd-export.h"

#include "job.h"
#include "unit.h"

/**
 * This class allows querying the underlying system.
 *
 * It is the unique entry point for systemd.
 *
 * Note that it is implemented as a singleton.
 */
namespace Systemd
{
    enum SessionType {
        System,
        User
    };

    class SDQT_EXPORT Notifier : public QObject
    {
        Q_OBJECT

    Q_SIGNALS:
        /*
         * Sent out each time a new job is queued.
         */
        void jobNew(const QString &jobPath, const QString &unit);

        /*
         * Sent out each time a new job is dequeued.
         */
        void jobRemoved(const QString &jobPath, const QString &unit, const Unit::Result result);

        /*
         * Is sent out immediately before a daemon reload is done (with the
         * boolean parameter set to True) and after a daemon reload is completed
         * (with the boolean parameter set to False).
         */
        void reloading(const bool active);

        /*
         * Sent out each time a new unit is loaded.
         */
        void unitNew(const QString &unitPath);

        /*
         * Sent out each time a new unit is unloaded.
         */
        void unitRemoved(const QString &unitPath);

        /*
         * Sent out each time the list of enabled or masked unit files on disk
         * have changed.
         */
        void unitFilesChanged();
    };

    // See http://www.freedesktop.org/wiki/Software/systemd/dbus for more info.

    /*
     * Cancels a specific job identified by its numer ID. This operation is also
     * available in the Cancel() method of Job objects (see below), and exists
     * primarily to reduce the necessary round trips to execute this operation.
     * Note that this will not have any effect on jobs whose execution has
     * already begun.
     */
    SDQT_EXPORT void cancelJob(const SessionType &session, const uint id);

    /*
     * Flushes the job queue, removing all jobs that are still queued. Note that
     * this does not have any effect on jobs whose execution has already begun,
     * it only flushes jobs that are queued and have not yet begun execution.
     */
    SDQT_EXPORT void clearJobs(const SessionType &session);

    /*
     * Disables one or more units in the system, i.e. removes all symlinks to
     * them in /etc and /run.
     */
    SDQT_EXPORT void disableUnitFiles(const SessionType &session, const QStringList &files, const bool runtime);

    /*
     * May be used to enable one or more units in the system (by creating
     * symlinks to them in /etc or /run).
     */
    SDQT_EXPORT void enableUnitFiles(const SessionType &session, const QStringList &files, const bool runtime, const bool force);

    /*
     * Returns the job object path for a specific job, identified by its id.
     */
    SDQT_EXPORT Job::Ptr getJob(const SessionType &session, const uint id);

    /*
     * May be used to get the unit object path for a unit name. It takes the
     * unit name and returns the object path. If a unit has not been loaded
     * yet by this name this call will fail.
     */
    SDQT_EXPORT Unit::Ptr getUnit(const SessionType &session, const QString &name);

    /*
     * May be used to get the unit object path of the unit a process ID
     * belongs to. Takes a Unix PID and returns the object path. The PID must
     * refer to an existing process of the system.
     */
    SDQT_EXPORT Unit::Ptr getUnitByPID(const SessionType &session, const uint pid);

    /*
     * Returns the current enablement status of specific unit file.
     */
    SDQT_EXPORT QString getUnitFileState(const SessionType &session, const QString &file);

    /*
     * May be used to kill (i.e. send a signal to) all processes of a unit.
     */
    SDQT_EXPORT void killUnit(const SessionType &session, const QString &name, const Unit::Who &who, const int signal);

    /*
     * Returns an array with all currently queued jobs.
     */
    SDQT_EXPORT QList<Job::Ptr> listJobs(const SessionType &session);

    /*
     * Returns an array with all currently loaded units. Note that units may
     * be known by multiple names at the same name, and hence there might be
     * more unit names loaded than actual units behind them.
     */
    SDQT_EXPORT QList<Unit::Ptr> listUnits(const SessionType &session);

    /*
     * Returns an array of unit names. Note that listUnit() returns a list of
     * units currently loaded into memory, while listUnitFiles() returns a
     * list of unit files that could be found on disk.
     */
    SDQT_EXPORT QStringList listUnitFiles(const SessionType &session);

    /*
     * Is similar to getUnit() but will load the unit from disk if possible.
     */
    SDQT_EXPORT Unit::Ptr loadUnit(const SessionType &session, const QString &name);

    /*
     * May be invoked to reexecute the main manager process. It will serialize
     * its state, reexecute, and deserizalize the state again. This is useful
     * for upgrades and is a more comprehensive version of Reload().
     */
    SDQT_EXPORT void reexecute(const SessionType &session);

    /*
     * May be invoked to reload all unit files.
     */
    SDQT_EXPORT void reload(const SessionType &session);

    /*
     * May be used to reload a unit, and takes similar arguments as
     * startUnit(). Reloading is done only if the unit is already running and
     * fails otherwise.
     */
    SDQT_EXPORT Job::Ptr reloadUnit(const SessionType &session, const QString &name, const Unit::Mode &mode);

    /*
     * Resets the "failed" state of all units.
     */
    SDQT_EXPORT void resetFailed(const SessionType &session);

    /*
     * Resets the "failed" state of a specific unit.
     */
    SDQT_EXPORT void resetFailedUnit(const SessionType &session, const QString &name);

    /*
     * Is similar to reloadUnit() but will restart the unit. If a service is
     * restarted that isn't running it will be started, unless the "Try"
     * flavor is used in which case a service that isn't running is not
     * affected by the restart.
     */
    SDQT_EXPORT Job::Ptr restartUnit(const SessionType &session, const QString &name, const Unit::Mode &mode);

    /*
     * May be used to modify certain unit properties at runtime. Not all
     * properties may be changed at runtime, but many resource management
     * settings may.
     */
    SDQT_EXPORT void setUnitProperties(const SessionType &session, const QString &name, const bool runtime, const QVariantMap &properties);

    /*
     * May be used to create and start a transient unit, which will be released
     * as soon as it is not running or referenced anymore or the system is
     * rebooted.
     */
    SDQT_EXPORT Job::Ptr startTransientUnit(const SessionType &session, const QString &name, const Unit::Mode &mode, const QVariantMap &properties);

    /*
     * Enqeues a start job, and possibly depending jobs. Takes the unit to
     * activate, plus a mode string.
     */
    SDQT_EXPORT Job::Ptr startUnit(const SessionType &session, const QString &name, const Unit::Mode &mode);

    /*
     * Is similar to startUnit() but stops the specified unit rather than
     * starting it. Note that "isolate" mode is invalid for this call.
     */
    SDQT_EXPORT Job::Ptr stopUnit(const SessionType &session, const QString &name, const Unit::Mode &mode);

    SDQT_EXPORT Notifier* notifier(const SessionType &session);
}

#endif
