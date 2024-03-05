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
    std::cout << "Type 'snap' for managing snap" << std::endl;
    std::cout << "Type 'pip' for managing pip" << std::endl;
}
void archwelcome() {
    std::cout << "Type in 'aur' to download packages from the AUR" << std::endl;
    std::cout << "Type in 'mremove' to remove multiple packages ()" << std::endl;
}

void aur() {
    clear
    //Aur downloader 
    std::string input;
    std::cout << "Enter packages name(s): ";
    std::cin >> input;
    if (input == "exit" || input == "Exit") {
        std::cout << "Exiting..." << std::endl;
    }
    else {
    std::cout << "Installing " << input << "..." << std::endl;
    //makes sure the directory is writable
    system("sudo chown -R $USER /usr/aiopm");
    //clones the repository to /usr/aiopm/nameoftherepo
    system(("git clone https://aur.archlinux.org/" + input + ".git " + "/usr/aiopm/" + input ).c_str());
    //makes the package
    system(("cd /usr/aiopm/" + input + " && makepkg -si").c_str());
    std::cout << "Installation complete!" << std::endl;
    system("read -p 'Press Enter to continue...'");
    }
    
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
    std::cout << "Avalible commands:'update','install','remove','exit' " << std::endl;
    //Idk whose gonna use this but is here 
    std::string input;
    std::cin >> input;
    if (input == "update" || input == "Update") {
        clear
        system("flatpak update");
        flatpak();
    }
    else if (input == "install" || input == "Install") {
            //this is defenetly not from OpenCW
            //developers never copy :)
            clear
            std::string input;
            std::cout << "Enter packages name(s): ";
            std::cin >> input;
            system(("flatpak install " + input).c_str());
            flatpak();
    }
    else if (input == "remove" || input == "Remove") {
            clear
            std::string input;
            std::cout << "Enter packages name(s): ";
            std::cin >> input;
            system(("flatpak remove " + input).c_str());
            flatpak();
    }

    else if (input == "exit" || input == "Exit") {
        clear
    }

    else{
        std::cout << "Invalid input! Retrying" << std::endl;
        system("read -p 'Press Enter to continue...'");
        welcome();
        flatpak();
    }


}

void pip() {
    clear
    std::cout << "You are now managing pip" << std::endl;
    std::cout << "Avalible commands:'install','remove','exit' " << std::endl;
    //Idk whose gonna use this but is here 
    std::string input;
    std::cin >> input;
    if (input == "install" || input == "Install") {
            //this is defenetly not from OpenCW
            //developers never copy :)
            clear
            std::string input;
            std::cout << "Enter packages name(s): ";
            std::cin >> input;
            //It dosnt break packages it just bypasses pep668
            system(("pip install --break-system-packages " + input).c_str());
            pip();
    }
    else if (input == "remove" || input == "Remove") {
            clear
            std::string input;
            std::cout << "Enter packages name(s): ";
            std::cin >> input;
            system(("pip uninstall --break-system-packages " + input).c_str());
            pip();
    }

    else if (input == "exit" || input == "Exit") {
        clear
    }

    else{
        std::cout << "Invalid input! Retrying" << std::endl;
        system("read -p 'Press Enter to continue...'");
        pip();
    }


}

void snap() {
    clear
    std::cout << "You are now managing snap" << std::endl;
    std::cout << "Avalible commands:'install','remove','exit' " << std::endl;
    //Idk whose gonna use either this but is here 
    std::string input;
    std::cin >> input;
    if (input == "install" || input == "Install") {
            //this is defenetly not from OpenCW
            //developers never copy :)
            clear
            std::string input;
            std::cout << "Enter packages name(s): ";
            std::cin >> input;
            system(("sudo snap install " + input).c_str());
            snap();
    }
    else if (input == "remove" || input == "Remove") {
            clear
            std::string input;
            std::cout << "Enter packages name(s): ";
            std::cin >> input;
            system(("sudo snap remove " + input).c_str());
            snap();
    }

    else if (input == "exit" || input == "Exit") {
        clear
    }

    else{
        std::cout << "Invalid input! Retrying" << std::endl;
        system("read -p 'Press Enter to continue...'");
        snap();
    }

}

void voidl() {
     std::string input;
    std::cin >> input;
    if (input == "update" || input == "Update") {
        clear
        system("sudo xbps-install -Su");
        welcome();
        voidl();
    }
    else if (input == "install" || input == "Install") {
            //this is defenetly not from OpenCW
            //developers never copy :)
            clear
            std::string input;
            std::cout << "Enter packages name(s): ";
            std::cin >> input;
            system(("sudo xbps-install " + input).c_str());
            welcome();
            voidl();
    }
    else if (input == "remove" || input == "Remove") {
            clear
            std::string input;
            std::cout << "Enter packages name(s): ";
            std::cin >> input;
            system(("sudo xbps-remove " + input).c_str());
            welcome();
            voidl();
    }

    else if (input == "exit" || input == "Exit") {
        clear
        std::cout << "Exiting..." << std::endl;
        system("exit");

    }
    else if (input == "flatpak" || input == "Flatpak") {
        flatpak();
        welcome();
        voidl();
    }
    else if (input == "pip" || input == "Pip") {
        pip();
        welcome();
        voidl();
    }
    else if (input == "snap" || input == "Snap") {
        snap();
        welcome();
        voidl();
    }
    

    else{
        std::cout << "Invalid input! Retrying" << std::endl;
        system("read -p 'Press Enter to continue...'");
        welcome();
        voidl();
    }
}

void opensuse() {
    std::string input;
    std::cin >> input;
    if (input == "update" || input == "Update") {
        clear
        system("sudo zypper update");
        welcome();
        opensuse();
    }
    else if (input == "install" || input == "Install") {
            //this is defenetly not from OpenCW
            //developers never copy :)
            clear
            std::string input;
            std::cout << "Enter packages name(s): ";
            std::cin >> input;
            system(("sudo zypper install " + input).c_str());
            welcome();
            opensuse();
    }
    else if (input == "remove" || input == "Remove") {
            clear
            std::string input;
            std::cout << "Enter packages name(s): ";
            std::cin >> input;
            system(("sudo zypper remove " + input).c_str());
            welcome();
            opensuse();
    }

    else if (input == "exit" || input == "Exit") {
        clear
        std::cout << "Exiting..." << std::endl;
        system("exit");

    }
    else if (input == "flatpak" || input == "Flatpak") {
        flatpak();
        welcome();
        opensuse();
    }
    else if (input == "pip" || input == "Pip") {
        pip();
        welcome();
        opensuse();
    }
    else if (input == "snap" || input == "Snap") {
        snap();
        welcome();
        opensuse();
    }
    

    else{
        std::cout << "Invalid input! Retrying" << std::endl;
        system("read -p 'Press Enter to continue...'");
        welcome();
        opensuse();
    }
}



void arch() {
    std::string input;
    std::cin >> input;
    if (input == "update" || input == "Update") {
        clear
        system("sudo pacman -Syy");
        system("sudo pacman -Syu");
        welcome();
        archwelcome();
        arch();
    }
    else if (input == "install" || input == "Install") {
            //this is defenetly not from OpenCW
            //developers never copy :)
            clear
            std::string input;
            std::cout << "Enter packages name(s): ";
            std::cin >> input;
            system(("sudo pacman -S " + input).c_str());
            welcome();
            archwelcome();
            arch();
    }
    else if (input == "remove" || input == "Remove") {
            clear
            std::string input;
            std::cout << "Enter packages name(s): ";
            std::cin >> input;
            system(("sudo pacman -R " + input).c_str());
            welcome();
            archwelcome();
            arch();
    }
    else if (input == "aur" || input == "AUR") {
        aur();
        welcome();
        archwelcome();
        arch();
    }
    else if (input == "pip" || input == "Pip") {
        pip();
        welcome();
        archwelcome();
        arch();
    }
    else if (input == "snap" || input == "Snap") {
        snap();
        welcome();
        archwelcome();
        arch();
    }

    else if (input == "mremove" || input == "Mremove") {
        clear
        std::string input;
        std::cout << "Enter packages name(s): ";
        std::cin >> input;
        system((" sudo pacman -R $(pacman -Qq | grep " + input + ")").c_str());
        welcome();
        archwelcome();
        arch();
    }
    

    else if (input == "exit" || input == "Exit") {
        clear
        std::cout << "Exiting..." << std::endl;
        system("exit");

    }
    else if (input == "flatpak" || input == "Flatpak") {
        flatpak();
        welcome();
        archwelcome();
        arch();
    }
    

    else{
        std::cout << "Invalid input! Retrying" << std::endl;
        system("read -p 'Press Enter to continue...'");
        welcome();
        archwelcome();
        arch();
    }
}

void deb() {
    std::string input;
    std::cin >> input;
    if (input == "update" || input == "Update") {
        clear
        system("sudo nala update");
        welcome();
        deb();
    }
    else if (input == "install" || input == "Install") {
            //this is defenetly not from OpenCW
            //developers never copy :)
            clear
            std::string input;
            std::cout << "Enter packages name(s): ";
            std::cin >> input;
            system(("sudo nala install " + input).c_str());
            welcome();
            deb();
    }
    else if (input == "remove" || input == "Remove") {
            clear
            std::string input;
            std::cout << "Enter packages name(s): ";
            std::cin >> input;
            system(("sudo nala remove " + input).c_str());
            welcome();
            deb();
    }

    else if (input == "exit" || input == "Exit") {
        clear
        std::cout << "Exiting..." << std::endl;
        system("exit");
    }
    else if (input == "flatpak" || input == "Flatpak") {
        flatpak();
        welcome();
        deb();
    }
    else if (input == "snap" || input == "Snap") {
        snap();
        welcome();
        deb();
    }
    else if (input == "pip" || input == "Pip") {
        pip();
        welcome();
        deb();
    }
    

    else{
        std::cout << "Invalid input! Retrying" << std::endl;
        system("read -p 'Press Enter to continue...'");
        welcome();
        deb();
    }

}
void fed() {
    std::string input;
    std::cin >> input;
    if (input == "update" || input == "Update") {
        clear
        system("sudo yum update");
        welcome();
        fed();
    }
    else if (input == "install" || input == "Install") {
            //this is defenetly not from OpenCW
            //developers never copy :)
            clear
            std::string input;
            std::cout << "Enter packages name(s): ";
            std::cin >> input;
            system(("sudo yum install " + input).c_str());
            welcome();
            fed();
    }
    else if (input == "remove" || input == "Remove") {
            clear
            std::string input;
            std::cout << "Enter packages name(s): ";
            std::cin >> input;
            system(("sudo yum remove " + input).c_str());
            welcome();
            fed();
    }

    else if (input == "exit" || input == "Exit") {
        clear
        std::cout << "Exiting..." << std::endl;
        system("exit");

    }
    else if (input == "flatpak" || input == "Flatpak") {
        flatpak();
        welcome();
        fed();
    }
    else if (input == "snap" || input == "Snap") {
        snap();
        welcome();
        fed();
    }
    else if (input == "pip" || input == "Pip") {
        pip();
        welcome();
        fed();
    }
    

    else{
        std::cout << "Invalid input! Retrying" << std::endl;
        system("read -p 'Press Enter to continue...'");
        welcome();
        fed();
    }
}

void fst() {
    clear
    //fst means first time setup
    std::cout << "Welcome to AIOPM Setup! " << std::endl;
    std::string input;
    std::cout << "What distro are you using?" << std::endl;
    std::cout << "(arch,debian,fedora,opensuse or void)" << std::endl;
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
    if (input == "opensuse" || input == "Opensuse") {
        system("sudo mkdir /usr/aiopm");
        system("sudo touch /usr/aiopm/a4.cw");
    }
    if (input == "void" || input == "Void") {
        system("sudo mkdir /usr/aiopm");
        system("sudo touch /usr/aiopm/a5.cw");
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
    clear
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
        archwelcome();
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
    //opensuse file
    std::ifstream file("/usr/aiopm/a4.cw");
    if (file.is_open()) {
        file.close();
        welcome();
        opensuse();
    }
    else {
    //fedora file
    std::ifstream file("/usr/aiopm/a5.cw");
    if (file.is_open()) {
        file.close();
        welcome();
        voidl();
    }
    else {
        //no file so first time setup
        fst();
        main();
    }
    }
    }
    
    }
    }
}

