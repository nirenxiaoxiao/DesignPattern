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
		int mid = start + (end-start) / 2;//�������int
		MergeSort(vec, start, mid, result);                    //����߽�������
		MergeSort(vec, mid + 1, end, result);                  //���ұ߽�������
		merge(vec, start, mid, end, result);                    //������õ����ݺϲ�
	}
}

template <typename T>
void merge(vector<T>& data, int start, int mid, int end, vector<T>& result)
{
	int i, j, k;
	i = start;
	j = mid + 1;                        //�����ظ��Ƚ�data[mid]
	k = 0;
	while (i <= mid && j <= end)        //����data[start,mid]������(mid,end]��û��ȫ����������result��ȥ
	{
		if (data[i] <= data[j])         //���data[i]С�ڵ���data[j]
			result[k++] = data[i++];    //��data[i]��ֵ����result[k]��֮��i,k����һ����ʾ����һλ
		else
			result[k++] = data[j++];    //���򣬽�data[j]��ֵ����result[k]��j,k����һ
	}
	while (i <= mid)                    //��ʾ����data(mid,end]�Ѿ�ȫ������result������ȥ�ˣ�������data[start,mid]����ʣ��
		result[k++] = data[i++];        //������data[start,mid]ʣ�µ�ֵ����һ��������result
	while (j <= end)                    //��ʾ����data[start,mid]�Ѿ�ȫ�����뵽result������ȥ�ˣ�������(mid,high]����ʣ��
		result[k++] = data[j++];        //������a[mid,high]ʣ�µ�ֵ����һ��������result

	for (i = 0; i < k; i++)             //���鲢��������ֵ��һ��������data[start,end]
		data[start + i] = result[i];    //ע�⣬Ӧ��data[start+i]��ʼ��ֵ
}