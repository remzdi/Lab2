#include "functions.h"

bool isValidPhoneNumber(const std::string& phoneNumber) {
    if (phoneNumber.length() != 5) {
        return false;
    }

    for (char c : phoneNumber) {
        if (!isdigit(c)) {
            return false;
        }
    }

    return true;
}

void addCallInfo(ofstream& file) {
    string phoneNumber, startTime, endTime;
    do {
        std::cout << "Enter the phone number (5 digits): ";
        std::cin >> phoneNumber;
        cout << endl;

        if (!isValidPhoneNumber(phoneNumber)) {
            std::cout << "Invalid phone number. Please enter 5 digits.\n";
        }
    } while (!isValidPhoneNumber(phoneNumber));

    cout << endl;
    cout << "Enter the start time of the call: ";
    cin >> startTime;
    cout << endl;
    cout << "Enter the end time of the call: ";
    cin >> endTime;
    cout << endl;
    file << phoneNumber << ", " << startTime << ", " << endTime << "\n";
}

void createOutputFiles() {
    ifstream inputFile("input.txt");
    ofstream outputDay("output_day.txt");
    ofstream outputNight("output_night.txt");

    if (!inputFile) {
        cerr << "Failed to open input.txt\n";
        cout << endl;
        return;
    }

    if (!outputDay) {
        cerr << "Failed to create output_day.txt\n";
        cout << endl;
        return;
    }

    if (!outputNight) {
        cerr << "Failed to create output_night.txt\n";
        cout << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) {
        string startTime = line.substr(line.find(",") + 1);
        int hour = stoi(startTime.substr(0, startTime.find(":")));

        if (hour >= 6 && hour < 20) {
            outputDay << line << "\n";
        } else {
            outputNight << line << "\n";
        }
    }

    cout << "Output files created successfully.\n";
    cout << endl;

    inputFile.close();
    outputDay.close();
    outputNight.close();
}

void displayFileContents(const string& filename) {
    ifstream file(filename);

    if (!file) {
        cerr << "Failed to open " << filename << "\n";
        return;
    }

    cout << "Contents of " << filename << ":\n";
    string line;
    while (getline(file, line)) {
        cout << line << "\n";
    }

    file.close();
}

bool addInformation(std::ofstream& inputFile) {
    bool addInfo = true;
    while (addInfo) {
        int choice;
        cout << "Do you want to add information? (1-yes, 2-no)";
        cout << endl;
        char er, ch;
        do {
            er = 0;
            cout << "Enter the number: ";
            scanf_s("%d%c", &choice, &ch);
            cout << endl;
            if ((ch != '\n') || (choice < 1) || (choice > 2)) {
                er = 1;
                fflush(stdin);
                printf("Incorrect input choice \n");
            }
        } while (er);

        if (choice == 1) {
            addCallInfo(inputFile);
        } else if (choice == 2) {
            addInfo = false;
        } else {
            cout << "Invalid choice. Please enter 1 or 2.\n";
            cout << endl;
        }
    }
    return true; // Indicate that information was added
}
