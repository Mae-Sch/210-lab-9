#include <iostream>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <array>
#include <iomanip>

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
    cout << "list Contents:\n";
    for (int i = 0; i < groceryList.size(); ++i) {
        cout << setw(5) << (i+1) << ": " << setw(20) << groceryList.at(i) << " ";
        if (i%3 == 0) // splits output into lines of 3 for readability
            cout << endl;
    }
    cout << endl << endl << endl;

    sort(groceryList.begin(), groceryList.end());
    cout << "sorted list Contents:";
    for (int i = 0; i < groceryList.size(); ++i) {
        cout << setw(5) << (i+1) << ": " << setw(20) << groceryList.at(i) << " ";
        if (i%3 == 0) // splits output into lines of 3 for readability
            cout << endl;
    }
    cout << endl;

    // using find() to return index
    cout << "Enter grocery to find: ";
    string toFind;
    cin >> toFind;
    array<string, MAXSIZE>::iterator foundIndex;
    foundIndex = find(groceryList.begin(), groceryList.end(), toFind);
    cout << toFind << " is at element " << (foundIndex - groceryList.begin() + 1) << endl;

    return 0;
}
