#include <stdio.h>
#include <math.h>
#define MAX 20

// Define a stack structure to store values
struct stack {
    int top;
    float str[MAX];
} s;

// Postfix expression array
char postfix[MAX];

// Function declarations
void push(float);                  // Push element to stack
float pop();                       // Pop element from stack
int isoperand(char);               // Check if a character is an operand
float operate(float, float, char); // Perform operation on operands

int main() {
    int i = 0;
    printf("Enter Postfix Expression: ");
    scanf("%s", postfix); // Read the postfix expression

    float ans, op1, op2;

    // Process each character in the postfix expression
    while(postfix[i] != '\0') {
        if(isoperand(postfix[i])) {
            // Convert operand (char to int) and push it to the stack
            push(postfix[i] - '0');
        }
        else {
            // Pop two operands and apply the operation
            op1 = pop();
            op2 = pop();
            ans = operate(op1, op2, postfix[i]);
            push(ans); // Push the result back to the stack

            // Print intermediate calculation steps
            printf("%f %c %f = %f\n", op2, postfix[i], op1, ans);
        }
        i++; // Move to the next character
    }

    // Final result is the remaining element in the stack
    printf("Result: %f\n", s.str[s.top]);
    return 0;
}

// Check if a character is an operand (digit in this case)
int isoperand(char x) {
    return (x >= '0' && x <= '9');
}

// Push a value onto the stack
void push(float x) {
    if(s.top < MAX - 1) {
        s.str[++s.top] = x; // Increment top and push the element
    }
    else {
        printf("Stack Overflow\n"); // Error message for overflow
    }
}

// Pop a value from the stack
float pop() {
    return (s.top != -1) ? s.str[s.top--] : -1; // Return -1 if stack is empty
}

// Perform the arithmetic operation
float operate(float op1, float op2, char a) {
    switch(a) {
        case '+': return op2 + op1;  // Addition
        case '-': return op2 - op1;  // Subtraction
        case '*': return op2 * op1;  // Multiplication
        case '/': return op2 / op1;  // Division
        case '^': return pow(op2, op1); // Exponentiation
        default: return 0; // Default case to avoid errors
    }
}
