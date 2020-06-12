#include<list>
#include<vector>
#include<iostream>

using namespace std;

template <typename Iterator, typename T>
Iterator find(Iterator start, Iterator end, const T& tar) {
    auto itr = start;
    while(itr != end) {
        if( &tar == &(*itr) ) {
            return itr;
        }
        ++itr;
    }
    return end;
}

template <typename L, typename T>
void test(const L& list, const T& tar) {
    auto itr = find(list.cbegin(), list.cend(), tar);
    cout << *itr << endl;
}

int main() {
    vector vec { 4, 7, 9, 10, 44, 98 };
    list lst { 3, 11, 23, 73 };

    test(vec, vec[4]);
    test(lst, *(++lst.begin()));

    return 0;
}
