/*
 * 
 * 문제: 주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.
 * 
 * 입력: 첫 줄에 수의 개수 N이 주어진다. N은 100이하이다. 다음으로 N개의 수가 주어지는데 수는 1,000 이하의 자연수이다.
 * 출력: 주어진 수들 중 소수의 개수를 출력한다.
 */


/*
 * 여기서 새롭게 알게 된 사실!!!
 * Scanner 객체로 첫줄 N을 받고 뒤에 숫자 배열은 BufferedReader로 받아서 StringToknizer로 분해하려고 했지만
 * 두 객체를 동시에 써서 입력을 받으면 런타임에러(NullPointerException)가 난다는 것을 알았다!
 * 
 * 그래서 다음과 같이 Scanner 만을 이용하여 입력을 받게 고쳤더니 문제 없이 통과했다
 */
import java.util.*;
import java.io.*;

public class Main_1978 {

	public static void main(String[] args) throws IOException {
		Scanner scanner = new Scanner(System.in);
		int N = Integer.parseInt(scanner.nextLine());

		String S = scanner.nextLine();
		StringTokenizer st = new StringTokenizer(S);
		int count = 0;

		for (int i = 0; i < N; i++) {
			int k = Integer.parseInt(st.nextToken());

			if(k==1) {
				count++;
				continue;
			}
			
			for (int j = 2; j < k; j++) {
				if (k % j == 0) {
					count++;
					break;
				}
			}
		}

		System.out.print(N-count);
		scanner.close();

	}
	

}
