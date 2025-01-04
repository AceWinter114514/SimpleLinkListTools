#pragma once
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

// 定义节点结构体
struct Node {
    int data;             // 存储数据
    struct Node* next;    // 指向下一个节点
};

// 创建新节点
struct Node* createNode(int value);

// 创建空节点
struct Node* createNULLNode(unsigned int count);

// 打印链表
void printList(struct Node* head);

// 获取链表长度
int getListLength(struct Node* head);

// 通过值查找节点
struct Node* findNodeByValue(struct Node* head, int value);

// 在尾部插入节点
void insertAtTail(struct Node** head, int value);

// 在头部插入节点
void insertAtHead(struct Node** head, int value);

// 根据索引插入节点
void insertList(struct Node** head, int index, int value);

// 删除指定值的节点
void deleteListDataByValue(struct Node** head, int value);

// 根据索引删除节点
void deleteListDataByIndex(struct Node** head, int index);

// 根据索引修改节点数据
void changeListDataByIndex(struct Node** head, int index, int value);

// 根据值修改节点数据
void changeListDataByValue(struct Node** head, int oldValue, int newValue);

// 释放链表
void freeList(struct Node** head);

// 链表排序
void sortLinkList(struct Node** head, short reverse);

#endif // LINKLIST_H
