import java.util.*;

class Solution {
    public int solution(int n) {
        int answer = 0;
        String nToBinaryNum = Integer.toBinaryString(n);
        
        for (int i = n + 1; i < Integer.MAX_VALUE; i++) {
            String iToBinaryNum = Integer.toBinaryString(i);
            
            int oneInN = nToBinaryNum.length() 
                - nToBinaryNum.replace("1","").length();
            
            int oneInI = iToBinaryNum.length() 
                - iToBinaryNum.replace("1","").length();
            
            if (oneInN == oneInI) {
                answer = i;
                break;
            }
                
        }
        
        return answer;
    }
}