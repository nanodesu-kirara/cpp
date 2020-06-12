#include<cstdio>
/*
    计算绝对深度为h的AVL树的最少节点数
*/
int foo(int h) {
    if (h==0)
        return 1;
    if (h==1)
        return 2;
    return foo(h-1) + foo(h-2) + 1;
}

int main() {
    const int i = 32; // increase exponentially
    printf("when absolute depth is %d, the minium count of nodes is %d", i, foo(i));
}
