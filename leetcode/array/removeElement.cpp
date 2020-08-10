#include<vector>
#include<iostream>

using namespace std;

template<typename T>
void removeElement(vector<T>&, const T&);


int findMaxConsecutiveOnes(vector<int>&);

int main()
{
    vector<int> numbers{2,1,3,2,2,4,2,3,2};
    removeElement(numbers, 2);
    for (auto x : numbers)
        cout << x << endl;
    return 0;
}

template<typename T>
void removeElement(vector<T>& arr, const T& val)
{
    const int len = arr.size();
    if (!len) return;
    int i = -1;int j = 0;
    /**
     * i始终指向遍历到的需要保留的最后一个元素
     * j控制遍历流程
     */
    while (j < len)
    {
        if (arr[j] != val)
            arr[++i] = arr[j];
        ++j;
    }

    arr.erase(arr.begin()+i+1, arr.end());
}

int findMaxConsecutiveOnes(vector<int>& nums) {
    const int len = nums.size();

    int j = 0; int l = 0; int ans = l;

    while (j < len)
    {
        if (nums[j++])
            ++l;
        else
        {
            ans = max(ans, l);
            l = 0;
        }
   }
    
    // ans最后的状态可能还没跟新
    return max(ans, l);

}
