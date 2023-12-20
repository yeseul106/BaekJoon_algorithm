import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int T, W;
        T = sc.nextInt();
        W = sc.nextInt();

        int[][][] DP = new int[31][2][1001];
        int[] dropTree = new int[1001];

        for (int i = 1; i <= T; i++) {
            dropTree[i] = sc.nextInt();
        }

        // Initialize DP array
        for (int j = 0; j <= W; j++) {
            for (int i = 0; i < 2; i++) {
                for (int k = 1; k <= T; k++) {
                    DP[j][i][k] = -1;
                }
            }
        }

        // DP array creation
        for (int i = 0; i <= W; i++) {
            for (int j = 1; j <= T; j++) {

                if (i == 0) {
                    DP[i][0][j] = DP[i][0][j - 1] + (dropTree[j] == 1 ? 1 : 0);
                } else {
                    DP[i][0][j] = Math.max(DP[i][0][j - 1] + (dropTree[j] == 1 ? 1 : 0), DP[i - 1][1][j - 1] + (dropTree[j] == 1 ? 1 : 0));
                    DP[i][1][j] = Math.max(DP[i][1][j - 1] + (dropTree[j] == 2 ? 1 : 0), DP[i - 1][0][j - 1] + (dropTree[j] == 2 ? 1 : 0));
                }
            }
        }

        // Find the maximum value
        int result = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j <= W; j++) {
                result = Math.max(result, DP[j][i][T]);
            }
        }

        System.out.println(result);
    }
}
