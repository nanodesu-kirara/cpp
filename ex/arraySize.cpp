#include<array>

template <typename T, std::size_t N>
constexpr std::size_t arraySize(T (&arr)[N]) noexcept {
    return N;
}

int main() {
    int arr[5] = { 1, 1, 2, 3, 5 };
    // std::size_t size = arraySize(arr);
    // 变味儿了，arraySize返回值初始化一个运行时变量
    std::array<int, arraySize(arr)> brr { 1, 2, 3, 4, 5 };
    for (auto x : brr)
        printf("%d\n", x);
}
