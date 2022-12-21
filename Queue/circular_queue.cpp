#include <iostream>
using namespace std;

class Queue
{
    public:
    int size;
    int front;
    int rear;
    int *arr;

    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void enQueue(int element)
    {
        if ((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))){
            cout << "Queue is full." << endl;
        }
        if(front == -1){
            front = rear = 0; 
            arr[rear] = element;
        }
        else if(rear == (size-1) && front != 0){ 
            rear = 0;
            arr[rear] = element;
        }
        else{
            rear++;
            arr[rear] = element;
        }
    }
 
    int dequeue()
    {
        if (front == -1){
            cout << "Queue is empty." << endl;
            return -1;
        }
        int ans = arr[front];
        arr[front]=-1;

        if(front == rear){
            front = rear = -1;
        }
        else if( front == size-1){
            front = 0;
        }
        else{
            front++;
        }
        return ans;
    }
};

int main()
{
    Queue q1(3);

    q1.enQueue(1);
    q1.enQueue(12);
    q1.enQueue(266);

    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    
    return 0;
}
