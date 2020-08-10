/**
 * 2.7 荷兰国旗
 * 其实就是之前的两组划分改成了三组划分
 * 例： 201002112 -> 000111222
 */

#include<vector>
#include"utils.hpp"

using std::vector;
using std::swap;

void ThreeSort(vector<int>&);

int main()
{
    vector<int> vec{ 2, 0 , 1, 0, 0, 2, 1, 1, 2 };
    M::printVector(vec);

    ThreeSort(vec);
    M::printVector(vec);
}

// 假定输入的元素 e ∈ { 0, 1, 2 }
void ThreeSort(vector<int>& vec)
{
    int i = 0, j = 0;
    int k = vec.size() - 1;

    while (j <= k)
    {
        if (vec[j] == 0)
            swap(vec[i++], vec[j++]); // j之所以要后移，是因为换过来的只会是1
        else if (vec[j] == 1)
            ++j;
        else if (vec[j] == 2)
            swap(vec[j], vec[k--]); // j不后移，因为换过来的可能是任何数（没有被j扫描过）
        else
            return; // 如果输入了除{ 0, 1, 2 }之外的数，直接返回
    }

}
