#include<iostream>
using namespace std;

void selection_sort(float a[], int n){
    for(int i=0; i<n-1; i++){
        int j=i;
        for(int k = j+1; k<n; k++){
            if(a[k]<a[j]){
                j=k;
            }
        }
        if(i != j){
            float tmp = a[i];
            a[i]= a[j];
            a[j]= tmp;
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
    selection_sort(a, n);
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}