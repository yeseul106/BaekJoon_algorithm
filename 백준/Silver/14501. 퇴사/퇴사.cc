#include <algorithm>
#include <iostream>
 
#define MAX 15+1
 
using namespace std;
 
// 전역 변수
int N;
// 0번은 쓰지 않는다.
int time_arr[MAX] = {0};
int profit_arr[MAX] = {0};
int max_val = 0 ;
 
void solve(int now_day, int now_sum, int added_num){
//    printf("solve(%d, %d, %d)\n",now_day,now_sum,added_num);
    // 현재 일수가 out of index 이면
    // 마지막에 수행한 결과가 완료 되었다면
    if(now_day == N + 1 ){
        max_val = max(max_val, now_sum);
        return ;
    } // 마지막에 수행한 결과가 완료 되지 않았다면
    else if (now_day > N + 1){
        max_val = max(max_val, now_sum-added_num);
        return ;
    }
    
    // 재귀 함수
    for ( int i = now_day + time_arr[now_day] ; i <= N + time_arr[now_day] ; i++)
        solve(i, now_sum + profit_arr[now_day] , profit_arr[now_day]);
    
}
 
int main(){
    cin >> N;
    // 정보 입력받기
    for ( int i = 1 ; i <= N; i++){
        cin >> time_arr[i]  >> profit_arr[i] ;
    }
    
    for ( int i = 1 ; i <= N ; i++)
        solve(i, 0, 0);
    
    cout << max_val;
    return 0;
}