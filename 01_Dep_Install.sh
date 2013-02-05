#!/bin/bash
# This script attempts to automatically execute the instructions in INSTALL.

# (1) Install instructions for sph2pipe_v2.5.tar.gz

if ! which wget >&/dev/null; then
   echo "This script requires you to first install wget";
   exit 1;
fi

if ! which automake >&/dev/null; then
   echo "Warning: automake not installed (IRSTLM installation will not work)"
   sleep 1
fi

if ! which libtoolize >&/dev/null && ! which glibtoolize >&/dev/null; then
   echo "Warning: libtoolize or glibtoolize not installed (IRSTLM installation probably will not work)"
   sleep 1
fi

cd tools

    cd sph2pipe_v2.5
    gcc -o sph2pipe *.c -lm  || exit 1
    cd ..
ok_sph2pipe=$?
if [ $ok_sph2pipe -ne 0 ]; then
  echo "****sph2pipe install failed."
fi

    cd irstlm
    patch -N -p0 < ../interpolatedwrite-5.60.02.patch #  || exit 1;
    ./regenerate-makefiles.sh || ./regenerate-makefiles.sh || exit 1;

   ./configure --prefix=`pwd` || exit 1

    # [ you may have to install zlib before typing make ]
    make || exit 1
    make install || exit 1
    cd ..
ok_irstlm=$?
if [ $ok_irstlm -ne 0 ]; then
  echo "****Installation of IRSTLM failed [not needed for most steps, anyway]."
fi


    cd sctk-2.4.0
    for x in src/asclite/core/recording.{h,cpp}; do # Fix a compilation error that can occur with newer compiler versions.
      sed 's/Filter::Filter/::Filter/' $x > tmpf; mv tmpf $x;
    done
    make config || exit 1
    make all || exit 1
    # Not doing the checks, they don't always succeed and it
    # it doesn't really matter.
    # make check || exit 1
    make install || exit 1
    make doc || exit 1
    cd ..
ok_sclite=$?
if [ $ok_sclite -ne 0 ]; then
  echo "****Installation of SCLITE failed [not needed anyway]."
fi

# (6) Install instructions for OpenFst

# Note that this should be compiled with g++-4.x
# You may have to install this and give the option CXX=<g++-4-binary-name>
# to configure, if it's not already the default (g++ -v will tell you).
# (on cygwin you may have to install the g++-4.0 package and give the options CXX=g++-4.exe CC=gcc-4.exe to configure).

    ( cd openfst-1.2.10/src/include/fst && patch -p0 -N <../../../../openfst.patch )
    #ignore errors in the following; it's for robustness in case
    # someone follows these instructions after the installation of openfst.
    ( cd openfst-1.2.10/include/fst && patch -p0 -N < ../../../openfst.patch )
    # Remove any existing link
    rm openfst 2>/dev/null
    ln -s openfst-1.2.10 openfst
     
    cd openfst-1.2.10
    # Choose the correct configure statement:

    # Linux or Darwin:
    if [ "`uname`" == "Linux"  ] || [ "`uname`" == "Darwin"  ]; then
        ./configure --prefix=`pwd` --enable-static --disable-shared || exit 1
    elif [ "`uname -o`" == "Cygwin"  ]; then
        which gcc-4.exe || exit 1
        ./configure --prefix=`pwd` CXX=g++-4.exe CC=gcc-4.exe --enable-static --disable-shared  || exit 1
    else
        echo "Platform detection error"
        exit 1
    fi

    # make install is equivalent to "make; make install"
    make install || exit 1
    cd ..
ok_openfst=$?
if [ $ok_openfst -ne 0 ]; then
  echo "****Installation of OpenFst failed"
fi

echo
echo Install summary:

if [ $ok_sph2pipe -eq 0 ]; then
   echo "sph2pipe:Success"
else
   echo "sph2pipe:Failure"
fi
if [ $ok_atlas -eq 0 ]; then
   echo "ATLAS:   Success [note: we install just the headers; do ./install_atlas.sh if ../src/configure fails.]"
else
   echo "ATLAS:   Failure"
fi
if [ $ok_clapack -eq 0 ]; then
   echo "CLAPACK: Success"
else
   echo "CLAPACK: Failure"
fi
if [ $ok_irstlm -eq 0 ]; then
   echo "irstlm:  Success"
else
   echo "irstlm:  Failure [optional anyway]"
fi
if [ $ok_sclite -eq 0 ]; then
   echo "sclite:  Success"
else
   echo "sclite:  Failure [optional anyway.. see INSTALL for more help]"
fi
if [ $ok_openfst -eq 0 ]; then
   echo "openfst: Success"
else
   echo "openfst: Failure"
fi


