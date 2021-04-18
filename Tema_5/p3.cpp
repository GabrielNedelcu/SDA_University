#include <bits/stdc++.h>
using namespace std;

int main() {
    int height;
    int width;
    int numberOfGroups;
    int groupSize;
    int lineNumber;
    int colNumber;
    int groupNumber;
    int value;

    vector<vector<int>> board;
    vector<vector<int>> square;

    string line;

    getline (cin, line);
    istringstream ss(line);
    ss >> height >> width >> numberOfGroups;

    groupSize = sqrt((height * width) / numberOfGroups);


    return 0;
}