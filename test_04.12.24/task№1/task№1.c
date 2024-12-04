#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define QUEUE_SIZE 50 

typedef struct { // data storage structure
	int data[QUEUE_SIZE]; // place to store elements
	int head; 
	int tail;
	int size;
} CircularQueue;

void initializeQueue(CircularQueue* queue) { // queue initialization function
	queue->head = 0;
	queue->tail = 0;
	queue->size = 0;
	// Filling the array with initial values
	for (int i = 0; i < QUEUE_SIZE; i++) {
		queue->data[i] = i + 1;
	}
	queue->tail = QUEUE_SIZE;
	queue->size = QUEUE_SIZE;
}

// Checking if the queue is empty
bool isEmpty(CircularQueue* queue) {
	return queue->size == 0;
}

// Checking if the queue is full
bool isFull(CircularQueue* queue) {
	return queue->size == QUEUE_SIZE;
}

// Adding an element to the queue
bool enqueue(CircularQueue* queue, int value) {
	if (isFull(queue)) {
		printf("The queue is full. It isn't possible to add an element!\n");
		return false;
	}
	queue->data[queue->tail] = value;
	queue->tail = (queue->tail + 1) % QUEUE_SIZE;
	queue->size++;
	return true;
}

// Removing an element from the queue
bool dequeue(CircularQueue* queue, int* value) {
	if (isEmpty(queue)) {
		printf("The queue is empty. The element cannot be deleted!\n");
		return false;
	}
	*value = queue->data[queue->head];
	queue->head = (queue->head + 1) % QUEUE_SIZE;
	queue->size--;
	return true;
}

// queue element output function
void printQueue(CircularQueue* queue) {
	if (isEmpty(queue)) {
		printf("The queue is empty!\n");
		return;
	}
	printf("Queue elements: ");
	for (int i = 0, idx = queue->head; i < queue->size; i++) {
		printf("%d ", queue->data[idx]);
		idx = (idx + 1) % QUEUE_SIZE;
	}
	printf("\n");
}

// Testing the queue functionality
void runTests() {
	CircularQueue testQueue;
	initializeQueue(&testQueue);
	printf("Test 1: Initialization and initial state\n");
	printQueue(&testQueue);
	printf("Test 2: Adding Elements (enqueue)\n");
	enqueue(&testQueue, 11);
	printQueue(&testQueue);
	printf("Test 3: Deleting Items (dequeue)\n");
	int value;
	dequeue(&testQueue, &value);
	printf("Deleted value: %d\n", value);
	printQueue(&testQueue);
	printf("Test 4: Queue overflow\n");
	for (int i = 0; i < 5; i++) {
		enqueue(&testQueue, i + 12);
	}
	printQueue(&testQueue);
	printf("Test 5: Empty queue\n");
	while (!isEmpty(&testQueue)) {
		dequeue(&testQueue, &value);
	}
	printQueue(&testQueue);
}

int main() {
	CircularQueue queue;
	initializeQueue(&queue);
	printf("Running tests:\n");
	runTests();
	int choice;
	int value;
	do {
		printf("\nMenu: \n");
		printf("1. Add an element to the queue (enqueue)\n");
		printf("2. Remove an element from the queue (dequeue)\n");
		printf("3. Show queue elements\n");
		printf("0. Exit\n");
		printf("Your choice: ");
		scanf_s("%d", &choice);
		switch (choice) {
		    case 1:
				printf("Enter the value to add: ");
				scanf_s("%d", &value);
				enqueue(&queue, value);
				break;
			case 2:
				if (dequeue(&queue, &value)) {
					printf("Deleted value: %d\n", value);
				}
				break;
			case 3:
				printQueue(&queue);
				break;
			case 0:
				printf("Exiting the program\n");
				break;
			default:
				printf("Wrong choice. Try again\n");
		}
	} while (choice != 0);
	return 0;
}