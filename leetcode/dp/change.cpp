/**
 * 凑零钱
 * 给定amount，给定币种[a, b, c]
 * 求凑出给定amount所需的coin的最小数目
 */

/**
 * 通常所求的最优解的定义就是所定义的状态
 * 本题，所求amount金额所需coin的最小数目
 * 可由 min{ amount - coins[i] } + 1 转换得到
 * 也就是可由几个最优子结构转换得到
 * 需要记录的就只是这个状态
 * 这个状态包含了我们需要的所有子结构的信息
 * 
 * 
 * 由底向上：
 * 底很好确认，但不好确认步长
 * 如果只走可能的步长，例如coins = { 2，4, 5 }，不会走到3
 * 也就是认为DP{3}这个状态是不存在的，但其实是-1
 * 就很难把握了
 * 
 * 事实上，我们走到DP{ i }，才会知道需要用到哪些子结构信息
 * 而不是在DP{ i - coin }这步考虑能转移到那个状态
 * 
 * 在自底向上的过程中，我们需要收集足够的信息
 * 而这些信息是不是最终结果需要的，我们并不知道
 * 换言之，如果我们知道需要收集哪些信息
 * 我们就已经知道最优解是哪些最优子结构的集合了
 * 所以这其实带有一定的「盲目」在里面
 * 
 * 所以这里只需要DP{1}, DP{2}...DP{amount}这样的自底向上就可以了.
 */
#include<vector>
#include<iostream>
using std::vector;

int change(int amount, vector<int> coins) {
    vector<int> dp(amount + 1, -1);
    dp[0] = 0; // 金额为0时，零钱数也是0
    for (std::size_t i = 1; i <= amount; ++i) {

        int min = -1;
        for (const auto& c : coins)
            if (i - c >= 0)
                min = min < 0 ? dp[i - c] : std::min(min, dp[i - c]);
        
        dp[i] = min < 0 ? -1 : min + 1;
    }

    return dp[amount];
}

/**********需要打印序列*************/
vector<int> printChange(int amount, vector<int> coins) {
    vector<int> dp(amount + 1, -1);
    vector<vector<int>> path(amount + 1);
    dp[0] = 0; // 金额为0时，零钱数也是0
    for (std::size_t i = 1; i <= amount; ++i) {

        int min = -1;
        int index = -1;
        
        /**
         * 这里的判断语句属实有点烦
         * 原本合并的情形这里必须拆分开来
         */
        for (const auto& c : coins)
            if (i - c >= 0)
                if (min < 0)
                {
                    min = dp[i-c];
                    if (min >= 0)
                        index = i-c;
                } else
                    if (dp[i-c] < min) {
                        min = dp[i-c];
                        index = i-c;
                    }
                
        
        dp[i] = min < 0 ? -1 : min + 1;
        if (index >= 0) {
            path[i] = path[index];
            path[i].push_back(i - index);
        }
    }   

    return path[amount];
}
/**********需要打印序列*************/

int main() {
    int amount = 11;
    vector<int> coins { 1, 2, 5 };
    // std::cout << "when amount = " << amount << ", coins = [1, 2, 5]\n" << "ans is: " << change(amount, coins) << std::endl;
    vector<int> path = printChange(amount, coins);
    for (auto x : path)
        std::cout << x << std::endl;
}

