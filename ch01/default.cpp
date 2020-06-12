#include<iostream>

class IntCell {
    public:
        explicit IntCell(int initialValue = 0);
        ~IntCell();

        /* copy/move ctor is implicitly declared as delete */
        explicit IntCell(const IntCell&);
        explicit IntCell(IntCell&&);

        /* copy/move assignment is also implicitly declared as delete */
        IntCell& operator=(const IntCell&);
        IntCell& operator=(IntCell&&);

        int read() const;
        void write(int x);

    private:
        int* storedValue;
};

IntCell::IntCell(int initialValue): storedValue { new int { initialValue } } {}
IntCell::~IntCell() { delete storedValue; }

IntCell::IntCell(const IntCell& cell): storedValue { new int { *cell.storedValue } } {}
IntCell::IntCell(IntCell&& cell): storedValue { storedValue = cell.storedValue } { cell.storedValue = nullptr; }

IntCell& IntCell::operator=(const IntCell& cell) { 
    /* 
        证同测试 
        不包含异常安全
        详见条款11
    */
    if (this == &cell) return *this;
    
    delete storedValue;
    storedValue = new int { *cell.storedValue };

    /*
        *storedValue = *cell.value
        在何种情况下何种更好？
        1. 弃用原先指向的对象，再开辟一块新的 
        or
        2. 在修改原先指向的对象（需要确保该对象的copy assignment）

        个人观点： 第一种更保险，而第二种会高效一点点, 但伴随着未定义copy assignment的风险
        对于基础内置的C类型，采用第一种， 赋值语句即可
    */

   /*
        使用copy and swap
        IntCell copy = cell;
        std::swap(*this, copy);
        return *this;
   */

    return *this;
}

IntCell& IntCell::operator=(IntCell&& cell) {

    delete storedValue;
    storedValue = cell.storedValue;
    cell.storedValue = nullptr;
    return *this;

    /* 
        使用swap
        std::swap(storedValue, cell.storedValue);
        return *this;
    */
    
}

int IntCell::read() const { return *storedValue; }
void IntCell::write(int x) { *storedValue = x; }

void foo();

int main() {
    foo();
    return 0;
}

void foo() {
    IntCell cellA {2};
    IntCell cellB { cellA };
    IntCell cellC {};

    cellC = cellB;
    cellA.write(4);

    std::cout << cellA.read() << std::endl
                << cellB.read() << std::endl
                    << cellC.read() << std::endl;

}
