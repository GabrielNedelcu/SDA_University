#include <bits/stdc++.h>

using namespace std;

unsigned get_biggest_digit(unsigned n){
    unsigned biggest_digit=0;
    while(n!=0){
        if(n%10>biggest_digit)
            biggest_digit=n%10;
        n/=10;
    }

    return biggest_digit;
}


unsigned get_smallest_digit(unsigned n){
    unsigned smallest_digit=9;
    while(n!=0){
        if(n%10<smallest_digit)
            smallest_digit=n%10;
        n/=10;
    }

    return smallest_digit;
}

bool comp(unsigned x, unsigned y){
    if(get_smallest_digit(x)!=get_smallest_digit(y))
        return (get_smallest_digit(x)<get_smallest_digit(y));
    else{
        if(get_biggest_digit(x)!=get_biggest_digit(y))
            return (get_biggest_digit(x)<get_biggest_digit(y));
        else
            return (x<y);
    }
    return false;
}


int main(){
    int n;
    unsigned number;
    vector<unsigned> myNumbers;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>number;
        myNumbers.push_back(number);
    }

    sort(myNumbers.begin(), myNumbers.end(), comp);

    for(vector<unsigned>::iterator it=myNumbers.begin();it!=myNumbers.end();it++)
        cout<<*it<<" ";
    return 0;
}
