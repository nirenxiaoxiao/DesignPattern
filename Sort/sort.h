#pragma once
#include <vector>
using std::vector;

void RandGen(vector<int>& vec, int cnt );


template <typename T>
void QSort(vector<T>&  vec, int start, int end)
{
	if (start >= end )
	{
		return;
	}
	int first  = start;
	int last = end;
	int key = vec[first];

	while(first < last)
	{
		while(first < last && vec[last] >= key)
		{
			--last;
		}

		vec[first] = vec[last];

		while(first < last &&vec[first] <= key)
		{
			++first;
		}
		vec[last] = vec[first];
	}

	vec[first] = key;

	QSort(vec, start, first - 1);
	QSort(vec, first+1, end);
}



template <typename T>
void MergeSort(vector<T>&  vec, int start, int end, vector<T>& result)
{
	if (start < end)
	{
		int mid = start + (end-start) / 2;//避免溢出int
		MergeSort(vec, start, mid, result);                    //对左边进行排序
		MergeSort(vec, mid + 1, end, result);                  //对右边进行排序
		merge(vec, start, mid, end, result);                    //把排序好的数据合并
	}
}

template <typename T>
void merge(vector<T>& data, int start, int mid, int end, vector<T>& result)
{
	int i, j, k;
	i = start;
	j = mid + 1;                        //避免重复比较data[mid]
	k = 0;
	while (i <= mid && j <= end)        //数组data[start,mid]与数组(mid,end]均没有全部归入数组result中去
	{
		if (data[i] <= data[j])         //如果data[i]小于等于data[j]
			result[k++] = data[i++];    //则将data[i]的值赋给result[k]，之后i,k各加一，表示后移一位
		else
			result[k++] = data[j++];    //否则，将data[j]的值赋给result[k]，j,k各加一
	}
	while (i <= mid)                    //表示数组data(mid,end]已经全部归入result数组中去了，而数组data[start,mid]还有剩余
		result[k++] = data[i++];        //将数组data[start,mid]剩下的值，逐一归入数组result
	while (j <= end)                    //表示数组data[start,mid]已经全部归入到result数组中去了，而数组(mid,high]还有剩余
		result[k++] = data[j++];        //将数组a[mid,high]剩下的值，逐一归入数组result

	for (i = 0; i < k; i++)             //将归并后的数组的值逐一赋给数组data[start,end]
		data[start + i] = result[i];    //注意，应从data[start+i]开始赋值
}