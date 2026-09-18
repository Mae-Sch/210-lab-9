#include <iostream>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <array>

using namespace std;

int main() {
    const int MAXSIZE = 30;

    // opens input file to read data
    ifstream inputFile("groceryList.txt");
    array<string, MAXSIZE> groceryList;

    // first line of file should be length of the list
    int fileLength;
    inputFile >> fileLength;
    inputFile.ignore(); // ignores rest of line used for list length

    // fills groceryList with file contents
    for (int i = 0; i < fileLength; ++i) {
        // collects grocery from line at stores it in the array
        getline(inputFile, groceryList.at(i));
    }
    inputFile.close(); //file is no longer in use

    // print array
    cout << "list Contents:";
    for (int i = 0; i < groceryList.size(); ++i) {
        cout << (i+1) << ": " << groceryList.at(i) << " ";
        if (i%3 == 0) // splits output into lines of 3 for readability
            cout << endl;
    }
    cout << endl;

    return 0;
}
