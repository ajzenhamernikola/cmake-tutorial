export CC=/usr/bin/gcc-8
export CXX=/usr/bin/g++-8

rm -Rf build bin
mkdir build 
cd build
cmake .. -DCMAKE_INSTALL_PREFIX="../" -G "Unix Makefiles"
make
make install
cd ..
