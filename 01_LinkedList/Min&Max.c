//
//  main.c
//  Min&Max
//
//  Created by rabbi on 2021/07/31.
//

// 백준 No.10818
// 첫째 줄에 주어진 정수 N개의 최솟값과 최댓값을 공백으로 구분해 출력한다.

#include <stdio.h>
#include <stdlib.h>

typedef int Data;

// Node 구조체
typedef struct _Node {
    Data data;
    struct _Node* next;
}Node;

// Node를 추가하는 함수
void add(Node** head, Data data) {
    if(*head==NULL) { // head에 아무 노드도 없을 때
        *head = (Node*)malloc(sizeof(Node));
        (*head)->data = data;
        (*head)->next = NULL;
    } else {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = *head;
        *head = newNode;
    }
}

void printMin_Max(Node** head) {
    // 둘째 줄에는 N개의 정수를 공백으로 구분해서 주어진다. 모든 정수는 -1,000,000보다 크거나 같고, 1,000,000보다 작거나 같은 정수이다.
    Node* cursor = *head;
    Data min = 1000000;
    Data max = -1000000;
    while(cursor != NULL) {
        if(cursor->data > max) max = cursor->data;
        if(cursor->data < min) min = cursor->data;
        cursor = cursor->next;
    }
    printf("%d %d", min, max);
}

// LinkedList에서 최솟값을 가진 Node를 찾아 Node의 데이터를 반환해주는 함수
Data findMin(Node** head) {
    Data min;
    min = (*head)->data;
    Node* cursor = *head;
    while(cursor != NULL) {
        if(cursor->data < min) min = cursor->data;
        cursor = cursor->next;
    }
    return min;
}

// LinkedList에서 최댓값을 가진 Node를 찾아 Node의 데이터를 반환해주는 함수
Data findMax(Node** head) {
    Data max;
    max = (*head)->data;
    Node* cursor = *head;
    while(cursor != NULL) {
        if(cursor->data > max) max = cursor->data;
        cursor = cursor->next;
    }
    return max;
}

int main(int argc, const char * argv[]) {
    int input_num;
    Data input;
    Node* head = NULL;
//    printf("입력할 정수의 개수: ");
    scanf("%d", &input_num);
    if(input_num < 1 || input_num > 1000000) return -1; // 첫째 줄에 정수의 개수 N (1 ≤ N ≤ 1,000,000)이 주어진다.
    for(int i = 0; i < input_num; i++) {
//        printf("데이터를 입력하세요: ");
        scanf("%d", &input);
        add(&head, input);
    }
    printMin_Max(&head);
//    printf("%d %d", findMin(&head), findMax(&head));
    return 0;
}
