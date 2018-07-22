#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

typedef struct NODE 
{
	NODE *prev, *next;
	int idx;
	bool dead;
	static bool dir;
	NODE()
		:prev(nullptr), next(nullptr), idx(-1), dead(false)
	{}

	static NODE* Next(const NODE* node)
	{
		if (dir)
			return node->next;
		else
			return node->prev;
	}

}Node;
bool NODE::dir = true;

Node **tail, **head, *list;
int nodecount;


void init(Node* firstNode) 
{

	nodecount = 0;

	if (list == nullptr)
		list = firstNode;
	else {

		Node *it = *tail;
		while (it != *head) 
		{
			Node *prev = it->prev;
			delete it;
			it = prev;
		}
		list = firstNode;

		*head = nullptr;
		*tail = nullptr;

	}

	head = new Node*;
	tail = new Node*;

	*head = list;
	*tail = list;
	list->next = list;
	list->prev = list;

	nodecount++;
}

void append(Node** newnode) 
{

	(*newnode)->prev = *tail;
	(*newnode)->next = *head;

	(*head)->prev = *newnode;
	(*tail)->next = *newnode;

	*tail = *newnode;

	nodecount++;

}

inline Node** remove(Node** dest)
{
	(*dest)->dead = true;
	nodecount--;
	return dest;
}

int main() 
{

	int number=0;
	int dir=0;
	int k=0, j=0;

	Node node;
	node.idx = 1;

	init(&node);
		
	scanf("%d %d %d %d", &number, &dir, &k, &j);

	for(size_t l=1; l < number ; l++)
	{
		int temp = l;
		Node *newNode = new Node();
		newNode->idx = l+1;
		append(&newNode);
	}
	if (dir)
		NODE::dir = true;
	else
		NODE::dir = false;

	Node *it = *head;

	while (nodecount >= 2) 
	{
		for (size_t i = 0; i < k;)
		{
			it = NODE::Next(it);

			if (!it->dead)
				i++;
		}

		k += j;
		it = *remove(&it);
	}

	printf("%d", it->next->idx);

	auto next = it->next;
	while (next != nullptr)
	{
		delete it;
		it = next;
	}
}

