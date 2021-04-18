#include <bits/stdc++.h>

using namespace std;

struct password{
    string pass;
    string sortedPass;
    bool has_anagram=false;
};

void check_for_anagrams(vector<password> &all_passwords, password &a_pass){
    bool has_no_anagrams = true;
    for(vector<password>::iterator it=all_passwords.begin(); it!=all_passwords.end();it++){
        if(it->sortedPass.compare(a_pass.sortedPass)==0){
            has_no_anagrams = false;
            it->has_anagram=true;
        }
    }
    if(has_no_anagrams==true)
        all_passwords.push_back(a_pass);

}

int main(){
    int n;
    password a_pass;
    string tmp_pass;
    vector<password> myPasswords;

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a_pass.pass;

        tmp_pass=a_pass.pass;
        sort(tmp_pass.begin(), tmp_pass.end());
        a_pass.sortedPass=tmp_pass;


        check_for_anagrams(myPasswords, a_pass);
    }

    for(vector<password>::iterator it=myPasswords.begin();it!=myPasswords.end();it++){
        if(it->has_anagram==false)
            cout<<it->pass<<endl;
    }



    return 0;
}
