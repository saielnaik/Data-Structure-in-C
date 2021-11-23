#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *root;

void beginsert(){
    struct node * temp;
    temp = (struct node*) malloc(sizeof(struct node));
    printf("Enter the Value");
    scanf("%d", &temp->data);
    temp->link=NULL;
    if(root==NULL){
        root=temp;
    }else{
        temp->link=root;
        root=temp;
    }

}

void lastinsert(){
        struct node * temp;
        temp = (struct node *) malloc(sizeof(struct node));
        printf("Enter Value");
        scanf("%d", &temp->data);
        temp->link=NULL;
        if(root==NULL){
            root=temp; 
        }else{
            struct node *p;
            p=root;
            while(p->link!=NULL){
                p= p->link;
            }
            p->link = temp;
        }
}

void locinsert(){
    struct node* temp, *ptr;
    temp = (struct node*) malloc(sizeof(struct node));
    int  i, pos;
    printf("Enter position");
    scanf("%d", &pos);
    printf("Enter Value");
    scanf("%d", &temp->data);
    temp->link=NULL;
    if(pos==0){
        temp->link=root;
        root=temp;
    }else{
        ptr=root;
        for(i=0; i<pos; i++){
            ptr=ptr->link;
            if(ptr==NULL){
                printf("Invalid Position");
                return;
            }

        }
        temp->link=ptr->link;
        ptr->link=temp;
    }
}

void begindelete(){
    struct node * temp;
    if(root==NULL){
        printf("List is Empty");
        return;
    }else{
        temp = root;
        root = temp->link;
        printf("%d has been deleted", temp->data);
        free(temp);
    }

}

void lastdelete(){
    struct node * temp, *ptr;
    if(root==NULL){
        printf("List is empty");
    } else if (root->link == NULL){
        temp = root;
        root = NULL;
        printf("%d has been deleted", temp->data);
        free(temp);
    }else{
        temp=root;
        while(temp->link!=NULL){
            ptr=temp;
            temp=temp->link;
        }
            ptr->link=NULL;
            printf("%d has been deleted", temp->data);
            free(temp);
    }
}

void locdelete(){
    int i, pos;
    struct node *temp, *ptr;

    if(root==NULL){
        printf("List is empty");
    }else{
        printf("Enter the position");
        scanf("%d", &pos);

        temp=root;
        for(i=0; i<pos; i++){
                ptr=temp;
                temp=temp->link;
            if(temp==NULL){
                printf("Invalid position");
            }
            ptr->link=temp->link;
            printf("%d has been deleted", temp->data);
            free(temp);
        }
    }
}

void display(){
    struct node *temp;
    if(root==NULL){
        printf("List is empty");
    }else{
        temp=root;
        while(temp!=NULL){
            printf("%d ->", temp->data);
            temp=temp->link;
        }
    }
}


int main(){

    int choice;
    while(choice!=8){
        printf("Choose one option \n");
        printf("\n 1.Insert in begining \n 2. Insert at end \n 3. Insert at location \n 4. Delete from Beginning \n 5. Delete from last \n 6. Delete node after specified location \n 7. Display \n 8. Exit");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: 
            beginsert();
            break;

        case 2: 
            lastinsert();
            break;

        case 3:
            locinsert();
            break;

        case 4:
            begindelete();
            break;

        case 5:
            lastdelete();
            break;

        case 6: 
            locdelete();
            break;

        case 7:
            display();
            break;

        case 8:
            exit(0);
            break;

        default:

            printf("Please enter valid choice");
            break;
        }
    }
    return 0;

}