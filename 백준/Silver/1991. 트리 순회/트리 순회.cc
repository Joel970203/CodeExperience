#include <iostream>
using namespace std;

struct Tree {
    char node;
    Tree* left;
    Tree* right;

    Tree(char value) : node(value), left(nullptr), right(nullptr) {}
};

struct TreeManager {
    Tree* root;

    TreeManager() : root(nullptr) {}

    // 노드 삽입 함수
    void insertNode(char parentValue, char leftValue, char rightValue) {
        if (!root) {
            root = new Tree(parentValue);  // 최초 루트 생성
        }

        Tree* parent = findNode(root, parentValue);
        if (parent) {
            if (leftValue != '.') {
                parent->left = new Tree(leftValue);
            }
            if (rightValue != '.') {
                parent->right = new Tree(rightValue);
            }
        }
    }

    // 부모 노드 찾기
    Tree* findNode(Tree* current, char value) {
        if (!current) return nullptr;
        if (current->node == value) return current;

        Tree* leftResult = findNode(current->left, value);
        if (leftResult) return leftResult;

        return findNode(current->right, value);
    }

    // 전위 순회
    void preorder(Tree* current) {
        if (!current) return;
        cout << current->node;
        preorder(current->left);
        preorder(current->right);
    }

    // 중위 순회
    void inorder(Tree* current) {
        if (!current) return;
        inorder(current->left);
        cout << current->node;
        inorder(current->right);
    }

    // 후위 순회
    void postorder(Tree* current) {
        if (!current) return;
        postorder(current->left);
        postorder(current->right);
        cout << current->node;
    }
};

int main() {
    TreeManager treeManager;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        char parent, left, right;
        cin >> parent >> left >> right;
        treeManager.insertNode(parent, left, right);
    }

    // 요구된 순서로 순회 결과 출력
    treeManager.preorder(treeManager.root);
    cout << endl;
    treeManager.inorder(treeManager.root);
    cout << endl;
    treeManager.postorder(treeManager.root);
    cout << endl;

    return 0;
}
