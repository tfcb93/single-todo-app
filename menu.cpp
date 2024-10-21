#include "menu.h"

void showActions() {
    printf("\n");
    printf("Choose one of the following actions\n");
    printf("1 - Insert new task\n");
    printf("2 - Edit task\n");
    printf("3 - Mark task as done\n");
    printf("4 - Delete task\n");
    printf("5 - Load\n");
    printf("6 - Save\n");
    printf("7 - Quit\n");
}

void checkChosenAction(int opt, std::vector<std::string> *list, std::unordered_set<int> * doneList) {
    switch (opt)
    {
    case 1:
        printf("You choose insert a new task\n");
        addItemToList(list);
        break;
    case 2:
        printf("You choose edit a task\n");
        changeListElement(list);
        break;
    case 3:
        markElementAsDone(doneList, list);
        break;
    case 4:
        deleteListElement(list, doneList);
        break;
    case 5:
        loadList(list, doneList);
        break;
    case 6:
        saveList(list, doneList);
        break;
    case 7:
        printf("You choose to quit the application. Goodbye.\n");
        exit(1);
        break;
    default:
        printf("Invalid option\n");
        break;
    }
}