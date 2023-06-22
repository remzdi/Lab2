#include "functions.h"
using namespace std;


int main()
{
    string InFilename;
    char check;
    cout << "Enter file name: ";
    cin >> InFilename;
    string filename = InFilename + ".bin";

    do
    {
        add_conversation(filename);
        cout << "Do you want to add another call?" << endl;
        check = getch();

    } while (check == '\r');

    read_info_from_file(filename);

    cout << "\nDay Time file: " << endl;
    read_output_file("daytime_calls.bin");
    cout << "Night Time file: " << endl;
    read_output_file("nighttime_calls.bin");
    return 0;
}
