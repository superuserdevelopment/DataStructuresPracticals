#include<iostream>
#include<conio.h>
using namespace std;

void mergeSorted(int a[], int b[], int la, int lb){
    int c[la+lb];
    int i=0;
    int ap=0, bp=0;
    while(i<la+lb){
        if(a[ap]<b[bp] && ap<la){
            c[i] = a[ap];
            ap++;
            i++;
            continue;
        }
        else if(b[ap]<a[bp] && ap<la){
            c[i] = b[bp];
            bp++;
            i++;
            continue;
        }
        else if(ap<la && bp>=lb){
            c[i] = a[ap];
            ap++;
            i++;
            continue;
        }
        else if(ap>=la && bp<lb){
            c[i] = b[bp];
            bp++;
            i++;
            continue;
        }
    }
    for(int i=0;i<12;i++){
        cout<<c[i]<<" ";
    }
}
void display(int a[], int l){
    int i;
    for(i=0;i<l;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int a[] = {10,20,30,40,50};
    int b[] = {60, 70, 80, 90, 100, 110, 120};
    display(a,5);
    display(b,7);
    mergeSorted(a,b,5,7);
    return 0;
}
