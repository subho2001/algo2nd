#include<iostream>
using namespace std;

void insertion_sort(float a[], int n){
    for(int j=1; j<n; j++){
        float key = a[j];
        int i= j-1;
        while(i>=0 && key<a[i]){
            a[i+1] = a[i];
            i = i-1;
        }
        a[i+1] = key;
    }
}

int main(){
    int n;
    cout<<"Enter Your Array size: ";
    cin>>n;

    float a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    insertion_sort(a, n);
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}