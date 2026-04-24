#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int cnt;
    Node *left;
    Node *right;
    Node()
    {
        cnt = 0;
        left = right = NULL;
    }
};

class Trie
{
public:
    Node *root;

    Trie()
    {
        root = new Node();
    }

    void insert(int num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (bit == 0)
            {
                if (!node->left)
                    node->left = new Node();
                node = node->left;
            }
            else
            {
                if (!node->right)
                    node->right = new Node();
                node = node->right;
            }
            node->cnt++;
        }
    }

    int query(int num)
    {
        Node *node = root;
        int ans = 0;

        for (int i = 31; i >= 0; i--)
        {
            if (!node)
                break;
            int bit = (num >> i) & 1;

            if (bit == 1)
            {
                if (node->left)
                    ans += node->left->cnt;
                node = node->right;
            }
            else
            {
                node = node->left;
            }
        }
        return ans;
    }
};

vector<int> countSmaller(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n);

    Trie t;

    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] = t.query(nums[i]);
        t.insert(nums[i]);
    }

    return ans;
}

int main()
{
    vector<int> nums = {5, 2, 6, 1};
    vector<int> res = countSmaller(nums);
    for (int x : res)
        cout << x << " ";
}