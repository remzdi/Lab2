#include "functions.h"

const string DIRECTORY_PATH = "./";  // Directory path where files will be saved

int main() {
    ofstream inputFile(DIRECTORY_PATH + "input.txt", ios::app);

    if (!inputFile) {
        cerr << "Failed to open input.txt\n";
        return 1;
    }

    addInformation(inputFile);

    inputFile.close();
    createOutputFiles();

    int displayChoice;
    cout << "Do you want to display the contents of the files? (1-yes, 2-no): ";
    cout << endl;
    cin >> displayChoice;
    cout << endl;

    if (displayChoice == 1) {
        displayFileContents("input.txt");
        displayFileContents("output_day.txt");
        displayFileContents("output_night.txt");
    }

    ofstream clearInputFile(DIRECTORY_PATH + "input.txt");
    clearInputFile.close();

    ofstream clearOutputDay(DIRECTORY_PATH + "output_day.txt");
    clearOutputDay.close();

    ofstream clearOutputNight(DIRECTORY_PATH + "output_night.txt");
    clearOutputNight.close();

    return 0;
}
