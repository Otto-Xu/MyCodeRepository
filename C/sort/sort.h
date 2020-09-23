#ifndef __SORT_H__
#define __SORT_H__

#define dprintf(format, ...) fprintf(stderr, "\033[31m[%s %s %d]\033[0m "format"", __FILE__, __func__, __LINE__, ##__VA_ARGS__)

//冒泡排序
void BlueSort(int *array, int len);

//选择排序
void SelectSort(int *array, int len);

//快速排序
void QuickSort(int *array, int left, int right);

//希尔排序
void ShellSort(int *array, int len);

//归并排序
void MergeSort(int *arrag, int len);

#endif 
