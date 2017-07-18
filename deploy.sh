#! /bin/sh

home_app=~/app

home_flat=${home_app}/flat

./configure --prefix=${home_flat}

if test -d ${home_flat}; then
    rm -rf ${home_flat}
fi

make install

make distclean
