//
//  main.c
//  Bracket
//
//  Created by rabbi on 2021/08/16.
//

// 백준 No.9012
//
// 괄호 문자열(Parenthesis String, PS)은 두 개의 괄호 기호인 ‘(’ 와 ‘)’ 만으로 구성되어 있는 문자열이다. 그 중에서 괄호의 모양이 바르게 구성된 문자열을 올바른 괄호 문자열(Valid PS, VPS)이라고 부른다.
// 한 쌍의 괄호 기호로 된 “( )” 문자열은 기본 VPS 이라고 부른다. 만일 x 가 VPS 라면 이것을 하나의 괄호에 넣은 새로운 문자열 “(x)”도 VPS 가 된다. 그리고 두 VPS x 와 y를 접합(concatenation)시킨 새로운 문자열 xy도 VPS 가 된다.
// 예를 들어 “(())()”와 “((()))” 는 VPS 이지만 “(()(”, “(())()))” , 그리고 “(()” 는 모두 VPS 가 아닌 문자열이다.
//
// 입력으로 주어진 괄호 문자열이 VPS 인지 아닌지를 판단해서 그 결과를 YES 와 NO 로 나타내어야 한다.

// 입력 데이터는 표준 입력을 사용한다. 입력은 T개의 테스트 데이터로 주어진다. 입력의 첫 번째 줄에는 입력 데이터의 수를 나타내는 정수 T가 주어진다. 각 테스트 데이터의 첫째 줄에는 괄호 문자열이 한 줄에 주어진다. 하나의 괄호 문자열의 길이는 2 이상 50 이하이다.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRING 50
typedef int Data;


typedef struct Stack {
    Data* data;
    int cursor;
    int StackSize;
}Stack;

void InitStack(Stack* Stack, int MAX_SIZE) {
    Stack->data = (Data*)malloc(sizeof(Data) * MAX_SIZE + 1);
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
    int input;
    char* ps = (char*)malloc(sizeof(char) * MAX_STRING); // ps에 저장된 주소는 읽기만 할 수 있고, 쓰기가 막혀있기 때문에 따로 메모리를 할당 해주어야 문자열을 저장할 수 있다
    
    scanf("%d", &input);
    Stack stack;
    bool check; // VPS 여부를 체크하는 변수

    for(int i = 0; i < input; i++) {
        check = true; // true로 초기화
        scanf("%s", ps);
        int str_len = (int)strlen(ps);
        InitStack(&stack, str_len);
        for(int j = 0; j < str_len; j++) {
            if(ps[j] == '(') { // '(' 일때 push
                Push(&stack, 1);
            } else if(ps[j] == ')') { // ')' 일때
                if(IsEmpty(&stack)) { // pop 할 것이 없다면 , VPS가 아님 ex. ())
                    check = false;
                    break;
                } else {
                    Pop(&stack);
                }
            }
        }

        if(!IsEmpty(&stack)) check = false; // Stack이 공백 상태가 아니라면 VPS가 아니다 ex. ((())
        
        if(check) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
