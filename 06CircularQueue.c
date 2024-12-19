#include <stdio.h>
#define MAX 5

// Circular Queue Array
char cqueue_arr[MAX];
// Front and Rear pointers
int front = -1, rear = -1;

// Insert an item into the circular queue
void insert(char item)
{
    // Check if queue is full (when rear is just one step behind front)
    if ((rear + 1) % MAX == front)
    {
        printf("Queue Overflow\n");
        return;
    }

    // If queue is initially empty, set both front and rear to 0
    if (front == -1)
    {
        front = rear = 0;
    }
    // Circular increment of rear pointer
    else
    {
        rear = (rear + 1) % MAX;
    }

    // Insert the element
    cqueue_arr[rear] = item;
    printf("\nInserted: %c", item);
}

// Delete an item from the circular queue
void del()
{
    // Check if queue is empty
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }

    // Display the deleted element
    printf("Element deleted: %c\n", cqueue_arr[front]);

    // If there is only one element in the queue, reset front and rear to -1
    if (front == rear)
    {
        front = rear = -1;
    }
    // Circular increment of front pointer
    else
    {
        front = (front + 1) % MAX;
    }
}

// Display the elements in the queue
void display()
{
    // Check if the queue is empty
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    // Print elements starting from front to rear
    printf("Queue elements: ");
    int i = front;
    // Loop until we reach the rear (circular manner)
    while (i != rear)
    {
        printf("%c ", cqueue_arr[i]);
        i = (i + 1) % MAX;
    }
    printf("%c\n", cqueue_arr[rear]);
}

int main()
{
    int choice;
    char item;
    printf("\nMenu:\n1. Insert\n2. Delete\n3. Display\n0. Quit\n");

    // Menu loop to perform operations
    do
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Switch case to handle different operations
        switch (choice)
        {
        case 1: // Insert an item
            printf("Input character for insertion: ");
            scanf(" %c", &item); // Notice the space before %c to skip any previous newline
            insert(item);
            break;
        case 2: // Delete an item
            del();
            break;
        case 3:
            display();
            break;
        case 0: // Exit program
            printf("Exited\n");
            break;
        default:
            printf("Invalid choice\n"); // Invalid input handling
        }
    } while (choice != 0); // Loop until user chooses to quit

    return 0;
}
