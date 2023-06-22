#include <string>
#include <iostream>
#include <conio.h>
using namespace std;

bool calculate_minutes (char* startTime, char* endTime);
bool calculate_time(char* startTime, char* endTime);
bool checkTimeFormat(char *input);
void add_conversation(string filename);
void read_info_from_file(string filename);
void read_output_file(const string& filename);
