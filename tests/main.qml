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

import QtQuick 2.0
import QtQuick.Controls 1.0
import org.qtsystemd 1.0

Rectangle {
    width: 300
    height: 400

    System {
        id: systemd
    }

    TableView {
        anchors.fill: parent
        sortIndicatorVisible: true

        TableViewColumn { role: "id"; title: "Service"; width: 200
            delegate: Text {
                text: styleData.value.slice(0, -8) // Hide the .service part from the name
            }
        }

        TableViewColumn { role: "activeState"; title: "Status"; width: 40
            delegate: CheckBox {
                checked: if ( styleData.value == "active" ) true; else false
            }
        }

        model: systemd.services
    }
}
