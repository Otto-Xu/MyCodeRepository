#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

//打印数组
void my_print(int *array, int len)
{
	if(NULL == array)
		return;
	
	int i = 0;
	for(i = 0; i < len; i++)
		printf("%d ", array[i]);

	printf("\n");
	return ;
}

//冒泡排序
void BlueSort(int *array, int len)
{
	if(NULL == array)
		return ;
	
	int tmp;
	int i, j;
	for(i = len-1; i > 0; i--)
	{
		for(j = 0; j < i; j++)
		{
			if(array[j] > array[i])
			{
				tmp = array[j];
				array[j] = array[i];
				array[i] = tmp;
			}
		}
	}

	return ;
}


//选择排序
void SelectSort(int *array, int len)
{
	if(NULL == array)
		return ;

	int i, j, index, max;
	for(i = 0; i < len-1; i++)
	{
		max = array[0];
		index = 0;

		for(j = 1; j < len-i; j++)
		{
			if(array[j] > max)
			{
				max = array[j];
				index = j;
			}
		}
	
		array[index] = array[len-1-i];
		array[len-1-i] = max;
	}

	return ;
}

//快速排序
void QuickSort(int  *array, int left, int right)
{
	if(NULL == array)
		return ;
	
	if(left < right)
	{
		int base;
		int i, j;

		i = left;
		j = right;
		base = array[i];

		while(i < j)
		{
			while(i < j && array[j] >= base)
				j--;
			array[i] = array[j];

			while(i < j && array[i] <= base)
				i++;
			array[j] = array[i];
		}

		array[i] = base;
		QuickSort(array, left, i-1);
		QuickSort(array, i+1, right);
	}
}

//希尔排序
void ShellSort(int *array, int len)
{
    int i, j, k;
    int gap, tmp;
    gap = len/3;
    
    for(i = 0; gap; i++)
    {
        if(i == gap)
        {
            gap /= 2;
            i = -1;
            continue;
        }

        for(j = gap + i; j < len; j += gap)
        {
            tmp = array[j];

            for(k = j; k >= gap && array[k - gap] > tmp; k -= gap)
            {
                array[k] = array[k - gap];
            }

            array[k] = tmp;
        }
    }
}

//归并排序
void dealMergeSort(int *src, int *tmp, int start, int end)
{
    if(start >= end)
        return ;

    int mid = (start + end) / 2;
    dealMergeSort(src, tmp, start, mid);
    dealMergeSort(src, tmp, mid + 1, end);

    int a = start;
    int b = mid + 1;
    int c = start;

    while(a <= mid && b <= end)
    {
        if(src[a] < src[b])
        {
            tmp[c] = src[a];
            ++a;
        }
        else
        {
            tmp[c] = src[b];
            ++b;
        }
        ++c;
    }

    for(; a <= mid; ++a, ++c)
    {
        tmp[c] = src[a];
    }
    for(; b <= end; ++b, ++c)
    {   
        tmp[c] = src[b];
    }

    for(int i = start; i <= end; ++i)
    {
        src[i] = tmp[i];
    }
}

void MergeSort(int *array, int len)
{
    int *tmp = (int *)malloc(len * sizeof(array[0]));
    dealMergeSort(array, tmp, 0, len - 1);
    free(tmp);
}


int main(int argc, char *argv[])
{
	int a[14] = {9, 2, 3, 10, 7, 5, 1, 56, 34, 76, 10, 43, 6, 0};
	
	//BlueSort(a, 7);
	//SelectSort(a, 7);
	//QuickSort(a, 0, 6);
    //ShellSort(a, 14);
    MergeSort(a, 14);

	my_print(a, 14);
	
	return 0;
}
