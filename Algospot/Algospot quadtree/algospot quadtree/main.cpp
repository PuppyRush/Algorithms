#define _CRT_SECURE_NO_WARNINGS
#define NODE_NUMBER  4

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>

struct Edge;

typedef struct Node {
	char value;
	Edge *edge;

};


typedef struct Edge {

	Node nodes[NODE_NUMBER];

};

enum KIND {
	BLACK = 1,
	WHITE = 0,
	HOLE = -1
};


using namespace std;

void drawGraph(const vector<char>*);
vector<char>* reverseGraphToUpDown(Edge*);
Edge* getGraphFrom(vector<char>*, int);
vector<char>* getGraphToVector(vector<char>*, int);
int indexOf(vector<char> *, int, char);

void setColor(Node* node, char color);
void setNode(Node* node, Edge *edge);
void reverseUpDownAtThis(Node *nodes);

int main() {

	char buf[1024];
	memset(buf, 0, sizeof(char)*1024);

	int size;
	scanf("%d", &size);

	//xxwwwbxwxwbbbwwxxxwwbbbwwwwbb
	vector<vector<char>> *source = new vector<vector<char>>(size);

	for (size_t i = 0; i < size; i++) {

		scanf("%s", &buf);
		
		int l = 0;
		while (buf[l] != 0) {
			source->at(i).push_back(buf[l]);
			l++;
		}
		memset(buf, 0, 1024);

	}

	for (size_t i = 0; i < source->size(); i++) {

		vector<char>* reserve = new vector<char>;



		if (source->at(i).size() == 1) {
			reserve->push_back(source->at(i).at(0));
		}
		else {

			Edge* wholeEdge = getGraphFrom(&source->at(i), 0);	
			//reserve = reverseGraphToUpDown(wholeEdge);

		}
		for (int l = 0; l < reserve->size(); l++)
			cout << reserve->at(l);

		cout << endl;
	}

	_CrtDumpMemoryLeaks();
}

Edge* getGraphFrom(vector<char> *source, int begin) {


	Edge *graph = new Edge();
	memset(graph, 0, sizeof(Edge));
	
	if (source->size() == 0)
		return graph;

	int i = 0;
	char buf;

	int deletedNodeNumber = 0;
	int idx = indexOf(source, begin, 'x');

	if (idx != -1) {

		for (i = 0; i < 4; i++) {

			if ((buf = source->at(idx + i + 1)) != 'x')
				setColor(&graph->nodes[i], buf);
			else {
				Edge *edge = getGraphFrom(source, idx + i + 1);
				setNode(&graph->nodes[i], edge);
				idx--;
				deletedNodeNumber++;
			}
		}

		if (source->size() <= 4)
			return graph;

		source->erase(source->begin() + begin, source->begin() + begin + 5 - deletedNodeNumber);
		reverseUpDownAtThis(graph->nodes);
	}
	else {

		if (source->size() == 1) {
			char buf = source->at(0);
			setColor(&graph->nodes[0] , buf);
			setColor(&graph->nodes[1] , buf);
			setColor(&graph->nodes[2] , buf);
			setColor(&graph->nodes[3] , buf);
		}

	}


	return graph;


}


vector<char>* reverseGraphToUpDown(Edge* src) {

	vector<char> *dest = new vector<char>;

	reverseUpDownAtThis(src->nodes);

	dest->push_back('x');
	for (int i = 0; i < NODE_NUMBER; i++) {
		if (src->nodes[i].value == HOLE) {
			vector<char> *temp = reverseGraphToUpDown(src->nodes[i].edge);
			dest->insert(dest->end(), temp->begin(), temp->end());
		}
		else
			dest->push_back(src->nodes[i].value);
	}

	return dest;
}

int indexOf(vector<char> *src, int begin, char dest) {

	for (size_t i = begin; i < src->size() - 1; i++) {

		if (src->at(i) == dest)
			return i;

	}

	return -1;
}


void setColor(Node* node, char color) {
	
	node->value = color;
	node->edge = NULL;

}

void setNode(Node* node , Edge *edge) {

	node->edge = edge;
	node->value = HOLE;

}

void reverseUpDownAtThis(Node *nodes) {

	Node temp = nodes[0];
	nodes[0] = nodes[2];
	nodes[2] = temp;

	temp =  nodes[1];
	nodes[1] = nodes[3];
	nodes[3] = temp;
}

