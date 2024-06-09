#include <iostream>
#include "graphics.h"

void displayMenu() {
    std::cout << "Menu:\n";
    std::cout << "1. Move object\n";
    std::cout << "2. Resize object\n";
    std::cout << "3. Change color\n";
    std::cout << "4. Rotate object\n";
    std::cout << "5. Print object\n";
    std::cout << "6. Exit\n";
}

int main() {
    Parallelepiped p(0, 0, 0, 255, 0, 0, 2, 3, 4);

    int choice;
    while (true) {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 6) break;

        double dx, dy, dz, factor, angle;
        int r, g, b;

        switch (choice) {
        case 1:
            std::cout << "Enter dx, dy, dz: ";
            std::cin >> dx >> dy >> dz;
            p.move(dx, dy, dz);
            break;
        case 2:
            std::cout << "Enter resize factor: ";
            std::cin >> factor;
            p.resize(factor);
            break;
        case 3:
            std::cout << "Enter new color (r, g, b): ";
            std::cin >> r >> g >> b;
            p.setColor(r, g, b);
            break;
        case 4:
            std::cout << "Enter rotation angle (in degrees): ";
            std::cin >> angle;
            p.rotate(angle);
            break;
        case 5:
            p.print();
            break;
        default:
            std::cout << "Invalid choice!\n";
        }
    }

    return 0;
}
