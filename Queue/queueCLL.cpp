#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        int value = this->data;
        cout << "Memory is free for the node with data " << value << " ." << endl;
    }
};

class Queue{
    public:
    Node* front;
    Node* back;

    Queue(){
        this->front = NULL;
        this->back = NULL;
    }

    void push(int data){
        Node* temp = new Node(data);
        if(front == NULL){
            front=temp; 
        }
        else{
            back->next=temp;
        }
        back=temp;
        back->next = front;
    }

    void pop(){
        if(front == NULL){
            cout<<"Queue Underflow"<<endl;
            return;
        }
        Node* nodetodel;
        if(front == back){
            nodetodel = front;
            front=NULL;
            back=NULL;
        }
        else{
            nodetodel = front;
            front = front->next;
            back->next= front;
        }
        free(nodetodel);
        return;
    }

    void peek(){
        if(front==NULL){
            cout<<"Queue Underflow\n";
            return;
        }
        cout<<front->data<<endl;
    }

    bool empty(){
        if(front==NULL){
            return true;
        }
        return false;
    }

    void display(){
        Node* temp = front;
        if(temp==NULL){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        do{
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp != front);
        cout<<endl;
    }
};

int main(){

    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    q.peek();
    q.pop();

    q.peek();
    q.pop();

    cout<<q.empty()<<endl;

    q.display();

    return 0;
}