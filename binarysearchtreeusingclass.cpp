#include<iostream>


using namespace std;


class Node{
    public: 
    Node *lchild;
    int data;
    Node *rchild;
};


class BST{
    private: 
    Node *root;
    public: 
    BST(){
        root = NULL;
    }
    Node *getRoot()
    {
        return root;
    }
    void iInsert(int key);
    void Inorder( Node *p);
    Node *iSearch(int key);
    Node *rSearch(Node *p, int key);
    Node *rSearch(Node*p , int key);
    Node *Delete (Node *p, int key );
    int Height( Node *p);
    Node *InPre(Node *p);
    Node *InSuc(Node *p);
    void createFromPreorder( int pre[], int n);
};

void BST :: iInsert( int key){
    Node *t = root; 
    Node *p; 
    Node *r;


    // If root is empty
    if(root == NULL)
    {
        p = new Node; 
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    
    while(t!=NULL)
    {
        r = t;
        if( key < t->data){
            t = t->lchild;
        }
        else if( key > t->data)
        {
            t = t->rchild;
        }
        else{
            return ;
        }
    }

    //  Now t points at NULL and r points at Insert Position
    p = new Node; 
    p->data = key;
    p->lchild = p->rchild = NULL;

    if( key < r->data)
    {
        r->lchild = p;
    }
    else{
        r->rchild = p;
    }

}

void BST :: Inorder( Node *p)
{
    if(p!=NULL)
    {
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }
}

Node *BST :: iSearch(int key)
{
    
}