#include <iostream>
#include <fstream>

using namespace std;



int main() {
    const int MAXSIZE = 50

    // opens input file to read data
    ifstream inputFile("groceryList.txt");
    string groceryList[MAXSIZE];

    // first line of file should be length of the list
    int fileLength;
    inputFile >> fileLength;
    // fills groceryList with file contents
    for (int i = 0; i < fileLength) {
        
    }


    return 0;
}
