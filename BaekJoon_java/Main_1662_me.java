/*
 * -문제: 압축되지 않은 문자열 S가 주어졌을 때, 이 문자열중 어떤 부분 문자열은 K(Q)와 같이 압축 할 수 있다. K는 한자리 정수이고, Q는 0자리 이상의 문자열이다.
 *  이 Q라는 문자열이 K번 반복된다는 뜻이다. 압축된 문자열이 주어졌을 때, 이 문자열을 다시 압축을 푸는 프로그램을 작성하시오.
 *  
 * -입력: 첫째 줄에 압축된 문자열 S가 들어온다. S의 길이는 최대 50이다. 문자열은 (, ), 0-9사이의 숫자로만 들어온다.
 * 
 * -출력: 첫째 줄에 압축되지 않은 문자열의 길이를 출력한다. 이 값은 int범위다.
 */

/*
 * 문자열을 쭉 탐색하면서 괄호 안에 문자를 계속해서 압축을 풀어야하므로 스택을 이용해야겠다는 생각이 먼저 들었다.
 * 
 * 1) 먼저 스택을 사용하여 괄호 쌍을 묶어야한다. 문자열에서 '('이 나오면 스택에 그 인덱스를 저장.
 * 2) 괄호쌍을 알아야한다. ')'가 나오면 앞에 '('와 짝을 지어야 하므로 배열하나를 만들어서 ')'가 나오면 그와 쌍이 되는 '('의 인덱스를 저장해두기
 * 3) 재귀함수를 이용해서 괄호를 풀기. 안쪽 괄호부터 글자수를 세야한다.
 */

import java.util.*;
import java.io.*;
import java.util.Scanner;
import java.util.Stack;

public class Main_1662 {

	static String input;
	static int pair[] = new int[51]; // 괄호 쌍을 저장할 배열

	public static int count(int start, int end) {
		int result = 0;

		for (int i = start; i < end; i++) {
			if (input.charAt(i) == '(') {
				int n = input.charAt(i - 1) - '0';
				result += n * count(i+1, pair[i]) - 1; //1을 빼주는 이유는 앞에 곱해지는 n까지 셌기 때문이다
				i = pair[i]; //중요!! 괄호 안에 글자수는 이미 재귀함수를 통해 계산했으므로 괄호 이후부터 이어서 탐색해야함
			} else
				result++;
		}
		return result;
	}

	public static void main(String[] args) throws IOException {
		Stack<Integer> stack= new Stack<Integer>(); // 인덱스를 저장하므로 타입을 Integer로 지정해주기
		
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		input = bf.readLine();

		for (int i = 0; i < input.length(); i++) {

			if (input.charAt(i) == '(')
				stack.push(i);

			else if (input.charAt(i) == ')')
				pair[stack.pop()] = i; // 가장 뒤에 나온 '('의 인덱스의 쌍이므로 스택에서 꺼내기
		}
		System.out.print(count(0, input.length()));
	}
}