#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    srand((unsigned)time(NULL));
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for(int i = 9; i >= 0; i--)
        swap(&arr[i], &arr[rand()%10]);

    for(int i = 0; i < 10; i++)
        printf("%d ", arr[i]);

    printf("\n");    

    return 0;
}
