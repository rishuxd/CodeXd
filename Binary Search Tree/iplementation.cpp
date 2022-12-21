#include<iostream>
#include<queue>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root == NULL)
        return ;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node* root){
    if(root == NULL)
        return ;
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

// creating BST
// time complexity: O(logn)
Node* insertIntoBST(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(data > root->data){
        root->right = insertIntoBST(root->right, data);
    }
    else{
        root->left = insertIntoBST(root->left, data);
    }
}

// inputs for BST
void takeInput(Node* &root){
    int data;
    cin >> data;

    while(data != -1){
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

// searching in BST (recursive way)
// TC: O(logn) SC: O(logn)
bool searchInBST(Node* root, int data){
    if(root == NULL){
        return false;
    }
    if(root->data == data){
        return true;
    }
    if(root->data > data){
        return searchInBST(root->left, data);
    }
    else{
        return searchInBST(root->right, data);
    }
}

// searching in BST (iterative way)
// TC: O(logn) SC: O(1)
bool searchInBST1(Node* root, int data){
    Node* temp = root;
    while(temp != NULL){
        if(temp->data == data){
            return true; 
        }
        if(temp->data > data){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    return false;
}

// minimum in a BST
Node* minBST(Node* root){
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

// maximum in a BST
Node* maxBST(Node* root){
    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

// deletion from BST

Node* minVal(Node* root){

}

Node* deleteFromBST_copying(Node* root, int data){
    if(root == NULL){
        return root;
    }
    if(root->data == data){
        // 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // 1 child

        // left child
        if(root->left != NULL && root->right == NULL){
            Node*temp = root->left;
            delete root;
            return temp;
        }

        // right child
        if(root->right != NULL && root->left == NULL){
            Node*temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if(root->left != NULL & root->right != NULL){
            int min = minVal(root->right)->data;
            root->data = min;
            root->right = deleteFromBST_copying(root->right, min);
            return root;
        }
    }
    if(root->data > data){
        root->left = deleteFromBST_copying(root->left, data);
        return root;
    }
    else{
        root->right = deleteFromBST_copying(root->right, data);
        return root;
    }
}

// Morris transversal(In order hai ye , post & pre ke lie cout ka place change kar do)
void morrisTransversal(Node* p){
    Node* temp;
    while(p != NULL){
        if(p->left == NULL){
            cout<<p->data<<" ";
            p = p->right;
        }
        else{
            temp = p->left;
            while(temp->right != NULL && temp->right != p){
                temp = temp->right;
            }
            if(temp->right == NULL){
                temp->right = p;
                p = p->left;
            }
            else{
                temp->right = NULL;
                cout<<p->data<<" ";
                p=p->right;
            }
        }
    }
}

// preorder & successor

int main(){
    // input string: 10 2 21 7 27 5 4 3 -1
    Node* root = NULL;
    cout<<"Enter data to create BST : ";
    takeInput(root);
    cout<<"Printing the BST by BFS:"<<endl;
    levelOrderTraversal(root);

    cout<<"Morris Transveral: ";
    morrisTransversal(root);
    cout<<endl;

    cout<<"21 present in BST or not: "<<searchInBST(root, 21)<<endl;
    cout<<"91 present in BST or not: "<<searchInBST1(root, 91)<<endl;
    
    cout<<"Maximum of BST: "<<maxBST(root)->data<<endl;
    cout<<"Minimum of BST: "<<minBST(root)->data<<endl;

    deleteFromBST_copying(root, 21);
    deleteFromBST_copying(root, 3);
    cout<<"BST after deletion: "<<endl;
    levelOrderTraversal(root);

    return 0;
}