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
    std::string input;
    std::cout << "What distro are you using?" << std::endl;
    std::cout << "(arch,debian,fedora,opensuse or void)" << std::endl;
    std::cout << "(Derivatives included)" << std::endl;
    //derivatives like ubuntu,mint...
    std::cin >> input;
    if (input == "arch" || input == "Arch") {
        system("sudo pacman -S git wget gcc");
        std::cout << "Setting configuration for Arch" << std::endl;
        system("sudo touch /etc/aiopm/a1.cw");
    }
    else if (input == "debian" || input == "Debian") {
        system("sudo apt-get install git wget build-essential");
        std::cout << "Setting configuration for Debian" << std::endl;
        system("sudo touch /etc/aiopm/a2.cw");
    }
    else if (input == "fedora" || input == "Fedora") {
        system("sudo dnf install git wget gcc-c++");
        std::cout << "Setting configuration for Fedora" << std::endl;
        system("sudo touch /etc/aiopm/a3.cw");
    }
    else if (input == "opensuse" || input == "Opensuse") {
        system("sudo zypper install git wget gcc-c++");
        std::cout << "Setting configuration for Opensuse" << std::endl;
        system("sudo touch /etc/aiopm/a4.cw");
    }
    else if (input == "void" || input == "Void") {
        system("sudo xbps-install git wget gcc");
        std::cout << "Setting configuration for Void linux" << std::endl;
        system("sudo touch /etc/aiopm/a5.cw");
    }
    else {
        std::cout << "Invalid input\n";
        dw();
    }
    
}

int main() {
    system("sudo rm -rf /usr/aiopmi");
    clear;
    std::cout << "AIOPM Installer" << std::endl;
    std::cout << "By VPeti" << std::endl;
    sleep(2);
    dw();
    system("read -p 'Press Enter to continue...'");
    system("sudo mkdir /usr/aiopmi/");
    system("sudo mkdir /etc/aiopm/");
    system("sudo wget https://raw.githubusercontent.com/VPeti1/AIOPM/main/main.cpp -O /usr/aiopmi/pm.cpp");
    system("sudo g++ /usr/aiopmi/pm.cpp -o /usr/bin/aiopm");
    system("sudo chmod +x /usr/bin/aiopm");
    std::cout << "AIOPM Installer Completed!" << std::endl;
    system("sudo rm -rf /usr/aiopmi");
}