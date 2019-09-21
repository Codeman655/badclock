#!/bin/bash

# Make the binaries
make clean
make

# copy output binaries to their final destinations
sudo cp clock /usr/local/bin/
sudo cp clock.sh /usr/local/bin/
sudo cp clocklib /usr/local/lib
sudo cp profile /usr/local/bin/

# set the service for your distro (systemd)
sudo cp clock.service /etc/systemd/system
sudo systemctl enable clock
sudo systemctl start clock

