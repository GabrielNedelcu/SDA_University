#include <string>
#include <sstream>
using namespace std;

#pragma once

struct Cnp {
    int sex;
    int year;
    int month;
    int day;
    string rest;
};

class Voter {
private:
    string name;
    string address;
    Cnp cnp;
    string identifier;
    bool voted = false;

public:
    Voter(string input);
    bool canVote();
    void print();
    string getCnp();
    bool alreadyVoted();
    void hasVoted();
};

Voter::Voter(string input) {
    string tmpName;
    string tmpAddress;
    string tmpCnp;
    string tmpIdentifier;
    istringstream ss(input);

    getline(ss, tmpName, ',');
    getline(ss, tmpAddress, ',');
    getline(ss, tmpCnp, ',');
    getline(ss, tmpIdentifier, ',');

    name = tmpName;
    address = tmpAddress;
    identifier = tmpIdentifier;

    cnp.sex = tmpCnp.c_str()[0]-'0';
    if (cnp.sex == 1 || cnp.sex == 2) {
        cnp.year = 1900 + (tmpCnp.c_str()[1]-'0') * 10 + tmpCnp.c_str()[2]-'0';
    } else if (cnp.sex == 3 || cnp.sex == 4) {
        cnp.year = 1800 + (tmpCnp.c_str()[1]-'0') * 10 + tmpCnp.c_str()[2]-'0';
    } else if ( cnp.sex == 5 || cnp.sex == 6) {
        cnp.year = 2000 + (tmpCnp.c_str()[1]-'0') * 10 + tmpCnp.c_str()[2]-'0';
    }
    cnp.month = (tmpCnp.c_str()[3]-'0') * 10 + tmpCnp.c_str()[4]-'0';
    cnp.day = (tmpCnp.c_str()[5]-'0') * 10 + tmpCnp.c_str()[6]-'0';
    cnp.rest = tmpCnp;
}

bool Voter::canVote() {
   /* int ageAtTheMomentOfVote;
    if (2018-cnp.year > 18)
        return true;
    else {
       if (cnp.month < 5)
           return true;
    }
    return false; */

   if (cnp.sex == 1 || cnp.sex == 2 || cnp.sex == 3 || cnp.sex == 4 )
        return true;
    else
    if (cnp.year == 2000 && cnp.month < 05)
        return true;
    return false;
}

void Voter::print() {
    cout << name << " " << address << " " << cnp.year << " " << cnp.day << " " << cnp.month << " " << identifier << endl;
}

string Voter::getCnp() {
    return cnp.rest;
}

bool Voter::alreadyVoted() {
    return voted == true;
}

void Voter::hasVoted() {
    voted = true;
}