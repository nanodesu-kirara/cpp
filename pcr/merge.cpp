/**
 * 1. 提前注明哪些刀可以拿补偿时间
 * 2. 使用了某作业之后的两队（阵容，伤害，最先适配boss，是否可以垫刀）
 * 3. 个人计划的局限性：
 *      a). 
 * */

#include<iostream>

using namespace std;
using std::size_t;

inline size_t give_back(size_t hp, size_t damage, size_t time = 90) {
    return 100 - static_cast<size_t>(hp / damage * time);
}

inline size_t piao(size_t damage) {
    return static_cast<size_t>(damage / 8.18);
}

inline size_t average_damage(size_t damage, size_t time = 90) {
    return static_cast<size_t>(damage / time);
}



int main() {

}


/**
 * 安排出刀实际上是一个规划问题
 * 由于个人不会考虑boss血量问题
 * 个人的最优解之和，其实是远远小于总伤害的最优解的
 * sum(m_1 + m_2 + ... + m_30) << total_max
 * 这个时候按boss来分配可能更好一些
 * 当然我还在考虑这个问题
 * 不过今天最主要的还是解决下面几个问题
 * 1. 哪些刀可以拿补偿时间（提前注明）
 * 2. 哪些作业剩余的刀是可以拿来垫刀的
        或者不仅仅是垫刀，没人愿意打某个boss的时候，该怎么处理
        （这个我暂时还没想好，大家有什么想法吗）
 * 3. 合刀的计算优化（已经在写脚本了）
 * 另外还有一些执行中的问题，
 * 表格格式可以再优化一下（按boss是方便指挥，但不方便后续的统计出刀数目）
 * 管理不在手上又有代刀的情况，一定要提前说明
 * 另外指挥的时候可能需要一个副指挥
 **/

