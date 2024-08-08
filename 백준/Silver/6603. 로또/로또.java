import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

  static ArrayList<Integer> totalArr;
  static ArrayList<Integer> result;
  static ArrayList<Boolean> visited;
  static int K;
  static final int LOTTO_LENGTH = 6;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    while (true) {
      StringTokenizer st = new StringTokenizer(br.readLine());
      K = Integer.parseInt(st.nextToken());
      totalArr = new ArrayList<>();
      result = new ArrayList<>();
      visited = new ArrayList<>();

      if (K == 0) break;

      for (int i = 0; i < K; i++) {
        totalArr.add(Integer.parseInt(st.nextToken()));
        result.add(0);
        visited.add(false);
      }

      BackTracking(0,0);
      System.out.println();
    }
  }

  private static void BackTracking(int start, int depth) {
    if (depth == LOTTO_LENGTH) {
      for (int i=0; i<LOTTO_LENGTH; i++) {
        System.out.print(result.get(i) + " ");
      }
      System.out.println();
      return;
    }

    for (int i = start; i < K; i++) {
      if (!visited.get(i)) {
        visited.set(i, true);
        result.set(depth, totalArr.get(i));
        BackTracking(i+1, depth+1);
        visited.set(i, false);
      }
    }
  }

}
