#define _CRT_SECURE_NO_WARNINGS
#define FOR(l,size) for(l ; l < size ; ++l)

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

typedef struct NODE {
	
	NODE *prev, *next;
	int idx;

}Node;

Node **tail, **head, *list;
int nodecount;
vector<vector<int>> result;

void init(Node* firstNode);
void append(Node** newnode);
void insert(Node** src, Node** newnode);
Node** remove(Node** dest);
void printAllList();
void josephus(Node *begignode, const int remaind);




int main() {

	nodecount = 0;

	size_t caseSize = 0;
	scanf("%d", &caseSize);
	
	for (size_t i = 0; i < caseSize; i++) {

		

		int number;
		int seq;

		Node node;
		node.idx = 1;

		init(&node);
		
		scanf("%d %d", &number, &seq);

		int l = 0;
		FOR(l,number-1) {
			int temp = l + 2;
			Node *newNode = new Node();
			newNode->idx = temp;
			append(&newNode);
		}
		
		josephus(*head,seq);

	}

	for (size_t i = 0; i < result.size(); i++) {
		for (size_t l = 0; l < result[i].size(); l++)
			cout << result[i][l] << " ";
		cout << endl;
	}

}

void josephus(Node *beginNode, const int remaind){

	Node *it = *remove(&beginNode);
	
	
	while (nodecount > 2) {

		for (size_t i = 0; i < remaind-1; i++)
			it = it->next;
		

		it = *remove(&it);
	}
	
	it = *head;
	vector<int> res;
	do {
		res.push_back(it->idx);
		it = it->next;
	} while (it != *head);
	
	result.push_back(res);
}

void init(Node* firstNode) {
	
	nodecount = 0;

	if (list == NULL)
		list = firstNode;
	else {
		
		Node *it = *tail;
		while (it != *head) {
			Node *prev = it->prev;
			delete it;
			it = prev;
		}
		list = firstNode;
		
		*head = NULL;
		*tail = NULL;
		
	}

	head = new Node*;
	tail = new Node*;

	*head = list;
	*tail = list;
	list->next = list;
	list->prev = list;

	nodecount++;
}

void append(Node** newnode) {

	(*newnode)->prev = *tail;
	(*newnode)->next = *head;

	(*head)->prev = *newnode;
	(*tail)->next = *newnode;

	*tail = *newnode;

	nodecount++;

}

void insert(Node** src, Node** newnode){

	if (*src == *head) {

		(*head)->prev = *newnode;
		*head = *newnode;

	}
	else {
		(*newnode)->next = *src;
		(*newnode)->prev = (*src)->prev;
		(*src)->prev->next = *newnode;
	}
	nodecount++;
}

Node** remove(Node** dest) {
	

	if (nodecount == 11)
		int i = 3;

	Node *nextIterator = NULL;

	if (*dest == *head) {

		if (nodecount == 1) {
			*head = NULL;
			*tail = NULL;
		}
		else {
			nextIterator = (*dest)->next;
			*head = (*dest)->next;
			list = (*head)->next;

			(*head)->prev = *tail;
			(*tail)->next = *head;
		}
	}
	else if (*dest == *tail) {
		nextIterator = (*tail)->next;

		*tail = (*tail)->prev;
		(*dest)->prev->next = *head;

		(*head)->prev = *tail;
		(*tail)->next = *head;
	}
	else {
		
		nextIterator = (*dest)->next;

		(*dest)->prev->next = (*dest)->next;
		(*dest)->next->prev = (*dest)->prev;
	
	}

	nodecount--;
	return &nextIterator;
}

void printAllList(){

	Node *it = *head;
	while (it != *tail) {

		cout << it->idx << endl;
		it = it->next;

	}
	cout << it->idx << endl;
}


