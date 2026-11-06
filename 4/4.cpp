#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

void insert(Node*& root, int val, int depth, vector<long long>& level_sum) {
    if (root == nullptr) {
        root = new Node(val);

        if (depth >= (int)level_sum.size()) {
            level_sum.resize(depth + 1, 0);
        }
        level_sum[depth] += val; 
        return;
    }

    if (val < root->val) {
        insert(root->left, val, depth + 1, level_sum);
    } else {
        insert(root->right, val, depth + 1, level_sum);
    }
}

int main() {
    int n;
    cin >> n;

    Node* root = nullptr;
    vector<long long> level_sum;

    for (int i = 0; i < n; ++i) {
        int p_i;
        cin >> p_i;
        insert(root, p_i, 0, level_sum);
    }

    cout << level_sum.size() << "\n";

    
    for (size_t i = 0; i < level_sum.size(); ++i) {
        cout << level_sum[i] << (i + 1 == level_sum.size() ? "" : " ");
    }
    cout << "\n";

    return 0;
}