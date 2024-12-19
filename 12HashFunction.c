#include <stdio.h>
#include <stdlib.h>

int *ht, key[20], n, m, h_index, count = 0;

// Function to insert a key into the hash table
void insert(int key)
{
    h_index = key % m; // Compute the index using the hash function
    // Linear probing to resolve collisions
    while (ht[h_index] != -1)
    {
        h_index = (h_index + 1) % m; // Move to the next index
    }
    ht[h_index] = key; // Insert the key into the hash table
    count++;         // Increment the count of inserted records
}

// Function to display the contents of the hash table
void display()
{
    if (count == 0)
    {
        printf("\nHash Table is empty\n");
        return;
    }
    printf("\nHash Table contents:\n");
    for (int i = 0; i < m; i++)
    {
        if (ht[i] != -1)
            printf("T[%d] --> %d\n", i, ht[i]);
        else
            printf("T[%d] --> Empty\n", i);
    }
}

int main()
{
    printf("\nEnter the number of employee records (N): ");
    scanf("%d", &n);

    // Check if the number of records is within the size of hash table
    if (n > 20)
    {
        printf("Maximum allowed records is 20. Please enter a valid number.\n");
        return 0;
    }

    printf("\nEnter the size of hash table (m, 2-digit): ");
    scanf("%d", &m);

    // Dynamically allocate memory for the hash table
    ht = (int *)malloc(m * sizeof(int));
    // Initialize all memory locations in the hash table to -1 (empty)
    for (int i = 0; i < m; i++)
    {
        ht[i] = -1;
    }

    printf("\nEnter the four-digit key values (K) for N Employee Records:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &key[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (count == m)
        {
            printf("\n~~~Hash table is full. Cannot insert the record with key %d~~~\n", key[i]);
            break;
        }
        insert(key[i]); // Insert each key into the hash table
    }

    // Displaying the contents of the hash table
    display();

    // Free dynamically allocated memory
    free(ht);

    return 0;
}
