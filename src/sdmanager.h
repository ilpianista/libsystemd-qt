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

    class SDQT_EXPORT Notifier : public QObject
    {
        Q_OBJECT

    Q_SIGNALS:
        void unitNew(const QString &unitPath);
        void unitRemoved(const QString &unitPath);
        void unitFilesChanged();
    };

    // See http://www.freedesktop.org/wiki/Software/systemd/dbus for more info.

    /*
     * Disable a unit in the system. Return false if something goes wrong.
     */
    SDQT_EXPORT bool disableUnitFiles(const QStringList &files, const bool runtime);

    /*
     * Enable a unit in the system. Return false if something goes wrong.
     */
    SDQT_EXPORT bool enableUnitFiles(const QStringList &files, const bool runtime, const bool force);

    SDQT_EXPORT QString getJob(const uint id);

    SDQT_EXPORT QString getUnit(const QString &name);

    SDQT_EXPORT QString getUnitByPID(const uint pid);

    SDQT_EXPORT QList<Job*> listJobs();

    /*
     * Lists the name of all units loaded.
     */
    SDQT_EXPORT QList<Unit*> listUnits();

    /*
     * Lists the name of all unit files on disk.
     */
    SDQT_EXPORT QList<Unit*> listUnitFiles();

    SDQT_EXPORT QString loadUnit(const QString &name);

    SDQT_EXPORT bool reloadUnit(const QString &name, const Mode mode);

    SDQT_EXPORT bool restartUnit(const QString &name, const Mode mode);

    /*
     * Start a unit. Return false if something goes wrong.
     */
    SDQT_EXPORT bool startUnit(const QString &name, const Mode mode);

    /*
     * Stop a unit. Return false if something goes wrong.
     */
    SDQT_EXPORT bool stopUnit(const QString &name, const Mode mode);

    SDQT_EXPORT Notifier *notifier();
}

#endif
