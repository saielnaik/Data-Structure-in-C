
#include <stdio.h>
#include <stdlib.h>
 
struct node {
    int data;
    struct node *prev, *next;
};
struct node* head = NULL;
 
void display()
{
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }
    struct node* temp;
    temp = head;
    while (temp != NULL) {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
}
 
void insertAtFront()
{
    int data;
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    temp->data = data;
    temp->prev = NULL;
 
    temp->next = head;
    head = temp;
}
 
void insertAtEnd()
{
    int data;
    struct node *temp, *trav;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    temp->data = data;
    temp->next = NULL;
    trav = head;
 
    if (head == NULL) {
 
        head = temp;
    }
 
    else {
        while (trav->next != NULL)
            trav = trav->next;
        temp->prev = trav;
        trav->next = temp;
    }
}
 
void insertAtPosition()
{
    int data, pos, i = 1;
    struct node *temp, *newnode;
    newnode = malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->prev = NULL;
 
    printf("\nEnter position : ");
    scanf("%d", &pos);
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    newnode->data = data;
    temp = head;
 
    if (head == NULL) {
        head = newnode;
        newnode->prev = NULL;
        newnode->next = NULL;
    }
 
    else if (pos == 1) {
        newnode->next = head;
        newnode->next->prev = newnode;
        newnode->prev = NULL;
        head = newnode;
    }
 
    else {
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next = newnode;
        temp->next->prev = newnode;
    }
}
 
void deleteFirst()
{
    struct node* temp;
    if (head == NULL)
        printf("\nList is empty\n");
    else {
        temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
    }
}
 
void deleteEnd()
{
    struct node* temp;
    if (head == NULL)
        printf("\nList is empty\n");
    temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    if (head->next == NULL)
        head = NULL;
    else {
        temp->prev->next = NULL;
        free(temp);
    }
}
 
void deletePosition()
{
    int pos, i = 1;
    struct node *temp, *position;
    temp = head;
 
    if (head == NULL)
        printf("\nList is empty\n");
 
    else {
        printf("\nEnter position : ");
        scanf("%d", &pos);
 
        if (pos == 1) {
            position = head;
            head = head->next;
            if (head != NULL) {
                head->prev = NULL;
            }
            free(position);
            return;
        }
 
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        position = temp->next;
        if (position->next != NULL)
            position->next->prev = temp;
        temp->next = position->next;
 
        free(position);
    }
}
 
int main()
{
    int choice;
    while (1) {
 
        printf("\n\t1  Display list\n");
        printf("\t2  Insertion at"
               " heading\n");
        printf("\t3  Insertion at"
               " end\n");
        printf("\t4  Insertion at "
               "any position\n");
        printf("\t5  Deletion of "
               "first element\n");
        printf("\t6  Deletion of "
               "last element\n");
        printf("\t7  Deletion of "
               "element at any position\n");
        printf("\t8 exit\n");
        printf("\nEnter Choice :\n");
        scanf("%d", &choice);
 
        switch (choice) {
        case 1:
            display();
            break;
        case 2:
            insertAtFront();
            break;
        case 3:
            insertAtEnd();
            break;
        case 4:
            insertAtPosition();
            break;
        case 5:
            deleteFirst();
            break;
        case 6:
            deleteEnd();
            break;
        case 7:
            deletePosition();
            break;
 
        case 8:
            exit(1);
            break;
        default:
            printf("Incorrect Choice. Try Again \n");
            continue;
        }
    }
    return 0;
}