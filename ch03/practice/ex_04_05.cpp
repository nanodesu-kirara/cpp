// ch03/practice/ex_04, ex_05

#include<iostream>
#include<sstream>
#include<chrono>
#include<vector>
#include<list>

using namespace std;

class D {
    public:
        int i;
        explicit D(int init): i { init } {}
};

bool operator<(const D& lhs, const D& rhs);
bool operator<=(const D& lhs, const D& rhs);
bool operator==(const D& lhs, const D& rhs);
bool operator==(const D& lhs, const D& rhs);
ostream& operator<<(ostream& out, const D& rhs) {
    return out << ostringstream { std::to_string(rhs.i) }.str();
}

bool operator<(const D& lhs, const D& rhs) {
    return lhs.i < rhs.i;
}
bool operator<=(const D& lhs, const D& rhs) {
    return lhs.i <= rhs.i;
}
bool operator==(const D& lhs, const D& rhs) {
    return lhs.i == rhs.i;
}

bool operator!=(const D& lhs, const D& rhs) {
    return lhs.i != rhs.i;
}

/* 
    O( min(m, n) )
*/

template <typename Collection>
Collection intersect(const Collection& sler, const Collection& lger) {

    Collection itsecion {};

    auto itra = lger.cbegin();
    auto itrb = sler.cbegin();

    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    /** code here **/
    
    while( itra != lger.cend() && itrb != sler.cend() ) {
        while( *itrb < *itra && itrb != sler.cend() ) {
            // cout << "++itrb "; 
            ++itrb;
        }
        // cout << endl;

        if(*itra == *itrb) {
            // 重复的处理 
            if( itsecion.empty() || itsecion.back() != *itra ) {
                // cout << "put in: " << *itra << endl;
                itsecion.push_back(*itra);
            }
        }

        ++itra;
        // cout << "++itra" << endl;
    }

    /** code here **/
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "It took "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
              << "us.\n";


    return itsecion;
}

template <typename Collection>
Collection unicorn(const Collection& A, const Collection& B) {

    /*
        O(m+n);
        用迭代器，一定要注意判断是否合法
        如果出了运行时问题，很大概率是使用了非法迭代器
        着重检查迭代器在循环中使用
    */
    Collection unionc {};

    auto itra = A.cbegin();
    auto itrb = B.cbegin();

    auto enda = A.cend();
    auto endb = B.cend();

    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    /** code here **/
    while( itra != enda && itrb != endb ) {

        /* 这里也要判断 合法 ，而且是在判断第二个表达式之前 */
        while( itra != enda && *itra <= *itrb ) {
            if( unionc.empty() || unionc.back() != *itra ) {
                // cout << "A: " << *itra
                //     << " B: " << *itrb
                //     << " put in A" << endl;
                unionc.push_back(*itra);
            }
            ++itra;
        }

        /* 一定要作这个判断，不可对非法迭代器解引用 */
        if (itra == enda)
            break; 

        /* 这里也要判断 合法 ，而且是在判断第二个表达式之前 */
        while( itrb != endb && *itrb < *itra ) {
            if( unionc.empty() || unionc.back() != *itrb ) {
                // cout << "A: " << *itra
                //     << " B: " << *itrb
                //     << " put in B" << endl;
                unionc.push_back(*itrb);
            }
            ++itrb;
        }
  
    }


    // cout << "put in rest of A: " << endl;
    while( itra != A.cend() ) {
             if( unionc.empty() || unionc.back() != *itra ) {
                // cout << *itra << " ";
                unionc.push_back(*itra);
             }
            ++itra;
    }

    // cout << "\nput in rest of B: ";
    while( itrb != B.cend() ) {
             if( unionc.empty() || unionc.back() != *itrb ) {
                // cout << *itrb << " ";
                unionc.push_back(*itrb);
             }
            ++itrb;
    }

    /** code here **/
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "It took "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
              << "us.\n";

    return unionc;
    
}

int main() {

    auto va = list<D> {};
    auto vb = list<D> {};

    for(int i = 0; i < 120; i += 2){
        va.push_back(D{i});
    }

    for(int i = 0; i < 40; ++i){
        vb.push_back(D{i});
    }

    // cout << va.size() << " " << vb.size() << endl;

    intersect(va, vb);
    unicorn(va, vb);

    // for( auto x : unicorn(va, vb) )
    //     cout << x.i << endl;

    return 0;
}


