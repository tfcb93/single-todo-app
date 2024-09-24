#include "actions.h"

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

void checkChosenAction(int opt, std::vector<char*> *list, std::unordered_set<int> * doneList) {
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
        markElementAsDone(doneList, list->size());
        break;
    case 4:
        deleteListElement(list, doneList);
        break;
    case 5:
        printf("You choose load a task board\n");
        break;
    case 6:
        printf("You choose save the task board\n");
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

void addItemToList(std::vector<char*>* list) {
    
    char* input = new char[100];
    
    printf("Please insert what you want inside the list: ");
    std::cin >> input;

    list->push_back(input);
}

void printList(std::vector<char*> list, std::unordered_set<int> * doneList) {
    printf("What is in the list: \n");
    int index = 1;
    for (const char* c : list) {
        printf("%d - %s", index, c);
        if (doneList->count(index) > 0) {
            printf(" - DONE");
        }
        printf("\n");
        ++index;
    }
}

void deleteListElement(std::vector<char*>* list, std::unordered_set<int> * doneList) {
    int index;
    printf("Please enter the number of the element you want to remove from the list");
    std::cin >> index;
    if (!std::cin) {
            std::cout << "Wrong value \n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else {
        if (index - 1 < 0 || index > list->size()) {
            printf("Invalid index\n");
            return;
        }
        list->erase(list->begin() + (index - 1));
        if(doneList->count(index) > 0) {
            doneList->erase(doneList->find(index));
        }
    }
    return;
}

void changeListElement(std::vector<char*>* list) {
        int index;
    printf("Please enter the number of the element you want to remove from the list: ");
    std::cin >> index;
    if (!std::cin) {
            std::cout << "Wrong value \n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else {
        if (index - 1 < 0 || index > list->size()) {
            printf("Invalid index\n");
            return;
        }
        char* edit = list->at(index - 1);
        printf("Edit entry %s: \n", edit);
        std::cin >> edit; // TODO: See how to show the previous value on CIN or somehow
    }
    return;
}

// decided to go with this approach instead of passing the whole list inside the function
void markElementAsDone(std::unordered_set<int> * doneList, int max_value) {
    int index = 0;
    if (max_value <= 0) {
        printf("There are no items to be marked as done.\n");
        return;
    }
    while(index <= 0 || index > max_value) {
        printf("Please enter the index (1 - %d) of the element you want to mark as done.\n", max_value);
        std::cin >> index;
        if (index <= 0 || index > max_value) {
            printf("Wrong value!\n");
        }
    }
    if(doneList->count(index) > 0) {
        printf("The element is already marked as done.\n");
        return;
    }
    doneList->insert(index);
}