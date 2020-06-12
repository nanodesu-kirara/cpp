#include<iostream>
class A {
    public:
        A() = default;
        explicit A(int);
        inline void foo() const { std::cout << "call const function." << std::endl; }
};

class B : public A {
    public:
        inline void foo() { std::cout << "call non-const function." << std::endl; }
};

A returnA(){
    return {2};
}

int main() {
    const B b {};
    b.foo();
    // Node* p = itr.current;
    ++size;
    // p->prev = p->prev->next = new Node { value, p->prev, p };

    // Node* p = itr.current;
    // Iterator retv { p->next };
    // p->prev->next = p->next;
    // p->next->prev = p->prev;
    // delete p;
    // --size;
    // return retv;
    return 0;
}
