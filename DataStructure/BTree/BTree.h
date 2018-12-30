//
// Created by chaed on 18. 12. 29.
//

#ifndef MULTINODETREE_MULTINODETREE_H
#define MULTINODETREE_MULTINODETREE_H

#include <vector>
#include <unordered_map>
#include <memory>
#include <cassert>

namespace maintree_manager
{
using namespace std;
using param_code = unsigned int;
using key_type = int;

typedef struct node;
typedef struct bnode {

    param_code paramcode;
    node* parent;
    node* head;
    node* tail;
    size_t nodesize;
    bnode(const param_code param, node* parent)
    :paramcode(param), head(nullptr), tail(nullptr),parent(parent),nodesize(0)
    {}
};

typedef struct node
{
    int key;
	param_code bnodeParam;
    bnode* child;
    node* prev;
    node* next;
    node(const param_code parentParam, const int key)
    :child(nullptr), prev(nullptr), next(nullptr),key(key), bnodeParam(parentParam)
    {}
};


/***
 * author : munkwon.chae
 * mail : gooddaumi@gmail.com
 * date : 2018.12.29
 */
class BTree
{
public:

    using ptr_type = std::shared_ptr<bnode>;

	BTree();

	~BTree();

	void Set(const param_code param);
	void Release();
	void Append(const int key);
	void Push(const param_code param, const int key);

	void Pop();
	bnode* Find(const param_code param);
	node* Find(const param_code param, const int key);

    template <class T>
	void Sort(T pred);

private:

	bnode* _CreateNewBNode(node* parent, const param_code param, const int key);
	node* _CreateNewHead(bnode* dest, const int key);
	void _releaseMemory(bnode* parent);

    std::unordered_map<param_code, bnode*> m_bnodemap;
    std::unordered_map<param_code, ptr_type> m_roots;
    bnode* m_currentParent;
    node* m_currentNode;
    std::vector<int> m_accuKey;
};

}

#endif //MULTINODETREE_MULTINODETREE_H
