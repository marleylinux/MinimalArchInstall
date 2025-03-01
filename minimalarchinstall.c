#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Functions

void forward() {
    printf("Press Enter key to continue...");
    fflush(stdout);
    while (getchar() != '\n'); // fixes text on top of text :)
}

char next(const char *prompt) {
    char choice;
    int valid_input = 0;

    while (!valid_input) {
        printf("%s", prompt);
        int result = scanf(" %c", &choice);

        // Clear the input buffer to avoid leftover characters
        while (getchar() != '\n'); 

        if (result == 1 && (choice == 'y' || choice == 'n')) {
            valid_input = 1;
        } else {
            printf("Invalid input. Please enter 'y' or 'n'.\n");
        }
    }

    return choice;
}

int main() {
    
    char choice;

// Welcome
    printf("\033[0mWelcome to my Minimal \033[36march\033[0m installer script\n");
    forward();
    printf("I made this for use just after choosing a minimal \033[36march\033[0m install on the \033[36marchinstall\033[0m script\n");
    forward();
    printf("I'm also trying to learn \033[33mC\033[0m that's why it's written in \033[33mC\033[0m\n");
    forward();
    printf("\033[35mEnjoy\033[0m!!\n");


// Linux Headers
if (next("Do you want to install \033[36mLinux\033[0m headers? (y/n): ") == 'y') {
    printf("Which \033[36mLinux\033[0m headers do you want to install?\n");
    printf("1) \033[36mLinux\033[0m\n");
    printf("2) \033[36mLinux\033[0m-\033[31mZen\033[0m\n");
    printf("3) \033[36mLinux\033[0m-\033[33mLTS\033[0m\n");
    printf("4) \033[35mEverything\033[0m\n");
    printf("0) Skip installation\n");
    printf("Enter the number of your choice (0-4): ");

    scanf(" %c", &choice);
    while (getchar() != '\n');  // Clear the input buffer

    if (choice == '1') {
        printf("Installing \033[36mLinux\033[0m headers\n");
        forward();
        system("sudo pacman -S --needed --noconfirm linux-headers");
    } else if (choice == '2') {
        printf("Installing \033[36mLinux\033[0m-\033[31mZen\033[0m headers\n");
        forward();
        system("sudo pacman -S --needed --noconfirm linux-zen-headers");
    } else if (choice == '3') {
        printf("Installing \033[36mLinux\033[0m-\033[33mLTS\033[0m headers\n");
        forward();
        system("sudo pacman -S --needed --noconfirm linux-lts-headers");
    } else if (choice == '4') {
        printf("Installing all \033[36mLinux\033[0m headers\n");
        forward();
        system("sudo pacman -S --needed --noconfirm linux-headers linux-zen-headers linux-lts-headers");
    } else if (choice == '0') {
        // Skip installation if the user chooses '0'
        printf("Skipping \033[36mLinux\033[0m headers installation.\n");
    } else {
        // Handle invalid choices
        printf("Invalid choice. Skipping \033[36mLinux\033[0m headers installation.\n");
    }
    forward();
} else {
    // Skip installation if the user declines
    printf("Skipping \033[36mLinux\033[0m headers installation.\n");
}



// Linux/app packages
if (next("\033[0mDo you want to install \033[36mlinux/app\033[0m packages? (y/n): ") == 'y') {
    printf("Installing \033[36mlinux/app\033[0m packages\n");
    forward();
    system("sudo pacman -S --needed --noconfirm pipewire bluez bluez-utils git gstreamer libva cpupower lact vim git base-devel gamemode mangohud wine");
    forward();
} else {
    printf("Skipping \033[36mlinux/app\033[0m packages.\n");
}


// Multilib Linux/app packages
if (next("Do you want to install \033[33mmultilib\033[0m \033[36mlinux/app\033[0m packages? (y/n): ") == 'y') {
    printf("Installing \033[33mmultilib\033[0m \033[36mlinux/app\033[0m packages\n");
    forward();
    system("sudo pacman -S --needed --noconfirm lib32-gstreamer lib32-libva lib32-gamemode lib32-mangohud lib32-pipewire");
    forward();
} else {
    printf("Skipping \033[33mmultilib\033[0m packages.\n");
}

// Proton packages
if (next("Do you want to install \033[35mProtonvpn\033[0m packages? (y/n): ") == 'y') {
    printf("Installing \033[35mProton\033[0m packages\n");
    forward();
    system("sudo pacman -S --needed --noconfirm proton-vpn-gtk-app python-proton-core python-proton-keyring-linux python-proton-vpn-api-core python-proton-vpn-local-agent python-proton-vpn-network-manager");
    forward();
} else {
    printf("Skipping \033[35mProtonvpn\033[0m packages.\n");
}


// AMD Mesa packages
if (next("Do you want to install \033[31mAMD\033[0m packages? (y/n): ") == 'y') {
    printf("Installing \033[31mAMD\033[0m packages\n");
    forward();
    system("sudo pacman -S --needed --noconfirm mesa mesa-utils vulkan-mesa-layers libva-mesa-driver");
    forward();
} else {
    printf("Skipping \033[31mAMD\033[0m packages\n");
}


// Multilib AMD Mesa packages
if (next("Do you want to install \033[33mmultilib\033[0m \033[31mAMD\033[0m packages? (y/n): ") == 'y') {
    printf("Installing \033[33mmultilib\033[0m \033[31mAMD\033[0m packages\n");
    forward();
    system("sudo pacman -S --needed --noconfirm lib32-mesa lib32-mesa-utils lib32-vulkan-mesa-layers lib32-libva-mesa-driver");
    forward();
} else {
    printf("Skipping \033[33mmultilib\033[0m \033[31mAMD\033[0m packages\n");
}


// Vulkan packages
if (next("Do you want to install \033[34mVulkan\033[0m packages? (y/n): ") == 'y') {
    printf("Installing \033[34mVulkan\033[0m packages\n");
    forward();
    system("sudo pacman -S --needed --noconfirm vulkan-radeon vulkan-validation-layers vulkan-headers vulkan-extra-layers vkd3d");
    forward();
} else {
    printf("Skipping \033[34mVulkan\033[0m packages.\n");
}


// Multilib Vulkan packages
if (next("Do you want to install \033[33mmultilib\033[0m \033[34mVulkan\033[0m packages? (y/n): ") == 'y') {
    printf("Installing \033[33mmultilib\033[0m \033[34mVulkan\033[0m packages\n");
    forward();
    system("sudo pacman -S --needed --noconfirm lib32-vulkan-validation-layers lib32-vkd3d");
    forward();
} else {
    printf("Skipping \033[33mmultilib\033[0m \033[34mVulkan\033[0m packages.\n");
}


// NVIDIA drivers
if (next("Do you want to install \033[32mNVIDIA\033[0m drivers? (y/n): ") == 'y') {
    printf("Installing \033[32mNVIDIA\033[0m drivers\n");
    forward();

    if (next("Do you want proprietary \033[32mNVIDIA\033[0m drivers (best for gaming)? (y/n): ") == 'y') {
        system("sudo pacman -S --needed nvidia nvidia-utils lib32-nvidia-utils nvidia-settings ffnvcodec-headers");
    } else {
        system("sudo pacman -S --needed nvidia-open nvidia-utils lib32-nvidia-utils nvidia-settings ffnvcodec-headers");
    }

    forward();
} else {
    printf("Skipping \033[32mNVIDIA\033[0m drivers.\n");
}

// STEAM install
if (next("Do you want to install \033[36mSTEAM\033[0m (y/n): ") == 'y') {
    // Ensure correct Vulkan packages are installed before Steam
    system("sudo pacman -S mesa vulkan-radeon lib32-mesa lib32-vulkan-radeon");

    // Now install Steam
    system("sudo pacman -S steam");

    forward(); // This should be fine unless forward() is undefined
}

// AUR setup
if (next("Do you want to set up \033[36mAUR\033[0m manually now? (y/n): ") == 'y') {
    printf("Creating \033[36m~/aur\033[0m directory...\033[0m\n");
    system("mkdir -p ~/aur");
    forward();
    
    
// Ask what to install
    printf("What \033[36mAUR\033[0m packages do you want to install?\n");
    printf("\033[90m1) Everything\033[0m (All my chosen \033[36mAUR\033[0m packages)\n");
    printf("\033[33m2) Important stuff\033[0m (libuvc, xpadneo-dkms, xone-dongle-firmware, xone-dkms)\n");
    printf("\033[33m3) Important stuff\033[0m + \033[35mProton apps\033[0m\n");
    printf("\033[31m4) Nothing\033[0m (Skip)\n");
    printf("Enter your choice (1-4): ");

    
    scanf(" %c", &choice);
    while (getchar() != '\n');

    
    if (choice == '1') {
        printf("Cloning and installing all my chosen \033[36mAUR\033[0m packages...\n");
        system("cd ~/aur && git clone https://aur.archlinux.org/xone-dongle-firmware.git && "
               "git clone https://aur.archlinux.org/papirus-folders.git && "
               "git clone https://aur.archlinux.org/librewolf-bin.git && "
               "git clone https://aur.archlinux.org/libuvc.git && "
               "git clone https://aur.archlinux.org/xpadneo-dkms.git && "
               "git clone https://aur.archlinux.org/ttf-ms-fonts.git && "
               "git clone https://aur.archlinux.org/proton-pass-bin.git && "
               "git clone https://aur.archlinux.org/proton-mail-bin.git && "
               "git clone https://aur.archlinux.org/xone-dkms.git");

    } else if (choice == '2') {
        printf("Cloning and installing important \033[36mAUR\033[0m packages...\n");
        system("cd ~/aur && git clone https://aur.archlinux.org/libuvc.git && "
               "git clone https://aur.archlinux.org/xpadneo-dkms.git && "
               "git clone https://aur.archlinux.org/librewolf-bin.git && "
               "git clone https://aur.archlinux.org/xone-dongle-firmware.git && "
               "git clone https://aur.archlinux.org/xone-dkms.git");

    } else if (choice == '3') {
        printf("Cloning and installing important \033[36mAUR\033[0m packages + Proton Suite...\n");
        system("cd ~/aur && git clone https://aur.archlinux.org/libuvc.git && "
               "git clone https://aur.archlinux.org/xpadneo-dkms.git && "
               "git clone https://aur.archlinux.org/xone-dongle-firmware.git && "
               "git clone https://aur.archlinux.org/xone-dkms.git && "
               "git clone https://aur.archlinux.org/librewolf-bin.git && "
               "git clone https://aur.archlinux.org/proton-pass-bin.git && "
               "git clone https://aur.archlinux.org/proton-mail-bin.git");
    } else if (choice == '4') {
        printf("Skipping \033[36mAUR\033[0m package installation.\n");
        forward();
        return 0;
    } else {
        printf("Invalid choice. Skipping \033[36mAUR\033[0m package installation.\n");
        forward();
        return 0;
    }

    // Build and install packages
    printf("Building and installing \033[36mAUR\033[0m packages...\n");
    system("cd ~/aur && makepkg -si https://aur.archlinux.org/xone-dongle-firmware.git && "
               "makepkg -si https://aur.archlinux.org/papirus-folders.git && "
               "makepkg -si https://aur.archlinux.org/librewolf-bin.git && "
               "makepkg -si https://aur.archlinux.org/libuvc.git && "
               "makepkg -si https://aur.archlinux.org/xpadneo-dkms.git && "
               "makepkg -si https://aur.archlinux.org/ttf-ms-fonts.git && "
               "makepkg -si https://aur.archlinux.org/proton-pass-bin.git && "
               "makepkg -si https://aur.archlinux.org/proton-mail-bin.git && "
               "makepkg -si https://aur.archlinux.org/xone-dkms.git");

    forward();
} else {
    printf("Skipping \033[36mAUR\033[0m setup.\n");
}


// GTK and Qt Installation
printf("Do you want to install \033[90mGTK\033[0m, \033[34mQt\033[0m, or \033[32mboth\033[0m?\n");
printf("1) \033[90mGTK\033[0m\n2) \033[34mQt\033[0m\n3) \033[32mBoth\033[0m\n4) \033[31mSkip\033[0m\n");
printf("Enter your choice (1-4): ");
scanf(" %c", &choice);
while (getchar() != '\n');

    
if (choice == '1') {
    printf("Installing \033[90mGTK\033[0m libraries...\n");
    forward();
    system("sudo pacman -S --needed --noconfirm gtk3 gtk4 adwaita-icon-theme gtk-layer-shell gtk4-layer-shell libappindicator-gtk3 libdbusmenu-gtk3 xdg-desktop-portal-gtk");
    forward();

    if (next("Do you want to install \033[33mmultilib\033[0m \033[90mGTK\033[0m packages? (y/n): ") == 'y') {
        printf("Installing \033[33mmultilib\033[0m \033[90mGTK\033[0m packages...\n");
        forward();
        system("sudo pacman -S --needed --noconfirm lib32-gtk3 lib32-libappindicator-gtk3 lib32-libdbusmenu-gtk3");
        forward();
    }
} else if (choice == '2') {
    printf("Installing \033[34mQt\033[0m libraries...\n");
    forward();
    system("sudo pacman -S --needed --noconfirm qt5-base qt6-base qt5-wayland qt6-wayland breeze-icons");
    forward();
} else if (choice == '3') {
    printf("Installing \033[90mGTK\033[0m and \033[34mQt\033[0m libraries...\n");
    forward();
    system("sudo pacman -S --needed --noconfirm gtk3 gtk4 adwaita-icon-theme gtk-layer-shell gtk4-layer-shell qt5-wayland qt6-wayland libappindicator-gtk3 libdbusmenu-gtk3 xdg-desktop-portal-gtk qt5-base qt6-base breeze-icons");
    forward();

    if (next("Do you want to install \033[33mmultilib\033[0m \033[90mGTK\033[0m packages? (y/n): ") == 'y') {
        printf("Installing \033[33mmultilib\033[0m \033[90mGTK\033[0m packages...\n");
        forward();
        system("sudo pacman -S --needed --noconfirm lib32-gtk3 lib32-libappindicator-gtk3 lib32-libdbusmenu-gtk3");
        forward();
    }
} else {
    printf("Skipping \033[90mGTK\033[0m and \033[34mQt\033[0m installation.\n");
}

    
// Desktop Environment Setup
int animegirlland = 0; // Track if Hyprland was chosen

    
printf("Setup a \033[34mdesktop environment\033[0m\n");
printf("\033[90m1) GNOME\033[0m\n\033[34m2) KDE Plasma\033[0m\n\033[36m3) Hyprland\033[0m\n\033[33m4) Sway\033[0m\n");
printf("Enter the number of your choice (1-4) or 0 to skip: ");
scanf(" %c", &choice);
while (getchar() != '\n');

    
if (choice == '1' && next("Are you sure you want to install \033[90mGNOME\033[0m? (y/n): ") == 'y') {
    printf("Installing \033[90mGNOME\033[0m\n");
    forward();
    system("sudo pacman -S --needed --noconfirm gnome xdg-desktop-portal-gnome");
    forward();
} else if (choice == '2' && next("Are you sure you want to install \033[34mKDE Plasma\033[0m? (y/n): ") == 'y') {
    printf("Installing \033[34mKDE Plasma\033[0m\n");
    forward();
    system("sudo pacman -S --needed --noconfirm plasma-desktop xdg-desktop-portal-kde");
    forward();
} else if (choice == '3' && next("Are you sure you want to install \033[36mHyprland\033[0m? (y/n): ") == 'y') {
    printf("Installing \033[36mHyprland\033[0m\n");
    forward();
    system("sudo pacman -S --needed --noconfirm hyprland xdg-desktop-portal-hyprland");
    forward();
    animegirlland = 1;  // Mark Hyprland as selected
} else if (choice == '4' && next("Are you sure you want to install \033[33mSway\033[0m? (y/n): ") == 'y') {
    printf("Installing \033[33mSway\033[0m\n");
    forward();
    system("sudo pacman -S --needed --noconfirm sway xdg-desktop-portal-wlr");
    forward();
} else {
    printf("Skipping \033[34mdesktop environment\033[0m installation.\n");
}


// Message indicating skipping installation
printf("Skipping installation.\n");


// If Hyprland was selected, ask about installing extra packages
if (animegirlland) {
    if (next("Do you want to install \033[36mHyprland\033[0m extra packages? (y/n): ") == 'y') {
        printf("Installing \033[36mHyprland\033[0m extra packages\n");
        forward();
        system("sudo pacman -S --needed --noconfirm nwg-panel nwg-look nwg-bar nwg-drawer hyprpaper hyprlock nwg-hello obs-studio code pavucontrol resources");
        forward();
    } else {
        printf("Skipping \033[36mHyprland\033[0m extra packages\n");
    }
}


printf("\033[31mT\033[33mh\033[32me \033[36mi\033[34mn\033[35ms\033[31mt\033[33ma\033[32ml\033[36ml\033[34ma \033[35mh\033[31ma\033[33ms \033[32mf\033[36mi\033[34mn\033[35mi\033[31ms\033[33mh\033[32me \033[36m!\033[0m\n");
return 0;


}
