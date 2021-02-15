import java.util.*;
import java.io.*;
public class Main {
	static int listSize;
	
	static int binarySearch(int key, int list[], int size) {
		int low = 0;
		int high = size-1;
		
		while(low<=high) {
			int mid = (low+high)/2;
			if(key<list[mid])
				high = mid-1;
			else if(key==list[mid])
				return mid;
			else
				low = mid+1;
		}
		
		return -1;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] myCard = new int[n];
		
		String mc = br.readLine();
		StringTokenizer st = new StringTokenizer(mc);
		for(int i=0; i<n; i++)
			myCard[i] = Integer.parseInt(st.nextToken());
		
		int m = Integer.parseInt(br.readLine());
		int[] checkCard = new int[m];
		
		String check = br.readLine();
		StringTokenizer st2 = new StringTokenizer(check);
		for(int i=0; i<m; i++)
			checkCard[i] = Integer.parseInt(st2.nextToken());
		
		Arrays.sort(myCard);
		
		for(int i=0; i<m; i++) {
			int num = checkCard[i];
			listSize = myCard.length;
			int result = binarySearch(num, myCard, listSize);
			
			if(result==-1)
				System.out.println(0);
			else
				System.out.println(1);
		}

	}

}
