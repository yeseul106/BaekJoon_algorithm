class Solution {
    public int solution(int n) {
        int answer = 0;
        
        for (int a = 1; a <= n; a++) {
            int sum = 0;
            for (int k = 0; k <= n - a; k++) {
                sum += (a + k);
                if (sum > n) break;
                if (sum == n) answer++;
            }
        }
        return answer;
    }
}