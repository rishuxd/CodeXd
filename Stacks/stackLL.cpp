#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }

    ~Node(){
        int value = this->data;
        cout << "Memory is free for the node with data " << value << " ." << endl;
    }
};

class Stack{
    public:
    Node* top;

    Stack(){
        this->top = NULL;
    }

    void push(int data){
        Node* temp = new Node(data);
        if(top == NULL){
            top = temp;
            return;
        }
        Node* curr = top;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = temp;
    }

    void pop(){
        if(top == NULL){
            cout<<"Stack Underflow.\n";
            return;
        }
        Node* curr = top;
        Node* temp = curr->next;
        while(temp->next != NULL){
            temp=temp->next;
            curr=curr->next;
        }
        curr->next=NULL;
        free(temp);
    }

    void display(){
        Node* temp = top;
        if(top ==  NULL){
            cout<<"Stack Underflow.\n";
            return;
        }
        while(temp!= NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }cout<<"NULL\n";
    }
};

int main(){
    Stack s;
    s.push(11);
    s.push(42);
    s.push(83);
    s.push(14);
    s.display();
    s.pop();
    s.display();
}