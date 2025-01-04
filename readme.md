������ѧ����ĸ�����(?������Ŀ�Ե���������һЩ���ܣ�Ȼ����������ֻ֧��int�������ø��ˣ����Ծ������ˡ���Ȼ����ѧʹ���Ҿ��û��ǹ��˵ģ��Ͼ��������ܶ��У�����������˸�����issue�����ٿ��żӹ��ܡ������Ƕ��ڸ������ܵĽ���

  

- ## struct Node* createNode(int value);
�˹��ܿ��Դ���һ���½ڵ㣬value����Ӧ��д�����ڵ���������е����ݣ�int�����÷�����:
```c
struct Node* head = createNode(10);
head->next = createNode(20);
```
- ### ��ע�⣬����������з�β�ڵ�ʹ�ã����ᶥ��n�ڵ������ݣ���������
```c
struct Node* head = createNode(1);
head->next  = createNode(2);
head->next->next  = createNode(3);
head->next  = createNode(4);
```
��δ���������������Ϊ`1->4->NULL`

- ## struct Node* createNULLNode(unsigned int count);
�˴�����Դ���n���սڵ㣬count������Ҫ�����Ŀսڵ��������ͬ��ֻ���������β�ڵ�ʹ�ã���Ȼ������սڵ��������Ϊ0��
�÷�����
```c
struct Node* head = createNULLNode(10);
```

�⽫������10���սڵ㡣

- ## void printList(struct Node* head);
��ʵ�޻��Ĵ�ӡ�ڵ㣬���Դ����з�����ӡ�����ĸ�ʽΪ`data1 -> data2 -> data3 -> ... -> NULL`
�÷�����
```c
struct Node* head = createNode(1);
struct Node* p = head;
for (int i = 2;i < 10;i++) {
	p->next = createNode(i);
	p = p->next;
}
printList(head);
```
������Ϊ`1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> NULL`

��Ȼ�����������Ĳ���ͷ�ڵ㣬��ô��Ӹýڵ㿪ʼ�����ӡ��

- ## int getListLength(struct Node* head);
����Բ���������ĳ��ȣ��÷�����
```c
struct Node* head = createNode(1);
struct Node* p = head;
for (int i = 2;i < 10;i++) {
	p->next = createNode(i);
	p = p->next;
}
printf("%d",getListLength(head));
```
������Ϊ`9`����Ȼ�����������Ĳ���ͷ�ڵ㣬��ô��Ӹýڵ㿪ʼ�������

- ## struct Node* findNodeByValue(struct Node* head, int value);
�����ͨ��ֵ�����ҽڵ㣬���ص���ָ����ҵ��Ľڵ��ָ�룬`struct Node* head`�Ĳ���Ӧ�������ͷ�ڵ㣬��`value`����Ӧ��Ҫ���ҵ�ֵ��

- ### ��ע�⣬���û�гɹ��������в��ҵ����ݽ��᷵��NULL��

�÷�����:
```c
struct Node* head = createNode(10);
struct Node* p = findNodeByValue(head, 10);
printf("%d", p->data);
```
������Ϊ`10`

- ## void insertAtTail(struct Node** head, int value);
�˹��ܿ������ض������β������ڵ㣬head���������������е�����һ����Ч�ڵ㣬������Ϊ`value`��ָ����Ϊ`NULL`��

�÷�����
```c
struct Node* head = createNode(10);
head->next = createNode(30);
insertAtTail(&head, 20);
printList(head);
```
������Ϊ`10 -> 30 -> 20 -> NULL`

��ȻҲ������ô��
```c
struct Node* head = createNode(10);
head->next = createNode(30);
insertAtTail(&(head->next), 20);
printList(head);
```
����һ�δ����������һ��

.......

����д��qwq���Ժ����д�ȡ�