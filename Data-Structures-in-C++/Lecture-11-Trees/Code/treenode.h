#include <vector>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data)
    {
        this->data = data;
    }

    ~TreeNode()             // now we just have to write delete root and whole tree would be deleted
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};