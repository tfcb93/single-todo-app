#include "actions.h"
#include "utils.h"

void printList(std::vector<std::string> *list, std::unordered_set<int> * doneList) {
    printf("\n\n");
    printf("========= TODO LIST ========= \n");
    int index = 1;
    if (list->size() <= 0) {
        printf("        List is empty!  \n");
    } else {
        for (const std::string c : *list) {
            printf("%d - %s", index, c.c_str());
            if (doneList->count(index) > 0) {
                printf(" - DONE");
            }
            printf("\n");
            ++index;
        }
    }
    printf("============================ \n\n");
}

void addItemToList(std::vector<std::string>* list) {
    std::string input;
    
    printf("Please insert what you want inside the list: ");
    std::getline(std::cin, input);

    list->push_back(input);
}

void deleteListElement(std::vector<std::string>* list, std::unordered_set<int> * doneList) {
    if (checkListIsEmpty(list)) return;
    int index = checkActionIndex(list, "remove from the list", true);
    if (index == -1) return;
    list->erase(list->begin() + (index - 1));
    if(doneList->count(index) > 0) {
        doneList->erase(doneList->find(index));
    }
    return;
}

void changeListElement(std::vector<std::string>* list) {
    if (checkListIsEmpty(list)) return;
    int index = checkActionIndex(list, "change", true);
    if (index == -1) return;
    std::string edit = list->at(index - 1);
    printf("Edit entry %s: \n", edit.c_str());
    std::getline(std::cin, edit);
    list->erase(list->begin() + index - 1);
    list->insert(list->begin() + index - 1, edit);
}

void markElementAsDone(std::unordered_set<int> * doneList, const std::vector<std::string>* list) {
    if (checkListIsEmpty(list)) return;
    int index = -2;
    while(!checkIntInterval(1, list->size(), index) || doneList->count(index) > 0) {
        index = checkActionIndex(list, "mark as done", true);
        printf("The element is already marked as done.\n");

        if (index == -1) return;
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
                    gotFirstLine = true;

                    // convert each number in the first line for the done set
                    for(const char val: line) {
                        if(val != ',') {
                            done->insert((int)val - '0');
                        }
                    }

                    continue;
                }
                if (!line.empty()){
                    list->push_back(line);
                }
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