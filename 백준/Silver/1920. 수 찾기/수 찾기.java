/*
 * - 문제: N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때, 이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오.
 * 
 * - 입력: 첫째 줄에 자연수 N(1 ≤ N ≤ 100,000)이 주어진다. 다음 줄에는 N개의 정수 A[1], A[2], …, A[N]이 주어진다. 다음 줄에는 M(1 ≤ M ≤ 100,000)이 주어진다. 
 *        다음 줄에는 M개의 수들이 주어지는데, 이 수들이 A안에 존재하는지 알아내면 된다. 모든 정수의 범위는 -231 보다 크거나 같고 231보다 작다.
 * - 출력: M개의 줄에 답을 출력한다. 존재하면 1을, 존재하지 않으면 0을 출력한다.
 * 
 * 빠른 시간 내에 문제 해결을 하기 위해 이분 탐색(BinarySearch) 알고리즘으로 구현하였다.
 * 
 */
import java.util.*;
import java.io.*;

public class Main{

	public static boolean BinarySearch(int key, int list[], int listSize) {
		int start = 0;
		int end = listSize - 1;
		boolean result = false;

		while (start <= end) {
			int mid = (start + end) / 2;
			if (key < list[mid])
				end = mid - 1;
			else if (key > list[mid])
				start = mid + 1;
			else {
				result = true;
				return result;
			}
		}
		
		return result;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(bf.readLine());
		StringTokenizer st1 = new StringTokenizer(bf.readLine());

		int array1[] = new int[N];
		for (int i = 0; i < N; i++)
			array1[i] = Integer.parseInt(st1.nextToken());

		int M= Integer.parseInt(bf.readLine());
		StringTokenizer st2 = new StringTokenizer(bf.readLine());

		int array2[] = new int[M];
		for (int i = 0; i < M; i++)
			array2[i] = Integer.parseInt(st2.nextToken());

		// array1에서 탐색할 것 이므로 정렬하기
		Arrays.sort(array1);
		
		for (int i = 0; i < M; i++) {
			if (BinarySearch(array2[i], array1, N))
				System.out.println("1");
			else
				System.out.println("0");
		}
	}
}
