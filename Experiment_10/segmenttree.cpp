#include <bits/stdc++.h>
using namespace std;

class SegTree {
public:
    vector<int> t;
    int n;

    SegTree(int n) {
        this->n = n;
        t.resize(4*n);
    }

    void update(int i, int l, int r, int pos) {
        if(l == r) {
            t[i]++;
            return;
        }
        int m = (l + r) / 2;
        if(pos <= m) update(2*i, l, m, pos);
        else update(2*i+1, m+1, r, pos);
        t[i] = t[2*i] + t[2*i+1];
    }

    int query(int i, int l, int r, int ql, int qr) {
        if(qr < l || r < ql) return 0;
        if(ql <= l && r <= qr) return t[i];
        int m = (l + r) / 2;
        return query(2*i, l, m, ql, qr) + query(2*i+1, m+1, r, ql, qr);
    }
};

vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    vector<int> v = nums;

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    unordered_map<int,int> mp;
    for(int i=0;i<v.size();i++) mp[v[i]] = i;

    SegTree st(v.size());
    vector<int> ans(n);

    for(int i=n-1;i>=0;i--) {
        int idx = mp[nums[i]];
        if(idx > 0)
            ans[i] = st.query(1, 0, v.size()-1, 0, idx-1);
        st.update(1, 0, v.size()-1, idx);
    }

    return ans;
}

int main() {
    vector<int> nums = {5,2,6,1};
    vector<int> res = countSmaller(nums);
    for(int x : res) cout << x << " ";
}