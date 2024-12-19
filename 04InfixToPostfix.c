#include <stdio.h>
#include <ctype.h> // For checking if a character is alphanumeric (isalnum)
#define SIZE 50    // Maximum size for the stack and expressions

// Stack for storing operators
char s[SIZE];
// Stack top index
int top = -1;

// Function to push an element onto the stack
void push(char elem)
{
    // Increment top and push the element to the stack
    s[++top] = elem;
}

// Function to pop an element from the stack
char pop()
{
    // Return the element at the top of the stack and decrement top
    return s[top--];
}

// Function to get precedence of operators
int pr(char elem)
{
    // Return precedence value based on operator type
    switch (elem)
    {
    case '#':
        return 0; // Sentinel character has lowest precedence
    case '(':
        return 1; // Parenthesis has lowest precedence in stack
    case '+':
    case '-':
        return 2; // Addition and subtraction
    case '*':
    case '/':
    case '%':
        return 3; // Multiplication, division, modulus
    case '^':
        return 4; // Exponentiation has highest precedence
    default:
        return -1; // Return -1 for invalid operators (just in case)
    }
}

void main()
{
    char infx[50], pofx[50], ch, elem;
    int i = 0, k = 0;

    // Input the infix expression
    printf("Enter the Infix Expression: ");
    scanf("%s", infx);

    // Initialize the stack with the sentinel value '#'
    push('#');

    // Process each character in the infix expression
    while ((ch = infx[i++]) != '\0')
    {
        if (ch == '(')
        {
            // Push '(' to stack
            push(ch);
        }
        else if (isalnum(ch))
        {
            // If the character is an operand (either a number or a letter), add it to postfix
            pofx[k++] = ch;
        }
        else if (ch == ')')
        {
            // Pop from stack until '(' is found
            while (s[top] != '(')
            {
                pofx[k++] = pop();
            }
            pop(); // Pop the '(' from the stack (no need to store it)
        }
        else
        {
            // For operators, pop higher or equal precedence operators from the stack
            while (pr(s[top]) >= pr(ch))
            {
                pofx[k++] = pop();
            }
            // Push the current operator to the stack
            push(ch);
        }
    }

    // Pop all remaining operators from the stack
    while (s[top] != '#')
    {
        pofx[k++] = pop();
    }

    // Null-terminate the postfix expression string
    pofx[k] = '\0';

    // Print the original infix and the resultant postfix expression
    printf("Given Infix Expression: %s\nPostfix Expression: %s\n", infx, pofx);
}
