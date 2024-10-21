#pragma once
#include <stdlib.h> // exit function
#include "actions.h"

void showActions();
void checkChosenAction(int, std::vector<std::string>*, std::unordered_set<int> *);