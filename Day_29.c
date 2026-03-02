#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

struct Node* rotateRight(struct Node* head, int k){
    if(head == NULL || head->next == NULL || k == 0)
        return head;

    struct Node* temp = head;
    int n = 1;

    while(temp->next){
        temp = temp->next;
        n++;
    }

    temp->next = head;
    k = k % n;
    int steps = n - k;

    while(steps--){
        temp = temp->next;
    }

    head = temp->next;
    temp->next = NULL;

    return head;
}

int main(){
    int n, x, k;
    scanf("%d",&n);

    struct Node *head = NULL, *tail = NULL;

    for(int i=0;i<n;i++){
        scanf("%d",&x);
        struct Node* newNode = createNode(x);
        if(head == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    scanf("%d",&k);

    head = rotateRight(head,k);

    struct Node* temp = head;
    while(temp){
        printf("%d ",temp->data);
        temp = temp->next;
    }

    return 0;
}