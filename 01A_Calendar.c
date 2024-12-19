#include <stdio.h>
#include <string.h>

struct Day
{
    char name[20];
    int date;
    char activity[100];
};

int main()
{
    struct Day calendar[7] = {
        {"Monday", 1, "Work from 9 AM to 5 PM"},
        {"Tuesday", 2, "Meeting at 10 AM"},
        {"Wednesday", 3, "Gym at 6 PM"},
        {"Thursday", 4, "Dinner with friends at 7 PM"},
        {"Friday", 5, "Movie night at 8 PM"},
        {"Saturday", 6, "Weekend getaway"},
        {"Sunday", 7, "Relax and recharge"}};
    for (int i = 0; i < 7; i++)
        printf("%s (Date: %d):\t%s\n", calendar[i].name, calendar[i].date, calendar[i].activity);
    return 0;
}