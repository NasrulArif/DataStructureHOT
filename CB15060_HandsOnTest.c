/*
    NAME: NASRUL ARIF BIN ZAKRIA
    MATRIC ID: CB15060
    SECTION: 05B
    LECTURER's NAME: DR MD SAIFUL AZAD
*/

#include<stdio.h>
#include<stdlib.h>

void push1 (char);
void pop1 ();
void push2 (char);
void pop2 ();
void display ();
void operate ();

//Declaration of function

struct Node
{
    char data;
    struct Node *nextPtr;
};

struct Node *head1, *newNode1, *currNode1; //Linked List #1
struct Node *head2, *newNode2, *currNode2; //Linked List #2
int sizeList1 = 0, sizeList2 = 0; //Size of Linked Lists


void push1 (char redoItem)
{
    char item;
    newNode1 = (struct Node*)malloc(sizeof(struct Node));

    if(head1 == NULL)
    {
        head1 = newNode1;
        newNode1->nextPtr = NULL;
    }
    else
    {
        newNode1->nextPtr = head1;
        head1 = newNode1;
    }

    if(redoItem == '\0') //If 'nothing' was sent
    {
        printf("Character: ");
        scanf(" %c",&item);
        newNode1->data = item;
        printf("\nAfter added: \n");
        display();
    }
    else
        newNode1->data = redoItem; //Else top node of list #1 will be the last redoed node


    sizeList1++;
}

void pop1 ()
{
    if (head1 == NULL)
        printf("\nThere is nothing to be Undo from the 1st list\n");
    else
    {
        currNode1 = head1;
        head1 = currNode1->nextPtr; //Top node from list #1 is physically deleted
        push2(currNode1->data); //Calling push2 function and passing the last deleted node from list #1
        sizeList1--;

        printf("\nAfter undoed: \n");
        display();
    }
}

void push2 (char undoItem)
{
    newNode2 = (struct Node*)malloc(sizeof(struct Node));
    newNode2->data = undoItem;

    if(head2 == NULL)
    {
        head2 = newNode2;
        newNode2->nextPtr = NULL;
    }
    else
    {
        newNode2->nextPtr = head2;
        head2 = newNode2;
    }

    sizeList2++;
}

void pop2 ()
{
    if (head2 == NULL)
        printf("\nThere is nothing to be Redo from the 2nd list\n");
    else
    {
        currNode2 = head2;
        head2 = currNode2->nextPtr; //Top node from list #2 is physically deleted
        push1(currNode2->data); //Calling push1 function and passing the last deleted node from list #2
        printf("\nAfter redoed: \n");
        display();
        sizeList2--;
    }
}

void display()
{
    currNode1 = head1;

    printf("\n\n");

    while(currNode1 != NULL)
    {
        printf("%c\n",currNode1->data);
        currNode1 = currNode1->nextPtr;
    }
}

void operate()
{
    char choice;

    printf(">> MENU <<\n");
    printf("\n\nI - Insert character\nU - Undo Operation\nR - Redo Operation\nX - Exit\n\nSELECT OPTION: ");
    scanf(" %c",&choice);

    switch(choice)
    {
        case 'I':   push1('\0'); //Sending 'nothing' so it will trigger user input instead
                    break;

        case 'U':   pop1();
                    break;

        case 'R':   pop2();
                    break;

        case 'X':   return;

        default:    printf("\n\n\n=======INVALID INPUT=======\n\n\n");
    }

    printf("\n\n");
    operate();
}

int main()
{
    operate();
}










