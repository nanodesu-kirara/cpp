#include<iostream>
using namespace std;

class A {
    public:
        A(int num);
        ~A();
        A(const A& a);
        A(A&& a);
        void show();
    private:
        int count;
};

A::A(int num):count{num}{
    cout<<"ctor "<<count<<endl;
}
A::~A(){
    cout<<"dtor "<<count<<endl;
}
A::A(const A& a):count{a.count+1}{
    cout<<"copy "<<a.count<<" to "<<count<<endl;
}
A::A(A&& a):count{a.count+1}{
    cout<<"move "<<a.count<<" to "<<count<<endl;
}
void A::show(){cout<<count<<endl;}

A returnValue(const A& a);
const A& returnRef(A& a);
A&& returnRef();

A strangeReturn();

int main(){
    // A a{0};
    // returnValue(a);
    strangeReturn();
    // A s {strangeReturn()};
    // s.show();

    // segmentation fault (core dumped)
    // A b{returnRef()};
    return 0;

}

// 返回一个(右)值
A returnValue(const A& a){
    return a;
}

// 返回一个引用(to a constant)
const A& returnRef(A& a){
    return a;
}

// 不存在返回一个右值引用
// 返回一个右值的引用
// 意味着
// 返回一个局部变量的引用
// 意味着
// undefined behavior
// dtor一定会在离开函数时就被调用
A&& returnRef(){
    return A{10};
}

// -fno-elide-constructors
// return value optimization
// Copy elision
// 编译器优化导致copy/move omitted 
A strangeReturn(){
    A temp{20};
    return temp;
}
