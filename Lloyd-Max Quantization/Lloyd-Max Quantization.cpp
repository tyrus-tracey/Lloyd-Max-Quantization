#include <iostream>
#include <sstream>
#include <string>
#include "lloydMax.h"
bool running = true;
std::string inputString;

int main()
{
    std::cout << "Lloyd-Max Quantization\n";
    while (running) {
        std::cout << "Enter integer N, followed by 3 floats y1 y2 y3 (Example: 1 -0.5 0 0.5). X to close:\n";
        std::getline(std::cin, inputString);

        if (inputString != "X" && inputString != "x") {
            std::stringstream inputStream(inputString);
            lloydMax L(inputStream);
            L.print();
        }
        else {
            running = false;
        }
    }
    std::cout << "Closing...\n";
}