#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<string> firstSlide;
    queue<string> secondSlide;
    queue<string> thirdSlide;

    string line;
    string tmpName;
    int slideNumber;

    int n;
    cin>>n;
    cin.get();

    for (int i=0; i < n; i++) {
    //while (getline(cin, line)) {
        getline(cin, line);
        istringstream ss(line);
        ss>>tmpName>>slideNumber;

        if (slideNumber == 1)
            firstSlide.push(tmpName);
        if (slideNumber == 2)
            secondSlide.push(tmpName);
        if (slideNumber == 3)
            thirdSlide.push(tmpName);

        if (firstSlide.size() != 0 && secondSlide.size() != 0 && thirdSlide.size() != 0) {
            cout<<firstSlide.front()<<" "<<secondSlide.front()<<" "<<thirdSlide.front()<<endl;
            firstSlide.pop();
            secondSlide.pop();
            thirdSlide.pop();
        }
    }


    return 0;
}
