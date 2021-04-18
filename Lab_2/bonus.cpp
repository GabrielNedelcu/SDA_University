#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<float> mySequence;
    int n;
    float x;

    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x;
        mySequence.push_back(x);
    }

    for(int i=n/2;i<n;i++)
        cout<<mySequence.at(i)<<" ";
    for(int i=0;i<n/2;i++)
        cout<<mySequence.at(i)<<" ";

    return 0;
}
