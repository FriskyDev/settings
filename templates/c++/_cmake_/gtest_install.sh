#!/usr/bin/env sh
sudo apt-get install cmake libgtest-dev google-mock

cd /usr/src/gtest
sudo cmake .
sudo make
sudo make install

cd /usr/src/gmock
sudo mkdir build
cd build
sudo cmake ..
sudo make
sudo make install
