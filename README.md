libsystemd-qt
=============

Qt-only wrapper for [Systemd D-Bus API](http://www.freedesktop.org/wiki/Software/systemd/dbus/).

Also supports [logind D-Bus interface](http://www.freedesktop.org/wiki/Software/systemd/logind/).

[![Flattr this git repo](http://api.flattr.com/button/flattr-badge-large.png)](https://flattr.com/submit/auto?user_id=ascarpino&url=https://github.com/ascarpino/libsystemd-qt&title=libsystemd-qt&language=&tags=systemd&category=software)

##Build and Installation##

It requires cmake >= 2.8.8 and Qt 5.x

    $ mkdir build
    $ cd build
    $ cmake ../ -DCMAKE_INSTALL_PREFIX=/usr
    $ make
    # make install

##Packages

* [PKGBUILD](https://aur.archlinux.org/packages/libsystemd-qt-git/) for Arch Linux
* [EBUILD](https://github.com/gentoo/qt/tree/master/dev-libs/libsystemd-qt) for Gentoo Linux in the Qt Overlay

##License

LGPL
