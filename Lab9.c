#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Enode {
    char ssn[15], name[20], dept[5], designation[10];
    int salary;
    long long int phno;
    struct Enode *left, *right;
} *head = NULL, *tail = NULL;

int count = 0;

// Function prototypes
struct Enode* createNode(char[], char[], char[], char[], int, long long int);
void insert(struct Enode**, struct Enode**, char[], char[], char[], char[], int, long long int, int);
void deleteNode(struct Enode**, struct Enode**, int);
void display();
void menu();

// Main function
void main() {
    menu();
}

// Helper to create a new node
struct Enode* createNode(char s[], char n[], char dpt[], char des[], int sal, long long int p) {
    struct Enode *node = (struct Enode *)malloc(sizeof(struct Enode));
    strcpy(node->ssn, s);
    strcpy(node->name, n);
    strcpy(node->dept, dpt);
    strcpy(node->designation, des);
    node->salary = sal;
    node->phno = p;
    node->left = node->right = NULL;
    return node;
}

// Insert at beginning (dir = -1) or end (dir = 1)
void insert(struct Enode **head, struct Enode **tail, char s[], char n[], char dpt[], char des[], int sal, long long int p, int dir) {
    struct Enode *node = createNode(s, n, dpt, des, sal, p);
    if (!*head) {
        *head = *tail = node;
    } else if (dir == -1) { // Insert at beginning
        node->right = *head;
        (*head)->left = node;
        *head = node;
    } else { // Insert at end
        node->left = *tail;
        (*tail)->right = node;
        *tail = node;
    }
    count++;
}

// Delete from beginning (dir = -1) or end (dir = 1)
void deleteNode(struct Enode **head, struct Enode **tail, int dir) {
    if (!*head) {
        printf("List is empty.\n");
        return;
    }
    struct Enode *temp = (dir == -1) ? *head : *tail;
    if (*head == *tail) { // Single node
        *head = *tail = NULL;
    } else if (dir == -1) { // Delete from beginning
        *head = (*head)->right;
        (*head)->left = NULL;
    } else { // Delete from end
        *tail = (*tail)->left;
        (*tail)->right = NULL;
    }
    free(temp);
    count--;
}

// Display the list and count
void display() {
    struct Enode *temp = head;
    if (!temp) {
        printf("List is empty.\n");
        return;
    }
    printf("Employee Details:\n");
    while (temp) {
        printf("%s %s %s %s %d %lld\n", temp->ssn, temp->name, temp->dept, temp->designation, temp->salary, temp->phno);
        temp = temp->right;
    }
    printf("Total Nodes: %d\n", count);
}

// Menu-driven program
void menu() {
    int choice, sal;
    long long int phno;
    char s[15], n[20], dpt[5], des[10];

    printf("1. Create\n2. Display\n3. Insert at Beginning\n4. Insert at End\n");
    printf("5. Delete from Beginning\n6. Delete from End\n7. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            case 3:
            case 4:
                printf("Enter (Emp no, Name, Dept, Desig, Sal, Phone): ");
                scanf("%s %s %s %s %d %lld", s, n, dpt, des, &sal, &phno);
                insert(&head, &tail, s, n, dpt, des, sal, phno, choice == 3 ? -1 : 1);
                break;
            case 2:
                display();
                break;
            case 5:
                deleteNode(&head, &tail, -1);
                break;
            case 6:
                deleteNode(&head, &tail, 1);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}
