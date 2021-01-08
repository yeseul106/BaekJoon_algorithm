
import java.util.Scanner;

public class BaekJoon_1019 {
		private static int[] numArr = new int[10];
		private static int pos=1; 
		
		public static void main(String[] args)
		{
			Scanner scanner = new Scanner(System.in);
			int n = scanner.nextInt();
			int start=1;
			int end=n;
			
			while(start <= end)
			{
				while(start%10!=0 && start <= end) {
					count(start);
					start++;
				}
				
				if(end < start)
					break;
				
				while(end%10 != 9 && start <= end) {
					count(end);
					end--;
				}
				
				start /= 10;  // 10 -> 1 
	            end /= 10;  // 29 -> 2
	            
	            for(int i=0 ; i<10 ; i++)
	                numArr[i] += (end-start+1) * pos;  // 일의 자리에 0~9가 총 2번씩 등장
	            
	            pos *= 10;  // 자리수 계산
			}
			
			String result = new String();
			for(int i=0; i<10; i++)
				result = result + numArr[i] + " ";
			
			System.out.println(result);
			scanner.close();
		}
		
		public static void count(int num) {
			if(num>0)
			{
				numArr[num%10] += pos;
				count(num/10);
			}
		}

	}

