//
//  main.c
//  Modi_Avg
//
//  Created by rabbi on 2021/08/01.
//

// 백준 No.1546
// 세준이는 기말고사를 망쳤다. 세준이는 점수를 조작해서 집에 가져가기로 했다. 일단 세준이는 자기 점수 중에 최댓값을 골랐다. 이 값을 M이라고 한다. 그리고 나서 모든 점수를 점수/M*100으로 고쳤다.
//
// 예를 들어, 세준이의 최고점이 70이고, 수학점수가 50이었으면 수학점수는 50/70*100이 되어 71.43점이 된다.
//
// 세준이의 성적을 위의 방법대로 새로 계산했을 때, 새로운 평균을 구하는 프로그램을 작성하시오.

#include <stdio.h>
#include <stdlib.h>

typedef float Data;

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
        Node* cursor = *head;
        while(cursor->next != NULL) {
            cursor = cursor->next;
        }
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;
        cursor->next = newNode;
    }
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

// 최고점을 활용해 기존 점수를 Data로 가지고 있는 LinkedList를 수정하는 함수
void ModifyScore(Node** head, Data max_score) {
    Node* cursor = *head;
    while(cursor != NULL) {
        cursor->data = cursor->data/max_score * 100;
        cursor = cursor->next;
    }
}

Data GetNewAvg(Node** head, int sub) {
    Data total = 0; // 총점
    Node* cursor = *head;
    while(cursor != NULL) {
        total += cursor->data;
        cursor = cursor->next;
    }
    return total/sub;
}

int main(int argc, const char * argv[]) {
    int sub; // 입력할 과목 수
    int score; // 점수
    Node* head = NULL;
    scanf("%d", &sub);
    if(sub > 1000) return -1; // 첫째 줄에 시험 본 과목의 개수 N이 주어진다. 이 값은 1000보다 작거나 같다.
    for(int i = 0; i < sub; i++) {
        scanf("%d", &score);
        if(score < 0 || score > 100) continue; // 둘째 줄에 세준이의 현재 성적이 주어진다. 이 값은 100보다 작거나 같은 음이 아닌 정수
        add(&head, score);
    }
    ModifyScore(&head, findMax(&head)); // 최고점을 활용해 기존 점수를 수정
    printf("%f", GetNewAvg(&head, sub));
    return 0;
}
