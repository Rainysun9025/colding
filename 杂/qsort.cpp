#include <stdio.h>
#include <stdlib.h>
//qsort被包含在头文件stdlib中
	//要传递四个参数 
	//指针 元素个数 每个元素的字节数 比较函数
	//在这里，元素不一定指一个数据，他可能包含了多个数据，比如要对二维数组进行排序，那么每个元素要包含两个数据，第三个参数也就要写成sizeof(int)*2 
int cmp(const void* a,const void* b)
{
	int* pa=(int *)a;
	int* pb=(int *)b;
	return pa[0]-pb[0];
	//这是一个最简单的比较函数，根据第一个数的大小来对每个元素升序排序	
	//降序排序只需要写成pb[0]-pa[0] 
} 
//如果想要对每个元素的第i个数升序排序，只需要写成pa[i]-pb[i] 
//有时候会遇到对long long的数组排序
//由于cmp返回的是int，如果还写 return pa[0]-pb[0] 可能会发生数据溢出的情况
//这个时候可以写成 return pa[i]>pb[i]-pa[i]<pb[i]来避免数据溢出 
//下面展示一个多级排序的cmp函数
int CMP(const void* a,const void* b)
{
	int* pa=(int *)a;
	int* pb=(int *)b;
	if(pa[0]!=pb[0]) return pa[0]-pb[0];
	return pa[1]-pb[1];
 } 
int main()
{
	return 0; 
} 
