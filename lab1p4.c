/*
Author: Nicholas Wilson
Goal: Create two structures, a linked list and node, to create the linked list data type in C
and read command line arguments on to it
Method: Use malloc, calloc, and pointers to dynamically create the head, tail, and pointer
structure of a linked list and nodes. Use C's built-in structure type as a way to actually
create the linked list and nodes.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
//Node, with data and a pointer to the next element
struct Node
{
    char* data;
    struct Node* next;
};
typedef struct Node Node;
//Linked list, with a pointer to the head
struct Linkedlist{
    Node* head;
};
typedef struct Linkedlist Linkedlist;
/*
Inserts the given element at the beginning of the linked list.
*/
void insertAtBeginning(struct Linkedlist* LL, char ele[]){
    //Allocate a node
    Node *n = (Node*)malloc(sizeof(Node)); //Allocate new node with malloc//Bin: The braces around malloc function can be removed
    n->next = LL->head; //Allocate new node's next to current head//Bin: The old version is correct. You may also change it to n->next = LL->head; The same to the rest.
    (*LL).head = (n); //Allocate linked list's head to the node
    int data_size = strlen(ele) + 1; //Get the size of ele//Bin: a small bug
    (*n).data = (char*)(malloc(data_size)); //Allocate a char* with malloc
    strcpy((*n).data, ele); //Copy ele to the new node's data
}
/*
Insert the given element at the end of the linked list.
*temp is a Node in the linked list
temp is a pointer to that Node
*/
void insertAtTheEnd(struct Linkedlist* LL, char ele[]){
    //Bin: This is OK for this testing code. How about if temp (i.e., LL->head) is empty?
    //Please handle this special case.
    if(LL->head == NULL){ //For the special case of the head being null
        insertAtBeginning(LL, ele);
        return;
    }

    Node *n = (Node*)(malloc(sizeof(Node))); //Allocate new node with malloc
    int data_size = strlen(ele) + 1; //Get the size of ele//Bin: a small bug
    (*n).data = (char*)(malloc(data_size)); //Allocate a char* with malloc
    strcpy((*n).data, ele); //Copy ele to the new node's data
    (*n).next = NULL;//Bin: always use NULL for pointers' initialization or testing, please.

    Node *temp = (*LL).head; //Use this while loop to iterate to the end of the linked list
    while((*temp).next != NULL){
        temp = temp->next;
    }

    (*temp).next = n; //Add the new node in at the end
}
/*
Delete the node with the given element, unless it doesn't exist.
*/
void deleteNode(struct Linkedlist* LL, char ele[]){
    if(LL->head == NULL){ //For the special case of the head being null
        return;
    }
    Node *temp = (*LL).head; 
    //printf("This is the address of temp's data: %s", &(*temp).data);
    if(strcmp((*temp).data, ele) == 0){ //If this node's data is equal to the ele
        //Set the new head of the Linkedlist to the next element in the linked list
        (*LL).head = (*temp).next;
        free((*temp).data); //Free the string
        free(temp); //Free the node
        return;
    }
    Node *before_temp; //The node prior to temp
    while((*temp).next != 0){//Use this while loop to iterate to the end of the linked list
        before_temp = temp;
        temp = temp->next;
        if(strcmp((*temp).data, ele) == 0){ //If this node's data is equal to the ele
            //Set the node prior to temp's next field to temp's next
            before_temp->next = temp->next;
            free((*temp).data); //Free the string
            free(temp); //Free the node
            return;
        }
    }
}
/*
Find the node with the given element, unless it doesn't exist.
*/
int findNode(struct Linkedlist* LL, char ele[]){
    Node *temp = (*LL).head; //Use this while loop to iterate to the end of the linked list
    if(LL->head == NULL){ //For the special case of the head being null
        return 0;
    }
    while((*temp).next != NULL){//Bin: How about temp == NULL? Please handle this special case.
                             //Or you may want to change your logic to while (temp != NULL) or simply while (temp)
        if(strcmp((*temp).data, ele) == 0){ //If this node's data is equal to the ele
            return 1;
        }
        temp = temp->next;
    }
    if(strcmp((*temp).data, ele) == 0){ //If this node's data is equal to the ele
        return 1;
    }
    return 0;
}
/*
*LL is a linked list, LL is a pointer to the linked list
Display the linked list to the user.
*/
void displayLinkedList(struct Linkedlist* LL){
    printf("The list:- ");
    Node *temp = (*LL).head; //Use this while loop to iterate to the end of the linked list
    while((*temp).next != 0){
        printf("%s, ", (*temp).data); //Print the data, with the comma and space separating it
        temp = temp->next;
    }
    printf("%s\n", (*temp).data); //Print the last item of data
}
/*
Declare a linked list LL. Don’t forget to initialize the head of the Linked List.
Ø Insert the arguments that start with an uppercase letter at the beginning of the Linked List in the
order they arrived in. Use insertAtBeginning.
Ø Insert the arguments that start with a lowercase letter at the end of the Linked List in the order they
arrived in. Use insertAtTheEnd. 
Ø Before inserting, check if the word exist in the Linked List using findNode. if it exists, delete it using
deleteNode.
*/
int main( int argc, char *argv[] ){
    //char *debug_array[] = {"my", "name", "is", "Marwan", "and", "my", "car", "is", "White" };
    if(argc == 1){
        printf("ERROR: The program must read at least an argument.\n");
        return 0;
    }
    struct Linkedlist LL;
    LL.head = NULL;

//Bin: In fact, your free error is caused by this initialization. You initialize LL.head with a static allocated node
//i.e., an object on stack; however, you try to free it later. We can change this into a dynamic allocation as well.
/*
    struct Node head;//Bin: This is fine for this testing code. In your final code,
                     //you cannot assume it always has a head.
                     //It will be helpful to initialize LL.head = NULL;
    //head.data = argv[1];
    head.data = debug_array[0];
    head.next = NULL;//Bin: Change to NULL
    LL.head = &head;
*/

    // struct Node *head = (struct Node*) malloc(sizeof(struct Node));
    // head->data = (char*) malloc(strlen(debug_array[0]) + 1);
    // memset(head->data, 0, strlen(debug_array[0]) + 1);//This initialization can also be omited.
    // strcpy(head->data, debug_array[0]);
    // head->next = NULL;
    // LL.head = head;  

    int i = 1;
    while(i < argc){
        if(findNode(&LL, argv[i])){ //If the element is already in the LL, delete it
            deleteNode(&LL, argv[i]);
        }
        else if(isupper(argv[i][0])){ //If the element starts with an uppercase letter, insert at beginning
            insertAtBeginning(&LL, argv[i]);
        }
        else{ //If the element doesn't start with an uppercase letter, insert at the end
           insertAtTheEnd(&LL, argv[i]);
        }
        i++;
    }
    displayLinkedList(&LL);

    //Bin: Please consider using a loop to free all nodes in the linked list
    // Node *temp = LL.head; //Use this while loop to iterate to the end of the linked list
    // while(temp){
    //     temp = temp->next;
    //     free((*temp).data); //Free the string
    //     free(temp); //Free the node
    // }
    return 0;
}
