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
        if (this->next != NULL){
            delete next;
            next = NULL;
        }
        cout << "Memory is free for the node with data " << value << " ." << endl;
    }
};

// insert at any position
void insertNode(Node *&head, int element, int data)
{
    Node *nodeToInsert = new Node(data);
    // empty list
    if (head == NULL){
        head = nodeToInsert;
        nodeToInsert->next = nodeToInsert;
    }
    else{
        // non-empty list
        Node *curr = head;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        // ----------------------------
        nodeToInsert->next = curr->next;
        curr->next = nodeToInsert;
    }
}

// delete node
void deleteNode(Node *&head, int element){
    // empty list
    if (head == NULL){
        cout << "List is already empty." << endl;
        return;
    }
    else{
        // non-empty list
        Node *prev = head;
        Node *curr = prev->next;
        while (curr->data != element){
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        // single element list
        if (curr == prev){
            head = NULL;
        }
        // >= 2 node list
        if (head == curr){
            head = prev;
        }

        curr->next = NULL;
        delete curr;
    }
}

// printing Linked List
void print(Node *&head){
    Node *temp = head;
    if (temp == NULL){
        cout << "Linked List is empty." << endl;
        return;
    }
    do{
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main(){
    
    Node *head = NULL;
    insertNode(head, 5, 3);
    print(head);
    cout << "Data at head : " << head->data << endl;
    insertNode(head, 3, 46);
    print(head);
    cout << "Data at head : " << head->data << endl;
    insertNode(head, 46, 100);
    print(head);
    cout << "Data at head : " << head->data << endl;
    insertNode(head, 46, 84);
    print(head);
    cout << "Data at head : " << head->data << endl;
    insertNode(head, 46, 84);
    print(head);
    cout << "Data at head : " << head->data << endl;
    deleteNode(head, 3);
    print(head);
    cout << "Data at head : " << head->data << endl;
}