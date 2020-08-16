/**
 * 逆序（从尾到头）打印链表
 * 要求不能修改原有结构
 */
#include<stack>
#include<iostream>

using std::stack;

struct ListNode
{
    int value;
    ListNode* next;
};

void PrintListReversinglyIteratively(ListNode* pHead)
{
    // 存指针好一点，如果不是int类型，复制开销会很大
    stack<ListNode*> nodes;

    ListNode* p = pHead;

    while (p != nullptr)
    {
        nodes.push(p);
        p = p -> next;
    }

    while (! nodes.empty())
    {
        printf("%d ", nodes.top() -> value);
        nodes.pop();
    }

}

void PrintListReversinglyRecursively(ListNode* p)
{
    // 基准情形
    if (p == nullptr)
        return;

    PrintListReversinglyRecursively(p -> next);
    printf("%d ", p -> value);
}

