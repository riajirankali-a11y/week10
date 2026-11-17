
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream infile("in.txt");
    ofstream outfile("out.txt");

    if (!infile || !outfile) {
        cout << "File opening failed!";
        return 0;
    }

    string line;
    int lineNumber = 1;

    while (getline(infile, line)) {
        outfile << lineNumber << ". " << line << endl;
        lineNumber++;
    }

    infile.close();
    outfile.close();

    cout << "File copied successfully!" << endl;

    return 0;
}
