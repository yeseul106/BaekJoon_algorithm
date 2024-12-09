/* 
 - 문제: 김형택은 지금 몰래 Spider Solitaire(스파이더 카드놀이)를 하고 있다. 형택이는 이 게임을 이길 때도 있었지만, 질 때도 있었다. 누군가의 시선이 느껴진 형택이는 게임을 중단하고 코딩을 하기 시작했다. 의심을 피했다고 생각한 형택이는 다시 게임을 켰다. 그 때 형택이는 잠시 코딩을 하는 사이에 자신의 게임 실력이 눈에 띄게 향상된 것을 알았다.

	이제 형택이는 앞으로의 모든 게임에서 지지 않는다. 하지만, 형택이는 게임 기록을 삭제 할 수 없기 때문에, 자신의 못하던 예전 기록이 현재 자신의 엄청난 실력을 증명하지 못한다고 생각했다.

	게임 기록은 다음과 같이 생겼다.

	게임 횟수 : X
	이긴 게임 : Y (Z%)
	Z는 형택이의 승률이고, 소수점은 버린다. 예를 들어, X=53, Y=47이라면, Z=88이다.
	X와 Y가 주어졌을 때, 형택이가 게임을 최소 몇 번 더 해야 Z가 변하는지 구하는 프로그램을 작성하시오.

 - 입력: 각 줄에 정수 X와 Y가 주어진다.
 - 출력: 첫째 줄에 형택이가 게임을 최소 몇 판 더 해야하는지 출력한다. 만약 Z가 절대 변하지 않는다면 -1을 출력한다.
 */

/*
 * X와 Y를 1씩 증가시키기엔 X가 10억까지 이므로 이분탐색으로 찾기! (low는 0, high는 1,000,000,000)
 * 승률이 99% 이상일때는 몇 번을 더해도 승률이 변할 수 없음! 따라서 99% 이상이면 -1을 출력
 * 
 */
import java.util.*;
import java.io.*;

public class Main{

	public static void main(String[] args) throws IOException {
		int low = 0;
		int high = 1000000001;

		// 버퍼에 저장받아서 StringTokenizer로 자르기!
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		// 토큰은 string 타입이므로 형변환 필수!
		// string형 -> int형 : Integer.parseInt 사용

		long X = Long.parseLong(st.nextToken());
		long Y = Long.parseLong(st.nextToken());

//		System.out.println("x: "+X);
//		System.out.println("y: "+Y);
		
		long score = Y * 100 / X;
//		System.out.println("score"+ score);
		int result=0;
		int mid=0;
		
		if (score >= 99) // 승률이 99% 이상이면 승률이 바뀔수는 없음!
			System.out.println("-1");
		else {  //이분탐색!
			while (low <= high) {
				mid = (low + high) / 2;
				long newscore = (Y+mid)*100/(X+mid);
				
				if(newscore>score)  //새로 갱신한 승률이 높으면 최소 더할 게임수를 찾기위해 high = mid-1
				{
					result = mid;
					high = mid-1;
					
				}
				else  //갱신한 승률이 높지 않다면 더 많은 게임을 해야하므로 low= mid+1
					low = mid+1;
			}
			System.out.println(result);
		}
	}
}
