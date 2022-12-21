#include<iostream>
#include<queue>
using namespace std;

int main(int argc, char const *argv[])
{
    queue<int> q;
    q.push(2);
    cout<<q.front()<<endl;
    q.push(5);
    q.push(6);
    
    return 0;
}
