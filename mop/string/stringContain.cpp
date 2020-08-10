/**
 * 判断短字符串b中的所有字母是否都在长字符串a出现的字母集当中
 */
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using std::string;
using std::vector;

// 蛮力轮询 O(mn)
bool StringContain(string& a, string& b)
{
    const int la = a.size();
    const int lb = b.size();

    for (int i = 0; i < lb-1; ++i)
    {
        int j = 0;
        while (j < la)
        {
            if (a[j] == b[i])
                break;
            ++j;
        }
        if (j == la)
            return false;
    }

    return true;
}

// 排序后轮询 O(nlogn) + O(mlogm), O(m+n)
bool StringContainSort(string& a, string& b)
{
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    for (int pb = 0, pa = 0; pb < b.size(); ++pb)
    {
        while (pa < a.size() && a[pa] < b[pb])
            ++pa;
        if (pa >= a.size() || a[pa] > b[pb])
            return false;
    }

    return true;
}

// 素数相乘，每个字母对应一个素数，相乘压缩成一个数字
// 不可行的原因是因为素数相乘的乘积会很大
// code 略

/** 位运算 散列
 * 对a散列得到一个字典，m次
 * 在字典中查b，n次
 * O(m+n)
 * 其实是将字符串a的存储方式进行了一次变更，使得每次查询的平均花费变为O(1)
 * 同时用一个26位数字代替散列表，使得空间花费为O(1)
 */
bool StringContainHash(string& a, string& b)
{
    int hash = 0;
    // 计算a的hash, f(set(a)) -> hash 唯一
    for (int i = 0; i < a.size(); ++i)
        hash |= (1 << (a[i] - 'a'));
    for (int i = 0; i < b.size(); ++i)
        if (((1 << (b[i] - 'a')) & hash) == 0)
            return false;
    return true;
}

// 变位词
bool anagram(string&a, string& b)
{
    vector<int> hash(26, 0);    
    for (int i = 0; i < a.size(); ++i)
        hash[a[i] - 'a'] += 1;
    for (int i = 0; i < b.size(); ++i)
        hash[b[i] - 'a'] -= 1;
    for (auto x : hash)
        if (x != 0)
            return false;
    return true;
}
 
int main()
{
    string a{"abcd"};
    string b{"aadb"};
    if (StringContainHash(a, b))
        std::cout << "true" << std::endl;
    else 
        std::cout << "false" << std::endl;
    return 0;
}
