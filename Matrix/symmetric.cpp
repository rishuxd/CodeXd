#include<iostream>
using namespace std;

class Symmetric{
    public:
    int * arr;
    int n;

    Symmetric(int size){
        this->n = size;
        arr = new int[n*(n+1)/2];
    }

    ~Symmetric(){
        delete []arr;
    }

    void store(int x, int i, int j){
        if(i<1 || j<1 || i>n || j>n){
            cout<<"Index out of bound."<<endl;
            exit(0);
        }
        else
            arr[i*(i-1)/2 + j-1] = x;
    }

    int retrieve(int i, int j){
        if(i<1 || j<1 || i>n || j>n){
            cout<<"Index out of bound."<<endl;
            exit(0);
        }
        else
            return arr[i*(i-1)/2 + j-1];
    }

    void display(){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++)
                cout<<arr[i*(i-1)/2+j-1]<<" ";
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
    
    Symmetric obj(m1);

    cout<<"\nEnter the elements of Symmetric matrix: "<<endl;
    for (int i=1; i<=m1; i++){
        for (int j = 1; j <=m1; j++){
            cout<<"\nEnter element at position "<<i<<", "<<j<<": ";
            cin>>y;
            obj.store(y,i,j);
        }
    }

    cout<<"\nThe Symmetric matrix is: "<<endl;
    obj.display();

    cout<<"\nEnter location to retrieve: ";
    cin>>i>>j;
    cout<<"\nElement retrieved: "<<obj.retrieve(i,j)<<endl;
    
    return 0;
}