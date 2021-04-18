#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, set<string>> words;
    string line;
    string tmp;

    getline(cin, line);
    istringstream ss(line);

    while (ss >> tmp) {
        transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
        if (words.find(tmp.length()) == words.end()) {
            set<string> tmpWords;
            tmpWords.insert(tmp);
            words.insert(pair<int, set<string>>(tmp.length(), tmpWords));
        } else {
            words.find(tmp.length()) -> second.insert(tmp);
        }
    }

    for (pair<int, set<string>> pair : words) {
        cout << pair . first << ": ";
        for (string word : pair.second) {
            cout << word << " ";
        }
        cout << endl;
    }


    return 0;
}
