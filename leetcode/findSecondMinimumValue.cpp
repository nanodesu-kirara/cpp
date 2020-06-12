/**
 * 
给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为 2 或 0。如果一个节点有两个子节点的话，那么这个节点的值不大于它的子节点的值。 

给出这样的一个二叉树，你需要输出所有节点中的第二小的值。如果第二小的值不存在的话，输出 -1 。

示例 1:

输入: 
    2
   / \
  2   5
     / \
    5   7

输出: 5
说明: 最小的值是 2 ，第二小的值是 5 。
示例 2:

输入: 
    2
   / \
  2   2

输出: -1
说明: 最小的值是 2, 但是不存在第二小的值。
通过次数12,090 提交次数25,896
**/

/**
 * 第一感觉不是对算法的考察，更像是对基础数据结构掌握的一个考察
 * 
 * 审题：
 * 
 * 对每棵子树而言，根节点都不会大于其子树中的所有节点
 * 
 * 也就是这棵树的节点值随深度，大体上是呈现一种非递减关系
 * 
 * 最小值必然 = 根节点值
 * 
 * 题意是去寻找比根节点值大的节点中最小的一个
 * 
 * 沿着左右子树向下递归地遍历，找到的比根节点大的第二大节点
 * 
 * 考虑到树的性质，采取递归的方法是很方便的
 * 
 * 原本应该是遍历整棵树
 * 
 * 现在遇到比根节点大的就返回
 * 
 * 然后在递归返回的上一层当中比较
 * 
 * 返回较小者（比根节点大）
 * 
 * 
 * 
 */
#include<algorithm>
#include<iostream> 

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    ~TreeNode(){
        if(left != nullptr){
            delete left;
            left = nullptr;
        }         
        if(right != nullptr) {
            delete right;
            right = nullptr;
        } 
        val = 0;
    }
};

/**
 *递归函数
 */
int findSecond(TreeNode * node, const int& min) {
    if (node -> left == nullptr)
        return node -> val;
    
    if (node -> val != min)
        return node -> val; 
    
    int left = findSecond(node -> left, min);
    int right = findSecond(node -> right, min);

    if (left == min)
        return right;
    else if (right == min)
        return left;
    
    return std::min(left, right);
}
 

int findSecondMinimumValue(TreeNode* root) {
    int min = root -> val;
    int result = findSecond(root, min);
    return result == min ? -1 : result;
}

int main() {
    TreeNode* root = new TreeNode(2);
    TreeNode* lcd = new TreeNode(2);
    TreeNode* rcd = new TreeNode(5);
    TreeNode* rcd_l = new TreeNode(5);
    TreeNode* rcd_r = new TreeNode(7);
    rcd -> left = rcd_l;
    rcd -> right = rcd_r;
    root -> left = lcd;
    root -> right = rcd;
    printf("second minimum value is %d\n", findSecondMinimumValue(root));
    delete root;
    return 0;
}
