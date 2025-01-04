#include <stdio.h>  
#include <stdlib.h>  

// 这里没有注释，别想了，自己读英语猜用途去吧。

struct Node {
    int data;
    struct Node* next;
};
void freeList(struct Node** head) {
    if (head == NULL || *head == NULL) {
        return;
    }

    struct Node* temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    *head = NULL;
}

int getListLength(struct Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}
struct Node* findNodeByValue(struct Node* head, int value) {
    while (head != NULL) {
        if (head->data == value) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void insertAtTail(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    
    struct Node* temp = *head;
    if (temp == NULL) {
        temp = newNode;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;

}
void insertAtHead(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  
    newNode->data = value;  
    newNode->next = NULL;
    return newNode;
}

struct Node* createNULLNode(unsigned int count) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (count == 1) {
        newNode->data = 0;
        newNode->next = NULL;
        return newNode;
    }
    newNode->data = 0;
    newNode->next = NULL;
    struct Node* p = newNode;
    for (int i = 1;i < count;i++) {
        p->next = createNULLNode(1);
        p = p->next;
    }
    
    return newNode;
}


void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL");
}
void deleteListDataByValue(struct Node** head, int value) {
    void printList(struct Node* head);
    if (*head == NULL) {
        printf("List is empty,ERROR List is ");
        printList(head);
        return;
    }

    if ((*head)->data == value) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    struct Node* wrong = *head;
    struct Node* temp = *head;
    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Value not found in the list,ERROR List is ");
        printList(wrong);
        return;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
    
}
void deleteListDataByIndex(struct Node** head,int index) {
    if (*head == NULL) {
        printf("List is empty,ERROR List is ");
        printList(head);
        return;
    }
    struct Node* temp = *head;
    if (index == 0) {
        *head = (*head)->next;
        free(temp);
        return;
    }
    if (index < 0) {
        printf("Index Out Of LinkList!,ERROR INFO:Index is smaller than zero\n");
        return;
    }
    struct Node* wrong = *head;
    for (int i = 0;i < index;i++) {
        if (temp->next == NULL) {
            printf("Index Out Of LinkList! ERROR List is ");
            printList(wrong);
            return;
        }
        temp = temp->next;
    }
    struct Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
}
void changeListDataByIndex(struct Node** head, int index,int value) {
    if (*head == NULL) {
        printf("List is empty,ERROR List is ");
        printList(head);
        return;
    }
    struct Node* temp = *head;
    if (index == 0) {
        temp->data = value;
        return;
    }
    if (index < 0) {
        printf("Index Out Of LinkList!,ERROR INFO:Index is smaller than zero\n");
        return;
    }
    struct Node* wrong = *head;
    for (int i = 0;i < index;i++) {
        if (temp->next == NULL) {
            printf("Index Out Of LinkList! ERROR List is \n");
            printList(wrong);
            printf("ERROR function is changeListDataByIndex\n");
            return;
        }
        temp = temp->next;
    }
    temp->data = value;
}

void changeListDataByValue(struct Node** head, int value1, int value2) {
    if (*head == NULL) {
        printf("List is empty,ERROR List is ");
        printList(head);
        return;
    }

    struct Node* temp = *head;
    if (temp->data == value1) {
        temp->data = value2;
        return;
    }
    struct Node* wrong = *head;
    while (temp->next != NULL && temp->data != value1) {
        temp = temp->next;
    }
    
    if (temp->data == value1) {
        temp->data = value2;
        return;
    }
    if (temp->next == NULL) {
        printf("ERROR:Value not found in the list,ERROR List is ");
        printList(wrong);
        return;
    }

}

void insertList(struct Node** head, int index, int value) {
    if (*head == NULL) {
        printf("List is empty");
        return;
    }
    if (index < 0) {
        printf("Index Out Of LinkList!,ERROR INFO:Index is smaller than zero\n");
        return;
    }
    struct Node* wrong = *head;
    struct Node* temp = *head;
    struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
    NewNode->data = value;
    if (index == 0) {
        NewNode->next = *head;
        *head = NewNode;
        return;
    }
    
    for (int i = 0;i < index;i++) {
        if (temp->next == NULL) {
            printf("Index Out Of LinkList! ERROR List is \n");
            printList(wrong);
            printf("ERROR function is insertList\n");
            return;
        }
        temp = temp->next;
    }
    NewNode->next=temp;
    struct Node* temp1 = *head;
    for (int i = 0;i < index - 1;i++) {
        temp1 = temp1->next;
    }
    temp1->next = NewNode;
}

void sortLinkList(struct Node** head, short reverse) {
    if (head == NULL || *head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* current;
    struct Node* last = NULL;
    int swapped;

    do {
        swapped = 0;
        current = *head;

        while (current->next != last) {
            int compare = reverse ? (current->data < current->next->data) : (current->data > current->next->data);
            if (compare) {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);

}