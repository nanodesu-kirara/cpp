/**
 * 9 用两个栈实现队列
 * 实现append 和 pop 方法
 */

#include<stack>
#include<exception>

using std::stack, std::exception;

template<typename T>
class CQueue
{
    private:
        stack<T> stack_1; // 主栈
        stack<T> stack_2; // 辅助栈
    public:
        CQueue();
        ~CQueue();

        void append(const T& element);
        T pop();
};

template<typename T>
void CQueue<T>::append(const T& element)
{
    stack_2.push(element);
}

template<typename T>
T CQueue<T>::pop()
{
    if (stack_1.empty())

        if (stack_2.empty())
            throw exception{};
        else
            while (! stack_2.empty())
            {
                stack_1.push(std::move(stack_2.top()));
                stack_2.pop();
            }


    T head = stack_1.top();
    stack_1.pop();
    return head;
}
