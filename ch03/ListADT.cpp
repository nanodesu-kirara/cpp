#include<iostream>
#include<vector>
#include<list>
using namespace std;

void foo() {
    std::vector<int> a { 0, 1, 2, 3, 4 };
    std::list<int> b { 0, 1, 2, 3, 4 };
    std::vector<int> c(10);// { 0, 1, 2, 3, 4 };
    // b.pop_front();
    // b.push_front(0);
    // std::cout << a[10] << std::endl;
    // std::cout << a.at(10) << std::endl;
    std::cout << c.capacity() << std::endl;
    c.reserve(100);
    std::cout << c.capacity() << std::endl;

}

void prtList(const vector<int>& v) {
    cout<<"------print list--------"<<endl;
    for(auto item : v)
        cout << item << endl;
    cout<<"------print list--------"<<endl;
}

void prtAddress(const vector<int>& v) {
    cout<<"------print address-----"<<endl;
    /* iterator is not allowed because of passing-by-ref-to-const */
    for(vector<int>::const_iterator citr = v.cbegin(); citr != v.cend(); citr++)
        cout<< &(*citr) << endl;
    cout<<"------print address-----"<<endl;
}


/* 
    如果一个行为是undefined behavior的，
    那么这个行为的结果就应该避免，无论lst.end()++返回是不是==lst.end()
    在某种特定实现下可能成立（但实际二者并不是指向同一个位置）
    但是不要依赖这个“奇怪的知识”，
    也没有必要去深究，一个晚上全浪费了。
*/

template <typename Container>
void removeEveryOtherItem(Container& lst) {
    // auto itr = lst.begin();
    // 有个问题，空表时lst.begin() == lst.end()
    // do
    // {
    //     cout << *itr << endl;
    //     itr = lst.erase(itr);
    // } while (itr++ != lst.end());

    // 对begin()++的行为未定义
    /* 在特定实现中这些迭代器可能可解引用，但库从不假设它们能。 */

    // for (auto itr = lst.begin(); itr != lst.end(); )
    // {
    //     cout<< *itr << " " << &(*itr) << endl;
    //     cout<< *lst.end() << "---end---" << &(*lst.end()) << endl;
    //     itr = lst.erase(itr);
    //     cout<< *itr << " " << &(*itr) << endl;
    //     itr++;
    //     cout<< *itr << " " << &(*itr) << endl << endl;

    // }
    
}

template<typename Container, typename Element>
void change(const Container& c, const Element& e) {
    
}

template<typename Container>
auto bgn(Container& c) -> decltype(c.begin()) {
    return c.begin();
}

template<typename Container>
void prtCont(const Container& c, ostream& out = cout) {
    if (empty(c))
        out << "(empty)";
    else {
        out << "[ ";
        for( auto e : c )
            out << e << " ";
        out << "]" << endl;
    }
}

int main() {
    vector a {1};
    vector b {2};
    auto itr = a.begin()
    b.insert(itr, 1); // incorrect
    for ( auto i : a) cout << i << " ";
    cout<<endl;
    for ( auto i : b) cout << i << " ";

    // std::vector<char> vec { 0, 1, 2, 3, 4 };
    // cout<<vec.size()<<endl;
    // cout<<vec.capacity()<<endl;
    // vec.reserve(10);
    // cout<<vec.size()<<endl;
    // cout<<vec.capacity()<<endl;
    // vec.reserve(2);
    // cout<<vec.size()<<endl;
    // cout<<vec.capacity()<<endl;
    // vec.resize(20);
    // cout<<vec.size()<<endl;
    // cout<<vec.capacity()<<endl;
    // prtCont(vec);

    // // foo();
    // prtList(vec);
    // vector<int>::iterator itr = vec.begin();

    /*
      vector<int>::const_iterator citr = vec.cbegin();
      *citr = 2;
    */

    /* 
        operator* 
        & erase
        & insert 
        都不会进行安全检查 
       vec.erase(vec.begin()-2, vec.begin());
       vec.insert(vec.begin()-3, 5);
    */

    /* 
    迭代器只需要视作特殊的指针，erase(itr)之后
    itr指向的位置不变，
    对于vector来说
    如果不是指向最后一个元素，
    那么会指向内容会被原先的下一个元素替代（所有元素前移一个单元）
    对于list来说
    依旧是指向原来的内容
    */

    // std::vector<int>::iterator itr = vec.end()-1;
    // prtAddress(vec);
    // cout<<"--------------"<<endl;
    // cout << &(*itr) << endl;
    // cout<<"--------------"<<endl;
    // vec.erase(itr);
    // cout << &(*itr) << endl;
    // cout<<"--------------"<<endl;
    // *itr = 5;
    // prtAddress(vec);
    
    // for( auto x : vec ) cout << x << endl;
    // cout<<"--------------"<<endl;
    // cout << *(itr + 2) << endl;

    // list<int> lst { 0, 1, 2, 3, 4 };
    // auto itr = lst.begin();
    // lst.erase(itr);
    // cout << &(*itr) << endl;
    // cout << *itr << endl;
    // cout << &(*itr) << endl;
    // *itr = 9;
    // for (auto i : lst) cout << i << endl;
    // lst.clear();
    // removeEveryOtherItem< list<int> >(lst);

    // auto itr = vec.end();
    // auto nitr = vec.end()+1;
    // cout<<&(*itr)<<endl;
    // cout<<&(*nitr)<<endl;
    // int a[10] {};

    // cout<<*begin(a)<<endl;
    // cout<<*begin(lst)<<endl;
    // auto end = lst.end();
    // lst.erase(lst.begin());
    // cout << &(*end)<< endl;
    // cout << &(*(++end)) << endl;
    // // cout << &(*lst.erase(++lst.end())) << endl;
    // cout << "----------" << endl;
    // if (++end == end)
    // {
        // for (auto i : lst) cout << i << endl;
    // }

    // prtCont<vector<int> >(vec);
    

    return 0;
}
