class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2];
        
        if(yellow==1) {
            answer[0] = 3;
            answer[1] = 3;
        }
        
        for (int i = 1; i < yellow; i++) {
            if (yellow % i != 0) continue;
            int j = yellow / i;
            
            if ((i+2)*(j+2)-yellow==brown) {
                answer[0] = (i+2) >= (j+2) ? i+2 : j+2;
                answer[1] = (i+2) >= (j+2) ? j+2 : i+2;
                break;
            }
        }
        
        return answer;
    }
}