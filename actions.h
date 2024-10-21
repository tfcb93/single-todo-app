#pragma once
#include <iostream>
#include <fstream>
#include <limits>
#include <stdio.h>
#include <stdlib.h> // exit function
#include <vector>
#include <string>
#include <unordered_set>

void showActions();
void checkChosenAction(int, std::vector<std::string>*, std::unordered_set<int> *);
void addItemToList(std::vector<std::string>*);
void printList(std::vector<std::string>*, std::unordered_set<int> *);
void deleteListElement(std::vector<std::string>*, std::unordered_set<int> *);
void changeListElement(std::vector<std::string>*);
void markElementAsDone(std::unordered_set<int> *, const std::vector<std::string>*);
void saveList(std::vector<std::string> *, std::unordered_set<int> *);
void loadList(std::vector<std::string> *, std::unordered_set<int> *);