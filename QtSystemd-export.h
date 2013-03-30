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

#ifndef SDQT_EXPORT_H
#define SDQT_EXPORT_H

/** \file QtSystemd-export.h
 \ brief Contains Macr*os for exporting symbols
 
 This file contains macros needed for exporting/importing symbols
 */

#include <QtCore/QtGlobal>

#ifndef SDQT_EXPORT
# if defined(MAKE_SDQT_LIB)
/* We are building this library */
#  define SDQT_EXPORT Q_DECL_EXPORT
# else
/* We are using this library */
#  define SDQT_EXPORT Q_DECL_IMPORT
# endif
#endif

#endif /*SDQT_EXPORT_H*/