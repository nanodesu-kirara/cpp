/**
 * 5.1 合并两个数组
 * 原先均不保证有序
 * 将A2数据插入A1当中，A1后有足够多的空间
 * 插入后确保A1中数字有序
 */

#include<vector>
#include<iostream>

using std::vector;

// B放到A里面
void MergeSort(vector<int>& a, vector<int>& b)
{
    const int la = a.size();
    const int lb = b.size();

    if (! lb)
        return;

    // capacity 不够会自动扩容
    a.resize(la + lb);

    int pa, pb, p; 
    p = a.size() - 1;
    pa = la - 1;
    pb = lb - 1;

    while (pa >= 0 && pb >= 0)
    {
        if (a[pa] < b[pb])
            a[p--] = b[pb--];
        else
            a[p--] = a[pa--];
    }

    // 原先就在a头部的就不用动了

    while (pb >= 0)
        a[p--] = b[pb--];

}

int main()
{
    vector<int> a{ 1, 3, 5, 7, 9 };
    // vector<int> a{};
    // vector<int> b{ 0, 2, 4, 6, 8 };
    vector<int> b{};

    MergeSort(a, b);

    for (auto x : a)
        std::cout << x << ' ';

    std::cout << std::endl;
}
