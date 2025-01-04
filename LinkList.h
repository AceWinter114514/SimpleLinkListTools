#pragma once
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

// ����ڵ�ṹ��
struct Node {
    int data;             // �洢����
    struct Node* next;    // ָ����һ���ڵ�
};

// �����½ڵ�
struct Node* createNode(int value);

// �����սڵ�
struct Node* createNULLNode(unsigned int count);

// ��ӡ����
void printList(struct Node* head);

// ��ȡ������
int getListLength(struct Node* head);

// ͨ��ֵ���ҽڵ�
struct Node* findNodeByValue(struct Node* head, int value);

// ��β������ڵ�
void insertAtTail(struct Node** head, int value);

// ��ͷ������ڵ�
void insertAtHead(struct Node** head, int value);

// ������������ڵ�
void insertList(struct Node** head, int index, int value);

// ɾ��ָ��ֵ�Ľڵ�
void deleteListDataByValue(struct Node** head, int value);

// ��������ɾ���ڵ�
void deleteListDataByIndex(struct Node** head, int index);

// ���������޸Ľڵ�����
void changeListDataByIndex(struct Node** head, int index, int value);

// ����ֵ�޸Ľڵ�����
void changeListDataByValue(struct Node** head, int oldValue, int newValue);

// �ͷ�����
void freeList(struct Node** head);

// ��������
void sortLinkList(struct Node** head, short reverse);

#endif // LINKLIST_H
