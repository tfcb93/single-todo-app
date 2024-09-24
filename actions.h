#pragma once
#include <iostream>
#include <limits>
#include <stdio.h>
#include <stdlib.h> // exit function
#include <vector>
#include <unordered_set>

void showActions();
void checkChosenAction(int, std::vector<char*>*, std::unordered_set<int> * doneList);
void addItemToList(std::vector<char*>*);
void printList(std::vector<char*>, std::unordered_set<int> * doneList);
void deleteListElement(std::vector<char*>*, std::unordered_set<int> * doneList);
void changeListElement(std::vector<char*>* list);
void markElementAsDone(std::unordered_set<int> * doneList, int max_value);