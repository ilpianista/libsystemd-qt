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
import org.qtsystemd 1.0

Rectangle {
    width: 250
    height: 400

    System {
        id: systemd
    }

    Component {
        id: unitDelegate

        Row {
            spacing: 10
            Text { text: id }
            Loader { sourceComponent: columnSeparator; height: parent.height }
            Text { text: type }
            Loader { sourceComponent: columnSeparator; height: parent.height }
            Text { text: loadState }
            Loader { sourceComponent: columnSeparator; height: parent.height }
            Text { text: activeState }

            Component {
                id: columnSeparator
                Rectangle {
                    width: 1
                    color: "black"
                    opacity: 0.3
                }
            }
        }
    }

    ListView {
        anchors.fill: parent
        model: systemd.units
        delegate: unitDelegate
    }
}
