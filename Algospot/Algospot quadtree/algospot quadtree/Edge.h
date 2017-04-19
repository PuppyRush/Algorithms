
#include <iostream>

class Edge;

typedef struct Node {
	char value;
	Edge *edge;
	
};

enum KIND {
	BLACK = 1,
	WHITE = 0,
	HOLE = -1
};


class Edge {

public:

	bool isOnlyOne;
	const int nodeNumber = 4;
	Node *nodes;

public:

	Edge::Edge() {

		isOnlyOne = false;
		nodes = new Node[nodeNumber];
		memset(nodes, 0, sizeof(Node) * 4);

	}

	Edge::~Edge() {

		for (int i = 0; i < nodeNumber; i++) {
			if (nodes[i].edge != NULL)
				delete nodes[i].edge;
		}
		delete nodes;
	}

	void Edge::setColor(int idx, char color) {

		nodes[idx].value = color;
		nodes[idx].edge = NULL;

	}

	void Edge::setNode(int idx, Edge *edge) {
		
		nodes[idx].edge = edge;
		nodes[idx].value = HOLE;
		
	}

	void Edge::reverseUpDownAtThis() {

		swap(0, 2);
		swap(1, 3);

	}


private :

	void swap(int i, int l) {

		Node temp = nodes[i];
		nodes[i] = nodes[l];
		nodes[l] = temp;

	}
};

