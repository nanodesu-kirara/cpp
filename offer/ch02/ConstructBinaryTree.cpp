/**
 * 输入一棵二叉树的：前序 和 中序遍历
 * 重构树结构
 */

/**
 * 分析：
 * preorder: { 1, 2, 4, 7, 3, 5, 6, 8 }
 * inorder: { 4, 7, 2, 1, 5, 3, 8, 6 }
 * 
 * 先看前序遍历的输入
 * 先根节点，意味着preorder[0] 是根节点
 * 剩下的数字是root的左右子树，但如何划分我们并没有相应的信息
 * 
 * 所以结合中序遍历来看
 * 中序输出根节点，在inorder中找到值为preorder[0]的项
 * 也就是说inorder数组当中的1，将左右两个部分划分成了左右子树
 * 
 * 也就是说preorder[1] ~ preorder[3] 是左子树，余下的是右子树
 * 这样的一个划分
 * 
 * 这时发现要去重构{ 2, 4, 7 }这个序列
 * 那我们就要重复上面的分析过程
 * 
 * 也就是原问题被拆分成了重构一个个子序列的过程
 * 这是一个明显的可以用递推解决的问题
 * 
 * 想到这里我们差不多就可以开始动手了
 * 
 */

#include<vector>
#include<iostream>

using std::vector;

struct BinaryTreeNode
{
    int val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

// 先序(根)遍历
void preorder(BinaryTreeNode* node, vector<int>& res)
{
    if (node == nullptr)
        return;
    
    res.push_back(node -> val);
    preorder(node -> left, res);
    preorder(node -> right, res);

}

// 中序遍历
void inorder(BinaryTreeNode* node, vector<int>& res)
{
    if (node == nullptr)
        return;
    
    inorder(node -> left, res);
    res.push_back(node -> val);
    inorder(node -> right, res);
}


BinaryTreeNode* widget(const vector<int>& preorder, const vector<int>& inorder, int x, int y, int len);
BinaryTreeNode* Construct(const vector<int>& preorder, const vector<int>& inorder)
{
    // 输入非空判断
    if (preorder.empty() || inorder.empty())
        return nullptr;

    // 判断是否元素一致(排序, hash)

    return widget(preorder, inorder, 0, 0, preorder.size());
}

BinaryTreeNode* widget(const vector<int>& preorder, const vector<int>& inorder, int x, int y, int len)
{
    // 递归基准情形
    if (len == 0)
        return nullptr;

    int root = preorder[x];

    int l = len;

    while (l > 0 && inorder[y+l-1] != root)
        --l;
    
    return new BinaryTreeNode
    {
        root,
        widget(preorder, inorder, x+1, y, l-1),
        widget(preorder, inorder, x+l, y+l, len-l)
    };

}

template<typename T>
void PrintVector(const vector<T>& v)
{
    for (auto x : v)
        std::cout << x << " ";
    std::cout << std::endl;
}

int main()
{
    vector<int> preorderInput{ 1, 2, 4, 7, 3, 5, 6, 8 };

    vector<int> inorderInput{ 4, 7, 2, 1, 5, 3, 8, 6 };

    BinaryTreeNode* root = Construct(preorderInput, inorderInput);

    vector<int> preorderRes{};
    vector<int> inorderRes{};

    preorder(root, preorderRes);
    inorder(root, inorderRes);

    PrintVector(preorderRes);
    PrintVector(inorderRes);
}
