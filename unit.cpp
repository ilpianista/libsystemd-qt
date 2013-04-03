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

#include "unit.h"

Systemd::Unit::Unit(const QString& id, const QString& description,
                    const QString& loadState, const QString& activeState,
                    const QString& subState, const uint jobId) :
                    m_id(id),
                    m_description(description),
                    m_loadState(loadState),
                    m_activeState(activeState),
                    m_subState(subState),
                    m_jobId(jobId)
{
}

Systemd::Unit::~Unit()
{
}

QString Systemd::Unit::activeState()
{
    return m_activeState;
}

QString Systemd::Unit::description()
{
    return m_description;
}

QString Systemd::Unit::id()
{
    return m_id;
}

uint Systemd::Unit::jobId()
{
    return m_jobId;
}

QString Systemd::Unit::loadState()
{
    return m_loadState;
}

QString Systemd::Unit::subState()
{
    return m_subState;
}
