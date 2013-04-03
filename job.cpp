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

#include "job.h"

Systemd::Job::Job(const uint id, const QString &unitId, const QString& type,
                  const QString& state) :
                  m_id(id),
                  m_unitId(unitId),
                  m_type(type),
                  m_state(state)
{
}

Systemd::Job::~Job()
{
}

uint Systemd::Job::id()
{
    return m_id;
}

QString Systemd::Job::state()
{
    return m_state;
}

QString Systemd::Job::type()
{
    return m_type;
}

QString Systemd::Job::unitId()
{
    return m_unitId;
}

