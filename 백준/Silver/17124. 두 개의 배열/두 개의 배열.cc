#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int A[1000009],B[1000009];
int small(int le,int ri,int num){
    int mid = (le+ri)/2;
    if(B[mid] == num){return B[mid];}
    if(B[mid]<num){
        if(mid == ri){return B[mid];}
        else{return max(small(mid+1,ri,num),B[mid]);}
    }
    else{
        if(mid == le){return -1;}
        else{return small(le,mid-1,num);}
    }
}
int large(int le,int ri,int num){
    int mid = (le+ri)/2;
    if(B[mid] == num){return B[mid];}
    if(B[mid]>num){
        if(mid == le){return B[mid];}
        else{return min(large(le,mid-1,num),B[mid]);}
    }
    else{
        if(mid == ri){return 1000000000;}
        else{return large(mid+1,ri,num);}
    }    
}
int main(void){
    int T;
    cin >> T;
    for(int i = 0;i<T;i++){
        int N,M;
        cin >> N >> M;
        for(int j = 1;j<=N;j++){cin >> A[j];}
        for(int j = 1;j<=M;j++){cin >> B[j];}
        sort(B+1,B+M+1);
        long long result = 0;
        for(int j = 1;j<=N;j++){
            int s = small(1,M,A[j]);
            int l = large(1,M,A[j]);
            if(s == -1){s = B[1];}
            if(l == -1){l = B[M];}
            if(abs(A[j]-s) <= abs(l-A[j])){
                result += s;
            }
            else{result += l;}
        }
        cout << result <<"\n";
    }
}