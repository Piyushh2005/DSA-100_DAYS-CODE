#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createNode(int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertEnd(struct Node *head, int value)
{
    struct Node *temp = createNode(value);

    if (head == NULL)
        return temp;

    struct Node *p = head;
    while (p->next != NULL)
        p = p->next;

    p->next = temp;
    return head;
}

struct Node* mergeSortedLists(struct Node *l1, struct Node *l2)
{
    struct Node dummy;
    struct Node *tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL)
    {
        if (l1->data <= l2->data)
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != NULL)
        tail->next = l1;
    else
        tail->next = l2;

    return dummy.next;
}

void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    int n, m, x;
    struct Node *list1 = NULL;
    struct Node *list2 = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        list1 = insertEnd(list1, x);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &x);
        list2 = insertEnd(list2, x);
    }

    struct Node *merged = mergeSortedLists(list1, list2);

    printList(merged);

    return 0;
}