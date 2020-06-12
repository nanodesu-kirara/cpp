#include<vector>
#include<iostream>

int main(){

    std::vector<int> v { 0, 1, 2, 3 };
    if (!std::empty(v))
    {
       for ( auto e : v ) std::cout << e << std::endl; 
    }
    
}