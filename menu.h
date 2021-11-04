// Header file for MENU functions

// Menu structure
struct Menu
{
    int index;
    char bev[25];
    float price;
    struct Menu *next;
};
struct Menu *menuHead = NULL;
struct Menu *menuTail = NULL;

// Display menu
void menuDisplay()
{
    // if menu is empty
    if (menuHead == NULL)
    {
        printf("Nothing in Menu!!\n");
        return;
    }

    struct Menu *temp = menuHead;

    while (temp != NULL)
    {
        printf("%2d   $%6.2f   %10s\n",temp->index, temp->price, temp->bev);
        temp = temp->next;
    }
}

// Insert an item in Menu
// Insertion is done at tail
void menuInsert(char NAME[], float PRICE)
{
    // creation of new node
    struct Menu *newNode = (struct Menu*)malloc(sizeof(struct Menu));
    int i = 0;
    // copy NAME[] to newNode->name[]
    while (NAME[i] != '\0')
    {
        newNode->bev[i] = NAME[i];
        i++;
    }
    NAME[i] = '\0';
    newNode->price = PRICE;
    newNode->next = NULL;

    // if menu is empty
    if (menuTail == NULL)
    {
        newNode->index = 1;
        menuHead = newNode;
        menuTail = newNode;
        return;
    }

    struct Menu *temp = menuTail;
    newNode->index = temp->index + 1;
    temp->next = newNode;
    menuTail = newNode;
}

// Remove an item from Menu
void menuRemove(int key)
{
    // if menu is empty
    if (menuHead == NULL)
    {
        printf("Nothing in Menu!!\n");
        printf("Removal Failed!!\n");
        return;
    }

    // if key > max index
    if (menuTail->index < key)
    {
        printf("Does not exist in Menu!!\n");
        printf("Removal Failed!!\n");
        return;
    }

    struct Menu *current = menuHead;

    // iterate to 1 less than the item to be removed
    for (int i = 1; i < key-1; i++)
    {
        current = current->next;
    }
    

    struct Menu *behind = current;
    if (key != 1)
    {
        current = current->next;
        behind->next = current->next;
    }
    else
    {
        menuHead = current->next;
    }

    // item to be removed is last
    if (menuTail->index == key)
    {
        if (key == 1) // only 1 element in menu
            menuTail = NULL;
    
        menuTail = behind;
    }

    behind = current->next;
    free(current);

    // decrease indices of the further items by 1
    while (behind != NULL)
    {
        behind->index -= 1;
        behind = behind->next;
    }
    
    printf("Removal Successful!!\n");
}

