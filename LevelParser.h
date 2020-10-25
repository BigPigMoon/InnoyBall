#pragma once
#include "BearLibTerminal.h"
#include "tinyxml2.h"

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

std::vector<std::vector<char>> levelParse(std::string fileName);
void dialogParse(std::string fileName, std::string personName);
