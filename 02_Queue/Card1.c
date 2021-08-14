//
//  main.c
//  Card1
//
//  Created by rabbi on 2021/08/09.

// 백준 No.2161
// N장의 카드가 있다. 각각의 카드는 차례로 1부터 N까지의 번호가 붙어 있으며, 1번 카드가 제일 위에, N번 카드가 제일 아래인 상태로 순서대로 카드가 놓여 있다.
// 이제 다음과 같은 동작을 카드가 한 장 남을 때까지 반복하게 된다. 우선, 제일 위에 있는 카드를 바닥에 버린다. 그 다음, 제일 위에 있는 카드를 제일 아래에 있는 카드 밑으로 옮긴다.
// 예를 들어 N=4인 경우를 생각해 보자. 카드는 제일 위에서부터 1234 의 순서로 놓여있다. 1을 버리면 234가 남는다. 여기서 2를 제일 아래로 옮기면 342가 된다. 3을 버리면 42가 되고, 4를 밑으로 옮기면 24가 된다. 마지막으로 2를 버리고 나면, 버린 카드들은 순서대로 1 3 2가 되고, 남는 카드는 4가 된다.
//
// N이 주어졌을 때, 버린 카드들을 순서대로 출력하고, 마지막에 남게 되는 카드를 출력하는 프로그램을 작성하시오

#include <stdio.h>
#include <stdlib.h>

typedef int Data;

typedef struct Queue {
    int rear;
    int front;
    int QueueSize;
    Data* data; // 동적 할당으로 크기를 정할 예정
}Queue;

// Queue가 비어 있는지 확인해주는 함수
int IsEmpty(Queue* queue) {
    if(queue->front == queue->rear) return 1; // front와 rear가 같은 곳을 가리키고 있다면 비어있다
    return 0;
}

// Queue가 꽉 차 있는지 확인해주는 함수
int IsFull(Queue* queue) {
    if(((queue->rear + 1) % queue->QueueSize) == queue->front) return 1;
    return 0;
}

// data를 Queue에 Enqueue 해주는 함수
void Enqueue(Queue *queue, Data data) {
//    if(IsFull(queue)) {
//        printf("\n");
//        printf("포화 상태입니다.\n");
//    } else {
        queue->data[(++queue->rear) % queue->QueueSize] = data;
//    }
}

// Queue에서 Dequeue 하고 data를 리턴해주는 함수
Data Dequeue(Queue *queue) {
//    if(IsEmpty(queue)) {
//        printf("비어 있습니다.\n");
//        return -1;
//    }
    Data ret_data = queue->data[(++queue->front) % queue->QueueSize];
    return ret_data;
}

// Queue의 첫 번째 data를 출력해주는 함수
Data Peek(Queue *queue) {
    return queue->data[(queue->front + 1) % queue->QueueSize];
}

int main(int argc, const char * argv[]) {
    Queue queue;
    int size;
    scanf("%d", &size);
    queue.QueueSize = size + 1;
    queue.data = (Data*)malloc(sizeof(Data) * queue.QueueSize);
    int collector[size];
    
//  1번 카드가 제일 위에, N번 카드가 제일 아래인 상태로 순서대로 카드가 놓여 있다.
    for(int i = 1; i <= size; i++) {
        Enqueue(&queue, i);
    }
    
    for(int i = 0; i < size - 1; i++) {
        collector[i] = Dequeue(&queue); // 제일 위에 있는 카드를 버리고 collector 배열에 넣어준다
        Enqueue(&queue, Dequeue(&queue)); // 그 다음, 제일 위에 있는 카드를 제일 아래에 있는 카드 밑으로 옮긴다
    }
    collector[size - 1] = Dequeue(&queue); // 마지막에 남게 되는 카드를 넣어준다

//    if(size == 1) printf("%d ", collector[0]);

    for(int i = 0; i < size; i++) {
        printf("%d ", collector[i]); // 버린 카드들을 순서대로 출력하고, 마지막에 남게 되는 카드를 출력
    }
    
    return 0;
}
