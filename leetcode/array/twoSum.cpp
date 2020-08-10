#include<vector>
#include<iostream>

using namespace std;
/**
 * 给定一个升序数组和数字，
 * 找出数组中 和等于该数字的 两个数字的下标
 */
vector<int> twoSum(const vector<int>&, int);

int main()
{
    vector<int> numbers{2,7,11,15};
    int target = 9;
    vector<int> index = twoSum(numbers, target);
    for (auto x : index)
        cout << x << endl;
    return 0;
}

vector<int> twoSum(const vector<int>& arr, int target)
{
    const int len = arr.size();
    if(len < 2) return vector<int>{};
    int i = 0; int j = len - 1;
    int sum = 0;
    while (i < j)
    {
        sum = arr[i] + arr[j];
        if (sum < target)
            ++i;
        else if (sum > target)
            --j;
        else return vector<int> { i+1 , j+1 };
    }
    return vector<int> {};
}
