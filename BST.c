#include<stdio.h>
#include<stdlib.h>
struct Node
{
    struct Node *llink;
    int data;
    struct Node *rlink;
}*root=NULL;
int Height(struct Node *p)
{
    if(p==NULL)
        return(0);
    int x,y;
    x=Height(p->llink);
    y=Height(p->rlink);
    if(x>y)
        {return(x+1);}
    else
        {return(y+1);}
}
struct Node *InPre(struct Node *p)
{
    while(p && p->rlink!=NULL)
        p=p->rlink;
    return(p);
}
struct Node *InSucc(struct Node *p)
{
    while(p && p->llink!=NULL)
        p=p->llink;
    return(p);
}
struct Node *Insert(struct Node *root,int key)
{
    struct Node *t=root,*p,*r;
    p=(struct Node*)malloc(sizeof(struct Node));
    p->data=key;
    p->llink=p->rlink=0;
    if(root==NULL)
    {
        root=p;
        return(root);
    }
    printf("%d\n",t->data );
    while(t!=NULL)
    {
        r=t;
        if(key==t->data)
            {printf("Redundancy\n");return(root);}
        else if(key<t->data)
            {t=t->llink;}
        else
            {t=t->rlink;}
    }
    
    if(key<r->data)
        r->llink=p;
    else
        r->rlink=p;
    return(root);
}
struct Node *Delete(struct Node *p,int key)
{
    struct Node *q;
    if(p==NULL)
        return(0);
    if(p->llink==NULL && p->rlink==NULL)
    {
        if(p==root)
        {
            root=NULL;
        }
        free(p);
        return NULL;
    }
    if(key<p->data)
        {p->llink=Delete(p->llink,key);}
    else if(key>p->data)
        {p->rlink=Delete(p->rlink,key);}
    else
    {
        if(Height(p->llink)>Height(p->rlink))
        {
            q=InPre(p->llink);
            p->data=q->data;
            p->llink=Delete(p->llink,q->data);
        }
        else
        {
            q=InPre(p->rlink);
            p->data=q->data;
            p->rlink=Delete(p->rlink,q->data);   
        }
    }
    return(p);
}
void Iter_Search(struct Node *root,int key)
{
    if(!root){printf("BST is Empty");return;}
    while(root)
    {
        if(key==root->data)
            {printf("Search Successful\n");return;}
        else if(key<root->data)
            {root=root->llink;}
        else
            {root=root->rlink;}
    }
    printf("Unsuccessful Search\n");
}
void Preorder(struct Node *r)
{
    if(r)
    {
        printf("%d\t",r->data);
        Preorder(r->llink);
        Preorder(r->rlink);
    }
}
void Inorder(struct Node *r)
{
    if(r)
    {
        Inorder(r->llink);
        printf("%d\t",r->data);
        Inorder(r->rlink);
    }
}
void Postorder(struct Node *r)
{
    if(r)
    {
        Postorder(r->llink);
        Postorder(r->rlink);
        printf("%d\t",r->data);
    }
}

int main()
{
    struct Node *root=NULL;
    int ch,key;
    for(;;)
    {
        printf("1:Insert\n2:Delete\n3:Iter_Search\n4:Preorder\n5:Inorder\n6:Postorder\n7:Exit\n");
        printf("Enter choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter key to be inserted\n");
                    scanf("%d",&key);
                    root=Insert(root,key);
                    break;
            case 2: printf("Enter key to be deleted\n");
                    scanf("%d",&key);
                    root=Delete(root,key);
                    break;
            case 3: printf("Enter key to be searched\n");
                    scanf("%d",&key);
                    Iter_Search(root,key);
                    break;
            case 4: printf("Preorder\n");
                    Preorder(root);
                    printf("\n");
                    break;
            case 5: printf("Inorder\n");
                    Inorder(root);
                    printf("\n");
                    break;
            case 6: printf("Postorder\n");
                    Postorder(root);
                    printf("\n");
                    break;
            default:exit(0);
        }
    }
}