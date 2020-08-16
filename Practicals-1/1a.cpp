#include<iostream>
#include<conio.h>
//1. Write a C++ program to store the elements in 1-D array and perform the operations like searching, sorting and reversing the elements. [Menu Driven]
using namespace std;
void display(int a[], int l){
    int i;
    for(i=0;i<l;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void searchArray(int a[], int l, int e){
    int i;
    for(i=0;i<l;i++){
        if(a[i] == e){
            cout<<e<<" Found at "<<i<<endl;
            break;
        }
    }
    if(i==l){
        cout<<"Element not present in the array"<<endl;
    }
}
void sortArray(int a[], int l){
    int i,j;
    for(i=0;i<l-1;i++){
        bool sorted = true;
        for(j=0;j<l-i-1;j++){
            if(a[j]>a[j+1]){
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                sorted = false;
            }
        }
        if(sorted){
            break;
        }
    }
}
void reverseArray(int a[], int l){
    int i;
    int b[l];
    for(i=0;i<l;i++){
        b[i] = a[i];
    }
    for(i=l-1;i>=0;i--){
        a[l-i-1] = b[i];
    }

}
int main(){
   int a[] = {10, 20, 50, 40, 30};
   int l = 5, c;
    cout<<"The Array is: ";
   display(a,l);
   cout<<endl<<"Select your choice"<<endl;
   cout<<"1. Search the array"<<endl;
   cout<<"2. Sort the array"<<endl;
   cout<<"3. Reverse the array"<<endl;
   cin>>c;
   cout<<endl;
   switch(c){
case 1:
    cout<<"Enter the element to be searched"<<endl;
    int e;
    cin>>e;
    searchArray(a, l, e);
    break;
case 2:
    cout<<"Sorted Array is: ";
    sortArray(a,l);
    display(a,l);
    break;
case 3:
    cout<<"Reversed Array is: ";
    reverseArray(a,l);
    display(a,l);
    break;
default:
    cout<<"Invalid Choice"<<endl;
   }
   return 0;
}

