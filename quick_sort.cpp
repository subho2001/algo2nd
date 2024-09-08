#include<iostream>
#include<cfloat>
using namespace std;

void quick_sort(float a[], int m, int n){
    if(m<n){
        float key = a[m];
        int i = m;
        int j = n+1;
        while(true){
            do{
                i = i+1;
            }while(a[i]<key);
            do{
                j= j-1;
            }while(a[j] > key);
            if(i<j){
                float temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }else{
                break;
            }
        }
         float temp = a[m];
                a[m] = a[j];
                a[j] = temp;
        quick_sort(a, m, j-1);
        quick_sort(a, j+1, n);
    }
}

int main(){
    cout<<"Enter array size : ";
    int n;
    cin>>n;
    float* a = new float[n];
    cout<<"Enter number : ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    quick_sort(a, 0, n-1);
    cout<<"Sorted Array: ";
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}