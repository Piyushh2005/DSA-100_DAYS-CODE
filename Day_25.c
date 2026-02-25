#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int val){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=NULL;
    return newNode;
}

int main(){
    int n,x,key,count=0;
    scanf("%d",&n);

    struct Node *head=NULL,*last=NULL,*temp=NULL;

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

    temp=head;
    while(temp!=NULL){
        if(temp->data==key)
            count++;
        temp=temp->next;
    }

    printf("%d",count);

    return 0;
}