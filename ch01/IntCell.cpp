#include<iostream>

class IntCell{
    public:
        explicit IntCell();
        explicit IntCell(int initialValue);
        IntCell(char non_explicit);
        // explicit IntCell(int initialValue = 1);
        // try it!
        // both are default ctor
        int read() const;
    private:
        int storedValue;
};

IntCell::IntCell():storedValue{0}{
    std::cout<<"The non-param default ctor was called."<<std::endl;
}

IntCell::IntCell(int initialValue):storedValue{initialValue}{
    std::cout<<"The integer ctor was called."<<std::endl;
}

IntCell::IntCell(char non_explicit):storedValue{non_explicit}{
    std::cout<<"The charactor ctor was called."<<std::endl;
}

int IntCell::read() const {return storedValue;}

int main(){
    IntCell cell;
    cell = 'a';
    // equals to:
    // IntCell temporary = 'a';
    // cell = temporary;
    std::cout<<cell.read()<<std::endl;
    IntCell* pic = new IntCell{};
    pic->read();
    delete pic;
    return 0;
}
