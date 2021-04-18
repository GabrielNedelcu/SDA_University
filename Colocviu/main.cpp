#include <bits/stdc++.h>
using namespace std;

struct Animal{
    string name;
    string species;
    int age;
};

bool cmp(const Animal& lhs, const Animal& rhs) {
    if (lhs.age != rhs.age) {
        return lhs.age < rhs.age;
    } else {
        return rhs.name.compare(lhs.name) > 0;
    }
}

bool cmp_endangered(const Animal& lhs, const Animal& rhs) {
    if (lhs.age != rhs.age) {
        return lhs.age > rhs.age;
    } else {
        return rhs.name.compare(lhs.name) > 0;
    }
}

bool alphabeticalSort(const Animal& lhs, const Animal& rhs) {
    return rhs.name.compare(lhs.name) > 0;
}

void count(map<string, vector<Animal>>& animals) {
    for (pair<string, vector<Animal>> species : animals) {
        cout << species.first << " (" << species.second.size() << "): ";
        sort(species.second.begin(), species.second.end(), cmp);
        for (Animal animal : species.second)
            cout << animal.name << " ";
        cout << endl;
    }
}

void endangered(map<string, vector<Animal>>& animals, int& k) {
    vector<Animal> tmp;
    for (pair<string, vector<Animal>> species : animals) {
        if (species.second.size() == 1)
            if (species.second[0].age >= k)
                tmp.push_back(species.second[0]);
    }
    sort(tmp.begin(), tmp.end(), cmp_endangered);

    for (Animal animal : tmp) {
        cout << animal.name << " ";
    }

    cout << endl;
}

void search(map<string, vector<Animal>>& animals, string& toFind) {
    if (animals.find(toFind) == animals.end()) {
        cout << "No match found." << endl;
    } else {
        sort(animals.find(toFind)->second.begin(), animals.find(toFind)->second.end(), alphabeticalSort);

        for (Animal animal : animals.find(toFind)->second) {
            cout << animal.name << " - " << animal.age << endl;
        }
    }
}

void show(map<string, vector<Animal>>& animals) {
    vector<Animal> show;

    for (pair<string, vector<Animal>> species : animals) {
        sort(species.second.begin(), species.second.end(), cmp);
        show.push_back(species.second[0]);
    }

    sort(show.begin(), show.end(), alphabeticalSort);

    for(Animal animal : show) {
        cout << animal.name << " (" << animal.species << ")" << endl;
    }
}

void oldest(map<string, vector<Animal>>& animals, int& oldestAge) {
    vector<Animal> oldest;

    for (pair<string, vector<Animal>> species : animals) {
        for (Animal animal : species.second) {
            if (animal.age == oldestAge)
                oldest.push_back(animal);
        }
    }

    sort(oldest.begin(), oldest.end(), alphabeticalSort);

    for(Animal animal : oldest) {
        cout << animal.name << " ";
    }

    cout << endl;
}


int main() {
    map<string, vector<Animal>> animals;
    int n;
    int tmpAge;
    int oldestAge;
    string line;
    string tmpName;
    string tmpSpecies;
    string command;

    oldestAge = 0;

    cin >> n;
    cin.get();
    for (int i = 0; i < n; i++) {
        Animal tmp;

        getline(cin, line);
        istringstream ss(line);
        ss >> tmpName >> tmpSpecies >> tmpAge;

        if (tmpAge > oldestAge)
            oldestAge = tmpAge;

        tmp.name = tmpName;
        tmp.age = tmpAge;
        tmp.species = tmpSpecies;

        if (animals.find(tmpSpecies) != animals.end()) {
            animals.find(tmpSpecies)->second.push_back(tmp);
        } else {
            vector<Animal> tmpAnimals;
            tmpAnimals.push_back(tmp);
            animals.insert(pair<string, vector<Animal>>(tmpSpecies, tmpAnimals));
        }
    }

    cin >> command;

    if (command == "count") {
        count(animals);
    }

    if (command == "endangered") {
        int k;
        cin >> k;

        endangered(animals, k);
    }

    if (command == "search") {
        string toSearch;

        cin >> toSearch;

        search(animals, toSearch);
    }

    if (command == "show") {
        show(animals);
    }

    if (command == "oldest") {
        oldest(animals, oldestAge);
    }

    return 0;
}