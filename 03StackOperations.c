#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int stack[MAX], top = -1;

// Function to push an element onto the stack
void push()
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    int item;
    printf("Enter element: ");
    scanf("%d", &item);
    stack[++top] = item;
    printf("Pushed: %d\n", item);
}

// Function to pop an element from the stack
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    printf("Popped: %d\n", stack[top--]);
}

// Function to check if the stack represents a palindrome
void checkPalindrome()
{
    if (top == -1)
    {
        printf("Stack is Empty\n");
        return;
    }
    int flag = 1; // Assume palindrome unless proven otherwise
    for (int i = 0; i <= top / 2; i++) //Iterate upto the middle of the stack
    {
        if (stack[i] != stack[top - i]) // Compare elements from the start and end of the stack
        {
            flag = 0; // Set flag to 0 if any pair of elements do not match
            break; // No need to continue checking further
        }
    }
    printf(flag ? "Palindrome\n" : "Not Palindrome\n");
}

// Function to display the stack
void display()
{
    if (top == -1)
    {
        printf("Stack is Empty\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

// Main function with menu-driven interface
int main()
{
    printf("\n1. Push\n2. Pop\n3. Check Palindrome\n4. Display\n0. Exit\n");

    while (1)
    {
        printf("Enter choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            checkPalindrome();
            break;
        case 4:
            display();
            break;
        case 0:
            printf("Exited\n");
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
