# include<iostream>

using namespace std;

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root = NULL;


void Insert( int key)
{
    struct Node *t = root;
    struct Node *r , *p;

    if(root==NULL)
    {
        p = new struct Node;
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while(t!=NULL)
    {
        r = t;
        if(key<t->data)
        {
            t = t->lchild;
        }
        else if (key>t->data)
        {
            t = t->rchild;
        }
        else
        {
            return;
        }
    }
    p = new struct Node;
    p->data = key;
    p->lchild = p->rchild = NULL;
    if(key<r->data)
    {
        r->lchild = p;
    }
    else
    {
        r->rchild = p;
    }

}

void Inorder( struct Node *p)
{
    if(p!=NULL)
    {
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }
}

struct Node * Search(int key)
{
    struct Node *t = root;
    while(t!=NULL)
    {
        if(key==t->data)
        {
            return t;
        }
        else if( key< t->data)
        {
            t = t->lchild;
        }
        else
        {
            t = t->rchild;
        }
    }
    return NULL;
}


struct Node *RInsert( struct Node *p , int key)
{
    struct Node *t = NULL;

    if(p==NULL)
    {
        t = new struct Node;
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }

    else{ 
    if(key<p->data)
    {
        p->lchild = RInsert(p->lchild, key);
    }
    else if( key>p->data)
    {
        p->rchild = RInsert(p->rchild, key);
    }
    else
    {
        return p;
    }
    }
    
};

struct Node *InPre( struct Node *p)
{
    while(p!=NULL && p->rchild!=NULL)
    {
        p = p->rchild;
    }
    return p;
};

struct Node *InSucc(struct Node *p)
{
    while (p!=NULL && p->lchild!=NULL)
    {
        p = p->lchild;
    }
    return p;
};


int Height (struct Node *p)
{
    int x=0, y=0;
    if(p==NULL)
    {
        return 0;
    }
    else
    {
        x = Height(p->lchild);
        y = Height(p->rchild);
        if(x> y)
        {
            return x+1;
        }
        else
        {
            return y+1;
        }
    }
}





struct Node *Delete( struct Node *p, int key)
{
    struct Node *q = NULL;
    if(p==NULL)
    {
        return NULL;
    }

    if(p->lchild == NULL && p->rchild ==  NULL)
    {
        if(p==NULL)
        {
            root = NULL;
        }
        delete p;
        return NULL;
    }


    if (key < p-> data)
    {
        p->lchild = Delete(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = Delete(p->rchild, key);
    }
    else
    {
        if(Height(p->lchild)> Height(p->rchild))
        {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }

    return p;

}







int main()
{
    struct Node *temp;

    // Insert(10);
    // Insert(5);
    // Insert(20);
    // Insert(8);
    // Insert(30);

    // Inorder(root);
    // cout<<endl;

    // temp = Search(2);
    // if(temp!=NULL)
    // {
    //     cout<<"Element is found "<<temp->data<<endl;
    // }
    // else
    // {
    //     cout<<"Element is not found"<<endl;
    // }


    root = RInsert(root, 50);
    RInsert(root, 10);
    RInsert(root, 40);
    RInsert(root, 20);
    RInsert(root, 30);

    Delete(root, 50);

    Inorder(root);
    cout<<endl;

    

    return 0;
}