#include <iostream>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <array>
#include <iomanip>
#include <vector>

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
    cout << "sorted list Contents:\n";
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

    // ********** Vector Version ********** //
    // some variables have V appended to serpate from the array version

    // opens input file to read data
    ifstream inputFileV("groceryList.txt");
    vector<string> groceryListV;

    // first line of file should be length of the list
    int fileLengthV;
    inputFileV >> fileLengthV;
    inputFileV.ignore(); // ignores rest of line used for list length

    // fills groceryList with file contents
    for (int i = 0; i < fileLengthV; ++i) {
        // collects grocery from line at stores it in the array
        string currentGrocery;
        getline(inputFileV, currentGrocery);
        groceryListV.push_back(currentGrocery);
    }
    inputFileV.close(); //file is no longer in use

    // print array
    cout << "list Contents:\n";
    for (int i = 0; i < groceryListV.size(); ++i) {
        cout << setw(5) << (i+1) << ": " << setw(20) << groceryListV.at(i) << " ";
        if (i%3 == 0) // splits output into lines of 3 for readability
            cout << endl;
    }
    cout << endl << endl << endl;

    sort(groceryListV.begin(), groceryListV.end());
    cout << "sorted list Contents:\n";
    for (int i = 0; i < groceryListV.size(); ++i) {
        cout << setw(5) << (i+1) << ": " << setw(20) << groceryListV.at(i) << " ";
        if (i%3 == 0) // splits output into lines of 3 for readability
            cout << endl;
    }
    cout << endl;

    // using find() to return index
    cout << "Enter grocery to find: ";
    string toFindV;
    cin >> toFindV;
    vector<string>::iterator foundIndexV;
    foundIndexV = find(groceryListV.begin(), groceryListV.end(), toFindV);
    cout << toFindV << " is at element " << -1*(groceryListV.begin() - foundIndexV -1) << endl;

    return 0;
}
