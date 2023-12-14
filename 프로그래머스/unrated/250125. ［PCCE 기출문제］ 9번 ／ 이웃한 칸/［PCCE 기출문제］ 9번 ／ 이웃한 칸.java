import java.util.*;

public class Solution {
    public int solution(String[][] board, int h, int w) {
        int answer = 0;
        String color = board[h][w];
        int[] dw = {0, 1, -1, 0};
        int[] dh = {1, 0, 0, -1};
        int n = board.length;

        for (int i = 0; i < 4; i++) {
            int h_check = h + dh[i];
            int w_check = w + dw[i];

            if (0 <= h_check && h_check < n && 0 <= w_check && w_check < n) {
                if (board[h_check][w_check].equals(color)) {
                    answer += 1;
                }
            }
        }

        return answer;
    }
}