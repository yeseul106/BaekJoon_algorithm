/*
 * -문제: 압축되지 않은 문자열 S가 주어졌을 때, 이 문자열중 어떤 부분 문자열은 K(Q)와 같이 압축 할 수 있다. K는 한자리 정수이고, Q는 0자리 이상의 문자열이다.
 *  이 Q라는 문자열이 K번 반복된다는 뜻이다. 압축된 문자열이 주어졌을 때, 이 문자열을 다시 압축을 푸는 프로그램을 작성하시오.
 *  
 * -입력: 첫째 줄에 압축된 문자열 S가 들어온다. S의 길이는 최대 50이다. 문자열은 (, ), 0-9사이의 숫자로만 들어온다.
 * 
 * -출력: 첫째 줄에 압축되지 않은 문자열의 길이를 출력한다. 이 값은 int범위다.
 */

import java.util.*;
import java.io.*;
import java.util.Scanner;
import java.util.Stack;
 
public class Main_1662{
	private static String s;
	private static int[] visited = new int[50];
	
	public static int check(int first, int last)
	{
		int count = 0;
		
		for(int i= first; i< last; i++)
		{
			if(s.charAt(i)=='(')
			{
				int k = s.charAt(i-1)-'0';
				count += k*check(i+1,visited[i])-1;
				i = visited[i];
				
				continue;
			}
			
		count++;
		}
		
		return count;
    }
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		s = sc.nextLine();
		Stack<Integer> stack = new Stack<>();
		
		for(int i=0; i<s.length(); i++) {
			if(s.charAt(i)=='(')
			{
				stack.push(i);
			}
			else if(s.charAt(i)==')')
			{
				visited[stack.peek()] =i;
				stack.pop();
			}
		}
		int result = check(0, s.length());
		System.out.print(result);
		
		sc.close();
	}
}