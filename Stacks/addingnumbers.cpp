#include<stack>
#include<iostream>
using namespace std;

stack<int> addnum(stack<int> s1, stack<int> s2){
    stack<int> res;
    int sum,rem = 0;
    while(!s1.empty() && !s2.empty()){
        sum = rem+s1.top()+s2.top();
        res.push(sum%10);
        rem = sum/10;
        s1.pop();
        s2.pop();
    }
    while(!s1.empty()){
        sum=rem+s1.top();
        res.push(sum%10);
        rem=sum/10;
        s1.pop();
    }
    while(!s2.empty()){
        sum=rem+s2.top();
        res.push(sum%10);
        rem=sum/10;
        s2.pop();
    }
    while(rem>0){
        res.push(rem);
        rem=rem/10;
    }
    while(!res.empty()){
        s1.push(res.top());
        res.pop();
    }
    res = s1;
    return s1;
}

void display(stack<int>& res)
{
    int N = res.size();
    string s = "";
    while (!res.empty()) {
        s = to_string(res.top()) + s;
        res.pop();
    }
     
  cout << s << endl;
}

int main(){
    stack<int> s1;
    s1.push(5);
    s1.push(8);
    s1.push(9);
    s1.push(1);

    stack<int> s2;
    s1.push(8);
    s1.push(3);
    s1.push(6);
    s1.push(1);
    s1.push(5);

    stack<int> res = addnum(s1, s2);
 
    display(res);
}