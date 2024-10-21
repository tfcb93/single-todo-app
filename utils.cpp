#include "utils.h"

int checkUsingIntInput() {
    int inputVal;
    bool isInputValid = false;
    
    // check if it's a valid input
    while(!isInputValid) {
        std::cin >> inputVal;
        std::cin.ignore(); // removes the last "break of line"
        if (!std::cin) {
            printf("Wrong value. Please try again: ");
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            isInputValid = true;
        }
    }
    return inputVal;
}

bool checkIntInterval(int min, int max, int value) {
    if (value >= min && value <= max) {
        return true;
    }
    
    return false;
}

bool checkListIsEmpty(const std::vector<std::string>* list) {
    if(list->size() <= 0) {
        printf("There is no item in the list.\n");
        return true;
    }
    return false;
}

int checkActionIndex(const std::vector<std::string>* list, std::string message, bool abortOnMinusOne = true) {
    int listSize = list->size();
    bool isIndexValid = false;
    int index;
    while(!isIndexValid) {
        // I know this statement is not much generic, but since I know where I'm using it, I will let it this way
        printf("Please enter the index (1 - %d) of the element you want to %s%s: ", listSize, message.c_str(), abortOnMinusOne ? " or press -1 to abort" : "");
        index = checkUsingIntInput();
        if (abortOnMinusOne && index == -1) return -1;
        if (!checkIntInterval(1, listSize, index)) {
            printf("Wrong value! Please try again: \n");
            continue;
        }
        isIndexValid = true;
    }
    return index;
}