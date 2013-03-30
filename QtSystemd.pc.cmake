prefix=@CMAKE_INSTALL_PREFIX@
exec_prefix=${prefix}
libdir=@CMAKE_INSTALL_PREFIX@/lib@LIB_SUFFIX@
includedir=${prefix}/include

Name: QtSystemd
Description: Convenience Qt library for Systemd
Version: @VERSION@

Requires: systemd
Cflags: -I${includedir} @CMAKE_INCLUDE_PATH@
Libs: -L${libdir} -lQtSystemd @CMAKE_LIBRARY_PATH@
