#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int key;
  Node* left;   // 왼쪽 자식 노드 인덱스
  Node* right;  // 오른쪽 자식 노드 인덱스
};

Node* newNode(int x) {
  Node* node = new Node;
  node->key = x;
  node->left = nullptr;
  node->right = nullptr;
  return node;
}

void preorder(Node* t) {
  if (!t) return;
  cout << t->key << ' ';
  preorder(t->left);
  preorder(t->right);
}

void inorder(Node* t) {
  if (!t) return;
  inorder(t->left);
  cout << t->key << ' ';
  inorder(t->right);
}

void postorder(Node* t) {
  if (!t) return;
  postorder(t->left);
  postorder(t->right);
  cout << t->key << ' ';
}

Node* treeInsert(Node* t, int x) {
  // t = 루트 노드
  // x = 삽입할 값
  // 작업 완료 후 노트 노드 포인터 반환
  if (t == nullptr) {
    return newNode(x);
  }
  if (x < t->key) {
    t->left = treeInsert(t->left, x);
    return t;
  } else {
    t->right = treeInsert(t->right, x);
    return t;
  }
}

Node* findParent(Node* t, int key, Node*& parent) {
  parent = nullptr;
  Node* cur = t;
  while (cur != nullptr && cur->key != key) {
    parent = cur;
    if (key < cur->key) {
      cur = cur->left;
    } else {
      cur = cur->right;
    }
  }
  return cur;
}

Node* deleteNode(Node* r) {
  if (r == nullptr) {
    return nullptr;
  }
  // 1. 단말 노드인 경우
  if (r->left == nullptr && r->right == nullptr) {
    delete r;
    return nullptr;
  }

  // 2. 자식이 오른쪽만 있을 때
  if (r->left == nullptr) {
    Node* temp = r->right;
    delete r;
    return temp;
  }

  // 3. 자식이 왼쪽만 있을 때
  if (r->right == nullptr) {
    Node* temp = r->left;
    delete r;
    return temp;
  }

  // 4. 자식이 둘 다 있을 때
  Node* parent = r;
  Node* succ = r->right;
  // 후계자 찾기
  while (succ->left != nullptr) {
    parent = succ;
    succ = succ->left;
  }
  r->key = succ->key;
  // 후계자의 부모 노드가 삭제할 노드인 경우
  if (parent == r) {
    parent->right = succ->right;
  } else {
    parent->left = succ->right;
  }
  delete succ;
  return r;
}

Node* treeDelete(Node* t, int key) {
  // t = 루트 노드
  // key = 삭제할 값
  if (t == nullptr) {
    return nullptr;
  }
  Node* p = nullptr;
  Node* r = findParent(t, key, p);
  if (r == nullptr) {
    // 삭제할 노드가 트리에 없음
    return t;
  }

  // 1. r이 루트 노드
  if (p == nullptr) {
    return deleteNode(r);
  }
  // 2. r이 p의 왼쪽 자식
  else if (r == p->left) {
    p->left = deleteNode(r);
  }
  // 3. r이 p의 오른쪽 자식
  else {
    p->right = deleteNode(r);
  }

  return t;
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

  int k;
  cin >> k;
  // p : 순회 종류 (0 : 전위, 1: 중위, 2: 후위)
  // x : 삭제할 원소
  for (int i = 0; i < k; i++) {
    int p, x;
    cin >> p >> x;
    bst = treeDelete(bst, x);
    if (p == 0) {
      preorder(bst);
    } else if (p == 1) {
      inorder(bst);
    } else {
      postorder(bst);
    }
    cout << '\n';
  }

  return 0;
}
