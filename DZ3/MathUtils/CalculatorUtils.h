#pragma once
#include <string>
#include <vector>

bool IsOperatorValue(std::string value);
double GetResult(std::string value,int mode, int selectButton);
double SimpleMode(std::vector<std::string> value);
double EngineerMode(std::vector<std::string> value,int selectButton);
std::vector<std::string> ParseInput(std::string value);


