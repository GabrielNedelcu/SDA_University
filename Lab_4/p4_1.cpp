#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<string> myPeople;
    vector<string> gifts;
    int n;
    string tmp;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>tmp;
        gifts.push_back(tmp);
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>tmp;
        myPeople.push_back(tmp);
    }
    int k=0;
    for(vector<string>::iterator it=myPeople.begin();it!=myPeople.end();it++){
        cout<<*it<<": ";
        for(int i=0;i<n;i++){
            if(i%myPeople.size()==k)
                cout<<gifts.at(i)<<" ";
        }
        cout<<endl;
        k++;
    }

    return 0;
}
