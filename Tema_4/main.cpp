#include <bits/stdc++.h>
#include "Patient.h"
#include "PriorityQueue.h"

#define MAX_PRIORITY 10

using namespace std;

int main() {

    PriorityQueue<Patient> myQueue(10);
    Patient tmpPatient;
    Patient maxPriorityPatient;
    uint32_t tmpPriority;
    char operation;
    string line;

    while (getline(cin, line)) {
        istringstream ss(line);
        ss >> operation;
        if (operation == '*') {
            break;
        }

        if (operation == '+') {
            ss >> tmpPatient.firstName >> tmpPatient.lastName >> tmpPatient.age >> tmpPatient.gender >> tmpPriority;
            myQueue.push(tmpPatient, tmpPriority);
        }

        if (operation == '-') {
            maxPriorityPatient = myQueue.pop();
            cout << maxPriorityPatient.firstName << " " << maxPriorityPatient.lastName << " " <<maxPriorityPatient.age
                 << " " << maxPriorityPatient.gender << endl;
        }
    }

    // myQueue.print();

    return 0;
}