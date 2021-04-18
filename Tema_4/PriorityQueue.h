/** ************************************************************************
 *
 * Fisier header pentru functiile necesare pentru cozile cu prioritati.
 *
 ***************************************************************************/

#pragma once

#include <cstdint>
#include <bits/stdc++.h>
#include "Patient.h"

using namespace std;

template <class T>
class PriorityQueue {
    vector<queue<T>> myQueue;

    uint32_t queueCapacity = 0; // the number of priorities
    int queueElements = 0; // the number of patients in the list

public:

    PriorityQueue(uint32_t maxPriorityValue) {
        queueCapacity = maxPriorityValue;

        for (int i = 0; i <= maxPriorityValue; i++) { ///initialize my structure with @param maxPriorityValue empty queues
            queue<T> tmpQueue;
            myQueue.push_back(tmpQueue);
        }
    }


    /**
     * Functia va intoarce numarul de elemente din coada.
     * @return numarul de elemente din coada.
     */

    uint32_t size() {
        return queueElements;
    }
    
    /**
     * Functia va intoarce true daca coada este goala.
     * @return true dacă coada este goala, altfel false
     */

    bool empty() {
        for (int i = 0; i <= queueCapacity; ++i) {
            if(!myQueue[i].empty())
                return false;
        }
        return true;
    }
    
    /**
     * Functia va insera in coada elementul cu prioritatea specificata.
     * @param value elementul care trebuie adaugat in coada.
     * @param priority prioritatea cu care se adauga in coada elementul.
     */

    /// De modificat insertia atunci cand nu mai exista pacient -- verifict prin empty si aduag cu push
    void push(T value, uint32_t priority) {
        myQueue[priority].push(value);
        queueElements++;
    }
    
    /**
     * Functia va extrage si elimina din coada pacientul cu prioritatea maxima.
     * @return elementul cu prioritatea maxima
     */
    T pop() {
        T value;
        for (int i = 0; i <= queueCapacity; i++) {
            if(myQueue[i].front().age != 0) {
                /*cout << myQueue[i].front().firstName << " " << myQueue[i].front().lastName << " " << myQueue[i].front().age
                    << " " << myQueue[i].front().gender << endl;*/
                value = myQueue[i].front();
                myQueue[i].pop();
                queueElements--;
                break;
            }
        }
        return value;
    }
    
    /**
     * Destructorul dezaloca memoria utilizata de coada, daca s-a alocat in 
     * constructor. Altfel, lasat-l gol.
     */
    ~PriorityQueue() {
        // TODO: scrieti codul aici
    }
};