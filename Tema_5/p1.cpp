#include <bits/stdc++.h>
using namespace std;

int main() {
    multiset<int> numbers;
    int tmp;

    while (cin>>tmp)
        numbers.insert(tmp);

    while (numbers.size() > 1) {
        int le; /// last element (biggest element)
        int pe; /// pen. element (second biggest (equal to biggest) number)

        auto it = numbers.end();

        le = *(--it);
        pe = *(--it);
        numbers.erase(numbers.lower_bound(le));
        numbers.erase(numbers.lower_bound(pe));

        if (le != pe)
            numbers.insert(abs(le - pe));
    }

    if (numbers.size())
        cout << *(numbers.begin());
    else
        cout << "-1";

    return 0;
}
