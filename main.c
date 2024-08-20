#include <stdio.h>
 #include <stdlib.h>
 struct Node{
 int data;
 struct Node * next;
 };
 void printLinkedList(struct Node * head){
 printf("The linked list is:\n");
 struct Node * p = head;
 do{
 printf("%d ", p->data);
 p = p->next;
 }while(p!=NULL);
 }
 void searchLinkedList(struct Node * head, int element){
 struct Node * ptr = head;
 int num = 0;
 while(ptr!=NULL){
 if(ptr->data == element){
 printf("Element found at node %d", num);
return;
 }
 ptr = ptr->next;
 num++;
 }
 printf("Element requested is not present in the linked list");
 }
 struct Node * insertElement(struct Node * head){
 printf("\nEnter 1 to insert element at head, 2 to insert element at an index and 3 to insert element at the end: ");
 int userChoice;
 scanf("%d", &userChoice);
 printf("\nEnter the element to be inserted: ");
 int element;
 scanf("%d", &element);
 if(userChoice==1){
 struct Node * ptr = (struct Node *) malloc(sizeof(struct
 Node));
 ptr->data = element;
 ptr->next = head;
 head = ptr;
 }
 else if(userChoice==2){
 printf("\nEnter the index at which the element is to be inserted: ");
 int index;
 scanf("%d", &index);
 struct Node * p = head;
 int count = 0;
 while(count<index-1){
 p = p->next;
 count++;
 }
 struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
 ptr->next = p->next;
 p->next = ptr;
 ptr->data = element;
 }
 else if(userChoice==3){
 struct Node * ptr = (struct Node *) malloc(sizeof(struct
 Node));
struct Node * p = head;
 while(p->next!=NULL){
 p = p->next;
 }
 p->next = ptr;
 ptr->data = element;
 ptr->next = NULL;
 }
 else{
 printf("\nEnter a valid choice!");
 }
 return head;
 }
 struct Node * deleteElement(struct Node * head){
 printf("\nEnter 1 to delete head node, 2 to delete a node at an index and 3 to delete the last node: ");
 int userChoice;
 scanf("%d", &userChoice);
 if(userChoice==1){
 struct Node * temp = head->next;
 free(head);
 head = temp;
 }
 else if(userChoice==2){
 int index;
 printf("\nEnter the index of the node to be deleted: ");
 scanf("%d", &index);
 int count=0;
 struct Node * temp = head;
 while(count<index-1){
 temp = temp->next;
 count++;
 }
 struct Node * temp2 = temp->next;
 temp->next = temp2->next;
 free(temp2);
 }
 else if(userChoice==3){
 struct Node * temp = head;
 while(temp->next->next!=NULL){
 temp = temp->next;
 }
struct Node * temp2 = temp->next;
 temp->next = NULL;
 free(temp2);
 }
 else{
 printf("\nEnter a valid choice!");
 }
 return head;
 }
 void sortLinkedList(struct Node * head){
 struct Node * temp = head;
 int count = 0;
 while(temp!=NULL){
 temp = temp->next;
 count++;
 }
 int i = 1;
 temp = head;
 while(i<count){
 int j = 0;
 temp = head;
 while(j<=count-i-1){
 struct Node * temp2;
 temp2 = temp->next;
 if(temp->data >= temp2->data){
 int x = temp->data;
 temp->data = temp2->data;
 temp2->data = x;
 }
 temp = temp->next;
 j++;
 }
 i++;
 }
 }
 int main()
 {
 //Input of elements by the user to make the starting linked list.
 int stop=1;
 int i = 0;
struct Node * head;
 struct Node * present;
 while(stop!=0){
 printf("Enter 0 to stop the process and any other number to continue entering numbers into the linked list: ");
 scanf("%d", &stop);
 if(stop == 0)
 break;
 else{
 i++;
 if(i==1){
 head = (struct Node *) malloc(sizeof(struct Node));
 int input;
 printf("Enter the head element: ");
 scanf("%d", &input);
 head->data = input;
 head->next = NULL;
 present = head;
 }
 else{
 struct Node * ptr = (struct Node *) malloc(sizeof(struct
 Node));
 int input;
 printf("Enter the element: ");
 scanf("%d", &input);
 ptr->data = input;
 ptr->next = NULL;
 present->next = ptr;
 present = ptr;
 }
 }
 }
 while(1){
 printf("\nEnter 1 to sort the linked list, 2 to search for an element in the linked list, 3 to insert an element in the linked list, 4 to delete an element from the linked list, 5 to print the linked list, 6 to exit: ");
 int choice;
 scanf("%d", &choice);
 if(choice==1){
 sortLinkedList(head);
 }
else if(choice==2){
 printf("\nEnter the element to be searched in the linked list:");
 int element;
 scanf("%d", &element);
 searchLinkedList(head, element);
 }
 else if(choice==3){
 head = insertElement(head);
 }
 else if(choice==4){
 head = deleteElement(head);
 }
 else if(choice==5){
 printLinkedList(head);
 }
 else if(choice==6){
 break;
 }
 else {
 printf("\nEnter a valid choice!");
 }
 }
 return 0;
 }
