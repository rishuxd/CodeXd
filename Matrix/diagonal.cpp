#include<iostream>
using namespace std;

class Diagonal{
    public:
    int n;
    int * arr;

    Diagonal(int size){
        this->n = size;
        this->arr = new int[size];
    }

    ~Diagonal(){
        delete []this->arr;
    }

    void store(int x, int i, int j){
        if(i<1 || j<1 || i>n || j>n){
            cout<<"Index out of bound."<<endl;
        }
        else if ((i>j || j>i) && x!=0){
            cout<<"Element should be zero."<<endl;
        }
        else if (i==j){
            arr[i]=x;
        }
    }

    int retrieve(int i, int j){
        if(i<1 || j<1 || i>n || j>n){
            cout<<"Index out of bound."<<endl;
            exit(0);
        }
        else if (i==j){
            return arr[i];
        }
        else
            return 0;
    }

    void display(){
        for (int i = 1; i <=n; i++){
            for (int j = 1; j <=n; j++){
                if(i == j){
                    cout<<arr[i]<<" ";
                }
                else
                    cout<<"0 ";
            }
            cout<<endl;
        }
    }
};

int main(){
    int m1=0,m2=0,y=0,i=0,j=0;
    cout<<"\nEnter no. of rows and columns: ";
    cin>>m1>>m2;
    if(m1 != m2){
        cout<<"Invalid size."<<endl;
        exit(0);
    }
    
    Diagonal obj(m1);

    cout<<"\nEnter the elements of diagonal matrix: "<<endl;
    for (int i=1, j=1; i<=m1,j<=m1; i++,j++)
    {
        cout<<"\nEnter element at position "<<i<<", "<<j<<": ";
        cin>>y;
        obj.store(y,i,j);
    }

    cout<<"The diagonal matrix is: "<<endl;
    obj.display();

    cout<<"Enter location to retrieve: ";
    cin>>i>>j;
    cout<<"Element retrieved: "<<obj.retrieve(i,j)<<endl;
    
}