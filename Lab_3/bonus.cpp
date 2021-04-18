#include <bits/stdc++.h>

using namespace std;

bool number_is_found(vector<long int> &numbers, long int to_find){
    vector<long int>::iterator left=numbers.begin();
    vector<long int>::iterator right=numbers.end();
    vector<long int>::iterator middle;

    while(left<=right){
        middle=left+distance(left, right)/2;
        if(*middle==to_find)
            return true;
        if(*middle<to_find)
            left=middle+1;
        else
            right=middle-1;
    }

    return false;
}

int main(){
    char FILE_NAME[100];
    ifstream FILE;
    int n, count=0;
    long int number;
    vector<long int> myNumbers;

    cin>>FILE_NAME;
    FILE.open(FILE_NAME);
    FILE>>n;
    for(int i=0;i<n;i++){
        FILE>>number;
        myNumbers.push_back(number);
    }

    sort(myNumbers.begin(), myNumbers.end());

    while(FILE>>number){
        if(number_is_found(myNumbers, number)==true)
            count++;
    }

    cout<<count;


    return 0;
}
