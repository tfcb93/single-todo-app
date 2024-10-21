#include "menu.h"
#include "utils.h"

int main(int argc, char** argv) {

    std::vector<std::string> a{};
    std::unordered_set<int> done{};

    bool run = true;

    // int actionInput = 0;

    while(run) {
        // print list so far and show actions menu
        printList(&a, &done);
        showActions();

        // check the action and use the function
        checkChosenAction(checkUsingIntInput(), &a, &done);
    }

    return 0;
}