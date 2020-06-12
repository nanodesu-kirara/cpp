#include<iostream>
#include<exception>
#include<utility>

using std::size_t, std::max, std::cout, std::endl, std::move, std::swap;

template<typename comparable>
class AVLTree {
    public:
        AVLTree(): root {nullptr} {}
        ~AVLTree() {}
        AVLTree(const AVLTree& t) {}
        AVLTree(AVLTree&& t): root {t.root} { t.root = nullptr; }

        void insert(const comparable& e) {
            insert(e, root);
        }

    private:
        struct AVLNode
        {
            comparable elem;
            AVLNode* left;
            AVLNode* right;
            size_t height;

            AVLNode(const comparable& e, AVLNode* left = nullptr, AVLNode* right = nullptr, size_t height = 0)
                : elem{e}, left{left}, right{right}, height{height} {}
            
            AVLNode(comparable&& e, AVLNode* left = nullptr, AVLNode* right = nullptr, size_t height = 0)
                : elem{ move(e) }, left{left}, right{right}, height{height} {}

        };
        
        AVLNode* root;

        static const size_t ALLOWED_IMBALANCE = 1;

        int height(const AVLNode* p) const {
            // 保留height字段的作用就是不用每次都进行下面的计算
            // 那么还有什么理由用这个呢
            // return height(p->right) < height(p->left) ? height(p->left) + 1 : height(p->right) + 1
            return p == nullptr ? -1 : p->height;
        }

        const AVLNode* min(const AVLNode* p) const {
            if (p == nullptr)
                return p;
            if (p->left != nullptr)
                return min(p->left);
            else 
                return p;
        }

        void insert(const comparable& e, AVLNode*& p) {
            if (p == nullptr)
                p = new AVLNode(e);
            else if (e < p->elem)
                insert(e, p->left);
            else if (p->elem < e)
                insert(e, p->right);
            else
                return; // 重复情况，此处直接返回了
            
            balance(p);
        }

        void remove(const comparable& e, AVLNode*& p) {
            if (p == nullptr)
                return;
            if (e < p->elem)
                remove(e, p->left);
            else if (p->elem < e)
                remove(e, p->right);
            else if (p->left != nullptr and p->right != nullptr){
                // 查找+删除可以写成一个特殊的函数实现
                p->elem = min(p->right)->elem;
                remove(p->elem, p->right);
            } else {
                AVLNode* old = p;
                p = p->left != nullptr ? p->left : p->right;
                delete old;
            }

            balance(p);
        }

        /*
            在插入操作之后进行，使树平衡
        */
        void balance(AVLNode*& p) {
            if (p == nullptr)
                return; 
            if (height(p->left) - height(p->right) > ALLOWED_IMBALANCE) {
                if (height(p->left->left) >= height(p->left->right)) // 只是插入并不会有等于情况
                    rotateWithLeft(p);
                else
                    doubleRotateWithLeft(p);
            } else if (height(p->right) - height(p->left) > ALLOWED_IMBALANCE) {
                if (height(p->right->right) >= height(p->right->left))
                    rotateWithRight(p);
                else
                    doubleRotateWithRight(p);
            } else ;

            adjust(p);
        }

        /**
         * 更新p指向节点高度
         * 依赖其子树高度正确性
        */
        void adjust(AVLNode* p) {
            p->height = max(p->left->height, p->right->height) + 1;
        }

        /**
         * 在左子树进行的
         * single rotation
         * 和rotateWithRight是镜像操作
         **/
        void rotateWithLeft(AVLNode*& p) {
            /**
             * 1. inner rotation
             * 2. update height
             * 3. out-pointer point to new child
             **/ 
            AVLNode* ptl = p->left;
            p->left = p->left->right;
            ptl->right = p;            

            // 其实ptl高度+1，p(原先)高度不变
            // 这里如果ptl不变，p(原先)-1            
            // 再再balance里面+1
            // 强耦合,把本来应该一步完成的事放在两个函数里不是什么好事
            // 事实上，更新高度其实只是一步常数级操作
            adjust(ptl->right);
            adjust(ptl);
            //注意必须先更新子树高度

            p = ptl;
        }
        
        /**
         * 在右子树进行的
         * single rotation
         * 和rotateWithLeft是镜像操作
         **/
        void rotateWithRight(AVLNode*& p) {
            AVLNode* ptr =  p->right;
            p->right = p->right->left;
            ptr->left = p;

            adjust(ptr->left);
            adjust(ptr);

            p = ptr;

        }

        /**
         * 在左儿子的右子树插入之后进行
         * double rotation
         * 和doubleRotateWithRight是镜像操作
         **/
        void doubleRotateWithLeft(AVLNode*& p) {
            /*未检验
            AVLNode* ptl = p->left;    
            p->left = p->left->right->right;
            AVLNode* ptlr = ptl -> right;
            ptl->right = ptl->right->left;
            ptlr->left = ptl;
            ptlr->right = p;

            adjust(ptlr->left);
            adjust(ptlr->right);
            adjust(ptlr);

            p = ptlr;
            */
           rotateWithRight(p->left);
           rotateWithLeft(p);
        }

        /**
         * 在右儿子的左子树插入之后进行
         * double rotation
         * 和doubleRotateWithLeft是镜像操作
         **/
        void doubleRotateWithRight(AVLNode*& p) {
            /*未检验
            AVLNode* ptr = p->right;
            p->right = p->right->left->left;
            AVLNode* ptrl = ptr->left;
            ptr->left = ptr->left->right;
            ptrl->left = p;
            ptrl->right = ptr;

            adjust(ptrl->left);
            adjust(ptrl->right);
            adjust(ptrl);

            p = ptrl;
            */
           rotateWithLeft(p->right);
           rotateWithRight(p);
        }

        

};

int main() {
}
