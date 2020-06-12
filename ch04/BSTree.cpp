#include<utility>
#include<iostream>
#include<exception>

using std::cout;
using std::endl;
using std::swap;

template<typename comparable>
class BinarySearchTree {
    public:
        BinarySearchTree(): root {nullptr} {}
        BinarySearchTree(const BinarySearchTree& bstree) { root = clone(bstree.root); }
        BinarySearchTree(BinarySearchTree&& bstree) {
            root = bstree.root;
            bstree.root = nullptr;
        }
        ~BinarySearchTree() { makeEmpty(); }

        bool contains(const comparable& e) const {
            return contains(e, root);
        }

        const comparable& min() const {
            BinaryNode* min = min(root);
            return min != nullptr ? min->elem : throw std::exception();
        }

        // const comparable& max() const;

        void insert(const comparable& e) {
            insert(e, root);
        }

        void remove(const comparable& e) {
            remove(e, root);
        }

        void makeEmpty() {
            makeEmpty(root);
        }

        void print(std::ostream& out = std::cout) const {
            if (root == nullptr)
                out << "empty tree.";
            else
                print(out, root);
            out << endl;
        }

    private:
        typedef struct BinaryNode
        {
            comparable elem;
            BinaryNode* left;
            BinaryNode* right;

            BinaryNode(const comparable& e, BinaryNode* left = nullptr, BinaryNode* right = nullptr)
                :elem {e}, left {left}, right {right} {
                    // std::cout << "copy cst was used." << std::endl;
                }

            BinaryNode(comparable&& e, BinaryNode* left = nullptr, BinaryNode* right = nullptr)
                :elem {std::move(e)}, left {left}, right {right} {
                    // std::cout << "move cst was used." << std::endl;
            }

        } BinaryNode;

        BinaryNode* root;

        bool contains(const comparable& e, const BinaryNode* node) const {
            if (node == nullptr)
                return false;
            else if (e < node->elem )
                return contains(e, node->left);
            else if (node->elem < e)
                return contains(e, node->right);
            else
                return true;
        }

        const BinaryNode* min(const BinaryNode* node) const {
            if (node == nullptr)
                return node;
            if (node->left != nullptr)
                return min(node->left);
            else 
                return node;
        }

        void insert(const comparable& e, BinaryNode*& node) {
            if (node == nullptr)
                node = new BinaryNode(e);
            else if (e < node->elem)
                insert(e, node->left);
            else if (node->elem < e)
                insert(e, node->right);
            else
                ;
        }

        void remove(const comparable&e, BinaryNode*& node) {
            if (node == nullptr)
                return;
            if (e < node->elem)
                remove(e, node->left);
            else if (e > node->elem)
                remove(e, node->right);
            else if (node->left != nullptr and node->right != nullptr)
                node->elem = removeMin(node->right);
            else {
                BinaryNode* old = node;
                node = node->left != nullptr ? node->left : node->right;
                delete old;
            }
        }

        comparable removeMin(BinaryNode*& node) {
            if (node == nullptr)
                throw std::exception();
            if (node->left != nullptr)
                removeMin(node->left);
            else 
            {
                /*
                    这里也许不用拷贝构造两次comparable对象
                */
                BinaryNode* old = node;
                comparable min = node->elem;
                node = node->right;
                delete old;
                return  min;
            }
            // control should not reach here!
            throw std::exception();
        }

        void makeEmpty(BinaryNode*& node) {
            if (node == nullptr)
                return;
            makeEmpty(node->left);
            makeEmpty(node->right);
            delete node;
            node = nullptr;// 这步得有，置空而非指向删除了的地址
        }

        BinaryNode* clone(BinaryNode* node) {
            if (node == nullptr)
                return nullptr;
            return new BinaryNode(node->elem, clone(node->left), clone(node->right));
        }

        void print(std::ostream& out, const BinaryNode* node) const {
            if (node == nullptr)
                return;
            print(out, node->left);
            out << node->elem << " ";
            print(out, node->right);
        }

};

int main() {
    /**
    const int i = 1;
    const int another = 2;
    const int* c_p = &i;
    c_p = &another;
    // *c_p = 2;
    const int* const& rtp = c_p;
    // rtp = &another;
    // *rtp = 2;
    **/
    BinarySearchTree<int> bstree {};
    const int a = 2;
    const int b = 5;
    const int c = 3;
    bstree.insert(a);
    bstree.insert(b);
    bstree.insert(c);
    // if (bstree.contains(a))
    //     cout << "it contains" << endl;
    bstree.print();

    bstree.remove(a);
    bstree.print();
    bstree.remove(b);
    bstree.print();
    bstree.remove(c);
    bstree.print();
    // bstree.makeEmpty();
    // if (!bstree.contains(a))
        // cout << "it contained" << endl;
}
