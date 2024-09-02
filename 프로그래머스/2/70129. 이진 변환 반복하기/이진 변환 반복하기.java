class Solution {
    public int[] solution(String s) {
        int[] answer = new int[2];
        int cnt = 0;
        int zeroCnt = 0;
        
        while (true) {
            if (s.equals("1"))
                break;
            String newStr = "";
            
            for (int i =0; i<s.length(); i++) {
                if (s.charAt(i) == '0') {
                    zeroCnt++;
                    continue;
                }
                newStr += (s.charAt(i));
            }
            
            int quotient = newStr.length();
            StringBuilder sb = new StringBuilder();
            
            while (quotient > 0) {
                int remainder = quotient % 2;
                sb.append(remainder);
                quotient = quotient / 2;
            }
            s = sb.reverse().toString();
            cnt++;
        }
        
        answer[0] = cnt;
        answer[1] = zeroCnt;
        
        return answer;
    }
}