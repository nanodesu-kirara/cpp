#include<algorithm>
class A {
    public:
    explicit A() = default;
    A(const A&) {}
    explicit A(A&&) {}
    ~A() = default;

    A& operator=(const A&) { return *this; }
    A& operator=(A&&) { return *this; }

};

template <typename T>
void mySwap(T& a, T& b) {
    T temp {a};
    a = b;
    b = temp;
}

int main() {
    // mySwap(a, b);
    std::swap(A {}, A {});
}
