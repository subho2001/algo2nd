#include<iostream>
using namespace std;

void bubble_sort(float a[], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(a[j] > a[j+1]){
                float tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
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
    bubble_sort(a, n);
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}