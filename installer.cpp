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
    std::cout << "Enter your Linux distribution (arch/debian/fedora): ";
    std::cin >> distro;
    if (distro == "arch") {
        system("sudo pacman -S git wget");
    } else if (distro == "debian") {
        system("sudo apt-get install git wget");
    } else if (distro == "fedora") {
        system("sudo dnf install git wget");
    }
    else if (distro == "skip") {

    }
     else {
        std::cout << "Unsupported distribution. Please choose arch, debian, or fedora." << std::endl;
    }
}

int main() {
    clear;
    std::cout << "AIOPM Installer" << std::endl;
    std::cout << "By VPeti" << std::endl;
    sleep(2);
    dw();
    system("read -p 'Press Enter to continue...'");
    system("sudo wget https://raw.githubusercontent.com/VPeti1/CWAcces/main/AIOPM.out -O /bin/aiopm");
    system("sudo chmod +x /bin/aiopm");
    std::cout << "AIOPM Installer Completed!" << std::endl;
    system("exit");
}