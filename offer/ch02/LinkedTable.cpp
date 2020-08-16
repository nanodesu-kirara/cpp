/**
 * 链表定义
 * 在末尾添加节点的操作
 * 在链表中找到第一个含有某值节点并删除的操作
 * 
 * 链表一定要注意考虑到各种情况：
 * 特别是在头尾的操作
 */

template<typename T>
class ListNode
{
    public:
        T value;
        ListNode<T>* next;

        ListNode(): value{ T{} }, next{ nullptr } {}

        void AddToTail(ListNode<T>** pHead, T value);
        void RemoveNode(ListNode<T>** pHead, T value);
};

// pHead 指向头结点的指针 的指针
template<typename T>
void ListNode<T>::AddToTail(ListNode<T>** pHead, T value)
{
    // 分配内存并创建新节点
    ListNode<T>* newNode = new ListNode<T>{}
    newNode -> value = value;

    // 比较重要的是对链表原本为空的处理
    if (*pHead == nullptr)
    {
        *pHead = newNode;
    }
    else
    {
        ListNode<T>* p = *pHead;

        while (p -> next != nullptr)
            p = p -> next;

        p -> next = newNode;
    }

}

template<typename T>
void ListNode<T>::RemoveNode(ListNode<T>** pHead, T value)
{
    if (pHead == nullptr || *pHead == nullptr)
        return;

    ListNode* toDelete = nullptr;

    // !!!
    // 依旧要注意删除头节点的情况
    if ((*pHead) -> value == value)
    {
        toDelete = *pHead;
        *pHead = (*pHead) -> next;
    }
    else
    {
        // search
        ListNode* p = *pHead;
        while (p -> next != nullptr && p -> next -> value != value)
            p = p -> next;

        // not found
        if (p -> next == nullptr)
            return;
        else
        {
            toDelete = p -> next;

            p -> next = p -> next -> next;
        }

    }

    // 释放资源之后不要忘了把指向资源的指针置空
    delete toDelete;
    toDelete = nullptr;

}
