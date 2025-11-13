#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int key;
  Node* left;   // 왼쪽 자식 노드 인덱스
  Node* right;  // 오른쪽 자식 노드 인덱스
};

int cnt = 0;

Node* treeInsert(Node* t, int x) {
  // t = 루트 노드
  // x = 삽입할 값
  // 작업 완료 후 노트 노드 포인터 반환
  cnt++;
  if (t == nullptr) {
    Node* t = new Node;
    t->key = x;
    t->left = nullptr;
    t->right = nullptr;
    return t;
  }
  if (x < t->key) {
    t->left = treeInsert(t->left, x);
    return t;
  } else {
    t->right = treeInsert(t->right, x);
    return t;
  }
}

int main(void) {
  int n;
  cin >> n;
  vector<int> tree(n);

  for (int i = 0; i < n; i++) {
    cin >> tree[i];
  }

  Node* bst = nullptr;
  for (int i = 0; i < n; i++) {
    bst = treeInsert(bst, tree[i]);
  }

  cout << cnt << "\n";
  return 0;
}
