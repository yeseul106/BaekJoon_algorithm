import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

  static int[] numbers;
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static StringTokenizer st;
  static StringBuilder sb = new StringBuilder();

  static int getCumulativeSum(int start, int end) {
    return numbers[end] - numbers[start - 1];
  }

  public static void main(String[] args) throws IOException {
    st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int M = Integer.parseInt(st.nextToken());

    numbers = new int[N + 1];
    numbers[0] = 0;
    st = new StringTokenizer(br.readLine());

    for (int i = 1; i <= N; i++) {
      numbers[i] = numbers[i - 1] + Integer.parseInt(st.nextToken());
    }

    for (int i = 0; i < M; i++) {
      st = new StringTokenizer(br.readLine());
      int start = Integer.parseInt(st.nextToken());
      int end = Integer.parseInt(st.nextToken());

      int result = getCumulativeSum(start, end);
      sb.append(result + "\n");
    }

    System.out.println(sb.toString().trim());
  }

}