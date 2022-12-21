#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* child;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->child = NULL;
    }
};

Node *merge(Node *left, Node *right)
{
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    Node *ans = new Node(-1);
    Node *temp = ans;

    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->child = left;
            temp = left;
            left = left->child;
        }
        else
        {
            temp->child = right;
            temp = right;
            right = right->child;
        }
    }
    while (left != NULL)
    {
        temp->child = left;
        temp = left;
        left = left->child;
    }
    while (right != NULL)
    {
        temp->child = right;
        temp = right;
        right = right->child;
    }
    ans = ans->child;
    return ans;
}

Node *flattenLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *down = head;
    Node *right = flattenLinkedList(head->next);
    down->next = NULL;
    head = merge(down, right);
    return head;
}
