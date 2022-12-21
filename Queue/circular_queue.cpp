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
        else if(front == -1){
            front = rear = 0; 
            arr[rear] = element;
            rear++;
        }
        else if( rear == (size-1) && front =! 0){
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
        if (front == rear){
            cout << "Queue is empty." << endl;
            return -1;
        }
        else{
            int ans = arr[front];
            arr[front] = -1;
            front++;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int peek(){
        if (front == rear){
            cout << "Queue is empty." << endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }

    bool isEmpty(){
        if (front == rear){
            cout << "Queue is empty." << endl;
            return true;
        }
        else{
            cout << "Queue isn't full." << endl;
            return false;
        }
    }
};

int main()
{
    Queue q1(3);

    q1.enQueue(1);
    q1.enQueue(12);
    q1.enQueue(266);

    cout<<q1.peek()<<endl;;
    q1.dequeue();
    
    cout<<q1.peek()<<endl;;
    q1.dequeue();
    
    cout<<q1.peek()<<endl;;
    q1.dequeue();

    cout << q1.isEmpty() << endl;
    
    return 0;
}
