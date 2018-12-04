#include <string>

template <class T>
struct Node 
{
	T data;
	Node* ptr;
	Node()
	{
		ptr = NULL;
	}
};

