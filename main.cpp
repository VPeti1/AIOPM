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

void welcome() {
    clear
    std::cout << "Welcome to the AIOPM!" << std::endl;
    std::cout << "Avalible commands:'update','install','remove','exit' " << std::endl;
    std::cout << "Type 'flatpak' for managing flatpak" << std::endl;
}

void debianinstall() {
    std::cout << "Setting configuration for Debian" << std::endl;
    system("sudo mkdir /usr/aiopm");
    system("sudo touch /usr/aiopm/a2.cw");
    //creates files for debian
    system("sudo apt install wget python3-apt python3-debian pandoc -y");
    system("sudo wget https://gitlab.com/volian/nala/uploads/0de9fe419f0792084bb1f170a9122d65/nala_0.15.1_all.deb -o /usr/aiopm/nala.deb");
    system("sudo dpkg -i /usr/aiopm/nala.deb");
    //installs nala
}
void flatpak() {
    clear
    std::cout << "You are now managing flatpak" << std::endl;
    //Idk whose gonna use this but is here 
    std::string input;
    std::cin >> input;
    if (input == "update" || input == "Update") {
        clear
        system("flatpak update");
    }
    else if (input == "install" || input == "Install") {
            //this is defenetly not from OpenCW
            //developers never copy :)
            clear
            std::string input;
            std::cout << "Enter packages name(s): ";
            std::cin >> input;
            system(("flatpak install " + input).c_str());
    }
    else if (input == "remove" || input == "Remove") {
            clear
            std::string input;
            std::cout << "Enter packages name(s): ";
            std::cin >> input;
            system(("flatpak remove " + input).c_str());
    }

    else if (input == "exit" || input == "Exit") {
        clear
    }

    else{
        std::cout << "Invalid input! Retrying" << std::endl;
        system("read -p 'Press Enter to continue...'");
        flatpak();
    }


}
void fallback() {
    std::string input;
    std::cin >> input;
    if (input == "update" || input == "Update") {
        clear
        system("sudo apt update");
        system("sudo apt upgrade");
    }
    else if (input == "install" || input == "Install") {
            //this is defenetly not from OpenCW
            //developers never copy :)
            clear
            std::string input;
            std::cout << "Enter packages name(s): ";
            std::cin >> input;
            system(("sudo apt install " + input).c_str());
    }
    else if (input == "remove" || input == "Remove") {
            clear
            std::string input;
            std::cout << "Enter packages name(s): ";
            std::cin >> input;
            system(("sudo apt purge " + input).c_str());
    }

    else if (input == "exit" || input == "Exit") {
        clear
        std::cout << "Exiting..." << std::endl;
        system("exit");

    }
    else if (input == "flatpak" || input == "Flatpak") {
        flatpak();
    }
    

    else{
        std::cout << "Invalid input! Retrying" << std::endl;
        system("read -p 'Press Enter to continue...'");
        fallback();
    }

}



void arch() {
    std::string input;
    std::cin >> input;
    if (input == "update" || input == "Update") {
        clear
        system("sudo pacman -Syy");
        system("sudo pacman -Syu");
    }
    else if (input == "install" || input == "Install") {
            //this is defenetly not from OpenCW
            //developers never copy :)
            clear
            std::string input;
            std::cout << "Enter packages name(s): ";
            std::cin >> input;
            system(("sudo pacman -S " + input).c_str());
    }
    else if (input == "remove" || input == "Remove") {
            clear
            std::string input;
            std::cout << "Enter packages name(s): ";
            std::cin >> input;
            system(("sudo pacman -R " + input).c_str());
    }

    else if (input == "exit" || input == "Exit") {
        clear
        std::cout << "Exiting..." << std::endl;
        system("exit");

    }
    else if (input == "flatpak" || input == "Flatpak") {
        flatpak();
        arch();
    }
    

    else{
        std::cout << "Invalid input! Retrying" << std::endl;
        system("read -p 'Press Enter to continue...'");
        arch();
    }
}

void deb() {
    std::string input;
    std::cin >> input;
    if (input == "update" || input == "Update") {
        clear
        system("sudo nala update");
    }
    else if (input == "install" || input == "Install") {
            //this is defenetly not from OpenCW
            //developers never copy :)
            clear
            std::string input;
            std::cout << "Enter packages name(s): ";
            std::cin >> input;
            system(("sudo nala install " + input).c_str());
    }
    else if (input == "remove" || input == "Remove") {
            clear
            std::string input;
            std::cout << "Enter packages name(s): ";
            std::cin >> input;
            system(("sudo nala remove " + input).c_str());
    }

    else if (input == "exit" || input == "Exit") {
        clear
        std::cout << "Exiting..." << std::endl;
        system("exit");
    }
    else if (input == "fallback" || input == "Fallback") {
        fallback();
    }
    else if (input == "flatpak" || input == "Flatpak") {
        flatpak();
        deb();
    }
    

    else{
        std::cout << "Invalid input! Retrying" << std::endl;
        system("read -p 'Press Enter to continue...'");
        deb();
    }

}
void fed() {
    std::string input;
    std::cin >> input;
    if (input == "update" || input == "Update") {
        clear
        system("sudo yum update");
    }
    else if (input == "install" || input == "Install") {
            //this is defenetly not from OpenCW
            //developers never copy :)
            clear
            std::string input;
            std::cout << "Enter packages name(s): ";
            std::cin >> input;
            system(("sudo yum install " + input).c_str());
    }
    else if (input == "remove" || input == "Remove") {
            clear
            std::string input;
            std::cout << "Enter packages name(s): ";
            std::cin >> input;
            system(("sudo yum remove " + input).c_str());
    }

    else if (input == "exit" || input == "Exit") {
        clear
        std::cout << "Exiting..." << std::endl;
        system("exit");

    }
    else if (input == "flatpak" || input == "Flatpak") {
        flatpak();
        fed();
    }
    

    else{
        std::cout << "Invalid input! Retrying" << std::endl;
        system("read -p 'Press Enter to continue...'");
        fed();
    }
}

void fst() {
    //fst means first time setup
    std::cout << "Welcome to AIOPM Setup! " << std::endl;
    std::string input;
    std::cout << "What distro are you using?" << std::endl;
    std::cout << "(arch,debian,fedora)" << std::endl;
    std::cout << "(Derivatives included)" << std::endl;
    //derivatives like ubuntu,mint...
    std::cin >> input;
    if (input == "arch" || input == "Arch") {
        std::cout << "Setting configuration for Arch" << std::endl;
        system("sudo mkdir /usr/aiopm");
        system("sudo touch /usr/aiopm/a1.cw");
        //creates files for arch
    }
    if (input == "debian" || input == "Debian") {
        debianinstall();
    }
    if (input == "fedora" || input == "Fedora") {
        std::cout << "Setting configuration for Fedora" << std::endl;
        system("sudo mkdir /usr/aiopm");
        system("sudo touch /usr/aiopm/a3.cw");
        //creates files for fedora
    }
    if (input == "exit" || input == "Exit") {
        std::cout << "Exiting..." << std::endl;
        system("exit");
        //do i have to explain?????????????????
    }
    else{
        std::cout << "Invalid input! Retrying" << std::endl;
        system("read -p 'Press Enter to continue...'");
        //finally a pause command alternative yeahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
        fst();
    }
    
}
    




int main() {
    //Splash screen
    std::cout << " $$$$$$\\  $$$$$$\\  $$$$$$\\  $$$$$$$\\  $$\\      $$\\ \n"
                 "$$  __$$\\ \\_$$  _|$$  __$$\\ $$  __$$\\ $$$\\    $$$ |\n"
                 "$$ /  $$ |  $$ |  $$ /  $$ |$$ |  $$ |$$$$\\  $$$$ |\n"
                 "$$$$$$$$ |  $$ |  $$ |  $$ |$$$$$$$  |$$\\$$\\$$ $$ |\n"
                 "$$  __$$ |  $$ |  $$ |  $$ |$$  ____/ $$ \\$$$  $$ |\n"
                 "$$ |  $$ |  $$ |  $$ |  $$ |$$ |      $$ |\\$  /$$ |\n"
                 "$$ |  $$ |$$$$$$\\  $$$$$$  |$$ |      $$ | \\_/ $$ |\n"
                 "\\__|  \\__|\\______| \\______/ \\__|      \\__|     \\__|\n";
    cout << "By VPeti" << endl;
    sleep(2);
    //no more libchrono
    std::ifstream file("/usr/aiopm/a1.cw");
    //arch file
    if (file.is_open()) {
        file.close();
        welcome();
        arch();
    } else {
    //debian file
    std::ifstream file("/usr/aiopm/a2.cw");
    if (file.is_open()) {
        file.close();
        welcome();
        deb();
    }
    else {
        //fedora file
        std::ifstream file("/usr/aiopm/a3.cw");
    if (file.is_open()) {
        file.close();
        welcome();
        fed();
    }
    else {
        //no file so first time setup
        fst();
        main();
    }
    
    }
    }
}

