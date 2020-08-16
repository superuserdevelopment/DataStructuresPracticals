#include<iostream>
#include<conio.h>
using namespace std;
 int** add(int **a, int **b, int m, int n){
    int **c = new int*[m];
    int i,j;
    for(i=0;i<m;i++){
        c[i] = new int[n];
        for(j=0;j<n;j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    return c;
 }
 int** transpose(int **a,int m, int n){
    int **c = new int *[n];
    int r=0,col=0;
    for(int i=0;i<n;i++){
        c[i] = new int[m];
        r = 0;
        for(int j=0;j<m;j++){
            c[i][j] = a[r][col];
            r++;
        }
        col++;
    }
    return c;
 }

int** multiply(int **a, int **b, int m1, int n1, int n2){
    int **c = new int*[m1];
    for(int i=0;i<m1;i++){
        c[i] = new int[n2];
        for(int j=0;j<n2;j++){
            c[i][j] = 0;
            for(int k=0;k<n1;k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}
int** read(int m,int n,char ch){
    cout<<"Enter the Matrix-"<<ch<<endl;
    int **A = new int*[m];
    for(int i=0;i<m;i++){
        A[i] = new int[n];
        for(int j=0;j<n;j++){
            cin>>A[i][j];
        }
    }
    return A;
 }
 void display(int **a, int m, int n, char ch){
    int i, j;
    cout<<"Matrix-"<<ch<<endl;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
 }
 int main(){
    cout<<endl<<"Select your choice"<<endl;
   cout<<"1. Matrix Addition"<<endl;
   cout<<"2. Matrix Transpose"<<endl;
   cout<<"3. Matrix Multiplication"<<endl;
   int choice;
   int m,n;
   cin>>choice;
   cout<<endl;
   if(choice == 1){
    cout<<"Enter the order of the matrix"<<endl;

     cin>>m>>n;
    int **a = read(m,n,'A');
    int **b = read(m,n,'B');
    int **c = add(a,b,m,n);
    display(c,m,n,'C');
   }
else if(choice == 2){
    cout<<"Enter the order of the matrix"<<endl;
     cin>>m>>n;
    int **a = read(m,n,'A');
    int **c = transpose(a,m,n);
    display(c,n,m,'C');
}
else if(choice == 3){
    cout<<"Enter the order of the matrix A"<<endl;
     int m1,n1;
     cin>>m1>>n1;
     cout<<"Enter the order of the matrix B"<<endl;
     int m2,n2;
     cin>>m2>>n2;
     if(n1 == m2){
        int **a = read(m1,n1,'A');
    int **b = read(m2,n2,'B');
    int **c = multiply(a,b,m1,n1,n2);
    display(c,m1,n2,'C');
     }
     else{
        cout<<"Invalid Dimensions"<<endl;
     }
}
else{
    cout<<"Invalid Choice"<<endl;
   }
 }
