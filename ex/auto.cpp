#include<iostream>
using std::endl;
using std::cout;
void foo(int, char);

template <typename T>
void printStr(T& arr);

template <typename Container, typename Index>
auto authAndAccess(Container& c, Index i)
   {
      /*do sth*/
      return c[i];
}

int main() {
    const int arr[20] = {0};
    /*incorrect
    auto(&)[n] typ = str;
    */
    auto& typr = arr;
    auto* typp = arr;
    auto& typf = foo;

    cout << typp << endl;
    printStr(typp);
    // typf(1 , 'a');
}

void foo(int a, char b) {
    cout << "a is \"" << a << "\", and b is \"" << b << "\"" << endl;
}
template <typename T>
void printStr(T& arry) {
    cout << arry << endl;
}
