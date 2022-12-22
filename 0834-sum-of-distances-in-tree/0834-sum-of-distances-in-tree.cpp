class Solution {
public:
    vector<unordered_set<int>> tree;
    vector<int> res, count;

    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        tree.resize(N);
        res.assign(N, 0);
        count.assign(N, 1);
        for (auto e : edges) {
            tree[e[0]].insert(e[1]);
            tree[e[1]].insert(e[0]);
        }
        postorder(0, -1);
        preorder(0, -1);
        return res;

    }

    void postorder(int root, int pre) {
        for (auto i : tree[root]) {
            if (i == pre) continue;
            postorder(i, root);
            count[root] += count[i];
            res[root] += res[i] + count[i];
        }
    }

    void preorder(int root, int pre) {
        for (auto i : tree[root]) {
            if (i == pre) continue;
            res[i] = res[root] - count[i] + count.size() - count[i];
            preorder(i, root);
        }
    }

};