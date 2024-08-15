import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

  static int N;
  static int M;
  static StringBuilder sb = new StringBuilder();
  static StringTokenizer st;
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static boolean[] isSelected = new boolean[8];
  static int[] combination = new int[8];

  static void makeCombination(int start, int depth) {
    if (depth == M) {
      for (int i = 0; i < M; i++) {
        sb.append(combination[i] + " ");
      }
      sb.append("\n");
    }

    for (int i = start; i <= N; i++) {
      combination[depth] = i;
      makeCombination(i + 1, depth + 1);
    }
  }


  public static void main(String[] args) throws IOException {
    st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    makeCombination(1, 0);

    System.out.println(sb.toString().trim());
  }
}