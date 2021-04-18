#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, string> dictionary;
    string word;
    string definition;
    string line;
    int n;
    cin >> n;
    cin.get();


    for (int i = 0; i < n; i++) {
        getline (cin, line);
        istringstream ss(line);
        getline(ss, word, ',');
        getline(ss, definition);
        if (dictionary.find(word) == dictionary.end()) {
            dictionary.insert(pair<string, string>(word, definition));
        } else {
            dictionary.find(word) -> second = definition;
        }
    }

    for (auto it = dictionary.begin(); it != dictionary.end(); it++) {
        cout << it -> first << ": " << it -> second << endl;
    }

    return 0;
}