#include<iostream>
#include<vector>
#include<string>
using namespace std;

void myCastSwap(vector<string>& x, vector<string>& y);
void myMoveSwap(vector<string>& x, vector<string>& y);
void show(const vector<string>& x, const vector<string>& y);

int main(){
    vector<string> x {"vector", "x"};
    vector<string> y {"vector", "y"};

    show(x, y);

    myCastSwap(x, y);
    // myMoveSwap(x, y);

    show(x, y);

    return 0;
}

/*用static_cast将左值转换为右值*/
void myCastSwap(vector<string>& x, vector<string>& y){
    vector<string> temp = static_cast<vector<string>&&>(x);
    x = static_cast<vector<string>&&>(y);
    y = static_cast<vector<string>&&>(temp);
}

void myMoveSwap(vector<string>& x, vector<string>& y){
    vector<string> temp = std::move(x);
    x = std::move(y);
    y = std::move(temp);
}

void show(const vector<string>& x, const vector<string>& y){

    cout << "---------------show---------------" << endl;
    for( auto str : x )
        cout << str << " ";
    cout << endl;
    for( auto str : y )
        cout << str << " ";
    cout << endl << "---------------show---------------" << endl;

}
