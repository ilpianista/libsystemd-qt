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

#include "system.h"

#include "../src/sdmanager.h"

System::System(QObject* parent): QObject(parent)
{
}

Unit *unitAt(QQmlListProperty<Unit> *property, int index)
{
    return static_cast<QList<Unit*> *>(property->data)->at(index);
}

int unitsSize(QQmlListProperty<Unit> *property)
{
    return static_cast< QList<Unit *> *>(property->data)->size();
}

int System::unitsCount() const
{
    return m_units.size();
}

int System::servicesCount() const
{
    return m_services.size();
}

QQmlListProperty<Unit> System::units()
{
    m_units = Systemd::listUnits();

    return QQmlListProperty<Unit>(this, &m_units, &unitsSize, &unitAt);
}

QQmlListProperty<Unit> System::services()
{
    Q_FOREACH (Unit* unit, Systemd::listUnits()) {
        if (unit->type() == "service") {
            m_services << unit;
        }
    }

    return QQmlListProperty<Unit>(this, &m_services, &unitsSize, &unitAt);
}
