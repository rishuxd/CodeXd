#include<iostream>
using namespace std;

class LowerTri{
    int * arr;
    int n;

    LowerTri(int size){
        this->n = size;
        arr = new int[n*(n+1)/2];
    }

    ~LowerTri(){
        delete []arr;
    }

    void store(int x, int i, int j){
        if(i<1 || j<1 || i>n || j>n){
            cout<<"Index out of bound."<<endl;
            exit(0);
        }
        else if(i>=j){
            arr[i*(i-1)/2 + j-1] = x;
        }
        else if(x!=0){
            cout<<"Element must be zero."<<endl;
        }
    }

    int retrieve(int i, int j){
        if(i<1 || j<1 || i>n || j>n){
            cout<<"Index out of bound."<<endl;
            exit(0);
        }
        else if(i<j){
            return 0;
        }
        else{
            return arr[i*(i-1)/2 + j-1];
        }
    }

    void display(){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if (i<j){
                    cout<<"0 ";
                }
                else{
                    cout<<arr[i*(i-1)/2+j-1]<<" ";
                }
            }
            cout<<endl;
        }
    }
};