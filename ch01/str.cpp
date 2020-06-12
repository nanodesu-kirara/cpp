#include<iostream>

int main(){
    char a[10] = "hello";
    char b[10] = "hello";
    int c[10] = {};
    // for (std::size_t i = 0; i < sizeof(a)/sizeof(char); i++)
    // {
    //     std::cout<<*(a+i);
    // }

    // if (a == b)
    // {
    //     std::cout<<"a == b"<<std::endl;
    // }
    
    // std::cout<<sizeof(c)<<std::endl;

    // a = "world";
    a = b;

    return 0;
}
