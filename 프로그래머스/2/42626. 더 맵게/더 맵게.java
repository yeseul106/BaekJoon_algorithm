import java.util.*;

class Solution {
    
    private class Scoville implements Comparable<Scoville> {
        int score;
        
        public Scoville(int score) {
            this.score = score;
        }
        
        public int compareTo(Scoville scoville) {
            return this.score - scoville.score;
        }
        
    }
    
    
    public int solution(int[] scoville, int K) {
        int answer = 0;
        PriorityQueue<Scoville> pq = new PriorityQueue<>();
        
        for (int s : scoville) {
            Scoville sc = new Scoville(s);
            pq.add(sc);
        }
        
        // 맵지 않은 애부터 뽑아서 만들어야 함
        while (!pq.isEmpty()) {
            int first = pq.poll().score;
            // System.out.println("first : " + first);
            
            if (first >= K) {
                return answer;
            }
            
            if (pq.isEmpty()) {
                return -1;
            }
            
            int second = pq.poll().score;
            // System.out.println("second : " + second);
            Scoville newScoville = new Scoville(first + (second * 2));
            pq.add(newScoville);
            answer += 1;
        }
        
        return 0;
    }
}