#include "LinkList.h"



int main() {
	struct Node* head = createNode(10);
	head->next = createNode(30);
	insertAtTail(&(head->next), 20);
	printList(head);
}