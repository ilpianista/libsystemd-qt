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

#ifndef SD_UNIT_H
#define SD_UNIT_H

#include <QObject>

namespace Systemd {

class Unit : public QObject
{
Q_OBJECT

public:
    explicit Unit(const QString &id, const QString &description,
                    const QString &loadState, const QString &activeState,
                    const QString &subState, const uint jobId = 0);
    virtual ~Unit();

    QString id();
    QString description();
    QString loadState();
    QString activeState();
    QString subState();
    uint jobId();

private:
    QString m_id;
    QString m_description;
    QString m_loadState;
    QString m_activeState;
    QString m_subState;
    uint m_jobId;
};
}

#endif