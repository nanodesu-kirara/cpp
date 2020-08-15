/**
 * 2. 设计一个类，只能生成该类的一个实例
 */
#include<memory>
#include<mutex>

// version_1
// 线程不安全，重复创建

class SingletonA
{
    public:
        ~SingletonA(){}
        SingletonA(const SingletonA&) = delete;
        SingletonA& operator=(const SingletonA&) = delete;

        static SingletonA* getInstance();
    private:

        static SingletonA* instance;

        SingletonA();
};

SingletonA* SingletonA::instance = nullptr;

SingletonA* SingletonA::getInstance()
{
    if (instance == nullptr)
        instance = new SingletonA{};
    return instance;
}

// version_2
// 线程安全，内存安全
// 使用智能指针，互斥锁

class SingletonB
{
    public:
        using ptr = std::shared_ptr<SingletonB>;

        ~SingletonB(){}
        SingletonB(const SingletonA&) = delete;
        SingletonB& operator=(const SingletonB&) = delete;

        static ptr getInstance();

    private:

        static ptr instance;
        static std::mutex mutex;
        SingletonB();
};

SingletonB::ptr SingletonB::instance = nullptr;
std::mutex SingletonB::mutex{};

SingletonB::ptr SingletonB::getInstance()
{
    // 第一次检查是否以及初始化，如果已经初始化，直接返回（不去获取锁）
    if (instance == nullptr)
    {
        // 检查未被初始化，获取锁
        // 这里可能会阻塞，因为其他线程抢先获取了锁
        std::lock_guard<std::mutex> lock{mutex};
        // 在获取了锁之后，再次判断
        // 已经获取了锁，其他进程无法进入，再次检查是否已经初始化
        if (instance == nullptr)
            instance = ptr{new SingletonB};
    }
    return instance;
}

// Meyers Singleton
class SingletonC
{
    public:
        ~SingletonC(){}
        SingletonC(const SingletonC&) = delete;
        SingletonC& operator=(const SingletonC&) = delete;

        // 返回引用，也只有静态局部变量是可以这样做的
        static SingletonC& getInstance();

    private:

        SingletonC();
};


SingletonC& SingletonC::getInstance()
{
    // static local variable
    // 线程安全
    static SingletonC instance{};
    return instance;
}

