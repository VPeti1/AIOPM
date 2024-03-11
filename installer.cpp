#include <chrono>
#include <cstdlib>
#include <iostream>
#include <string>
#include <thread>
#include <fstream>
#include <stdio.h>
#include <unistd.h>
#define clear std::cout << "\033[2J\033[1;1H";
using namespace std;


void dw() {
    std::string distro;
    std::cout << "Enter your Linux distribution (arch/debian/fedora/void/opensuse): ";
    std::cin >> distro;
    if (distro == "arch") {
        system("sudo pacman -S git wget");
    } else if (distro == "debian") {
        system("sudo apt-get install git wget");
    } else if (distro == "fedora") {
        system("sudo dnf install git wget");
    }
     else if (distro == "void") {
        system("sudo xbps-install git wget gcc");
    }
     else if (distro == "opensuse") {
        system("sudo zypper install git wget gcc-c++");
    }
     else {
        std::cout << "Unsupported distribution!" << std::endl;
        dw();
    }
}

int main() {
    system("sudo rm -rf /usr/aiopm");
    system("sudo rm -rf /usr/aiopmi");
    clear;
    std::cout << "AIOPM Installer" << std::endl;
    std::cout << "By VPeti" << std::endl;
    sleep(2);
    dw();
    system("read -p 'Press Enter to continue...'");
    system("sudo mkdir /usr/aiopmi/");
    system("sudo mkdir /usr/aiopm/");
    system("sudo wget https://raw.githubusercontent.com/VPeti1/AIOPM/main/main.cpp -O /usr/aiopmi/pm.cpp");
    system("sudo g++ /usr/aiopmi/pm.cpp -o /bin/aiopm");
    system("sudo chmod +x /bin/aiopm");
    std::cout << "AIOPM Installer Completed!" << std::endl;
    system("exit");
}