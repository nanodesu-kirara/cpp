// ch03/practice/ex01
#include<iostream>
#include<vector>
#include<list>
#include<chrono>

using namespace std;

template<class ListP>
void printLot(vector<int>& L, ListP& P) {
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    /** code here **/
    for (auto i : P)
        L.at(i-1);
    /** code here **/
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "It took "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
              << "us.\n";
}

template<class ListP>
void printLot(list<int>& L, ListP& P) {
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    /** code here **/
    auto itrl = L.cbegin();
    auto itrp = P.cbegin();
    int i = 0;
    while(itrl != L.cend()) {
        /* 同样是对迭代器解引用，vector、list时间也不同 */
        if (i + 1 == *itrp) {
            itrp++;
            *itrl;
        }
        itrl++;
        i++;
    }
    /** code here **/
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "It took "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
              << "us.\n";
}

int main() {
    /* L */
    vector<int> vecL(1000);
    list<int> lstL(0);
    vecL.clear();
    lstL.clear();

    for (int i = 0; i < 1000; ++i) {
        vecL.push_back(i+1);
        lstL.push_back(i+1);
    }
    

    /* P */
    vector<int> vecP500(500);
    vector<int> vecP1000(1000);
    list<int> lstP500(0);
    list<int> lstP1000(0);
    vecP500.clear();
    vecP1000.clear();

    for (int i = 0; i < 1000; i+=2) {
        vecP500.push_back(i+1);
        lstP500.push_back(i+1);
    }

    for (int i = 0; i < 1000; ++i) {
        vecP1000.push_back(i+1);
        lstP1000.push_back(i+1);
    }
    
    cout << "===============================" << endl;

    cout << "<vector, vector> P size 500:" << endl;
    printLot(vecL, vecP500);
    cout << "<vector, vector> P size 1000:" << endl;
    printLot(vecL, vecP1000);

    cout << "===============================" << endl;

    cout << "<vector, list>: P size 500:" << endl;
    printLot(vecL, lstP500);
    cout << "<vector, list>: P size 1000:" << endl;
    printLot(vecL, lstP1000);
 
    cout << "===============================" << endl;

    cout << "<list, vector>: P size 500:" << endl;
    printLot(lstL, vecP500);
    cout << "<list, vector>: P size 1000:" << endl;
    printLot(lstL, vecP1000);

    cout << "===============================" << endl;

    cout << "<list, list>: P size 500:" << endl;
    printLot(lstL, lstP500);
    cout << "<list, list>: P size 1000:" << endl;
    printLot(lstL, lstP1000);

    cout << "===============================" << endl;

    return 0;
}
