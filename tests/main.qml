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
import QtQuick.Layouts 1.0

import org.qtsystemd 1.0

GridLayout {
    id: layout
    rows: 2
    width: 600
    height: 300
    columns: 4

    Text {
        Layout.row: 1
        Layout.column: 1
        Layout.columnSpan: 4
        Layout.fillWidth: true

        text: "Select a service to change its status."
    }

    TableView {
        Layout.row: 2
        Layout.rowSpan: 2
        Layout.column: 1
        Layout.fillHeight: true
        Layout.preferredWidth: 300

        System {
            id: systemd
        }

        TableViewColumn { role: "activeState"; title: "On"; width: 30
            delegate: CheckBox {
                x: 8 //ugly workaround to center the checkbox
                checked: if ( styleData.value == "active" ) true; else false
            }
        }

        TableViewColumn { role: "description"; title: "Service"; width: 250 }

        model: systemd.services
    }

    Text {
        Layout.row: 2
        Layout.column: 2
        Layout.fillWidth: true

        text: "unit file name goes here"
    }

    Button {
        Layout.row: 2
        Layout.column: 3

        text: "Start/Stop"
    }

    Button {
        Layout.row: 2
        Layout.column: 4

        text: "Enable/Disable"
    }

    TextArea {
        Layout.row: 3
        Layout.column: 2
        Layout.columnSpan: 3
        Layout.fillHeight: true
        Layout.fillWidth: true

        text: "journal log goes here"
    }
}
