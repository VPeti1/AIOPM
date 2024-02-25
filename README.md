# AIOPM
An all in one package manager for linux

# How to install
## Download the latest installer
## Type in "chmod +x installer.out"
## Type in "./installer.out"
## AIOPM is now added to PATH and you can run it by typing in 'aiopm' on your terminal

# How to uninstall
## Type in "sudo rm -r /bin/aiopm"

# How to build with g++
## Clone the repo
## Edit the code to your liking
## Type in g++ main.cpp

# What are its features?
## Manages apt,yum,pacman,aur and flatpak with (really) easy syntax

# How to enable snap functionality?
## Clone the repo 
## Call the snap funtion somewhere
For example: snap();
## Type in 'g++ main.cpp'
## The file generated now has snap support

# Known issues
## Error: ./AIOPM.out: /lib/x86_64-linux-gnu/libc.so.6: version `GLIBC_2.34' not found (required by ./AIOPM.out)
Fix: compile the source code yourself with g++. 
