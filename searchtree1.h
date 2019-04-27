#ifndef SEARCHTREE.H
#define SEARCHTREE.H

#include <iostream>

typedef int object;
class tree_element1 {
    public:
        object val; // value
        tree_element1* left;  // left next element
        tree_element1* right; // right next element
};

class searchtree1 {
    private:
        tree_element1* root; // root of the tree
        void Insert(tree_element1 *currRoot, tree_element1 *elem);
        void DeleteTree(tree_element1 *root);
        void Print(tree_element1 *root);
    public:
        searchtree1();
        ~searchtree1();
        void Insert(object o); // insert value
        bool Contains(object o); // value in tree?
        void DeleteValue(object o); // delete value
        void Print(); // print tree
};

searchtree1::searchtree1(){
    root = NULL;
}

searchtree1::~searchtree1(){
    DeleteTree(root);
    root = NULL;
}

void searchtree1::DeleteTree(tree_element1 *root){
    if (root != NULL){
        if (root->left != NULL)
            DeleteTree(root->left);
        if(root->right != NULL)
            DeleteTree(root->right);
        delete root;
    }
}

bool searchtree1::Contains(object o){
    tree_element1 *curr = root;
    while (curr != NULL){
            if (curr->val == o)
                return true;
            else{
                if(o <= curr->val)
                    curr = curr->left;
                else curr = curr->right;
            }
    }

            return false;
}

void searchtree1::Insert(object o){
    tree_element1 *elem = new tree_element1;
    elem->val = o;
    elem->left = NULL;
    elem->right=NULL;
    if(root == NULL)
        root=elem;
    else Insert(root,elem);
}

void searchtree1::Insert(tree_element1 *currRoot, tree_element1 *elem){
    if(elem->val <= currRoot->val){
            if(currRoot->left == NULL)
                currRoot->left = elem;
            else Insert(currRoot->left,elem);
    }else{
        if(currRoot->right == NULL)
            currRoot->right = elem;
        else Insert(currRoot->right,elem);
    }
}

void searchtree1::Print(){
    Print(root);
    printf("\n");
}

void searchtree1::Print(tree_element1 *root){
    if(root!=NULL){
        //cout<<"(";
        printf("(");
        Print(root->left);
        //cout<<","<<root->val<<",";
        printf(",%d,", root->val);
        Print(root->right);
        //cout<<")";
        printf(")");
    }else{
        //cout<<"n";
        printf("n");
    }
}

#endif
