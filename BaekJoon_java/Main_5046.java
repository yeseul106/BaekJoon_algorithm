import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
	      Scanner sc = new Scanner(System.in);
	      
	      int N = sc.nextInt(); //참가자의 수 
	      int B = sc.nextInt(); //예산 
	      int H = sc.nextInt(); //호텔 
	      int W = sc.nextInt(); //고를 수 있는 주의 개수 
	      int[] a = new int[W]; // i번째 주에 투숙 가능한 인원 
	      int[] price = new int[W*H]; //가능한 비용을 체크하기 위한 배열  
	      int priceCount = 0; //가능한 비용을 체크하기 위한 인덱스번호  
	      
	      for(int i = 0; i < H; i++) {
	    	      int p = sc.nextInt(); //호텔의 일인당 숙박비용
	    	      
	    	      for(int j = 0; j < W; j++) {
		    	      a[j] = sc.nextInt(); // i번째 주에 투숙 가능한 인원 
	    	      }
	    	    
	    	      if(p * N <= B) { //숙박비용 * 참가자 <= 전체예산 OK면 계속 진행  
		    	      for(int j = 0; j < W; j++) {
			    	      if(a[j] >= N) { //숙박가능 인원이 참가자보다 커야함 
			    	          price[priceCount] = p * N; //가능한 비용을 체크하기 위해 참가자와 참가비용 곱해서 넣기 
			    	          priceCount++;
			    	      }
		    	      }    
	    	      }      
	      }	 
	      
	      if(price[0] == 0) { //최소 비용이 없다면 
	    	      System.out.println("stay home");
	      }
	      
	      else { //최소 비용이 존재한다면 
	    	      for(int i = 0; i < priceCount - 1; i++) { //가능 비용 중에서 최소 비용 출력하기 
		    	    	  for (int j = 0; j < priceCount - 1 - i; j++ ) {				
		    	    		  if ( price[j] > price[j + 1] ) {
		    						int TEMP = price[j];
		    						price[j] = price[j + 1];
		    						price[j + 1] = TEMP;
		    		      }
		    	    	  }
		      }
	    	      
	    	      System.out.println(price[0]);
	      }
	}
}

