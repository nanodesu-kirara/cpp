#include <iostream>
#include <time.h>
using namespace std;

void print(const int *a, long size);

void bubbleSort(int* a, long size);

void selectSort(int* a, long size);

void insertSort(int* a, long size);

int main(int argc, const char *argv[]) {
    int arr[20] = {};
    for (size_t i = 0; i < 20; i++)
    {
        *(arr+i) = (i+7) % 3;
    }
    
    // print(arr, sizeof(arr)/sizeof(int));
    insertSort(arr, sizeof(arr)/sizeof(int));
    print(arr, sizeof(arr)/sizeof(int));

}

void insertSort(int* a, long size) {
    int temp = *a;
    /* loop */
    for (long i = 1; i < size; i++)
    {

        /*** Implicit condition:
        Sequence before a[i] is in order
        To compare backward is a better choice which is different from some other methods
        ***/

        /* need to record the index when the loop is finished */
        /* insert to a[j] */
        long j = i;

        temp = *(a + i);
        /* a[j-1] 记录位置的前一个元素 */ 
        while (temp < *(a+j-1) && j > 0)
        {
            /* move to tail */
            *(a+j) = *(a+j-1);
            /* backward */
            j--;
        }
        
        /* insert */
        *(a+j) = temp;
        
        print(a, size);
        cout << endl;

    }
    
}

void selectSort(int* a, long size) {
    long min = 0;
    int temp = *a;
    /* loop */
    for (long i = 0; i < size - 1; i++)
    {
        min = i;
        for (long j = 0; j < size - i - 1; j++)
        {
            /* select */
            if (*(a + min) > *(a + i + j + 1))
                min = i+ j + 1;
        }

        /* swap */
        temp = *(a + i);
        *(a + i) = *(a + min);
        *(a + min) = temp;
        
    }
    
}

void bubbleSort(int* a, long size) {
    int temp = 0;
    for (long i = 0; i < size-1; i++)
    {
        // wrong:
        // j < size - i
        for (long j = 0; j < size - i - 1; j++) 
        {
            if (*(a+j) > *(a+j+1))
            {
                temp = *(a+j);
                *(a+j) = *(a+j+1);
                *(a+j+1) = temp;
            }
        }
    }
}

void print(const int *a, long size) {
    for(long i = 0; i < size; i++) {
        cout << *(a + i) << "  ";
        if ((i+1) % 4 == 0)
        {
            cout << endl;
        }
    }
}
