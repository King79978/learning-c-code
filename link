#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义链表节点
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// 插入节点
void insert(Node **head, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// 删除节点
void delete(Node **head, int value)
{
    Node *temp = *head;
    Node *prev = NULL;

    // 如果要删除的节点是头节点
    if (temp != NULL && temp->data == value)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    // 查找要删除的节点
    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    // 如果没有找到要删除的节点
    if (temp == NULL)
        return;

    // 进行删除
    prev->next = temp->next;
    free(temp);
}

// 反转链表
void reverse(Node **head)
{
    Node *prev = NULL;
    Node *current = *head;
    Node *next = NULL;

    while (current != NULL)
    {
        next = current->next; // 保存下一个节点
        current->next = prev; // 反转当前节点的指针
        prev = current;       // 移动 prev 和 current 指针
        current = next;
    }
    *head = prev; // 更新头指针
}

// 打印链表
void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// 主函数
int main(int argc, char *argv[])
{
    Node *head = NULL;
    if (argc < 2)
    {
        printf("命令:\n");
        printf("  insert <value>  - 插入节点\n");
        printf("  delete <value>  - 删除节点\n");
        printf("  reverse         - 反转链表\n");
        printf("  print           - 打印链表\n");
        return 1;
    }

    if (strcmp(argv[1], "insert") == 0 && argc == 3)
    {
        int value = atoi(argv[2]);
        insert(&head, value);
        printf("插入节点 %d\n", value);
    }
    else if (strcmp(argv[1], "delete") == 0 && argc == 3)
    {
        int value = atoi(argv[2]);
        delete (&head, value);
        printf("删除节点 %d\n", value);
    }
    else if (strcmp(argv[1], "reverse") == 0)
    {
        reverse(&head);
        printf("链表已反转。\n");
    }
    else if (strcmp(argv[1], "print") == 0)
    {
        printList(head);
    }
    else
    {
        printf("无效命令或参数。\n");
    }

    // 释放链表
    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
