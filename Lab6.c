#include <stdio.h>
#include <stdlib.h>

#define MAX 3

char cqueue_arr[MAX];
int front = -1;
int rear = -1;

void insert(char item) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    } else {
        if (rear == MAX - 1) {
            rear = 0;
        } else {
            rear++;
        }
    }
    cqueue_arr[rear] = item;
}

void del() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Element deleted from queue is: %c\n", cqueue_arr[front]);
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        if (front == MAX - 1) {
            front = 0;
        } else {
            front++;
        }
    }
}

void display() {
    int front_pos = front, rear_pos = rear;
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements:\n");
    if (front_pos <= rear_pos) {
        while (front_pos <= rear_pos) {
            printf("%c ", cqueue_arr[front_pos]);
            front_pos++;
        }
    } else {
        while (front_pos < MAX) {
            printf("%c ", cqueue_arr[front_pos]);
            front_pos++;
        }
        front_pos = 0;
        while (front_pos <= rear_pos) {
            printf("%c ", cqueue_arr[front_pos]);
            front_pos++;
        }
    }
    printf("\n");
}

int main() {
    int choice;
    char item;

    do {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Input the character for insertion in queue: ");
                scanf(" %c", &item);
                insert(item);
                break;
            case 2:
                del();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting Program...\nExited\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}






