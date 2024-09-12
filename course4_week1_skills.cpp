#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<unordered_map>
#include<sstream>

using namespace std;

int main() {

    // I hate it when courses require you to buy books

    // Let's start with a function for reading strings from a file into a vector
    ifstream file("../words.txt");
    vector<string> lines;
    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }
    file.close();

    // Let's print the vector
    for (int i = 0; i < lines.size(); i++) {
        cout << lines[i] << endl;
    }

    // Now I want to find how many times each word occurs in the vector
    // I'll use an unordered map

    unordered_map<string, int> word_count;

    for (int i = 0; i < lines.size(); i++) {
        istringstream iss(lines[i]);
        string word;

        // Check all the characters in the line
        for (int j = 0; j < lines[i].length(); j++) {
            // Check if the character is a letter
            if (isalpha(lines[i][j])) {
                // Convert to lower case
                lines[i][j] = tolower(lines[i][j]);
            }
        }

        // Split the line into individual words
        while (iss >> word) {
            word_count[word]++;
        }
    }

    // Let's print the map
    for (auto it = word_count.begin(); it != word_count.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}
    