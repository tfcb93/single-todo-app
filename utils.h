#pragma once
#include <iostream>
#include <limits>
#include <vector>
#include <string>

int checkUsingIntInput();
bool checkIntInterval(int min, int max, int value);
bool checkListIsEmpty(const std::vector<std::string>*);
int checkActionIndex(const std::vector<std::string>* list, std::string message, bool);