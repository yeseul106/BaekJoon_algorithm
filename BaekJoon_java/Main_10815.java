import java.util.*;
import java.io.*;

public class Main {
	static int listSize;

	static int binarySearch(int[] list, int listSize, int low, int high, int c) {
		int res=0;
		
		while (low <= high) {
			int mid = (low+high)/2;
			int cnt = 1;
			int start = list[0];
			
			for(int i=0; i<listSize; i++) {
				int dist = list[i]-start;
				
				if(mid<=dist)
				{
					cnt++;
					start = list[i];
				}
			} //for�� �̿��ؼ� ������ ���� ������ ��ġ (���� mid���� �Ÿ��� ũ�ų� ������ ������ ��ġ)
			
			if(cnt<c) {
				high = mid-1;
			} //��ġ�� ������ ������ ���� ��-> �Ÿ� ������
			
			else{
				low = mid+1;
				res = mid;
			} //��ġ�� ���� ������ Ŭ ��-> �Ÿ� �ø���, ��ġ�� ������ ���� ���Ƶ� �� ū �ִ� �Ÿ��� ���� �� �����ϱ� Ž��
			
		}
		
		return res;
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int C = Integer.parseInt(st.nextToken());
		int[] house = new int[N];
		
		for(int i=0; i<N; i++) {
			house[i] = Integer.parseInt(br.readLine());
		}

		Arrays.sort(house);
		
		int result = binarySearch(house,N,1,house[N-1]-house[0],C); // low=1(�� ��ǥ ���̴� �ּ� 1), high�� �� ���� ����

		System.out.print(result);
	}

}
