#include<iostream>
#include<chrono>
#include<list>

using namespace std;
using size_t = std::size_t;

void josphus(list<int>&, size_t);

void josphus(list<int>& lst, size_t m) {
    auto itr = lst.cbegin();
    const auto end = lst.cend();

    // cout << "delete order: " << endl;
    chrono::steady_clock::time_point start = chrono::steady_clock::now();
    while(lst.begin() != end) {

        for(size_t i = 0; i < m; i++) {
            if(lst.begin() == end)
                break;
            else if(itr == end)
                itr = lst.begin();
            ++itr;
        }

        if(lst.begin() == end)
            break;
        else if(itr == end)
            itr = lst.begin();
        
        /* delete node here */
            // cout << *itr << " ";
            itr = lst.erase(itr);
        /* delete node here */
        
    }
    chrono::steady_clock::time_point endt = chrono::steady_clock::now();

    cout << endl;
    std::cout << "It took "
              << chrono::duration_cast<chrono::microseconds>(endt - start).count()
              << "us.\n";
}

int main() {

    size_t m = 1;
    size_t n = 1000;
    list<int> lst {};
    for(size_t i = 1; i <= n; ++i)
        lst.push_back(i);
    josphus(lst, m); 
    return 0;
}

