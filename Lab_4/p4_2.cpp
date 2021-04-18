#include <bits/stdc++.h>
using namespace std;

int main(){
    stack<string> pile;
    vector<string> scannedBooks;
    string book;
    string operation;
    int n;
    cin>>n;
    cin.get();
    for(int i=0;i<n;i++){
       cin>>operation;
       cin.get();
       if(operation.compare("+")==0){
           getline(cin, book);
           //cin.get();
           pile.push(book);
       }
      if(operation.compare("-")==0){
            if(!pile.empty()){
                scannedBooks.push_back(pile.top());
                pile.pop();
            }
       }
    }

    for(vector<string>::iterator it=scannedBooks.begin(); it!=scannedBooks.end(); it++)
        cout<<*it<<",";


    return 0;
}
