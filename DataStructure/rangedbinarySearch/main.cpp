#include <iostream>
#include <vector>
#include <cassert>

typedef struct datapack
{
    datapack(const size_t param)
    :rawparam(param)
    {}
    std::vector<int> ary;
    int rawparam;
};


template <class T>
struct node
{
    explicit node(node* left, node* right,const size_t begin,const size_t end, const T& data)
        :left(left), right(right), begin(begin) ,end(end), data(data)
    {
    }

    explicit node(const size_t begin,const size_t end, const T& data)
        :left(nullptr), right(nullptr), begin(begin), end(end), data(data)
    { }

    node* right;
    node* left;
    size_t begin;
    size_t end;
    T data;
};

template <class T>
class RangedBinarySearch
{
public:
    explicit RangedBinarySearch(const size_t begin, const size_t end, const T& data)
        :root(nullptr)
    {
        root = new node<T>(nullptr, nullptr, begin, end, data);
        nodeCount = 1;
    }

    ~RangedBinarySearch()
    {
        _removeAll(root);
    }

    void insert(node<T>* src)
    {
        _insert(root,src);
    }

    const node<T>* find(const size_t param) const
    {
        return _find(root, param);
    }

    void removeAll()
    {
        _removeAll(root);
        delete root;
        root = nullptr;
    }

    inline const size_t size() const
    {
        return nodeCount;
    }
private:
    node<T>* root;
    size_t nodeCount;

    //return ranged node, if cant find ranged node, return nullptr
    const node<T>* _find(const node<T>* dest, const size_t param) const
    {
        if(dest->begin < param && param < dest->end )
            return dest;

        if(dest->begin && dest->begin > param)
           return _find(dest->left, param);
        else if(dest->end && dest->end < param)
            return _find(dest->right, param);

        return nullptr;
    }

    void _insert( node<T>* dest, node<T>* src)
    {

        if(dest->begin > src->end) {
            if(dest->left)
                _insert(dest->left, src);
            else
            {
                dest->left = src;
            }
            nodeCount++;
        }
        else if(dest->end < src->begin) {
            if(dest->right)
                _insert(dest->right, src);
            else
            {
                dest->right = src;
            }
            nodeCount++;
        }
        else
            assert(0); // cant insert duplicated node with inserted node. (duplicated range)
    }

    void _removeAll(node<T>* _node)
    {
        if(_node==nullptr)
            return;

        _removeAll(_node->left);
        if(_node->left) {
            delete _node->left;
            _node->left = nullptr;
        }

        _removeAll(_node->right);
        if(_node->right) {
            delete _node->right;
            _node->right = nullptr;
        }
    }

};

int main() {
    std::cout << "Hello, World!" << std::endl;

    RangedBinarySearch<datapack> bs(100u,110u, datapack(105));
    bs.insert(new node<datapack>(50,70, datapack(60)));
    bs.insert(new node<datapack>(120,130, datapack(60)));
    bs.insert(new node<datapack>(210,250, datapack(60)));
    bs.insert(new node<datapack>(150,200, datapack(60)));
    bs.insert(new node<datapack>(5,7, datapack(60)));
    bs.insert(new node<datapack>(10,40, datapack(60)));
    bs.insert(new node<datapack>(71,90, datapack(60)));
    bs.insert(new node<datapack>(95,97, datapack(60)));

    auto n = bs.find(60);
    bs.removeAll();
    return 0;
}