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
    bnode(const param_code param)
    :paramcode(param), head(nullptr), tail(nullptr),parent(nullptr),nodesize(0)
    {}
};

typedef struct node
{
    int key;
    bnode* child;
    node* prev;
    node* next;
    node(const int key)
    :child(nullptr), prev(nullptr), next(nullptr),key(key)
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

    BTree(const param_code parentParam)
    :m_parentParam(parentParam),m_currentParent(nullptr)
    {
        m_accuKey.reserve(10);
    }

    ~BTree()
    {
        for(auto n : m_roots)
            _releaseMemory(n.second.get());
    }

    void set(const param_code param)
    {
        if(m_roots.count(param))
        {
            m_currentParent = m_roots.at(param).get();
        }
        else
        {
            auto root = std::make_shared<bnode>(param);
            m_roots.insert(make_pair(param, root));
            m_currentParent = root.get();
            m_bnodemap.insert(make_pair(param, root.get()));
        }
    }

    void Release()
    {
        m_currentParent = nullptr;
        m_accuKey.clear();
    }

    void Append(const param_code param, const int key)
    {
        if(m_currentParent==nullptr)
        {
            assert(0);
            return;
        }

        if(m_currentParent->head==nullptr)
        {
            auto newnode = _CreateNewHead(m_currentParent, key);
            m_currentNode = newnode;
        }
        else
        {
            if(m_currentParent->paramcode != param)
            {
                assert(0);
                return;
            }

            if(( m_currentNode = Find(param,key)) == nullptr)
            {
                auto dest = new node(key);
                dest->prev = m_currentParent->tail;
                m_currentParent->tail->next = dest;
                m_currentParent->tail = dest;
                m_currentNode = dest;
            }
        }

        m_accuKey.emplace_back(key);
    }

    void Push(const param_code param, const int key)
    {
        if(m_currentParent==nullptr)
        {
            assert(0);
            return;
        }

        if(m_currentParent==nullptr) {
            Append(param, key);
        }
        else
        {
            auto newparent = _CreateNewBNode(m_currentNode, param, key);
            m_currentParent = newparent;
        }

        m_accuKey.emplace_back(key);
    }

    void Pop()
    {
        if(m_accuKey.empty())
        {
            assert(0);
            return;
        }

        m_accuKey.pop_back();
        if(!m_accuKey.empty()) {
            m_currentParent = m_bnodemap.at(m_accuKey.back());
            m_currentNode = m_currentParent->head;
        }
    }

    bnode* Find(const param_code param)
    {
        if(m_bnodemap.count(param))
            return m_bnodemap.at(param);
        else
            nullptr;
    }

    node* Find(const param_code param, const int key)
    {
        auto n = Find(param);
        if(n == nullptr)
            return nullptr;

        int i=0;
        node* cur_node = nullptr;
        const int size = n->nodesize;
        for(cur_node = n->head ; cur_node != nullptr ; ++i)
        {
            if(cur_node->key == key)
                break;
            cur_node = cur_node->next;
        }
        if(i==size) //the key has found;
        {
            return cur_node;
        }

        return nullptr;
    }

    template <class T>
    void sort(T pred)
    {

    }


private:

    bnode* _CreateNewBNode(node* parent, const param_code param, const int key)
    {
        auto newbnode = new bnode(param);
        parent->child = newbnode;

        _CreateNewHead(newbnode, key);
        m_bnodemap.insert(make_pair(key,newbnode));

        return newbnode;
    }

    node* _CreateNewHead(bnode* dest, const int key)
    {
        if(dest->head != nullptr)
        {
            assert(0);
            return dest->head;
        }

        auto head = new node(key);

        dest->head = head;
        dest->tail = m_currentParent->head;
        dest->nodesize++;

        return head;
    }

    void _releaseMemory(bnode* parent)
    {
        node* n = parent->head;
        while(n != nullptr)
        {
            if(n->child)
                _releaseMemory(n->child);

            auto prev = n;
            n = n->next;
            delete prev;
        }

        delete parent;
    }

    param_code m_parentParam;
    std::unordered_map<param_code, bnode*> m_bnodemap;
    std::unordered_map<param_code, ptr_type> m_roots;
    bnode* m_currentParent;
    node* m_currentNode;
    std::vector<int> m_accuKey;
};

}

#endif //MULTINODETREE_MULTINODETREE_H
