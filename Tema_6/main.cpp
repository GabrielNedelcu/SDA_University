#include <bits/stdc++.h>
#include "voter.h"
using namespace std;

struct CandidateInfo {
    int votes;
    int priority;
};

bool sortByVal(const pair<string, CandidateInfo> &a, const pair<string, CandidateInfo> &b)
{
    if(a.second.votes != b.second.votes)
        return (a.second.votes > b.second.votes);
    else
        return (a.second.priority < b.second.priority);
}

void readVoters(string& filename, map<string, Voter>& database) {
    string line;
    fstream file;
    file.open(filename);

    if (file.is_open()) {
        while (getline(file, line)) {
            Voter tmp(line);
            database.insert(pair<string, Voter>(tmp.getCnp(), tmp));
        }
    } else {
        cout << "ERROR OPENING " << filename;
    }

    file.close();
}

void submitVote(string cnp, string candidate, map<string, Voter>& voterDatabase, map<string, CandidateInfo>& candidates, int& fraud, int& totalVotes,int& priority) {
    if (voterDatabase.find(cnp) == voterDatabase.end()) {
        cout << "CNP invalid"<<endl;
        fraud++;
    } else {
        if(voterDatabase.find(cnp)->second.alreadyVoted()) {
            cout << "Vot deja inregistrat"<<endl;
            fraud++;
        } else if (voterDatabase.find(cnp)->second.canVote()) {
            if (candidates.find(candidate.substr(1, candidate.size()-1)) == candidates.end()) {
                priority++;
                CandidateInfo tmp;
                tmp.votes = 1;
                tmp.priority = priority;
                candidates.insert(pair<string, CandidateInfo>(candidate.substr(1, candidate.size()-1), tmp));
            } else {
                candidates.find(candidate.substr(1, candidate.size()-1))->second.votes++;
            }
            totalVotes++;
            voterDatabase.find(cnp)->second.hasVoted();
        } else {
            cout << "Persoana minora" << endl;
        }
    }
}

void printCandidates(map<string, CandidateInfo>& candidates, int& totalVotes) {
    vector<pair<string, CandidateInfo>> vec;
    map<string, CandidateInfo> :: iterator it2;
    for (it2=candidates.begin(); it2!=candidates.end(); it2++)
    {
        CandidateInfo tmp;
        tmp.votes = it2->second.votes;
        tmp.priority = it2->second.priority;
        vec.push_back(make_pair(it2->first, tmp));
    }

    sort(vec.begin(), vec.end(), sortByVal);

    for (pair<string, CandidateInfo> pair : vec) {
        cout << pair.first << ": " << pair.second.votes << " voturi " << "(";
        cout << fixed << setprecision(2) << (float)pair.second.votes/totalVotes*100 <<"%)"<<endl;
    }
}

void printStatistics (map<string, CandidateInfo>& candidates, int& totalVotes, int& fraud) {
    cout << "Statistici" << endl << "==========" << endl;
    printCandidates(candidates, totalVotes);
    cout << "Incercari de frauda: " << fraud << endl;
}

int main() {
    map<string, Voter> voterDatabase;
    map<string, CandidateInfo> candidates;
    string FILENAME = "evidenta.csv";
    string line;
    char operation;
    int fraud;
    int totalVotes;
    int priority;
    fraud = 0;
    totalVotes = 0;
    priority = 0;

    readVoters(FILENAME, voterDatabase);

    while (getline(cin, line)) {
        istringstream ss(line);
        ss >> operation;
        if (operation == '?') {
            printStatistics(candidates, totalVotes, fraud);
        } else if (operation == '*') {
            printStatistics(candidates, totalVotes, fraud);
            break;
        } else if (operation == '+') {
            string voterCnp;
            string candidate;
            ss >> voterCnp;
            getline(ss, candidate);
            submitVote(voterCnp, candidate, voterDatabase, candidates, fraud, totalVotes, priority);
        }

    }

    return 0;
}
