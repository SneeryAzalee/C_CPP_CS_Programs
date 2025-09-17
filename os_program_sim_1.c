#include <stdio.h> 
#include <stdlib.h>

int main()
{
    printf("\n==========================");
    printf("\nDINING PHILOSOPHER PROBLEM");
    printf("\n==========================");
    printf("\n\n");

    int total_philosophers = 0;
    printf("\nEnter the total no. of philosophers: ");
    scanf("%d", &total_philosophers);

    int hungry_count = 0;
    printf("\nHow many are hungry: ");
    scanf("%d", &hungry_count);

    int hungry[hungry_count];
    printf("\n");
    for (int i = 0; i < hungry_count; i++)
    {
        printf("\nEnter philosopher %d position: ", i + 1);
        scanf("%d", &hungry[i]);
    }
    printf("\n");

    int choice;
    do
    {
		printf("\n");
        printf("\n=======");
        printf("\nOPTIONS");
        printf("\n=======");
        printf("\n");
        printf("\n1.One can eat at a time");
        printf("\n2.Two can eat at a time");
        printf("\n3.Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                printf("\n\n");
                printf("\n=========================================");
                printf("\nALLOWING 1 PHILOSOPHER TO EAT AT ANY TIME");
                printf("\n=========================================");
                printf("\n\n");
                for (int i = 0; i < hungry_count; i++)
                {
                    printf("\n==========================\n");
                    printf("P%d is granted to eat\n", hungry[i]);
                    for (int j = 0; j < hungry_count; j++)
                    {
                        if (j != i)
                        {
                            printf("P%d is waiting\n", hungry[j]);
                        }
                    }
                    printf("==========================\n\n");
                }
                break;
            }

            case 2:
            {
                printf("\n\n");
                printf("\n==========================================");
                printf("\nALLOWING 2 PHILOSOPHERS TO EAT AT ANY TIME");
                printf("\n==========================================");
                printf("\n\n");
                int combo = 1;
                for (int i = 0; i < hungry_count; i++)
                {
                    for (int j = i + 1; j < hungry_count; j++)
                    {
                        printf("\n>> Combination %d <<", combo++);
                        printf("\n=================================\n");
                        printf("P%d and P%d are granted to eat\n", hungry[i], hungry[j]);
                        for (int k = 0; k < hungry_count; k++)
                        {
                            if (k != i && k != j)
                            {
                                printf("P%d is waiting\n", hungry[k]);
                            }
                        }
                        printf("=================================\n\n");
                    }
                }
                break;
            }

            case 3:
            {
				printf("\n");
				printf("\n=======");
                printf("\nEXITING");
                printf("\n=======");
                printf("\n\n\n");
                break;
            }

            default:
            {
                printf("\n");
                printf("\n==============");
                printf("\nINVALID CHOICE");
                printf("\n==============");
                printf("\n");
            }
        }

    } while (choice != 3);

    return 0;
}
