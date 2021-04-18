#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    vector<string> myWords;
    string word;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>word;
        myWords.push_back(word);
    }
    sort(myWords.begin(),myWords.end());
    cout<<myWords.at(0);
}
