这是我学链表的副产物(?。此项目对单链表做了一些功能，然而数据类型只支持int，我懒得改了，所以就这样了。当然，教学使用我觉得还是够了的，毕竟基础功能都有，如果后面有人给我提issue，我再看着加功能。如下是对于各个功能的介绍

  

- ## struct Node* createNode(int value);
此功能可以创建一个新节点，value参数应填写创建节点的数据域中的数据（int），用法如下:
```c
struct Node* head = createNode(10);
head->next = createNode(20);
```
- ### 请注意，如果对链表中非尾节点使用，将会顶掉n节点后的数据，例子如下
```c
struct Node* head = createNode(1);
head->next  = createNode(2);
head->next->next  = createNode(3);
head->next  = createNode(4);
```
这段代码如果输出链表结果为`1->4->NULL`

- ## struct Node* createNULLNode(unsigned int count);
此代码可以创建n个空节点，count参数填要创建的空节点的数量，同样只能在链表的尾节点使用，当然，这个空节点的数据域为0。
用法如下
```c
struct Node* head = createNULLNode(10);
```

这将创建出10个空节点。

- ## void printList(struct Node* head);
朴实无华的打印节点，不自带换行符，打印出来的格式为`data1 -> data2 -> data3 -> ... -> NULL`
用法如下
```c
struct Node* head = createNode(1);
struct Node* p = head;
for (int i = 2;i < 10;i++) {
	p->next = createNode(i);
	p = p->next;
}
printList(head);
```
输出结果为`1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> NULL`

当然，如果参数填的不是头节点，那么会从该节点开始往后打印。

- ## int getListLength(struct Node* head);
这可以测量出链表的长度，用法入下
```c
struct Node* head = createNode(1);
struct Node* p = head;
for (int i = 2;i < 10;i++) {
	p->next = createNode(i);
	p = p->next;
}
printf("%d",getListLength(head));
```
输出结果为`9`，自然，如果参数填的不是头节点，那么会从该节点开始往后测量

- ## struct Node* findNodeByValue(struct Node* head, int value);
这可以通过值来查找节点，返回的是指向查找到的节点的指针，`struct Node* head`的参数应填链表的头节点，而`value`参数应填要查找的值。

- ### 请注意，如果没有成功在链表中查找到数据将会返回NULL。

用法如下:
```c
struct Node* head = createNode(10);
struct Node* p = findNodeByValue(head, 10);
printf("%d", p->data);
```
输出结果为`10`

- ## void insertAtTail(struct Node** head, int value);
此功能可以在特定链表的尾部插入节点，head参数可以填链表中的任意一个有效节点，数据域为`value`，指针域为`NULL`。

用法如下
```c
struct Node* head = createNode(10);
head->next = createNode(30);
insertAtTail(&head, 20);
printList(head);
```
输出结果为`10 -> 30 -> 20 -> NULL`

当然也可以这么用
```c
struct Node* head = createNode(10);
head->next = createNode(30);
insertAtTail(&(head->next), 20);
printList(head);
```
与上一段代码的输出结果一致

.......

懒得写了qwq，以后继续写叭。