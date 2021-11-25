
# Doubly linked list

Doubly linked list is a complex type of linked list in which a node contains a pointer to the previous as well as the next node in the sequence. Therefore, in a doubly linked list, a node consists of three parts: node data, pointer to the next node in sequence (next pointer) , pointer to the previous node (previous pointer). A sample node in a doubly linked list is shown in the figure.

![Singly Linked List](https://github.com/saielnaik/Data-Structure-in-C/blob/main/Doubly%20linked%20list/doubly-linked-list.png)
##
![Singly Linked List](https://github.com/saielnaik/Data-Structure-in-C/blob/main/Doubly%20linked%20list/doubly-linked-list2.png)

A doubly linked list containing three nodes having numbers from 1 to 3 in their data part, is shown in the following image.

    struct node   
    {  
        struct node *prev;   
        int data;  
        struct node *next;   
    }   

The prev part of the first node and the next part of the last node will always contain null indicating end in each direction.
n a singly linked list, we could traverse only in one direction, because each node contains address of the next node and it doesn't have any record of its previous nodes. However, doubly linked list overcome this limitation of singly linked list. Due to the fact that, each node of the list contains the address of its previous node, we can find all the details about the previous node as well by using the previous address stored inside the previous part of each node.