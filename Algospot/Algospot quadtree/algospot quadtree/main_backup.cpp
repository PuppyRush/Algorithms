#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include "Edge.h"

using namespace std;

void drawGraph(const vector<char>*);
vector<char>* reverseGraphToUpDown(Edge*);
Edge* reverseGraphToUpDown(vector<char>*, int);
Edge* getGraphFrom(vector<char>*,int);
int indexOf(vector<char> *, int, char);

int main() {

	char buf[1024];
	memset(buf, 0, 1024);

	int size;
	scanf("%d", &size);
	
	//xxwwwbxwxwbbbwwxxxwwbbbwwwwbb
	vector<vector<char>> *source = new vector<vector<char>>(size);

	for (size_t i = 0; i < size; i++) {

		scanf("%s", &buf);
		
		int l = 0;
		while (buf[l] != NULL) {
			source->at(i).push_back(buf[l]);
			l++;
		}
		memset(buf, 0, 1024);

	}

	for (size_t i = 0; i < source->size(); i++) {
		Edge* wholeEdge = getGraphFrom(&source->at(i),0);

		vector<char>* reserve = new vector<char>;
		if (wholeEdge->isOnlyOne) {
			for (int i = 0; i < wholeEdge->nodeNumber; i++)
				reserve->push_back(wholeEdge->nodes[i].value);
		}
		else
			reserve = reverseGraphToUpDown(wholeEdge);

		for (int l = 0; l < reserve->size(); l++)
			cout << reserve->at(l);

		cout << endl;
	}
	
}

vector<char>* reverseGraphToUpDown(Edge* src) {
		
	vector<char> *dest = new vector<char>;

	src->reverseUpDownAtThis();

	dest->push_back('x');
	for (int i = 0; i < src->nodeNumber; i++) {
		if (src->nodes[i].value == HOLE) {
			vector<char> *temp = reverseGraphToUpDown(src->nodes[i].edge);
			temp->insert(temp->begin(), 'x');
			dest->insert(dest->end(), temp->begin(), temp->end());
		}
		else
			dest->push_back(src->nodes[i].value);
	}
		
	return dest;
}

Edge* getGraphFrom(vector<char> *source,int begin) {


	Edge *graph = new Edge();

	if (source->size() == 0)
		return graph;

	int i = 0;
	char buf;
	
	int deletedNodeNumber = 0;
	int idx = indexOf(source, begin, 'x');
	
	if (idx != -1) {

		for (i = 0; i < 4; i++) {

			if ((buf = source->at( idx + i+1) ) != 'x')
				graph->setColor(i, buf);
			else {
				Edge *edge = getGraphFrom(source, idx + i+1);
				graph->setNode(i, edge);
				idx--;
				deletedNodeNumber++;
			}

		}

		if (source->size() <= 4)
			return graph;

		source->erase(source->begin() + begin, source->begin() + begin + 5 - deletedNodeNumber);
		
	}
	else {

		graph->isOnlyOne = true;

		if (source->size() == 1) {
			int buf = source->at(0) = BLACK ? BLACK : WHITE;
			graph->setColor(0, buf);
			graph->setColor(1, buf);
			graph->setColor(2, buf);
			graph->setColor(3, buf);
		}

	}
	

	return graph;


}

int indexOf(vector<char> *src, int begin, char dest) {

	for (size_t i = begin ; i < src->size()-1 ; i++) {

		if (src->at(i) == dest)
			return i;

	}

	return -1;
}
