#pragma once
#include <iostream>
#include <fstream>
#include <limits>
#include <stdio.h>
#include <unordered_set>
#include "utils.h"

void addItemToList(std::vector<std::string>*);
void printList(std::vector<std::string>*, std::unordered_set<int> *);
void deleteListElement(std::vector<std::string>*, std::unordered_set<int> *);
void changeListElement(std::vector<std::string>*);
void markElementAsDone(std::unordered_set<int> *, const std::vector<std::string>*);
void saveList(std::vector<std::string> *, std::unordered_set<int> *);
void loadList(std::vector<std::string> *, std::unordered_set<int> *);