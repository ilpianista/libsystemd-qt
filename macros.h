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

#ifndef SD_MACROS_H
#define SD_MACROS_H

# define SD_GLOBAL_STATIC_STRUCT_NAME(NAME)
typedef void (*SdCleanUpFunction)();
class SdCleanUpGlobalStatic
{
public:
    SdCleanUpFunction func;

    inline ~SdCleanUpGlobalStatic() { func(); }
};

#define SD_GLOBAL_STATIC(TYPE, NAME) SD_GLOBAL_STATIC_WITH_ARGS(TYPE, NAME, ())
#define SD_GLOBAL_STATIC_WITH_ARGS(TYPE, NAME, ARGS)                            \
static QBasicAtomicPointer<TYPE > _sd_static_##NAME = Q_BASIC_ATOMIC_INITIALIZER(0); \
static bool _sd_static_##NAME##_destroyed;                                      \
static struct SD_GLOBAL_STATIC_STRUCT_NAME(NAME)                                \
{                                                                              \
    inline bool isDestroyed() const                                            \
    {                                                                          \
    return _sd_static_##NAME##_destroyed;                                   \
    }                                                                          \
    inline bool exists() const                                                 \
    {                                                                          \
    return _sd_static_##NAME != 0;                                          \
    }                                                                          \
    inline operator TYPE*()                                                    \
    {                                                                          \
    return operator->();                                                   \
    }                                                                          \
    inline TYPE *operator->()                                                  \
    {                                                                          \
    if (!_sd_static_##NAME) {                                               \
        if (isDestroyed()) {                                               \
            qFatal("Fatal Error: Accessed global static '%s *%s()' after destruction. " \
            "Defined at %s:%d", #TYPE, #NAME, __FILE__, __LINE__);  \
            }                                                                  \
            TYPE *x = new TYPE ARGS;                                           \
            if (!_sd_static_##NAME.testAndSetOrdered(0, x)                      \
                && _sd_static_##NAME != x ) {                                   \
                delete x;                                                      \
            } else {                                                           \
                static SdCleanUpGlobalStatic cleanUpObject = { destroy };       \
            }                                                                  \
        }                                                                      \
        return _sd_static_##NAME;                                               \
    }                                                                          \
    inline TYPE &operator*()                                                   \
    {                                                                          \
        return *operator->();                                                  \
    }                                                                          \
    static void destroy()                                                      \
    {                                                                          \
        _sd_static_##NAME##_destroyed = true;                                   \
        TYPE *x = _sd_static_##NAME;                                            \
        _sd_static_##NAME = 0;                                                  \
        delete x;                                                              \
    }                                                                          \
} NAME;

#endif
