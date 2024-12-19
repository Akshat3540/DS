#include <stdio.h>
#include <string.h>

// Define a structure to represent a day
struct Day
{
    char name[20];
    int date;
    char activity[100];
};

// Function to create the calendar
void create(struct Day cal[7])
{
    FILE *f = fopen("calendar.txt", "w");
    if (!f)
    {
        printf("Error opening the file for writing.\n");
        return;
    }

    for (int i = 0; i < 7; i++)
    {
        printf("\nEnter details for %s:\n", cal[i].name);
        printf("Date:\t\t");
        scanf("%d", &cal[i].date);
        printf("Activity:\t");
        scanf(" %[^\n]", cal[i].activity);

        // Write the details to the file
        fprintf(f, "%d %s\n", cal[i].date, cal[i].activity);
    }

    fclose(f);
}

// Function to read data from a file
void read(struct Day cal[7])
{
    FILE *f = fopen("calendar.txt", "r");
    if (!f)
    {
        printf("Error opening the file.\n");
        return;
    }
    for (int i = 0; i < 7; i++)
    {
        fscanf(f, "%d", &cal[i].date);
        fscanf(f, "%[^\n]", cal[i].activity);
    }
    fclose(f);
}

// Function to display the calendar
void display(struct Day cal[7])
{
    printf("\nCalendar for the week:\n\n");
    for (int i = 0; i < 7; i++)
        printf("%s (Date: %d):\t%s\n", cal[i].name, cal[i].date, cal[i].activity);
}

int main()
{
    struct Day cal[7] = {
        {"Monday"}, {"Tuesday"}, {"Wednesday"}, {"Thursday"}, {"Friday"}, {"Saturday"}, {"Sunday"}};
    int ch;

    printf("1. Create Calendar\n2. Read Calendar from File\n0. Exit\n");

    while (ch != 0)
    {
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            create(cal);
            break;
        case 2:
            read(cal);
            display(cal);
            break;
        case 0:
            break;
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}
