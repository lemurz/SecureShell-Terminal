#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

// Configuration structure
struct Config {
    string promptColor;
    string messageColor;
};

// Helper function to convert color names to ANSI codes
string get_color_code(const string& color) {
    unordered_map<string, string> colorMap = {
        {"red", "\033[1;31m"}, {"green", "\033[1;32m"}, {"blue", "\033[1;34m"},
        {"yellow", "\033[1;33m"}, {"default", "\033[0m"}
    };
    return colorMap.count(color) ? colorMap[color] : colorMap["default"];
}

// Function to load configuration from file
Config load_config() {
    Config config = {"default", "default"};
    ifstream configFile("config.txt");

    if (configFile.is_open()) {
        string key, value;
        while (configFile >> key >> value) {
            if (key == "promptColor") config.promptColor = value;
            else if (key == "messageColor") config.messageColor = value;
        }
        configFile.close();
    }
    return config;
}

// Shell function with customizable appearance
void run_shell() {
    Config config = load_config();
    
    while (true) {
        cout << get_color_code(config.promptColor) << "Shell>> " << get_color_code("default");
        string input;
        getline(cin, input);

        // Example: use message color for displaying messages
        cout << get_color_code(config.messageColor) << "You typed: " << input << endl;
        cout << get_color_code("default"); // Reset color
    }
}

int main() {
    run_shell();
    return 0;
}
