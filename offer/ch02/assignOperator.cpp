/**
 * 1. 为如下类型添加赋值运算符函数
 */

#include<algorithm>

class CMyString
{
    public:
        CMyString(char* pData = nullptr);
        CMyString(const CMyString& str);
        ~CMyString(void);

        // 解答内容
        CMyString& operator=(const CMyString&);

    private:
        char* m_pData;
};

// 解答内容
CMyString& CMyString::operator=(const CMyString& rhs)
{
    // copy and swap
    CMyString copy{rhs};
    std::swap(*this, copy);

    /**
     * copy and swap这种一般化解法掩盖了以下细节
     * 1. 证同测试，处理自我赋值
     * 2. 异常安全性
     * 除此之外函数返回自身引用，传递const ref也是需要注意的
     */

    // return itself
    return *this;
}

