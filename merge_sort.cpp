#include<iostream>
#include<cfloat>
using namespace std;

void merge(float a[], int p, int q, int r){
    int n1 = q-p+1;
    int n2 = r-q;
    float L[n1+1]; 
    float R[n2+1]; 
    for(int i=0; i<n1; i++){
        L[i] = a[p+i];
    }
    for(int j =0; j<n2; j++){
        R[j] = a[q+1+j];
    }
    L[n1] = R[n2] = FLT_MAX;
    int i=0, j=0;
    for(int k=p; k<=r; k++){
        if(L[i]<= R[j]){
            a[k] = L[i];
            i++;
        }
        else{
            a[k] = R[j];
            j++;
        }
    }
}

void merge_sort(float a[], int p, int r){
    if(p<r){
        int q = (p+r)/2;
        merge_sort(a, p, q);
        merge_sort(a, q+1, r);
        merge(a, p, q, r);
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
    merge_sort(a, 0, n-1);
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}