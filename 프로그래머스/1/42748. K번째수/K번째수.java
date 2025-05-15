import java.util.*;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int size = commands.length;
        int[] answer = new int[size];
        
        for (int a = 0; a < size; a++) {
            int[] command = commands[a];
            int i = command[0] - 1;
            int j = command[1] - 1;
            int k = command[2] - 1;
            
            ArrayList<Integer> tmp = new ArrayList<>();
            for (int idx = i; idx <= j; idx++) {
                tmp.add(array[idx]);
            }
            Collections.sort(tmp);
            answer[a] = tmp.get(k);
        }
        
        return answer;
    }
}