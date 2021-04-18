#include <bits/stdc++.h>

using namespace std;

int main(){

    vector<string> myText;
    string word;
    int numberOfWords=0;

    while(cin>>word){
         myText.push_back(word);
         numberOfWords++;
    }

    for(int i=numberOfWords-1;i>=0;i--)
        cout<<myText.at(i);
    return 0;
}
