/**
 * 8. 二叉树的下一个节点
 * 中序遍历
 * 有指向父节点的指针
 * 本质就是考察中序遍历
 */

struct BinaryTreeNode
{
    int val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode* parent;
};

using btn = BinaryTreeNode;

btn* NextNode(btn* node)
{
    if (node == nullptr)
        return nullptr;

    if (node -> right != nullptr)
    {
        node = node -> right;

        while (node -> left != nullptr)
            node = node -> left;
        
        return node;
    }
    else
    {
        while (node -> parent != nullptr && node -> parent -> left != node)
            node = node -> parent;

        return node -> parent;
    }
}
