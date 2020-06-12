#include<utility>
#include<cstdio>
#include<math.h>

double myPow(double x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x;
    std::size_t y = labs(n);
    if (y % 2 == 0) {
        double half = myPow(x, y/2);
        return n < 0 ? 1 / (half * half) : half * half;
    } else {
        double half = myPow(x, y/2);
        return n < 0 ? 1 / (half * half * x) : half * half * x;
    }
}

int main() {
    double x = 1.00000;
    int y = -2147483648;
    printf("pow(%f, %d) = %f\n", x, y, myPow(x, y));
}
