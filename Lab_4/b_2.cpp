#include <bits/stdc++.h>
using namespace std;

std::queue<int> reverse(std::queue<int> originalQueue) {
    queue<int> reversed_queue;

    if(originalQueue.empty())
        return reversed_queue;
    else {
        int data = originalQueue.front();
        originalQueue.pop();
        reversed_queue = reverse(originalQueue);
        reversed_queue.push(data);
    }
}



int main() {
    int n;
    queue<int> originalQueue;
    queue<int> reversedQueue;

    cin>>n;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin>>tmp;
        originalQueue.push(tmp);
    }

    reversedQueue = reverse(originalQueue);

    while (!reversedQueue.empty()) {
        cout<<reversedQueue.front()<<" ";
        reversedQueue.pop();
    }

    return 0;
}
