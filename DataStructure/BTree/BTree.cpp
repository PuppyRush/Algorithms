//
// Created by chaed on 18. 12. 29.
//

#include "BTree.h"

using namespace maintree_manager;

BTree::BTree()
	: m_currentParent(nullptr)
{
	m_accuKey.reserve(10);
}

BTree::~BTree()
{
	for (auto n : m_roots)
		_releaseMemory(n.second.get());
}

void BTree::Set(const param_code param)
{
	if (m_roots.count(param))
	{
		m_currentParent = m_roots.at(param).get();
	}
	else
	{
		auto root = std::make_shared<bnode>(param, nullptr);
		m_roots.insert(make_pair(param, root));
		m_currentParent = root.get();
		m_bnodemap.insert(make_pair(param, root.get()));
	}
}

void BTree::Release()
{
	m_currentParent = nullptr;
	m_accuKey.clear();
}

void BTree::Append(const int key)
{
	if (m_currentParent == nullptr)
	{
		assert(0);
		return;
	}

	if (m_currentParent->head == nullptr)
	{
		auto newnode = _CreateNewHead(m_currentParent, key);
		m_currentNode = newnode;
	}
	else
	{
		m_currentNode = Find(m_currentParent->paramcode, key);
		if(m_currentNode == nullptr)
		{
			auto dest = new node(m_currentParent->paramcode , key);
			dest->prev = m_currentParent->tail;
			m_currentParent->tail->next = dest;
			m_currentParent->tail = dest;
			m_currentParent->nodesize++;
			m_currentNode = dest;
		}
	}

	if (m_accuKey.empty())
		m_accuKey.push_back(key);
	else
		m_accuKey.back() = key;
}

void BTree::Push(const param_code param, const int key)
{
	if (m_currentParent == nullptr)
	{
		assert(0);
		return;
	}
	else if (m_currentParent->head == nullptr)
	{
		assert(0); //it need to node lease one;
		return;
	}

	if (m_bnodemap.count(param))
	{
		m_currentParent = m_bnodemap.at(param);
	}
	else
	{
		auto newparent = _CreateNewBNode(m_currentNode, param, key);
		m_currentParent = newparent;
	}

	m_accuKey.emplace_back(key);
}

void BTree::Pop()
{
	if (m_accuKey.empty())
	{
		return;
	}

	m_accuKey.pop_back();
	if (!m_accuKey.empty()) {
		m_currentParent = m_bnodemap.at(m_currentParent->parent->bnodeParam);
		m_currentNode = m_currentParent->head;
	}
}

bnode* BTree::Find(const param_code param)
{
	if (m_bnodemap.count(param))
		return m_bnodemap.at(param);
	else
		nullptr;
}

node* BTree::Find(const param_code param, const int key)
{
	auto n = Find(param);
	if (n == nullptr)
		return nullptr;

	int i = 0;
	node* cur_node = nullptr;
	const int size = n->nodesize;
	for (cur_node = n->head; cur_node != nullptr; ++i)
	{
		if (cur_node->key == key)
			break;
		cur_node = cur_node->next;
	}
	if (i == size) //the key has found;
	{
		return nullptr;
		
	}

	return cur_node; // there is no the key.
}



template <class T>
void BTree::Sort(T pred)
{

}


bnode* BTree::_CreateNewBNode(node* parent, const param_code param, const int key)
{
	auto newbnode = new bnode(param, parent);
	parent->child = newbnode;

	_CreateNewHead(newbnode, key);
	m_bnodemap.insert(make_pair(param, newbnode));

	return newbnode;
}

node* BTree::_CreateNewHead(bnode* dest, const int key)
{
	if (dest->head != nullptr)
	{
		assert(0);
		return dest->head;
	}

	auto head = new node(dest->paramcode, key);

	dest->head = head;
	dest->tail = head;
	dest->nodesize++;

	return head;
}

void BTree::_releaseMemory(bnode* parent)
{
	node* n = parent->head;
	while (n != nullptr)
	{
		if (n->child)
			_releaseMemory(n->child);

		auto prev = n;
		n = n->next;
		delete prev;
	}

	delete parent;
}
