/*
3. Write a program to implement singly linked list which supports the following operations: 
(i) Insert an element x at the beginning of the singly linked list 
(ii) Insert an element x at position in the singly linked list 
(iii)Remove an element from the beginning of the singly linked list 
(iv) Remove an element from position in the singly linked list. 
(v) Search for an element x in the singly linked list and return its pointer 
(vi) Concatenate two singly linked lists
*/

#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node * next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
    cout<<"Memory is free for the node with data "<<value<<" ."<<endl;
    }
};

// (i) Insert an element x at the beginning of the singly linked list
void insertAtHead(Node* &head, Node* &tail, int data){
    Node* temp = new Node(data);
    if (head == NULL){
        head = temp;
        tail = temp;
    }
    else{
        temp->next = head;
        head = temp;    
    }
}

// (ii) Insert an element x at position in the singly linked list 

void insertAtPosition(Node* head,Node* tail, int data, int position){
    Node* temp = head;
    int count = 1;
    while(count < position-1){
        temp = temp->next;
        count++;
    }
    if(head == NULL){
        insertAtHead(head, tail, data);
        return;
    }
    if (temp->next == NULL){
        insertAtTail  
    }
    

}

int main(int argc, char const *argv[])
{
    Node* head = NULL;
    Node* tail = NULL;

    return 0;
}
