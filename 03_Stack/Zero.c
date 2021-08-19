//
//  main.c
//  Zero
//
//  Created by rabbi on 2021/08/16.
//

// 백준 No.10773
//
// 나코더 기장 재민이는 동아리 회식을 준비하기 위해서 장부를 관리하는 중이다.
// 재현이는 재민이를 도와서 돈을 관리하는 중인데, 애석하게도 항상 정신없는 재현이는 돈을 실수로 잘못 부르는 사고를 치기 일쑤였다. 재현이는 잘못된 수를 부를 때마다 0을 외쳐서, 가장 최근에 재민이가 쓴 수를 지우게 시킨다.
//
// 재민이는 이렇게 모든 수를 받아 적은 후 그 수의 합을 알고 싶어 한다. 재민이를 도와주자!

// 첫 번째 줄에 정수 K가 주어진다. (1 ≤ K ≤ 100,000)
//
// 이후 K개의 줄에 정수가 1개씩 주어진다. 정수는 0에서 1,000,000 사이의 값을 가지며, 정수가 "0" 일 경우에는 가장 최근에 쓴 수를 지우고, 아닐 경우 해당 수를 쓴다.
//
//정수가 "0"일 경우에 지울 수 있는 수가 있음을 보장할 수 있다.

//[1]
//[1,3]
//[1,3,5]
//[1,3,5,4]
//[1,3,5] (0을 불렀기 때문에 최근의 수를 지운다)
//[1,3] (0을 불렀기 때문에 그 다음 최근의 수를 지운다)
//[1,3,7]
//[1,3] (0을 불렀기 때문에 최근의 수를 지운다)
//[1] (0을 불렀기 때문에 그 다음 최근의 수를 지운다)
//[1,6]

#include <stdio.h>
#include <stdlib.h>

typedef int Data;

typedef struct Stack {
    Data* data;
    int cursor;
    int StackSize;
}Stack;

void InitStack(Stack* Stack, int MAX_SIZE) {
    Stack->data = (Data*)malloc(sizeof(Data) * MAX_SIZE);
    Stack->cursor = -1;
    Stack->StackSize = MAX_SIZE;
}

int IsEmpty(Stack* Stack) {
    if(Stack->cursor == -1) { // cursor가 index 0을 가리킨다면 비어있다
        return 1;
    } else {
        return 0;
    }
}

int IsFull (Stack* Stack) {
    if(Stack->cursor ==  Stack->StackSize - 1) { // cursor가 배열의 끝의 index를 가리킨다면 포화 상태이다
        return 1;
    } else {
        return 0;
    }
}

void Push(Stack* Stack, Data data) {
    if(IsFull(Stack)) {
        printf("포화 상태입니다.\n");
    } else {
        Stack->data[++Stack->cursor] = data;
    }
}

Data Pop(Stack* Stack) {
    if(IsEmpty(Stack)) {
        printf("비어있는 상태입니다.\n");
        return -1;
    } else {
        return Stack->data[Stack->cursor--];
    }
}

void PrintStack(Stack* Stack) {
    if(IsEmpty(Stack)) {
        printf("비어 있습니다.\n");
    } else {
        for(int i = 0; i <= Stack->cursor; i++) {
                printf("%d --> ", Stack->data[i]);
            }
            printf("END\n");
    }
}

int main(int argc, const char * argv[]) {
    Stack stack;
    int input;
    int data;
    int total = 0;
    
    scanf("%d", &input);
    InitStack(&stack, input);
    
    for(int i = 0; i < input; i++) {
        scanf("%d", &data);
        if(data==0) {
            Pop(&stack);
        } else {
            Push(&stack, data);
        }
    }
    
    while (!IsEmpty(&stack)) {
        total += Pop(&stack);
    }
    
    printf("%d\n", total);
    
    return 0;
}
