#include<bits/stdc++.h>
using namespace std;

int main(){
    char c;
    queue<char> operations;
    bool digits_started = false;
    int result;
    string to_show;

    while(scanf("%c", &c)!=EOF){
        if(!isdigit(c)){
            operations.push(c);
        }
        else{
            if(digits_started==false){
                digits_started = true;
                result=c-'0';
                to_show+=c;
            }
            else{
                if(operations.front()=='+'){
                    result+=c-'0';
                    to_show+="+";
                    to_show+=c;
                }
                if(operations.front()=='-'){
                    result-=c-'0';
                    to_show+="-";
                    to_show+=c;
                }
                if(operations.front()=='*'){
                    result*=c-'0';
                    to_show+="*";
                    to_show+=c;
                }
                if(operations.front()=='/'){
                    result/=c-'0';
                    to_show+="/";
                    to_show+=c;
                }
                operations.pop();
            }
        }
    }
    to_show+="=";
    cout<<to_show<<result;

    return 0;
}
