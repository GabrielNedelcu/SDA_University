#include <bits/stdc++.h>
using namespace std;


int main(){
    stack<char> openBrackets;
    string line;
    char c;
    int ok = 1;

    getline(cin, line);
    istringstream ss(line);
    while (ss>>c) {
        if (c=='('||c=='['||c=='{')
            openBrackets.push(c);
        if (c==')'||c==']'||c=='}') {
            if (c==')')
                c = '(';
            if (c==']')
                c = '[';
            if (c=='}')
                c = '{';

            if (openBrackets.top() == c)
                openBrackets.pop();
            else {
               ok = 0;
               break;
            }
        }

    }
    if (openBrackets.size() != 0)
        ok = 0;
    cout<<ok;

    return 0;
}
