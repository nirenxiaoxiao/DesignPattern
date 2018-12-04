#include "macro.h"
#include<stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "LeetCommon.h"
using namespace std;
int test(const char* szsrc)
{
	char chararr[4]={0};
	int iparr[4]={0};

	char outstr[200]={0};
	int success=0;
	unsigned int outresult = 0;
	int i = 0;
	success=sscanf(szsrc, "%3d%c%3d%c%3d%c%3d%c", &iparr[0], &chararr[0], &iparr[1],&chararr[1],&iparr[2],&chararr[2], &iparr[3], &chararr[3]);

	if(success==7 && chararr[0]==chararr[1] && chararr[2]=='.' && chararr[0]=='.')
	{

		for( i =0; i < 4 ; i++)
		{
			if(iparr[i]<0 ||iparr[i] >255)
				goto ERROR;
		}
		outresult= (iparr[0]<<24) + (iparr[1]<<16) + (iparr[2]<<8) + iparr[3];

		sprintf(outstr,"%u\n",outresult);
		printf(outstr);
		return 0;
	}
ERROR:
	printf("ERROR\n");
	return -1;
}


Node<int>* GenIntList(int cnt)
{
	if (cnt <= 0)
	{
		return NULL;
	}

	Node<int>* head = new Node<int>;
	head->data = rand()%100;
	Node<int>* next = head;
	int i = 1;
	while(i < cnt)
	{
		next->ptr = new Node<int>;
		next->ptr->data = rand()%100;
		next = next->ptr;
		++i;
	}
	return head;
}

Node<int>* ReverseList(Node<int>* node)
{
	if (node == NULL || node->ptr== NULL)
	{
		return node;
	}
	Node<int>* newhead = ReverseList(node->ptr); // �ȷ�ת���������

	node->ptr->ptr = node;	//�ٽ���ǰ�ڵ�(head)����Ϊ��Ȼ������ڵ�(head->next)�ĺ����ڵ�
	node->ptr = NULL;
	return newhead;	// �˴����ص�newhead����Զָ��ת���������Ԫ�ڵ㣬�����Ż�˷���仯��
}


Node<int>* ReverseList2(Node<int>* node)
{
	Node<int>* rev = NULL; //ָ��ʼ��ָ��ת���������׽ڵ�
	Node<int>* now = node; //ָ��ָ��ǰ�������ķ�תǰ��������׽ڵ�
	Node<int>* next = node->ptr; //ָ��ָ�� now �ڵ����һ���ڵ㣬������ now->next ָ��ת��������׽ڵ�ʱ����ʧ�˷�תǰ����������á�

	while(now)
	{
		now->ptr = rev;
		rev = now;
		now = next;
		if (next)
		{
			next = next->ptr;
		}
	}
	return rev;
}

int main2()
{
	char instr[200];
	int res =0;
	freopen("in.txt","r",stdin);
	while((res=scanf("%s", instr)) >0)
	{
		printf("%s:", instr);
		test(instr);
	}
	fclose(stdin);
	return 0;
}




int main()
{
	srand(time(0));

	Node<int>* intList = GenIntList(10);
	Node<int>* it = intList;
	while(it)
	{
		cout << it->data <<" ";
		it = it->ptr;
	}
	cout <<endl;
	Node<int>* rev = ReverseList2(intList);
	it = rev;
	while(it)
	{
		cout << it->data <<" ";
		it = it->ptr;
	}
	cout <<endl;

	Node<int>* rev2 = ReverseList(rev);
	it = rev2;
	while(it)
	{
		cout << it->data <<" ";
		it = it->ptr;
	}
	cout <<endl;

	ReverseList(NULL);

}