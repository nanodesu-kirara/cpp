#include<string>
#include<stack>
#include<iostream>

using std::string;
using std::stack;
using std::cout;
using std::endl;

// 双指针，两头往中间
bool IsPalindrome(const string& str)
{
    const int len = str.size();    
    if (!len)
        return false;
    int front = 0;
    int back = len - 1;

    while (front < back)
    {
        if (str[front] != str[back])
            return false;
        ++front;
        --back;
    }
    return true;
}

// 中间往两头扫描
// 虽然不如第一种直白，但这种方式在判断子串的时候很有用
bool IsPalindromeFromMid(const string& str)
{
    const int len = str.size();    
    if (!len)
        return false;
    int lhs, rhs;
    int m = ((len >> 1) - 1) >= 0 ? (len >> 1) - 1 : 0;
    lhs = m;
    rhs = (len - 1) - m; // 字符串中关于中心对称的两个字母位置都满足这个规律，下标之和 = len-1

    while (lhs >= 0)
    {
        if (str[lhs] != str[rhs])
            return false;
        --lhs;
        ++rhs;
    }

    return true;
}

// 判断单链表
// 单链表不支持从索引高到低的遍历
// 想想有什么解决方式呢
// 需要用到一个常用的操作：单链表逆置
struct Node
{
    char val;
    Node* next = nullptr;

    Node (char v, Node* n = nullptr): val{v}, next{n} {}

    Node (const Node* n): val{n->val}, next{n->next} {}
};


bool IsPalindromeSingleD(const Node* head, const int len)
{
    if (!len)
        return false;
    if (len == 1)
        return true;

    int m = ((len >> 1) - 1) >= 0 ? (len >> 1) - 1 : 0;

    Node* lhs = nullptr;
    for (int i = 0; i <= m; ++i, head = head -> next)
    {
        Node* copy = new Node(head);
        copy->next = lhs;
        lhs = copy;
    }

    for (int i = m+1; i < len-1-m; ++i)
        head = head -> next;
    const Node* rhs = head;

    while (lhs != nullptr)
    {
        if (lhs->val != rhs->val)
            return false;
        lhs = lhs -> next;
        rhs = rhs -> next;
    }

    return true;

}

Node* StrToNodes(const string& str)
{
    Node* n = nullptr;
    for (int i = str.size()-1; i>=0 ; --i)
    {
        Node* c = new Node(str[i], n);
        n = c;
    }
    return n;
}

void printNodes(const Node* head)
{
    while (head != nullptr)
    {
        cout << head -> val << ' ';
        head = head -> next;
    }
    cout << endl;
}

/**//////////////////////

// 判断一个栈是不是回文
// 栈的特性是只能访问栈顶的元素
// 出栈顺序和入栈顺序完全相反
bool isPalindromeStack(stack<char>& str)
{
    stack<char> copy{str};
    stack<char> reverse{};
    if (!str.empty())
    {
        reverse.push(str.top());
        str.pop();
    }

    while (!copy.empty())
    {
        if (copy.top() != reverse.top())
            return false;
        copy.pop();
        reverse.pop();
    }

    return true;
}


int main()
{
    string str{"qaq"};
    Node* n = StrToNodes(str);
    printNodes(n);
    if (IsPalindromeSingleD(n, str.size()))
        cout << str << " is palindrome." << endl;
    else
        cout << str << " isn't palindrome." << endl;
}
 