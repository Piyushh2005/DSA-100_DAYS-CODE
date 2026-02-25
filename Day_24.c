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

int main(){
    int n,x,key;
    scanf("%d",&n);

    struct Node *head=NULL,*temp=NULL,*last=NULL;

    for(int i=0;i<n;i++){
        scanf("%d",&x);
        temp=createNode(x);
        if(head==NULL){
            head=temp;
            last=temp;
        }else{
            last->next=temp;
            last=temp;
        }
    }

    scanf("%d",&key);

    struct Node *curr=head,*prev=NULL;

    while(curr!=NULL){
        if(curr->data==key){
            if(prev==NULL)
                head=curr->next;
            else
                prev->next=curr->next;
            free(curr);
            break;
        }
        prev=curr;
        curr=curr->next;
    }

    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }

    return 0;
}