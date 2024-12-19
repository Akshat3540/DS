#include <stdio.h>
#include <string.h>

void main()
{
    char STR[100], PAT[100], REP[100], ans[100]; // Strings for main, pattern, replacement, and result
    int i = 0, j = 0, c = 0, m = 0, flag = 0;    // Index variables and flag for pattern match

    // Input strings
    printf("Enter the MAIN string: ");
    fgets(STR, sizeof(STR), stdin);
    STR[strcspn(STR, "\n")] = '\0'; // Remove trailing newline

    printf("Enter a PATTERN string: ");
    fgets(PAT, sizeof(PAT), stdin);
    PAT[strcspn(PAT, "\n")] = '\0'; // Remove trailing newline

    printf("Enter a REPLACE string: ");
    fgets(REP, sizeof(REP), stdin);
    REP[strcspn(REP, "\n")] = '\0'; // Remove trailing newline

    // Main logic: Traverse the input string
    while (STR[c] != '\0')
    {
        // Check if the pattern matches
        if (STR[m] == PAT[i])
        {
            i++;
            m++; // Increment both pattern and main string indices
            if (PAT[i] == '\0')
            { // Pattern fully matched
                // Copy replacement string into result
                for (int k = 0; REP[k] != '\0'; k++, j++)
                    ans[j] = REP[k];
                c = m;    // Move to next part of main string
                i = 0;    // Reset pattern index
                flag = 1; // Indicate pattern was found
            }
        }
        else
        {
            // No match, copy current character and move forward
            ans[j++] = STR[c++];
            m = c; // Reset match starting point
            i = 0; // Reset pattern index
        }
    }

    // Finalize the result
    ans[j] = '\0';

    // Output the result
    if (!flag)
        printf("Pattern doesn't exist!!!\n");
    else
        printf("The RESULTANT string is: %s\n", ans);
}
