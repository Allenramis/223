#include <iostream>
#include <string>
#include <filesystem>
#include <vector>

using namespace std;
namespace fs = filesystem;

// Function to display the main menu
void displayMenu() {
    cout << "Directory Management System" << endl;
    cout << "----------------------------" << endl;
    cout << "1. List files in the current directory" << endl;
    cout << "2. Create a new directory" << endl;
    cout << "3. Change the current working directory" << endl;
    cout << "4. Exit the program" << endl;
    cout << "----------------------------" << endl;
}

// Function to list files in the current directory
void listFiles() {
    try {
        for (const auto& entry : fs::directory_iterator(fs::current_path())) {
            if (entry.is_regular_file()) {
                cout << entry.path().filename().string() << endl;
            }
        }
    } catch (const fs::filesystem_error& e) {
        cout << "Error listing files: " << e.what() << endl;
    }
}

// Function to create a new directory
void createDirectory() {
    string directoryName;
    cout << "Enter the name of the directory: ";
    cin >> directoryName;
    try {
        if (fs::create_directory(directoryName)) {
            cout << "Directory created successfully!" << endl;
        } else {
            cout << "Directory already exists or failed to create directory." << endl;
        }
    } catch (const fs::filesystem_error& e) {
        cout << "Error creating directory: " << e.what() << endl;
    }
}

// Function to change the current working directory
void changeDirectory() {
    string directoryPath;
    cout << "Enter the path of the directory: ";
    cin >> directoryPath;
    try {
        fs::current_path(directoryPath);
        cout << "Directory changed successfully!" << endl;
    } catch (const fs::filesystem_error& e) {
        cout << "Error changing directory: " << e.what() << endl;
    }
}

int main() {
    while (true) {
        displayMenu();
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                listFiles();
                break;
            case 2:
                createDirectory();
                break;
            case 3:
                changeDirectory();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
