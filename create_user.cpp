#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cerrno>

using namespace std;

int main(int argc, char *argv[]) {
    char username[21];  // Increased size to 21 to accommodate null-terminated string
    char mkdir_command[60];  // Increased size to 60 to ensure space for mkdir command

    // Checks if the expected argument (username) has been passed correctly
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " username" << endl;
        return 1;
    }

    // Safely copies the argument to the username variable
    if (strlen(argv[1]) > 20) {
        cout << "Error: Username exceeds maximum allowed length." << endl;
        return 1;
    }
    strncpy(username, argv[1], sizeof(username) - 1);
    username[sizeof(username) - 1] = '\0';  // Ensures username is correctly terminated

    // Constructs the command to create the directory with the username
    snprintf(mkdir_command, sizeof(mkdir_command), "mkdir \"%s\"", username);

    // Executes the mkdir command to create the directory
    cout << "Executing command: " << mkdir_command << endl;
    int result = system(mkdir_command);

    // Checks if the directory was created successfully
    if (result == 0) {
        cout << "Directory '" << username << "' created successfully." << endl;
    } else {
        cout << "Error creating directory '" << username << "': " << strerror(errno) << endl;
        return 1;  // Exits the program in case of error during directory creation
    }

    // Here you can continue the flow of your program as necessary

    return 0;
}
