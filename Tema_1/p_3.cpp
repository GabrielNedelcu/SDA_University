#include <bits/stdc++.h>

using namespace std;

class Person{
public:
    string nume;
    string prenume;
    string cnp;
    uint32_t nr_cerere;

    void print();

};

void Person::print(){
    cout<<nume<<" "<<prenume<<" "<<nr_cerere;
}

vector<Person> readData(uint32_t peopleCount) {
    vector<Person> my_persons;
    Person one_person;
    for(int i=0;i<peopleCount;i++){
        cin>>one_person.nume>>one_person.prenume>>one_person.cnp>>one_person.nr_cerere;
        my_persons.insert(my_persons.begin(),one_person);
    }

    return my_persons;
}

void erasePerson(vector<Person> * people) {
    people->erase(people->begin()+people->size()-1);

}

vector<Person>::iterator find_max(vector<Person> * people) {
    vector<Person>::iterator myMax;
    vector<Person>::iterator i;
    int max=(*people).at(0).nr_cerere;
    myMax=people->begin();
    for(i=people->begin()+1;i<people->end();i++){
        if((*i).nr_cerere>max){
            max=(*i).nr_cerere;
            myMax=i;
        }
    }
    return myMax;
}

int main(){
    int no_of_persons,m;

    cin>>no_of_persons;

    vector<Person> people = readData(no_of_persons);

    cin>>m;
    for(int i=0;i<m;i++)
        erasePerson(&people);

    (*find_max(&people)).print();


    return 0;
}
