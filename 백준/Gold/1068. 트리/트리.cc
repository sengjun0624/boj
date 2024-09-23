#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int Max = 50;

struct Node {
public:
    int data;
    vector<Node *> childs;
    Node *parent = nullptr;

    Node(int data) {
        this->data = data;
    }

    void addChild(Node *node) {
        childs.emplace_back(node);
        node->parent = this;
    }

};

Node *pool[50];
Node *root;
void Delete(Node *cur) {
    if (cur == nullptr) return;  // 존재하지 않는 노드 처리
   
    while (!cur->childs.empty()) {
        Delete(cur->childs.back());
       
    }

   if (cur->data == root->data) {
        // 루트 노드 처리
        root = nullptr;
       pool[cur->data] = nullptr;
        return;
    } else {
        Node *parent = cur->parent;
        auto it = find(parent->childs.begin(), parent->childs.end(), cur);
        if (it != parent->childs.end()) {
            parent->childs.erase(it);
        }
    }

    pool[cur->data] = nullptr;
    delete cur;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < Max; i++) {
        pool[i] = nullptr;
    }
    vector<pair<int,int>>tree;
    for (int i = 0; i < n; i++) {
        int node;
        cin >> node;
        if (node == -1) {
            root = new Node(i);
            pool[i] = root;
        } else {
            Node *newNode = new Node(i);
            pool[i] = newNode;
            tree.push_back({node,i});
        }
    }

    for (auto it: tree) {
        pool[it.first]->addChild(pool[it.second]);
    }

    int num;
    cin >> num;
    if (num >= 0 && num < n && pool[num] != nullptr) {
        Delete(pool[num]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (pool[i] != nullptr && pool[i]->childs.empty()) {

            ans++;
        }
    }
    cout << ans;
}