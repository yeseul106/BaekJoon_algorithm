import java.util.*;

class Solution {
    public String solution(String s) {
        StringTokenizer st = new StringTokenizer(s);
        StringBuilder sb = new StringBuilder();
        
        ArrayList<Integer> numArr = new ArrayList<>();
        
        while(st.hasMoreTokens()) {
            numArr.add(Integer.parseInt(st.nextToken()));
        }
       
        Collections.sort(numArr);
        
        sb.append(numArr.get(0)).append(" ").append(numArr.get(numArr.size()-1));
        
        return sb.toString();
    }
}