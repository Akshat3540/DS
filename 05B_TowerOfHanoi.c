#include <stdio.h>
#include <math.h>

// Optimized Tower function using recursion
void tower(int n, char source, char temp, char destination)
{
    // Base case: No discs to move
    if (n == 0)
        return;

    // Move n-1 discs from source to temp using destination as auxiliary
    tower(n - 1, source, destination, temp);

    // Print the move for the current disc
    printf("\nMove disc %d from %c to %c", n, source, destination);

    // Move n-1 discs from temp to destination using source as auxiliary
    tower(n - 1, temp, source, destination);
}

int main()
{
    int n;
    // Input the number of discs
    printf("\nEnter the number of discs: \n");
    scanf("%d", &n);

    // Start the recursive function
    tower(n, 'A', 'B', 'C');

    // Calculate and print the total number of moves required
    printf("\n\nTotal Number of moves are: %d\n", (int)pow(2, n) - 1);

    return 0;
}
