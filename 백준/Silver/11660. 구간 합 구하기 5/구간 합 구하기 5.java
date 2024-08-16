import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

  static int[][] numArr;
  static int[][] prefixSum;
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static StringTokenizer st;
  static StringBuilder sb = new StringBuilder();
  static int N, M;
  static int x1, x2, y1, y2;

  static void getCumulativeSum() {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        prefixSum[i][j] = numArr[i-1][j-1] + prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1];
      }
    }
  }


  public static void main(String[] args) throws IOException {
    st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    numArr = new int[N][N];
    prefixSum = new int[N + 1][N + 1];  // (N+1) x (N+1) 크기의 누적합 배열

    for (int i = 0; i < N; i++) {
      st = new StringTokenizer(br.readLine());
      for (int j = 0; j < N; j++) {
        numArr[i][j] = Integer.parseInt(st.nextToken());
      }
    }

    getCumulativeSum();

    for (int i = 0; i < M; i++) {
      st = new StringTokenizer(br.readLine());
      x1 = Integer.parseInt(st.nextToken());
      y1 = Integer.parseInt(st.nextToken());
      x2 = Integer.parseInt(st.nextToken());
      y2 = Integer.parseInt(st.nextToken());

      int result = prefixSum[x2][y2] - prefixSum[x1-1][y2] - prefixSum[x2][y1-1] + prefixSum[x1-1][y1-1];
      sb.append(result + "\n");
    }

    System.out.println(sb.toString().trim());
  }
}