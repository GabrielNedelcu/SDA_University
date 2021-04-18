#include <bits/stdc++.h>
using namespace std;

int fromCharToInt(char c){
    return c-'0';
}

int op(int a, int b, char c){
    if(c=='+')
        return a+b;
    if(c=='-')
        return a-b;
    if(c=='*')
        return a*b;
    if(c=='/')
        return a/b;

    return 0;
}


int main(){
    stack<int> myNumbers;
    string text;
    char c;
    int a;
    int b;
    getline(cin,text);
    istringstream is(text);
    while(is>>c){
        if(isdigit(c)){
            myNumbers.push(fromCharToInt(c));
        }
        else{
            b=myNumbers.top();
            myNumbers.pop();
            a=myNumbers.top();
            myNumbers.pop();
            myNumbers.push(op(a,b,c));
        }
    }

    cout<<myNumbers.top();

    return 0;
}
