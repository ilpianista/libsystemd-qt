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
 * Note that it is implemented as a singleton
 */
namespace Systemd
{
    enum Mode {
        Replace,
        Fail,
        Isolate,
        IgnoreDependencies,
        IgnoreRequirements
    };

    enum Result {
        Done,
        Canceled,
        Timeout,
        Failed,
        Dependency,
        Skipped
    };

    enum Who {
        Main,
        Control,
        All
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
        void jobRemoved(const QString &jobPath, const QString &unit, const Systemd::Result result);

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
     * Disables one or more units in the system, i.e. removes all symlinks to
     * them in /etc and /run.
     */
    SDQT_EXPORT void disableUnitFiles(const QStringList &files, const bool runtime);

    /*
     * May be used to enable one or more units in the system (by creating
     * symlinks to them in /etc or /run).
     */
    SDQT_EXPORT void enableUnitFiles(const QStringList &files, const bool runtime, const bool force);

    /*
     * Returns the job object path for a specific job, identified by its id.
     */
    SDQT_EXPORT Job::Ptr getJob(const uint id);

    /*
     * May be used to get the unit object path for a unit name. It takes the
     * unit name and returns the object path. If a unit has not been loaded
     * yet by this name this call will fail.
     */
    SDQT_EXPORT Unit::Ptr getUnit(const QString &name);

    /*
     * May be used to get the unit object path of the unit a process ID
     * belongs to. Takes a Unix PID and returns the object path. The PID must
     * refer to an existing process of the system.
     */
    SDQT_EXPORT Unit::Ptr getUnitByPID(const uint pid);

    /*
     * Returns the current enablement status of specific unit file.
     */
    SDQT_EXPORT QString getUnitFileState(const QString &file);

    /*
     * May be used to kill (i.e. send a signal to) all processes of a unit.
     */
    SDQT_EXPORT void killUnit(const QString &name, const Systemd::Who who, const int signal);

    /*
     * Returns an array with all currently queued jobs.
     */
    SDQT_EXPORT QList<Job::Ptr> listJobs();

    /*
     * Returns an array with all currently loaded units. Note that units may
     * be known by multiple names at the same name, and hence there might be
     * more unit names loaded than actual units behind them.
     */
    SDQT_EXPORT QList<Unit::Ptr> listUnits();

    /*
     * Returns an array of unit names. Note that listUnit() returns a list of
     * units currently loaded into memory, while listUnitFiles() returns a
     * list of unit files that could be found on disk.
     */
    SDQT_EXPORT QStringList listUnitFiles();

    /*
     * Is similar to getUnit() but will load the unit from disk if possible.
     */
    SDQT_EXPORT Unit::Ptr loadUnit(const QString &name);

    /*
     * May be used to reload a unit, and takes similar arguments as
     * startUnit(). Reloading is done only if the unit is already running and
     * fails otherwise.
     */
    SDQT_EXPORT Job::Ptr reloadUnit(const QString &name, const Mode mode);

    /*
     * Is similar to reloadUnit() but will restart the unit. If a service is
     * restarted that isn't running it will be started, unless the "Try"
     * flavor is used in which case a service that isn't running is not
     * affected by the restart.
     */
    SDQT_EXPORT Job::Ptr restartUnit(const QString &name, const Mode mode);

    /*
     * Enqeues a start job, and possibly depending jobs. Takes the unit to
     * activate, plus a mode string.
     */
    SDQT_EXPORT Job::Ptr startUnit(const QString &name, const Mode mode);

    /*
     * Is similar to startUnit() but stops the specified unit rather than
     * starting it. Note that "isolate" mode is invalid for this call.
     */
    SDQT_EXPORT Job::Ptr stopUnit(const QString &name, const Mode mode);

    SDQT_EXPORT Notifier* notifier();
}

#endif
