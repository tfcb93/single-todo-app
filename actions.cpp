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

void addItemToList(std::vector<std::string>* list) {
    std::string input;
    
    printf("Please insert what you want inside the list: ");
    std::getline(std::cin, input);
    // std::cin >> input;

    list->push_back(input);
}

void printList(std::vector<std::string> *list, std::unordered_set<int> * doneList) {
    printf("What is in the list: \n");
    int index = 1;
    for (const std::string c : *list) {
        printf("%d - %s", index, c.c_str());
        if (doneList->count(index) > 0) {
            printf(" - DONE");
        }
        printf("\n");
        ++index;
    }
}

void deleteListElement(std::vector<std::string>* list, std::unordered_set<int> * doneList) {
    int index;
    printf("Please enter the index (1 - %d) of the element you want to remove from the list: ", (int)list->size());
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

void changeListElement(std::vector<std::string>* list) {
    int index;
    printf("Please enter the index (1 - %d) of the element you want to remove from the list: ", (int)list->size());
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
        std::cin.ignore();
        std::string edit = list->at(index - 1);
        printf("Edit entry %s: \n", edit.c_str());
        std::getline(std::cin, edit);
        list->erase(list->begin() + index - 1);
        list->insert(list->begin() + index - 1, edit);

    }
}

// decided to go with this approach instead of passing the whole list inside the function
void markElementAsDone(std::unordered_set<int> * doneList, const std::vector<std::string>* list) {
    int index = 0;
    int max_value = list->size();
    if (max_value <= 0) {
        printf("There are no items to be marked as done.\n");
        return;
    }
    while(index <= 0 || index > max_value) {
        printf("Please enter the index (1 - %d) of the element you want to mark as done: ", max_value);
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

void loadList(std::vector<std::string> * list, std::unordered_set<int> * done) {
    std::string option = "";
    std::ifstream file;
    std::string line;
    bool gotFirstLine = false;

    printf("Continue with this operation will delete the current TODO list, are you ok with that? [Y]es/[N]o: ");
    std::cin >> option;

    if (option == "Yes" || option == "yes" || option == "Y" || option == "y") {
        list->clear();
        done->clear();
        file.open("list.txt");
        if(file.is_open()) {
            while(!file.eof()) {
                getline(file, line);
                if(!gotFirstLine) {
                    std::cout << "First line is: " << line << '\n';
                    gotFirstLine = true;
                    continue;
                }
                list->push_back(line);
            }
            file.close();
        }
        return;
    }
    if (option == "NO" || option == "no" || option == "N" || option == "n"){
        printf("Load aborted.\n");
        return;
    }
    printf("Instruction not clear. Load aborted.\n");
    return;
}

void saveList(std::vector<std::string> * list, std::unordered_set<int> * done) {
    std::ofstream file;
    file.open("list.txt");
    for(const int d : *done) {
        file << d << ',';
    }
    file << "\n";
    for(const std::string item : *list) {
        file << item << "\n";
    }
    file.close();
    return;
}