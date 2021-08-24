//
//  main.c
//  Tree
//
//  Created by rabbi on 2021/08/21.
//

#include <stdio.h>
#include <stdlib.h>

typedef int Data;

// 배열로 이진 트리를 구현할 수도 있지만 링크드 리스트로 구현하는 것이 더 직관적
typedef struct BTreeNode {
    Data data;
    struct BTreeNode* left;
    struct BTreeNode* right;
}BTreeNode;

// Node에 동적 할당하여 주소값을 리턴해주는 함수
BTreeNode* MakeBTreeNode() {
    BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
    node->left = NULL;
    node->right = NULL;
    return node;
}

// parameter의 node의 데이터를 설정하는 함수
void SetData(BTreeNode* node, Data data) {
    node->data = data;
}

// parameter의 node의 데이터 값을 반환하는 함수
Data GetData(BTreeNode* node) {
    return node->data;
}

// parent Node의 Left sub Tree를 설정해주는 함수
void MakeLeftSubTree(BTreeNode* parent, BTreeNode* left_child) {
    parent->left = left_child;
}

// parent Node의 Right sub Tree를 설정해주는 함수
void MakeRightSubTree(BTreeNode* parent, BTreeNode* right_child) {
    parent->right = right_child;
}

// parameter의 Left sub Tree의 주소값을 반환하는 함수
BTreeNode* GetLeftSubTree(BTreeNode* parent) {
    return parent->left;
}

// parameter의 Right sub Tree의 주소값을 반환하는 함수
BTreeNode* GetRightSubTree(BTreeNode* parent) {
    return parent->right;
}

// 전위 순회 (루트 노드를 먼저 출력)
void PreorderTraversal(BTreeNode* Node) {
    if(Node == NULL) return;
    printf("%d ", Node->data);
    PreorderTraversal(Node->left);
    PreorderTraversal(Node->right);
    return;
}

// 중위 순회 (루트 노드를 중간(두 번째)에 출력)
void InorderTraversal(BTreeNode* Node) {
    if(Node == NULL) return;
    InorderTraversal(Node->left);
    printf("%d ", Node->data);
    InorderTraversal(Node->right);
    return;
}

// 후위 순회 (루트 노드를 마지막에 출력)
void PostorderTraversal(BTreeNode* Node) {
    if(Node == NULL) return;
    PostorderTraversal(Node->left);
    PostorderTraversal(Node->right);
    printf("%d ", Node->data);
    return;
}

int main(int argc, const char * argv[]) {
    printf("트리 시작...\n");
    printf("\n");
    // Node 생성
    BTreeNode* rootNode = MakeBTreeNode();
    SetData(rootNode, 0);
    BTreeNode* node1 = MakeBTreeNode();
    SetData(node1, 1);
    BTreeNode* node2 = MakeBTreeNode();
    SetData(node2, 2);
    BTreeNode* node3 = MakeBTreeNode();
    SetData(node3, 3);
    BTreeNode* node4 = MakeBTreeNode();
    SetData(node4, 4);
    BTreeNode* node5 = MakeBTreeNode();
    SetData(node5, 5);
    BTreeNode* node6 = MakeBTreeNode();
    SetData(node6, 6);
    
    // 완전 이진 트리(complete binary tree) 생성
    MakeLeftSubTree(rootNode, node1);
    MakeRightSubTree(rootNode, node2);
    MakeLeftSubTree(node1, node3);
    MakeRightSubTree(node1, node4);
    MakeLeftSubTree(node2, node5);
    MakeRightSubTree(node2, node6);
    
    // 순회 별 출력
    printf("전위 순회\n");
    PreorderTraversal(rootNode);
    printf("\n중위 순회\n");
    InorderTraversal(rootNode);
    printf("\n후위 순회\n");
    PostorderTraversal(rootNode);
    printf("\n");
    
    return 0;
}
