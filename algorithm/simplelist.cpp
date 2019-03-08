#include <iostream>

using namespace std;

struct node
{
	node *next;
	node *prev;
	int data;
};

struct  simpleList
{
	node *nil;
};

node* list_search(simpleList L, int k)
{
	node* x = L.nil->next;
	while (x != L.nil && x->data != k)
	{
		x = x->next;
	}
	return x;
}

void list_insert(simpleList L,int item)
{
	node* new_node = new node; 
	new_node->data = item;
	new_node->next = L.nil->next;
	L.nil->next->prev = new_node;
	L.nil->next = new_node;
	new_node->prev = L.nil;
}

void iterate_list(simpleList L) {
	node *x = L.nil->next;
	while (x != L.nil)
	{
		cout << x->data << " ";
		x = x->next;
	}
}
//n번째를 지워라정도..
void list_delete(simpleList L, int n)
{
	node* x = L.nil;
	for (int i = 0; i < n; i++)
	{
		x = x->next;
	}
	x->prev->next = x->next;
	x->next->prev = x->prev;
	delete x;
}

int main()
{
	node* nil = new node;
	nil->next = nil;
	nil->prev = nil;
	simpleList L = {nil};
	list_insert(L, 1);
	list_insert(L, 2);
	list_insert(L, 4);
	list_insert(L, 3);
	list_insert(L, 6);
	list_insert(L, 7);
	iterate_list(L);
	list_delete(L, 2);
	iterate_list(L);

	delete nil;
	return 0;
	//병신리스트
}