#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isValidPhoneNumber(const std::string& phoneNumber);
void addCallInfo(ofstream& file);
void createOutputFiles();
void displayFileContents(const std::string& filename);
bool addInformation(std::ofstream& inputFile);
