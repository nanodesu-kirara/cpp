/*
56. 合并区间
给出一个区间的集合，请合并所有重叠的区间。

示例 1:

输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2:

输入: [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
*/

#include<vector>
#include<algorithm>
#include<iostream>
using std::vector;

bool comp(vector<int>& x, vector<int>& y){
    return x[0] < y[0];
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {

    const int len = intervals.size();
    if (len < 2)
        return intervals;

    std::sort(intervals.begin(), intervals.end(), comp);
    vector<vector<int>> ans{};

    for (int i = 0; i < len - 1; ++i) {
        // 该区间右端点 >= 后一个区间左端点
        if (intervals[i][1] >= intervals[i+1][0]) {
            intervals[i+1][0] = intervals[i][0];
            // 并且大于后一个端点的右端点
            if (intervals[i][1] > intervals[i+1][1])
                intervals[i+1][1] = intervals[i][1];
        } else ans.push_back(intervals[i]);
    }

    ans.push_back(intervals[len - 1]);
    return ans;
}

int main() {
    vector<vector<int>> fields{};

    /**
        //test case 1
        fields.push_back(vector<int>{2,6});
        fields.push_back(vector<int>{15,18});
        fields.push_back(vector<int>{8,10});
        fields.push_back(vector<int>{1,3});
    */

    // /**
        //test case 2
        fields.push_back(vector<int>{1,4});
        fields.push_back(vector<int>{4,5});
    // */
    for (auto& x : fields)
        std::cout << x[0] << " " << x[1] << std::endl;

    std::cout << std::endl;
    auto afterMerge = merge(fields);

    for (auto& x : afterMerge)
        std::cout << x[0] << " " << x[1] << std::endl;

}
