#ifndef SEARCHTREE.H
#define SEARCHTREE.H

#include <iostream>

typedef int object;
class tree_element1 {
    public:
        object val; // value
        tree_element1* left;  // left next element
        tree_element1* right; // right next element
        tree_element1* DeleteVal(object o);
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
        void DeleteValueIterative(object o); // delete value iterative
        void DeleteValueRecursive(object o);//delete value rekursive
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

tree_element1* searchMin(tree_element1* root){
    tree_element1* pre;
    while(root->left != NULL){
        pre = root;
        root = root->right;
    }
    pre->right = root->right;
    printf("%d\n", root->val);
    return root;
}

void searchtree1::DeleteValueIterative(object o){
    tree_element1 *curr = root;
    tree_element1 *pre;      //saves previous element
    tree_element1 *save;
    bool right = false;

        while (curr != NULL){
            if (curr->val == o){
                if(curr->left == NULL && curr->right == NULL){
                        if(curr == root){
                        DeleteTree(root);
                        }else{
                        if(right){
                            pre->right = NULL;
                        }else{
                            pre->left = NULL;
                        }}
                        delete curr;
                        return;
                    }
                if(curr->left == NULL && curr->right != NULL){
                        if(curr == root){
                            root = curr->right;
                        }else{
                            if(right){
                                pre->right = curr->right;
                            }else{
                                pre->left = curr->right;
                            }
                        }
                        delete curr;
                        return;
                    }
                if(curr->left != NULL && curr->right == NULL){
                        if(curr == root){
                            root = curr->left;
                        }else{
                            if(right){
                                pre->right = curr->left;
                            }else{
                                pre->left = curr->left;
                            }
                        }
                        delete curr;
                        return;
                    }
                if(curr->left != NULL && curr->right != NULL){
                        save = searchMin(curr);
                        if(curr->left != save){
                            save->left = curr->left;
                        }
                        if(curr->right != save){
                            save->right = curr->right;
                        }
                        if(curr == root){
                            root = save;
                        }else{
                        if(right){
                            pre->right = save;
                        }else{
                            pre->left = save;
                        }}
                        delete curr;
                        return;
                    }
            }
            else{
                pre = curr;
                if(o <= curr->val){
                    curr = curr->left;
                    right = false;
                }else{
                    curr = curr->right;
                    right = true;
                }
            }
    }
}

void searchtree1::DeleteValueRecursive(object o){
    tree_element1* save = root;
    tree_element1* curr;
    if(root->val == o){
        if(save->left == NULL && save->right == NULL){
                        DeleteTree(root);
                    }
                if(save->left == NULL && save->right != NULL){
                        root = root->right;
                        delete save;
                    }
                if(save->left != NULL && save->right == NULL){
                        root = save->left;
                        delete save;
                    }
                if(save->left != NULL && save->right != NULL){
                        curr = searchMin(save);
                        if(save->left != curr){
                            curr->left = save->left;
                        }
                        if(save->right != curr){
                            curr->right = save->right;
                        }
                        root = curr;
                        delete save;
                    }

    }else{
        root->DeleteVal(o);
    }
}

tree_element1* tree_element1::DeleteVal(object o){
    tree_element1* save;
    tree_element1* curr;
            if (left != NULL && left->val == o){
                save = left;
                if(save->left == NULL && save->right == NULL){
                        left = NULL;
                        delete save;
                        return this;
                    }
                if(save->left == NULL && save->right != NULL){
                        left = save->right;
                        delete save;
                        return this;
                    }
                if(save->left != NULL && save->right == NULL){
                        left = save->left;
                        delete save;
                        return this;
                    }
                if(save->left != NULL && save->right != NULL){
                        curr = searchMin(save);
                        if(save->left != curr){
                            curr->left = save->left;
                        }
                        if(save->right != curr){
                            curr->right = save->right;
                        }
                        left = curr;
                        delete save;
                        return this;
                    }
            }else if (right != NULL && right->val == o){
                save = right;
                if(save->left == NULL && save->right == NULL){
                        right = NULL;
                        delete save;
                        return this;
                    }
                if(save->left == NULL && save->right != NULL){
                        right = save->right;
                        delete save;
                        return this;
                    }
                if(save->left != NULL && save->right == NULL){
                        right = save->left;
                        delete save;
                        return this;
                    }
                if(save->left != NULL && save->right != NULL){
                        curr = searchMin(save);
                        if(save->left != curr){
                            curr->left = save->left;
                        }
                        if(save->right != curr){
                            curr->right = save->right;
                        }
                        right = curr;
                        delete save;
                        return this;
                    }
            }else{
                if(o <= val && left != NULL){
                    left = left->DeleteVal(o);
                    return this;
                }else if(o > val && right != NULL){
                    right = right->DeleteVal(o);
                    return this;
                }
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
