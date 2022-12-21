#include<iostream>
using namespace std;

class UpperTri{
    int * arr;
    int n;

    UpperTri(int size){
        this->n = size;
        arr = new int[n*(n+1)/2];
    }

    ~UpperTri(){
        delete []arr;
    }

    void store(int x, int i, int j){
        if(i<1 || j<1 || i>n || j>n){
            cout<<"Index out of bound."<<endl;
            exit(0);
        }
        else if(i<=j){
            int h = (n*(n+1)/2)-(j*(j-1)/2)+i-j;
            arr[h] = x;
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
        else if(i>j){
            return 0;
        }
        else{
            int h = (n*(n+1)/2)-(j*(j-1)/2)+i-j;
            return arr[h];
        }
    }

    void display(){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if (i>j){
                    cout<<"0 ";
                }
                else{
                    int h = (n*(n+1)/2)-(j*(j-1)/2)+i-j;
                    cout<<arr[h]<<" ";
                }
            }
            cout<<endl;
        }
    }
};