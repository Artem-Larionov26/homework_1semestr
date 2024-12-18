#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Узел стека
typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

// Структура стека
typedef struct Stack {
    StackNode* top;
} Stack;

// Прототип функции isEmpty
bool isEmpty(Stack* stack);

// Очередь на двух стеках
typedef struct Queue {
    Stack* stack1;
    Stack* stack2;
} Queue;

// Создать стек
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) {
        fprintf(stderr, "Stack memory allocation error\n");
        return NULL;
    }
    stack->top = NULL;
    return stack;
}

// Добавить элемент в стек
void push(Stack* stack, int value) {
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    if (!node) {
        fprintf(stderr, "Memory allocation error for stack node\n");
        return;
    }
    node->data = value;
    node->next = stack->top;
    stack->top = node;
}

// Удалить элемент из стека
int pop(Stack* stack, bool* success) {
    if (isEmpty(stack)) {
        if (success) *success = false;
        return 0;
    }
    StackNode* temp = stack->top;
    int value = temp->data;
    stack->top = temp->next;
    free(temp);
    if (success) *success = true;
    return value;
}

// Проверить, пуст ли стек
bool isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Освободить память, выделенную под стек
void destroyStack(Stack* stack) {
    while (!isEmpty(stack)) {
        bool success;
        pop(stack, &success);
    }
    free(stack);
}

// Создать очередь
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (!queue) {
        fprintf(stderr, "Memory allocation error for the queue\n");
        return NULL;
    }
    queue->stack1 = createStack();
    queue->stack2 = createStack();
    if (!queue->stack1 || !queue->stack2) {
        destroyStack(queue->stack1);
        destroyStack(queue->stack2);
        free(queue);
        return NULL;
    }
    return queue;
}

// Добавить элемент в очередь
void enqueue(Queue* queue, int value) {
    push(queue->stack1, value);
}

// Удалить элемент из очереди
int dequeue(Queue* queue, bool* success) {
    if (isEmpty(queue->stack2)) {
        while (!isEmpty(queue->stack1)) {
            bool tempSuccess;
            int value = pop(queue->stack1, &tempSuccess);
            push(queue->stack2, value);
        }
    }
    return pop(queue->stack2, success);
}

// Проверить, пуста ли очередь
bool isQueueEmpty(Queue* queue) {
    return isEmpty(queue->stack1) && isEmpty(queue->stack2);
}

// Освободить память, выделенную под очередь
void destroyQueue(Queue* queue) {
    destroyStack(queue->stack1);
    destroyStack(queue->stack2);
    free(queue);
}

// *** Тесты ***
void runTests() {
    Queue* queue = createQueue();
    if (!queue) {
        printf("Failed to create a queue\n");
        return;
    }
    printf("Test 1: Adding and removing elements\n");
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    bool success;
    int value = dequeue(queue, &success);
    printf("Expected value: 10, Received value: %d\n", value);
    value = dequeue(queue, &success);
    printf("Expected value: 20, Received value: %d\n", value);
    value = dequeue(queue, &success);
    printf("Expected value: 30, Received value: %d\n", value);
    printf("Test 2: Checking for an empty queue\n");
    value = dequeue(queue, &success);
    printf("Expected value: error, Received value: %s\n", success ? "success" : "fail");
    destroyQueue(queue);
    printf("The tests are completed.\n");
}

// *** Основная функция ***
int main() {
    printf("Run tests:\n");
    runTests();
    return 0;
}
