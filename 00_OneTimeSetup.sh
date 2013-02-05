#!/usr/bin/env bash


# This installs system-wide dependencies
#

sudo apt-get install gfortran automake cmake libtool libzip-dev build-essential

cd tools/ATLAS

mkdir MyObj
cd MyObj

../configure
make
sudo make install
