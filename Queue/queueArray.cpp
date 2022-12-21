#include <iostream>
using namespace std;

class Queue
{
    int size;
    int qfront;
    int rear;
    int *arr;

public:
    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    // push function
    void enQueue(int element)
    {
        if (rear == size)
        {
            cout << "Queue is full." << endl;
        }
        else
        {
            arr[rear] = element;
            rear++;
        }
    }
    // pop funtion
    int dequeue()
    {
        if (qfront == rear)
        {
            cout << "Queue is empty." << endl;
            return -1;
        }
        else
        {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if (qfront == rear)
            {
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }
    // qfront function
    int qFront()
    {
        if (qfront == rear)
        {
            cout << "Queue is empty." << endl;
            return -1;
        }
        else
        {
            return arr[qfront];
        }
    }
    bool isEmpty()
    {
        if (qfront == rear)
        {
            cout << "Queue is empty." << endl;
            return true;
        }
        else
        {
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

    cout<<q1.qFront()<<endl;;
    q1.dequeue();
    
    cout<<q1.qFront()<<endl;;
    q1.dequeue();
    
    cout<<q1.qFront()<<endl;;
    q1.dequeue();

    cout << q1.isEmpty() << endl;
    
    return 0;
}
