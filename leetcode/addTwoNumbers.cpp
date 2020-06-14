/*
2. 两数相加
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
通过次数445,641 提交次数1,187,392
*/

/**
 * 思路：
 * 乍一看感觉还是比较简单的？
 * 
 * 求和， 逆序
 * 
 * 想法： 对齐之后，从头开始（最低位）求和
 * 
 * 因为逆序的原因，最低位是对齐的
 * 
 * 那问题就变成了，以求和的形式归并两个单向列表
 * 
 * 有一个很自然的时间复杂度为m+n的算法
 */

#include<iostream>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}

    ~ListNode() {
        if (next != nullptr) {
            delete next;
            next = nullptr;
        }
    }
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode(-1);
    ListNode* tail = head;

    int sum = 0;
    int carry = 0;

    while (l1 != nullptr && l2 != nullptr)
    {
        sum = l1 -> val + l2 -> val + carry;
        carry = sum / 10;
        tail -> next = new ListNode(sum % 10);
        tail = tail -> next;

        l1 = l1 -> next;
        l2 = l2 -> next;
    }

    /**
     * 还存在因为进位导致余下的位疯狂进位...
     * 思维不够严谨= =
     */

    while (l1 != nullptr) {
        /**
         * 如果可以偷懒不复制, 就这样
         * if (carry == 0) {
         *     tail -> next = l1;    
         *     break;
         * }
         * 
         */
        sum = l1 -> val + carry;
        carry = sum / 10;
        tail -> next = new ListNode(sum % 10);
        tail = tail -> next;
        l1 = l1 -> next;
    }

    while (l2 != nullptr) {
        /**
         * 如果可以偷懒不复制, 就这样
         * if (carry == 0) {
         *     tail -> next = l2;    
         *     break;
         * }
         * 
         */
        sum = l2 -> val + carry;
        // printf("sum: %d\n", sum);
        carry = sum / 10;
        tail -> next = new ListNode(sum % 10);
        tail = tail -> next;
        l2 = l2 -> next;
    }

    /**
     * 还有一种情形：
     * 同时同时达到最后一位
     * 但存在进位
     * 比如 5 + 5 = 0 -> 1
     */
    if(l1 == nullptr && l2 == nullptr && carry == 1) {
        tail -> next = new ListNode(carry);
    }

    return head -> next;
}

int main() {
    ListNode* a1 = new ListNode(1);
    // ListNode* a2 = new ListNode(4);
    // ListNode* a3 = new ListNode(3);
    // a1 -> next = a2;
    // a2 -> next = a3;

    ListNode* b1 = new ListNode(9);
    ListNode* b2 = new ListNode(9);
    // ListNode* b3 = new ListNode(4);
    b1 -> next = b2;
    // b2 -> next = b3;

    ListNode* ans = addTwoNumbers(a1, b1);
    while (ans != nullptr)
    {
        printf("%d -> ", ans -> val); // 小问题 7 -> 0 -> 8 ->
        ans = ans -> next;
    }

    printf("\n");
    
}
