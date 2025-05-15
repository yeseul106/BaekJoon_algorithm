import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for (int s : scoville) {
            pq.add(s);
        }
        
        // 맵지 않은 애부터 뽑아서 만들어야 함
        while (!pq.isEmpty()) {
            int first = pq.poll();
            // System.out.println("first : " + first);
            
            if (first >= K) {
                return answer;
            }
            
            if (pq.isEmpty()) {
                return -1;
            }
            
            int second = pq.poll();
            // System.out.println("second : " + second);
            int newScoville = first + (second * 2);
            pq.add(newScoville);
            answer += 1;
        }
        
        return answer;
    }
}