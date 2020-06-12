#include<iostream>
#include<sstream>
#include<string>
#include<utility>

class A {
    public:
        int a = 0;
        A() = default;
        // A(const A&) = delete;
        // A(A&&) = delete;
        // A(A&& rv): a { std::move(rv.a) } {}
        A& operator=(const A& rv) { a = rv.a; return *this;}
        explicit A(int init): a { init } {}
        int value() { return a; }
};

template <typename T>
class PreNode {
    public:
        T data;
        PreNode<T>* next;
        PreNode(): data { T {} }, next { nullptr } {}
};

template <typename T>
class PreList {
    private:
        std::size_t size;
        PreNode<T>* head;
    public:
        PreList(): size {0}, head { nullptr } {}

        PreNode<T>* begin() { return head; }

        void pushFront(T&& pnd) {
            PreNode<T>* pt = new PreNode<T>;
            // 依赖于 T 的copy/move assignment 实现
            pt -> data = pnd;
            pt -> next = head;
            head = pt;
            ++size;
        }

        void print() {
            PreNode<T>* pt = head;
            while(pt != nullptr) {
                std::cout << pt->data << " ";
                pt = pt -> next;
            }
            std::cout << std::endl;
        }
};

template <typename T>
void swapPreNode(PreNode<T>* preNode, PreNode<T>& lhs, PreNode<T>& rhs) {
    std::swap(lhs.next, rhs.next);
    std::swap(rhs.next, preNode -> next);
}

template <typename T>
class Node {
    public:
        T data;
        Node<T>* prev;
        Node<T>* next;
        Node(): data { T {} }, prev { nullptr }, next { nullptr } {}
};

template <typename T>
class List {
    private:
        std::size_t size = 0;
        Node<T>* head;
        Node<T>* tail;
    public:
        List(): size {0}, head { new Node<T> }, tail { new Node<T> } {
            head -> next = tail;
            tail -> prev = head;
        }

        void pushBack(T&& nd) {

            Node<T>* pt = new Node<T>;
            // 依赖于 T 的copy/move assignment 实现
            pt -> data = nd;
            pt -> prev = tail -> prev;
            pt -> next = tail;

            tail -> prev -> next = pt;
            tail -> prev = pt;

            ++size;
        }

        Node<T>* begin() { return head -> next ; }

        void print() {
            Node<T>* pt = head -> next;
            while(pt != tail) {
                std::cout << pt->data << " ";
                pt = pt -> next;
            }
            std::cout << std::endl;
        }
};

template <typename T>
void swapNode(Node<T>& lhs, Node<T>& rhs) {
    /* 
        思路：先修改两边，
        然后如果某个指针已经转移到了另一地方,
        那么就可以优先修改他(即使修改了，也不怕丢失，不用暂存)
    */

    lhs.prev -> next = lhs.next;
    rhs.next -> prev = rhs.prev;

    lhs.next = rhs.next;
    rhs.prev = lhs.prev;

    lhs.prev = rhs.prev -> next;
    rhs.next = lhs.next -> prev;

}


std::ostream & operator << (std::ostream& out, A& a);
std::ostream & operator << (std::ostream& out, A& a) {
    // incorrect: std::cout << static_cast<char>(1) << std::endl;
    std::ostringstream buf { std::to_string(a.a) };
    return out << buf.str();
}

void swapPreList() {

    PreList<A> flst {};

    flst.pushFront(A {2});
    flst.pushFront(A {1});
    flst.pushFront(A {0});

    std::cout << "before swapping forward list" << std::endl;

    flst.print();

    swapPreNode(flst.begin(), *(flst.begin() -> next), *(flst.begin() -> next -> next));

    std::cout << "after swapping 2nd and 3rd" << std::endl;

    flst.print();

}

void swapList() {
    List<A> lst {};
    lst.pushBack( A {0} );
    lst.pushBack( A {1} );
    lst.pushBack( A {2} );

    // test: std::cout << lst.begin()->data << std::endl;

    std::cout << "before swapping double-linked list" << std::endl;

    lst.print();

    swapNode(*lst.begin(), *(lst.begin() -> next));

    std::cout << "after swapping 1st and 2nd" << std::endl;

    lst.print();

}

int main() {
    swapPreList();
    swapList();
    return 0;
}

/* try 
1.重写流运算符 <<
2.试着用swap交换双向列表
3.data应该是public吗
4.试着实现forward-list & list
*/
