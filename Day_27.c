#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int x){
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    n->data=x;
    n->next=NULL;
    return n;
}

void append(struct Node** head,int x){
    struct Node* n=createNode(x);
    if(*head==NULL){
        *head=n;
        return;
    }
    struct Node* temp=*head;
    while(temp->next) temp=temp->next;
    temp->next=n;
}

int length(struct Node* head){
    int c=0;
    while(head){
        c++;
        head=head->next;
    }
    return c;
}

struct Node* findIntersection(struct Node* h1,struct Node* h2){
    int l1=length(h1);
    int l2=length(h2);
    int d=abs(l1-l2);

    if(l1>l2){
        while(d--) h1=h1->next;
    }else{
        while(d--) h2=h2->next;
    }

    while(h1 && h2){
        if(h1->data==h2->data) return h1;
        h1=h1->next;
        h2=h2->next;
    }
    return NULL;
}

int main(){
    int n,m,x,i;
    struct Node *head1=NULL,*head2=NULL;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        append(&head1,x);
    }

    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d",&x);
        append(&head2,x);
    }

    struct Node* ans=findIntersection(head1,head2);

    if(ans) printf("%d",ans->data);
    else printf("No Intersection");

    return 0;
}