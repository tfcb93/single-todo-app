#include <stdio.h>
#include<string.h>
#include <iostream>
#include <limits>
#include <vector>
#include <unordered_set>
#include "actions.h"

int main(int argc, char** argv) {

    std::vector<std::string> a{};
    std::unordered_set<int> done{};

    bool run = true;

    // char* input;
    char input[100]; // for now I will limit input

    int actionInput = 0;

    while(run) {
        printList(&a, &done);
        showActions();
        std::cin >> actionInput;
        std::cin.ignore(); // removes the last "break of line"
        if (!std::cin) {
            std::cout << "Wrong value \n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            checkChosenAction(actionInput, &a, &done);
        }
    }


    return 0;
}