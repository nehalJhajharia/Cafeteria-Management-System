// Header file for ORDER functions

// Order structure
struct Order
{
    char name[10];
    int order[10];
    float total;
    struct Order *next;
};
struct Order *orderHead = NULL;
struct Order *orderTail = NULL;

// Add an order to the queue
// Enqueue will be done at Tail
void orderEnqueue(char NAME[], int orders[])
{
    struct Order *newNode = (struct Order*)malloc(sizeof(struct Order));
    struct Menu *temp = menuHead;

    // Filling values to newNode structure
    newNode->total = 0;
    int i = 0;
    while (NAME[i] != '\0' && i < 9)
    {
        newNode->name[i] = NAME[i];
        i++;
    }
    newNode->name[9] = '\0';

    // calculate total price
    i = 0;
    while (orders[i] > 0)
    {
        newNode->order[i] = orders[i];
        while (temp->index != newNode->order[i])
        {
            temp = temp->next;
        }
        newNode->total += temp->price;
        i++;
        temp = menuHead;
    }

    // if queue is empty
    if (orderTail == NULL)
    {
        orderTail = newNode;
        orderHead = newNode;
        return;
    }

    struct Order *temp2 = orderTail;
    temp2->next = newNode;
    orderTail = newNode;
}

// Remove an order from the queue
// Dequeue will be done at Head
void orderDequeue()
{
    // if queue is empty
    if (orderHead == NULL)
    {
        printf("Dequeue Failed!!\n");
        printf("No more orders for now!!\n");
        return;
    }

    struct Order *temp = orderHead;
    // if only 1 order is there
    // orderHead and orderTail point at same node
    if (orderHead == orderTail)
    {
        orderHead = NULL;
        orderTail = NULL;
        free(temp);
        printf("Dequeue Successfull!!\n");
        return;
    }

    orderHead = temp->next;
    free(temp);
    printf("Dequeue Successfull!!\n");
}

// Generate BILL for front order
void orderBill()
{
    // if queue is empty
    if (orderHead == NULL)
    {
        printf("No more orders for now!!\n");
        return;
    }

    struct Order *orderTemp = orderHead;
    struct Menu *menuTemp = menuHead;
    printf("\n\t%s\n", orderTemp->name);
    int i = 0;
    while (orderTemp->order[i] > 0)
    {
        while (menuTemp->index != orderTemp->order[i])
        {
            menuTemp = menuTemp->next;
        }
        printf("%10s      %6.2f\n", menuTemp->bev, menuTemp->price);
        i++;
        menuTemp = menuHead;
    }
    printf("--------------------------------\n");
    char string[10] = "Total";
    printf("%10s      %6.2f\n", string, orderTemp->total);
    printf("--------------------------------\n");
}
