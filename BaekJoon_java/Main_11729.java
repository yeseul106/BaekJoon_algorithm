/*
 * 하노이 탑 이동 순서
 * 
 * 세 개의 장대가 있고 첫 번째 장대에는 반경이 서로 다른 n개의 원판이 쌓여 있다. 각 원판은 반경이 큰 순서대로 쌓여있다. 이제 수도승들이 다음 규칙에 따라 첫 번째 장대에서 세 번째 장대로 옮기려 한다.
 * 
 * 1. 한 번에 한 개의 원판만을 다른 탑으로 옮길 수 있다.
 * 2. 쌓아 놓은 원판은 항상 위의 것이 아래의 것보다 작아야 한다.
 * 이 작업을 수행하는데 필요한 이동 순서를 출력하는 프로그램을 작성하라. 단, 이동 횟수는 최소가 되어야 한다.
 * 
 * 입력: 첫째 줄에 첫 번째 장대에 쌓인 원판의 개수 N (1 ≤ N ≤ 20)이 주어진다.
 * 
 * 출력: 첫째 줄에 옮긴 횟수 K를 출력한다.
 * 두 번째 줄부터 수행 과정을 출력한다. 두 번째 줄부터 K개의 줄에 걸쳐 두 정수 A B를 빈칸을 사이에 두고 출력하는데, 이는 A번째 탑의 가장 위에 있는 원판을 B번째 탑의 가장 위로 옮긴다는 뜻이다.
 */

/*
 * 재귀 함수를 이용하여 문제를 해결!
 *  
 *  1) n-1개의 원판을 3번을 거쳐 2번에 놓이게 하기
 *  2) n번쨰 원판을 3번으로 옮기기
 *  3) 2번에 있는 n-1개의 원판을 1번을 거쳐 3번에 놓이게 하기
 *  
 *  위 세가지 규칙을 가지고 해결할 수 있다.
 */

/*
 * 그냥 System.out.print로 계속해서 출력해줬더니 시간초과 뜬다...
 * StringBuilder 사용하기!
 * 객체.append하면 문자열이 계속해서 붙여진다!
 */

import java.util.*;
import java.io.*;
import java.lang.*;

public class Main_11729 {

	static StringBuilder sb = new StringBuilder();
	public static void hnoi(int n, int start, int mid, int end) {
		
		if (n == 1) {
			sb.append(start + " " + end+"\n");
			return;
		} else {
			hnoi(n - 1, start, end, mid);
			sb.append(start + " " + end+"\n");
			hnoi(n - 1, mid, start, end);
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n;
		n = Integer.parseInt(sc.nextLine());

		// 하노이탑에서 총 원판을 움직인 횟수는 공식이 있다!
		// p(n) = p(n-1) +1 + p(n-1)
		// p(n) = 2*p(n-1) +1
		// p(n) = 2의 n승 -1

		System.out.println((int) Math.pow(2, n) - 1);
		hnoi(n, 1, 2, 3);
		System.out.println(sb);

	}

}
