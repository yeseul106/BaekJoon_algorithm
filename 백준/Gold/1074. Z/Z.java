import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

  static int N, r, c, size;
  static int count;
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static StringTokenizer st;

  static void calCount(int size, int r, int c) {
    if (size == 1) { // 더 이상 쪼갤 수 없을 정도로 왔을 때 종료
      return;
    }

    // 1사분면에 있을 때
    if (r < size / 2 && c < size / 2) {
      calCount(size / 2, r, c);
    }
    // 2사분면
    else if (r < size / 2 && c >= size / 2) {
      count += (size * size) / 4; // 1사분면 크기만큼
      calCount(size / 2, r, c - size / 2); // 상대 좌표
    }
    // 3사분면
    else if (r >= size / 2 && c < size / 2) {
      count += (size * size) / 4 * 2; // 1사분면 + 2사분면 크기만큼
      calCount(size / 2, r - size / 2, c); // 상대 좌표
    }
    // 4사분면
    else if (r >= size / 2 && c >= size / 2) {
      count += (size * size) / 4 * 3; // 1 + 2 + 3사분면 크기만큼
      calCount(size / 2, r - size / 2, c - size / 2); // 상대 좌표
    }

  }

  public static void main(String[] args) throws IOException {
    st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());
    r = Integer.parseInt(st.nextToken());
    c = Integer.parseInt(st.nextToken());
    size = (int) Math.pow(2, N); // 사각형 한 변의 길이

    calCount(size, r, c);

    System.out.println(count);

  }

}