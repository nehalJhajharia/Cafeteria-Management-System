#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "order.h"

#define ESC 27

// Prototype functions
void separate(char type);
void defaultMenu(char string[]);

// MAIN
int main()
{
    char key = '0';
    char key2 = '0';
    char string[25] = "\0";
    int array[10] = {0};
    float price = 0;
    int temp = 0;

    // generate a default menu
    defaultMenu(string);

    separate('#');
    printf("o      -    Order creation\n"
           "m      -    Menu display\n"
           "i      -    Insert in menu\n"
           "r      -    Remove from menu\n"
           "Esc    -    EXIT\n");
    separate('*');

    while (key != ESC)
    {
        printf("Press a key : ");
        scanf(" %c", &key);

        switch (key)
        {
        case 'o': // Create Order
            separate('*');
            printf("e     -    Enqueue order\n"
                   "d     -    Dequeue order\n"
                   "b     -    Generate Bill\n"
                   "Esc   -    Exit\n\n");

            while (key2 != ESC)
            {
                printf("Press a key for order actions : ");
                scanf(" %c", &key2);

                switch (key2)
                {
                case 'e': // Enqueue order
                    printf("\nName : ");
                    scanf(" %s", string);
                    printf("Orders : ");
                    int i = 0;
                    do
                    {
                        scanf("%d", &array[i]);
                        i++;
                    }while(array[i-1] > 0);
                    orderEnqueue(string, array);
                    printf("Enqueue Successfull!!\n");
                    separate('*');
                    break;

                case 'd': // Dequeue order
                    orderDequeue();
                    separate('*');
                    break;

                case 'b': // Generate Bill
                    orderBill();
                    separate('*');
                    break;

                case ESC: // Exit Order loop
                    key2 = ESC;
                    break;

                default:
                    printf("Oops! No choice available to that key!!\n");
                    break;
                }
            }
            separate('*');
            break;

        case 'm': // Show Menu
            separate('*');
            menuDisplay();
            separate('*');
            break;

        case 'i': // Insert in Menu
            printf("\nEnter name of the beverage : ");
            scanf(" %[^\n]s", string);
            printf("Price of '%s' : ", string);
            scanf(" %f", &price);
            menuInsert(string, price);
            printf("Insertion Successfull!!\n");
            separate('*');
            break;

        case 'r': // Remove from Menu
            separate('*');
            printf("Enter number of the beverage to be removed : ");
            scanf(" %d", &temp);
            menuRemove(temp);
            separate('*');
            break;

        case ESC: // EXIT
            key = ESC;
            separate('*');
            printf("Thank you :) \n");
            separate('#');
            break;

        default:
            printf("Oops! No choice available to that key!!\n");
            break;
        }
    }

    return 0;
}

// Create a ' ' line to separate sections
void separate(char type)
{
    printf("\n");
    for (int i = 0; i < 50; i++)
    {
        printf("%c", type);
    }
    printf("\n\n");
}

// Generate a default menu
void defaultMenu(char string[])
{
    /********** --- TEA --- **********/
    // A
    string[0] = 'T';
    string[1] = 'e';
    string[2] = 'a';
    string[3] = ' ';
    string[4] = 'A';
    string[5] = '\0';
    menuInsert(string, 5);

    // B
    string[4] = 'B';
    menuInsert(string, 6.99);

    // C
    string[4] = 'C';
    menuInsert(string, 9.99);

    /********** --- COFFEE --- **********/
    // A
    string[0] = 'C';
    string[1] = 'o';
    string[2] = 'f';
    string[3] = 'f';
    string[4] = 'e';
    string[5] = 'e';
    string[6] = ' ';
    string[7] = 'A';
    string[8] = '\0';
    menuInsert(string, 5);

    // B
    string[7] = 'B';
    menuInsert(string, 9.99);

    // C
    string[7] = 'C';
    menuInsert(string, 12.50);

    // D
    string[7] = 'D';
    menuInsert(string, 15);

    // E
    string[7] = 'E';
    menuInsert(string, 19.99);

    /********** --- COOKIE --- **********/
    // A
    string[0] = 'C';
    string[1] = 'o';
    string[2] = 'o';
    string[3] = 'k';
    string[4] = 'i';
    string[5] = 'e';
    string[6] = ' ';
    string[7] = 'A';
    string[8] = '\0';
    menuInsert(string, 0.99);

    // B
    string[7] = 'B';
    menuInsert(string, 2.50);

    // C
    string[7] = 'C';
    menuInsert(string, 4.99);

    // D
    string[7] = 'D';
    menuInsert(string, 10);
}
