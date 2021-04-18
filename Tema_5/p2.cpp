#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    int numberOfNodes;
    map<string, unordered_set<string>> adjList;

public:
    Graph(int N, unordered_set<string> dictionary);
    void addEdge(string src, string dest);
    void displayAdjList();
    void showPath(string begin, string end);
};

/**
 * A function to construct a grapf containing all the words in the given dictionary
 * @param nodes number of words(nodes) in the dictionary
 * @param dictionary
 */

Graph::Graph(int nodes, unordered_set<string> dictionary) {
    numberOfNodes = nodes;
    for(string word : dictionary) {
        unordered_set<string> tmp;
        adjList.insert(pair<string, unordered_set<string>>(word, tmp));
    }
}

/**
 * Link @src and @dest
 * @param src
 * @param dest
 */

void Graph::addEdge(string src, string dest) {
    adjList[src].insert(dest);
}

/**
 * Display the adjacency list: show each word and the word that it is connected to
 */

void Graph::displayAdjList() {
    for (auto it = adjList.begin(); it != adjList.end(); it++){
        cout << it->first << " ---> ";
        for(auto  j = it->second.begin(); j != it->second.end(); j++)
            cout << *j << " ";
        cout << endl;
    }
}

/***
 * A function to show the only path between a begin word and an end word (since it is said that there can be only one)
 * @param begin the begin word
 * @param end the end word
 */

void Graph::showPath(string begin, string end) {
    set<string> visited;
    vector<string> path;
    string currentWord = begin;
    cout << currentWord;
    visited.insert(currentWord);
    while ( currentWord != end && adjList[currentWord].size() != 0) {
        for(auto it = adjList[currentWord].begin(); it != adjList[currentWord].end(); it++) {
            if (visited.find(*it) == visited.end()) {
                currentWord = *it;
                visited.insert(currentWord);
                cout << " -> " << currentWord;
                break;
            }
        }
    }
}

/***
 * A function to generate and insert all the possible buckets for a word
 * ex: For CAR we will have the following buckets : CA*, C*R, *AR
 * In such buckets we will store all the words that have the same format so we can link them in a graph
 * @param buckets a list of all the buckets for all the words in our dictionary
 * @param word the word for whom we want to generate buckets
 * @param DIM the length of the words
 */


void createBuckets(map<string, unordered_set<string>>& buckets, string& word, const int DIM) {
    string tmp;
    for (int i = 0; i < DIM; i++) {
        tmp = word;
        tmp[i] = '*';
        /// check if the bucket already exists
        /// if it does, we need to insert the word in found bucket
        /// else, we need to create a new bucket and add the word there
        if (buckets.find(tmp) != buckets.end()) {
            buckets.find(tmp)->second.insert(word);
        }
        else {
            unordered_set<string> tmpBucket;
            tmpBucket.insert(word);
            buckets.insert(pair<string, unordered_set<string>>(tmp, tmpBucket));
        }
    }
}



int main() {
    map<string, unordered_set<string>> buckets;
    unordered_set<string> dictionary;

    string begin;
    string end;
    string tmp;
    string line;

    getline(cin, line);
    istringstream ss1(line);
    ss1 >> begin >> end;

    int DIM = begin.length();
    ///create bucket for the begin word
    createBuckets(buckets, begin, DIM);

    getline(cin, line);
    istringstream ss2(line);

    while (ss2 >> tmp) {
        ///create a dictionary with the words
        dictionary.insert(tmp);
        ///create the buckets for the word
        createBuckets(buckets, tmp, DIM);
    }

    /// check if the end word is fount in the list of given words

    if (dictionary.find(end) == dictionary.end()) {
       cout << "0" << endl;
    } else {
        ///create a graph with the words in our dictionary

        Graph g(dictionary.size(), dictionary);

        ///create the connections between the words

        for (auto it = buckets.begin(); it != buckets.end(); it++) {
            for (auto j = it->second.begin(); j != it->second.end(); j++) {
                for (auto i = it->second.begin(); i != it->second.end(); i++)
                    g.addEdge(*i, *j);
            }
        }

       /* for (auto it = buckets.begin(); it != buckets.end(); it++) {
            cout << "BUCKET " << it -> first << ": ";
            for (auto j = it->second.begin(); j != it->second.end(); j++) {
                cout << *j << " ";
            }
            cout << endl;
        } */

       // g.displayAdjList();


        g.showPath(begin, end);
    }

    return 0;
}