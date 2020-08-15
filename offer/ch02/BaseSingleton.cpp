/**
 * 2. 单例模式扩展
 * 编写一个基类
 * 其派生类都只能产生一个实例
 */

// 奇异递归模板
template<typename T>
class Base
{
    public:
        // 基类析构函数声明为虚函数
        virtual ~Base(){}
        Base(const Base&) = delete;
        Base& operator=(const Base&) = delete;

        static T& getInstance()
        {
            static T instance{};
            return instance;
        }

    protected:
        Base(){}

};


class DerivedSingleton : public Base<DerivedSingleton>
{
    // 若不声明为友类
    // Base类中的 getInstance方法无法调用 DerivedSingleton构造函数
    friend class Base<DerivedSingleton>;

    public:
        DerivedSingleton(const DerivedSingleton&) = delete;
        DerivedSingleton& operator=(const DerivedSingleton&) = delete;

    private:
        DerivedSingleton() = default;
};

