//
//  main.c
//  01_LinkedList
//
//  Created by rabbi on 2021/07/30.
//

#include <stdio.h>
#include <stdlib.h>

typedef int Data;

// Node 구조체
typedef struct _Node {
    Data data;
    struct _Node* next;
}Node;

// Node를 LinkedList Head에 추가하는 함수
void addAtHead(Node** head, Data data) {
    if(*head==NULL) { // head에 아무 노드도 없을 때
        printf("\n");
        printf("노드가 없습니다. 노드를 추가합니다...\n\n");
        *head = (Node*)malloc(sizeof(Node));
        (*head)->data = data;
        (*head)->next = NULL;
    } else {
        printf("\n");
        printf("노드를 추가합니다...\n\n");
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = *head;
        *head = newNode;
    }
}

// Node를 LinkedList tail에 추가하는 함수
void addAtTail(Node** head, Data data) {
    if(*head==NULL) { // head에 아무 노드도 없을 때
        printf("\n");
        printf("노드가 없습니다. 노드를 추가합니다...\n\n");
        *head = (Node*)malloc(sizeof(Node));
        (*head)->data = data;
        (*head)->next = NULL;
    } else {
        printf("\n");
        printf("노드를 추가합니다...\n\n");
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

// 맨 앞의 Node를 삭제하고 삭제한 Node의 데이터를 반환하는 함수
Data deleteHead(Node** head) {
    Node* cursor = *head;
    Data ret_data = -1; // 삭제 후 반환할 데이터
    if(cursor==NULL) { // 삭제할 Node가 없을 때
        printf("\n");
        printf("삭제할 Node가 없습니다.\n\n");
        return -1;
    } else {
        ret_data = (*head)->data;
        *head = (*head)->next;
        free(cursor);
    }
    printf("\n");
    printf("노드를 삭제했습니다. 삭제 데이터: %d\n\n", ret_data);
    return ret_data;
}

// 맨 끝의 Node를 삭제하고 삭제한 Node의 데이터를 반환하는 함수
Data deleteTail(Node** head) {
    Node* cursor = *head;
    Data ret_data = -1; // 삭제 후 반환할 데이터
    if(cursor==NULL) { // 삭제할 Node가 없을 때
        printf("삭제할 Node가 없습니다.\n\n");
        return -1;
    } else if(cursor->next==NULL) { // 삭제할 Node가 하나 남았을 때
        ret_data = cursor->data;
        free(cursor);
        *head = NULL;
    } else {
        while(cursor->next->next != NULL) {
            cursor = cursor->next;
        }
        ret_data = cursor->next->data;
        free(cursor->next);
        cursor->next = NULL;
    }
    printf("\n");
    printf("노드를 삭제했습니다. 삭제 데이터: %d\n\n", ret_data);
    return ret_data;
}

// Node 탐색 함수
void show(Node** head) {
    if(*head==NULL) {
        printf("Node가 없습니다.\n\n");
    } else {
        printf("노드를 출력합니다...\n");
        Node* cursor = *head;
        while(cursor != NULL) {
            printf("%d -> ", cursor->data);
            cursor = cursor->next;
        }
        printf("END\n\n");
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    Node* head = NULL;
    int input = -1; // 선택 input
    
    while(1) {
        printf("링크드 리스트 시작...\n\
1. 추가\n\
2. 삭제\n\
3. 탐색\n\
4. 종료\n");
        scanf("%d", &input);
        printf("\n");
        switch (input) {
            case 1: // 1. 추가
                printf("추가할 데이터를 입력하세요\n");
                Data data;
                scanf("%d", &data);
                printf("\n");
                printf("Node를 어디에 추가할까요?\n\
1. Head\n\
2. tail\n");
                scanf("%d", &input);
                if(input == 1) addAtHead(&head, data);
                if(input == 2) addAtTail(&head, data);
                break;
            case 2: // 2. 삭제
                printf("어디에 있는 Node를 삭제할까요?\n\
1. Head\n\
2. tail\n");
                scanf("%d", &input);
                if(input == 1) deleteHead(&head);
                if(input == 2) deleteTail(&head);
                break;
            case 3: // 3. 탐색
                show(&head);
                break;
            case 4:
                goto EXIT;
            default:
                printf("잘못된 입력입니다.\n\n");
        }
    EXIT:
        if(input==4) break; // 4. 종료
    }
    return 0;
}
