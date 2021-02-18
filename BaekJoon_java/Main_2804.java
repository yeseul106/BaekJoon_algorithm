
/*
 * -문제: 창영이는 크로스워드 퍼즐을 만들려고 한다.
 *  두 단어 A와 B가 주어진다. A는 가로로 놓여야 하고, B는 세로로 놓여야 한다. 또, 두 단어는 서로 교차해야 한다.(정확히 한 글자를 공유해야 한다) 
 *  공유하는 글자는 A와 B에 동시에 포함되어 있는 글자여야 하고, 그런 글자가 여럿인 경우 A에서 제일 먼저 등장하는 글자를 선택한다. 
 *  마찬가지로 이 글자가 B에서도 여러 번 등장하면 B에서 제일 처음 나오는 것을 선택한다. 예를 들어, A = "ABBA"이고, B = "CCBB"라면, 아래와 같이 만들 수 있다.
 *  
 * -입력: 첫째 줄에 두 단어 A와 B가 주어진다. 두 단어는 30글자 이내이고, 공백으로 구분되어져 있다. 또, 대문자로만 이루어져 있고, 적어도 한 글자는 두 단어에 포함되어 있다.
 * -출력: A의 길이를 N, B의 길이를 M이라고 했을 때, 출력은 총 M줄이고, 각 줄에는 N개 문자가 있어야 한다. 문제 설명에 나온 것 같이 두 단어가 교차된 형태로 출력되어야 한다. 
 *       나머지 글자는 '.'로 출력한다.
 */
import java.util.Scanner;
import java.util.StringTokenizer;
import java.io.*;

public class Main_2804 {

	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(bf.readLine());
		String A = st.nextToken();
		String B = st.nextToken();

//		System.out.println(A);
//		System.out.println(B);
		
		int inxA = -1;
		int inxB = -1;

		//이중 for문을 이용하여 크로스 위치를 찾기
		//여기서 내가 몰랐던 부분!! 이중for문을 어떻게 빠져나갈 수 있을까? 
		//다음처럼 루프의 라벨을 정해주고 break 루프이름; 해주면 된다.
		loop1:
		for (int i = 0; i < A.length(); i++) {
			char tmp = A.charAt(i);
			loop2:
			for (int j = 0; j < B.length(); j++) {
				if (B.charAt(j) == tmp) {
					inxB = j;
					inxA = i;
					break loop1;
				}
			}
		}
//		System.out.println(inxA);
//		System.out.println(inxB);
		
		//출력하기
		for(int i=0; i<B.length();i++) {
			String result="";
			for(int j=0; j<A.length(); j++) {
				if(inxB==i) {
					result+=Character.toString(A.charAt(j));
				}
				else {
					if(inxA==j)
						result+=Character.toString(B.charAt(i));
					else
						result+='.';
				}
			}
			System.out.println(result);
		}
	}
}
