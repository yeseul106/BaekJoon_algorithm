import java.util.*;

public class Solution {
    public int solution(int n) {
        
        // 점프는 최소한 사용, 순간 이동은 최대한 사용하는 것이 키 포인트
        int ans = 0;
        while (n > 0) {
            if (n%2 == 0) {
                n/=2;
            } else {
                n-=1;
                ans++;
            }
        }
        
        return ans;
    }
}