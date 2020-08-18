/**
 * 二叉树的几种遍历的不同实现方法
 */

#include<vector>
#include<stack>
#include<queue>
#include<iostream>
using std::vector, std::stack, std::queue;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

/*递归版本*/

// 先序(根)遍历
void preorder(TreeNode* node, vector<int>& res)
{
    if (node == nullptr)
        return;
    
    res.push_back(node -> val);
    preorder(node -> left, res);
    preorder(node -> right, res);

}

// 中序遍历
void inorder(TreeNode* node, vector<int>& res)
{
    if (node == nullptr)
        return;
    
    inorder(node -> left, res);
    res.push_back(node -> val);
    inorder(node -> right, res);
}

// 后序遍历
void postorder(TreeNode* node, vector<int>& res)
{
    if (node == nullptr)
        return;
    
    postorder(node -> left, res);
    postorder(node -> right, res);
    res.push_back(node -> val);
}

/*递归版本*/

/*非递归版本*/

void preorderIteratively(TreeNode* root, vector<int>& res)
{
    if (root == nullptr)
        return;

    stack<TreeNode*> s{};
    s.push(root);

    TreeNode* p = root;

    while (! s.empty())
    {
        res.push_back(p -> val);

        // 提前压入右子树
        if (p -> right != nullptr)
            s.push(p -> right);
        
        // 左子树不为空则转向左子树
        if (p -> left != nullptr)
            p = p -> left;
        else
        {
            // 转向右子树
            p = s.top();
            s.pop(); // 最后一个出栈的元素是root
        }

    }
}

// 中序遍历也是 深度优先搜索DFS
void inorderIteratively(TreeNode* root, vector<int>& res)
{
    if (root == nullptr)
        return;

    stack<TreeNode*> s{};

    TreeNode* p = root;

    while (!s.empty() || p != nullptr)
    {
        while (p != nullptr)
        {
            s.push(p);
            p = p -> left;
        }


        if (! s.empty())
        {
            p = s.top();
            res.push_back(p -> val);
            s.pop();
            p = p -> right;
        }
        else
            break;
        
    }
}

void postorderIteratively(TreeNode* root, vector<int>& res)
{
    if (root == nullptr)
        return;

    stack<TreeNode*> s{};
    
    TreeNode* p = root;
    TreeNode* pre = nullptr;

    while (p != nullptr)
    {
        s.push(p);
        p = p -> left;
    }
    
    while (! s.empty())
    {
        p = s.top();
        s.pop();

        // 右子树为空，或右子树已经遍历过的情况下，才输出当前根节点
        if (p -> right == nullptr || p -> right == pre)
        {
            res.push_back(p -> val);
            pre = p;
        }
        else
        {
            s.push(p);
            p = p -> right;

            while (p)
            {
                s.push(p);
                p = p -> left;
            }
        }

    }
       
}

// BFS 得到的就是个堆
void BFS(TreeNode* root, vector<int>& res)
{
    if (root == nullptr)
        return;

    TreeNode* p = root;

    queue<TreeNode*> q{};
    q.push(p);

    while (! q.empty())
    {
        p = q.front();
        res.push_back(p -> val);

        q.pop();
        if (p -> left != nullptr)
            q.push(p -> left);
        if (p -> right != nullptr)
            q.push(p -> right);
    }
}

/*非递归版本*/

// 暂时先这样，后面改成用二叉堆来生成
TreeNode* BuildTree()
{
    TreeNode* child_4 = new TreeNode{};
    child_4 -> val = 4;
    child_4 -> left = nullptr;
    child_4 -> right = nullptr;

    TreeNode* child_5 = new TreeNode{};
    child_5 -> val = 5;
    child_5 -> left = nullptr;
    child_5 -> right = nullptr;

    TreeNode* lchild = new TreeNode{};
    lchild -> val = 2;
    lchild -> left = child_4;
    lchild -> right = child_5;

    TreeNode* child_6 = new TreeNode{};
    child_6 -> val = 6;
    child_6 -> left = nullptr;
    child_6 -> right = nullptr;

    TreeNode* child_7 = new TreeNode{};
    child_7 -> val = 7;
    child_7 -> left = nullptr;
    child_7 -> right = nullptr;

    TreeNode* rchild = new TreeNode{};
    rchild -> val = 3;
    rchild -> left = child_6;
    rchild -> right = child_7;

    TreeNode* root = new TreeNode{};
    root -> val = 1;
    root -> left = lchild;
    root -> right = rchild;

    return root;
}



int main()
{
    TreeNode* root = BuildTree();
    vector<int> res{};
    BFS(root, res);

    for (auto x : res)
        printf("%d ", x);

}