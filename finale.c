#include <stdio.h>
#include <string.h>

int main()
{

    int i = 0, j = 0, x, size_c, choice, currentU, swapped, search;
    char login[10];
    char fNames[50][25], fNames_c[50][25];
    char lNames[50][25], lNames_c[50][25];
    char ID[20][10], ID_c[20][10], currentU_ID[10][10];
    float amount[50], stack;

    printf("\n\t\t[1]- A single User:\n\t\t[2]- Multiple Users:\n\t\t[Others]- Exit\n");
    printf("Input: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        size_c = 1;
        printf("User number %d -- Enter your first or last name: \n", i + 1);
        scanf("%s", &fNames[i]);
        printf("User number %d -- Enter your first or last name: \n", i + 1);
        scanf("%s", &lNames[i]);
        printf("User number %d -- Enter your ID: \n", i + 1);
        scanf("%s", &ID[i]);
        printf("User number %d -- Enter the amount of money you wish to deposit: \n", i + 1);
        scanf("%f", &amount[i]);
        break;
    case 2:
        printf("Enter the number of users: ");
        scanf("%d", &size_c);
        for (i = 0; i < size_c; i++)
        {
            printf("User number %d -- Enter your first or last name: \n", i + 1);
            scanf("%s", &fNames[i]);
            printf("User number %d -- Enter your first or last name: \n", i + 1);
            scanf("%s", &lNames[i]);
            printf("User number %d -- Enter your ID: \n", i + 1);
            scanf("%s", &ID[i]);
            printf("User number %d -- Enter the amount of money you wish to deposit: \n", i + 1);
            scanf("%f", &amount[i]);
        }
        break;
    default:
        break;
    }

login:

    for (i = 0; i < size_c; i++)
    { //printing all users to choose which one to log in as
        printf("\t[First Name] -- %s", fNames[i]);
        printf("\t[Last Name] -- %s", lNames[i]);
        printf("\t[ID/CIN] -- %s", ID[i]);
        printf("\t[Balance] -- %f\n", amount[i]);
    }
    do
    {
        printf("\t\tChoose the ID of whichever user you want to login as:\n");
        scanf("%s", &login);

        for (i = 0; i < size_c; i++)
        {
            if (strcmp(login, ID[i]) == 0)
            {
                j++;
                break;
            }
        }
        if (j == 1)
        {
            printf("\n\tFound! at the position %d\n", i + 1);
            break;
        }
        else
        {
            printf("\n\tSorry, couldn't find the user you were looking for.\n");
        }

    } while (strcmp(login, ID[i]) != 0);

    currentU = i;

    strcpy(currentU_ID, ID[i]);

    do
    {
        for (i = 0; i < size_c; i++)
        {
            if (strcmp(currentU_ID, ID[i]) == 0)
            {
                j++;
                break;
            }
        }
        if (j == 1)
        {
            currentU = i;
            break;
        }

    } while (strcmp(login, ID[i]) != 0);

menu:

    printf("\n%d\n", i);

    printf("\t\tWelcome Mr./Mrs./Ms %s %s\n", fNames[currentU], lNames[currentU]);
    printf("\t\tYour balance is %f.\n", amount[currentU]);

    printf("\t\tSelect one of the operations below:\n");
    printf("\n\n\t\t[1]- Deposit\n\t\t[2]- Withdraw\n\t\t[3]- Sort\n\t\t[4]- Loyalty\n\t\t[5]- Show all Users\n\t\t[6]- Search by CIN\n\t\t[7]- Change User\n\t\t[Others]- Exit\n");
    printf("\n\n\t\tInput: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("\n\t\tEnter the amount of money you wish to deposit: ");
        scanf("%f", &stack);
        amount[i] += stack;
        printf("\n\t\tYou deposited %f dollars\n", stack);
        stack = 0;
        choice = 0;
        printf("\nReturn to the main menu? \t[1]- Yes \t[2]- Exit program");
        scanf("%d", &choice);

        if (choice == 1)
        {
            goto menu;
        }
        else
        {
            return 0;
        }
    case 2:
        printf("\n\t\tEnter the amount of money you wish to withdraw: ");
        scanf("%f", &stack);
        amount[i] -= stack;
        printf("\n\t\tYou withdrew %f dollars\n", stack);
        stack = 0;
        choice = 0;
        printf("\nReturn to the main menu? \t[1]- Yes \t[2]- Exit program");
        scanf("%d", &choice);

        if (choice == 1)
        {
            goto menu;
        }
        else
        {
            return 0;
        }
    case 3:
        printf("\n\n\t\t[1]- Ascending sort\n\t\t[2]- Descending sort\n\t\t[3]- Ascending sort(User dependant)\n\t\t[4]- Descending sort(User dependant)\n\t\t[Others]- Exit\n");
        printf("\n\t\tInput: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            while (1)
            {
                swapped = 0;
                for (i = 0; i < size_c - 1; i++)
                {
                    if (amount[i] > amount[i + 1])
                    {
                        stack = amount[i];
                        amount[i] = amount[i + 1];
                        amount[i + 1] = stack;

                        strcpy(fNames_c, fNames[i]);
                        strcpy(fNames[i], fNames[i + 1]);
                        strcpy(fNames[i + 1], fNames_c);

                        strcpy(lNames_c, lNames[i]);
                        strcpy(lNames[i], lNames[i + 1]);
                        strcpy(lNames[i + 1], lNames_c);

                        strcpy(ID_c, ID[i]);
                        strcpy(ID[i], ID[i + 1]);
                        strcpy(ID[i + 1], ID_c);

                        swapped = 1;
                    }
                }
                if (swapped == 0)
                {
                    break;
                }
            }
            choice = 0;
            printf("\n\t\tThe list of users is now sorted in ascending order.\n");
            for (i = 0; i < size_c; i++)
            {
                printf("\tFirst Name -- %s", fNames[i]);
                printf("\tLast Name -- %s", lNames[i]);
                printf("\tID/CIN -- %s", ID[i]);
                printf("\tBalance -- %f\n", amount[i]);
            }
            printf("\nReturn to the main menu? \t[1]- Yes \t[2]- Exit program");
            scanf("%d", &choice);

            if (choice == 1)
            {
                goto menu;
            }
            else
            {
                return 0;
            }

        case 2:
            while (1)
            {
                swapped = 0;
                for (i = 0; i < size_c - 1; i++)
                {
                    if (amount[i] < amount[i + 1])
                    {
                        stack = amount[i];
                        amount[i] = amount[i + 1];
                        amount[i + 1] = stack;

                        strcpy(fNames_c, fNames[i]);
                        strcpy(fNames[i], fNames[i + 1]);
                        strcpy(fNames[i + 1], fNames_c);

                        strcpy(lNames_c, lNames[i]);
                        strcpy(lNames[i], lNames[i + 1]);
                        strcpy(lNames[i + 1], lNames_c);

                        strcpy(ID_c, ID[i]);
                        strcpy(ID[i], ID[i + 1]);
                        strcpy(ID[i + 1], ID_c);

                        swapped = 1;
                    }
                }
                if (swapped == 0)
                {
                    break;
                }
            }
            printf("\n\t\tThe list of users is now sorted in descending order.\n");
            for (i = 0; i < size_c; i++)
            {
                printf("\tFirst Name -- %s", fNames[i]);
                printf("\tLast Name -- %s", lNames[i]);
                printf("\tID/CIN -- %s", ID[i]);
                printf("\tBalance -- %f\n", amount[i]);
            }
            choice = 0;

            printf("\nReturn to the main menu? \t[1]- Yes \t[2]- Exit program");
            scanf("%d", &choice);

            if (choice == 1)
            {
                goto menu;
            }
            else
            {
                return 0;
            }
        case 3:

            printf("Please enter an amount:\n");
            scanf("%d", &x);

            while (1)
            {
                swapped = 0;
                for (i = 0; i < size_c - 1; i++)
                {
                    if (amount[i] > amount[i + 1])
                    {
                        stack = amount[i];
                        amount[i] = amount[i + 1];
                        amount[i + 1] = stack;

                        strcpy(fNames_c, fNames[i]);
                        strcpy(fNames[i], fNames[i + 1]);
                        strcpy(fNames[i + 1], fNames_c);

                        strcpy(lNames_c, lNames[i]);
                        strcpy(lNames[i], lNames[i + 1]);
                        strcpy(lNames[i + 1], lNames_c);

                        strcpy(ID_c, ID[i]);
                        strcpy(ID[i], ID[i + 1]);
                        strcpy(ID[i + 1], ID_c);

                        swapped = 1;
                    }
                }
                if (swapped == 0)
                {
                    break;
                }
            }

            for (i = 0; i < size_c; i++)
            {
                if (amount[i] > x)
                {
                    printf("\tFirst Name -- %s", fNames[i]);
                    printf("\tLast Name -- %s", lNames[i]);
                    printf("\tID/CIN -- %s", ID[i]);
                    printf("\tBalance -- %f\n", amount[i]);
                }
            }
            printf("\nReturn to the main menu? \t[1]- Yes \t[2]- Exit program");
            scanf("%d", &choice);

            if (choice == 1)
            {
                goto menu;
            }
            else
            {
                return 0;
            }

        case 4:

            printf("Please enter an amount:\n");
            scanf("%d", &x);

            while (1)
            {
                swapped = 0;
                for (i = 0; i < size_c - 1; i++)
                {
                    if (amount[i] > amount[i + 1])
                    {
                        stack = amount[i];
                        amount[i] = amount[i + 1];
                        amount[i + 1] = stack;

                        strcpy(fNames_c, fNames[i]);
                        strcpy(fNames[i], fNames[i + 1]);
                        strcpy(fNames[i + 1], fNames_c);

                        strcpy(lNames_c, lNames[i]);
                        strcpy(lNames[i], lNames[i + 1]);
                        strcpy(lNames[i + 1], lNames_c);

                        strcpy(ID_c, ID[i]);
                        strcpy(ID[i], ID[i + 1]);
                        strcpy(ID[i + 1], ID_c);

                        swapped = 1;
                    }
                }
                if (swapped == 0)
                {
                    break;
                }
            }

            for (i = 0; i < size_c; i++)
            {
                if (amount[i] > x)
                {
                    printf("\tFirst Name -- %s", fNames[i]);
                    printf("\tLast Name -- %s", lNames[i]);
                    printf("\tID/CIN -- %s", ID[i]);
                    printf("\tBalance -- %f\n", amount[i]);
                }
            }
            printf("\nReturn to the main menu? \t[1]- Yes \t[2]- Exit program");
            scanf("%d", &choice);

            if (choice == 1)
            {
                goto menu;
            }
            else
            {
                return 0;
            }

        default:
            break;
        }

    case 4:

        int count = 0, amountChange = 0, i = 0;

        while (1)
        {
            swapped = 0;
            for (i = 0; i < size_c - 1; i++)
            {
                if (amount[i] < amount[i + 1])
                {
                    stack = amount[i];
                    amount[i] = amount[i + 1];
                    amount[i + 1] = stack;

                    strcpy(fNames_c, fNames[i]);
                    strcpy(fNames[i], fNames[i + 1]);
                    strcpy(fNames[i + 1], fNames_c);

                    strcpy(lNames_c, lNames[i]);
                    strcpy(lNames[i], lNames[i + 1]);
                    strcpy(lNames[i + 1], lNames_c);

                    strcpy(ID_c, ID[i]);
                    strcpy(ID[i], ID[i + 1]);
                    strcpy(ID[i + 1], ID_c);

                    swapped = 1;
                }
            }
            if (swapped == 0)
            {
                break;
            }
        }

        while (count < 3)
        {
            if (amount[i] != amount[i + 1])
            {
                count++;
            }
            amountChange++;
            i++;
        }

        for (i = 0; i < amountChange; i++)
        {
            amount[i] = amount[i] + (amount[i] * 0.013);
        }

        for (i = 0; i < size_c; i++)
        {
            if (amount[i] > x)
            {
                printf("\tFirst Name -- %s", fNames[i]);
                printf("\tLast Name -- %s", lNames[i]);
                printf("\tID/CIN -- %s", ID[i]);
                printf("\tBalance -- %f\n", amount[i]);
            }
        }

        printf("\nReturn to the main menu? \t[1]- Yes \t[2]- Exit program");
        scanf("%d", &choice);

        if (choice == 1)
        {
            goto menu;
        }
        else
        {
            return 0;
        }

    case 5:

        printf("\t\tChoose the ID of whichever user you want to search for:\n");
        scanf("%s", &search);

        for (i = 0; i < size_c; i++)
        {
            if (strcmp(search, ID[i]) == 0)
            {
                j++;
                break;
            }
        }
        if (j == 1)
        {
            printf("\n\tFound! at the position %d\n", i + 1);
            printf("\n\tFirst Name -- %s", fNames[i]);
            printf("\n\tLast Name -- %s", lNames[i]);
            printf("\n\tID/CIN -- %s", ID[i]);
            printf("\n\tBalance -- %f\n", amount[i]);
            break;
        }
        else
        {
            printf("\n\tSorry, couldn't find the user you were looking for.\n");
        }

        printf("Return to the main menu? \t[1]- Yes \t[2]- Exit program");
        scanf("%d", &choice);

        if (choice == 1)
        {
            goto menu;
        }
        else
        {
            return 0;
        }

    case 6:
        goto login;
    case 7:
        goto login;

    default:
        break;
    }

    return 0;
}
