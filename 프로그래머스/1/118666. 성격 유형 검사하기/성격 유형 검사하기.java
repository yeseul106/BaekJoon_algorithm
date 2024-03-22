import java.util.*;

class Solution {
    public String solution(String[] survey, int[] choices) {
        String answer = "";
        
        //먼저 점수를 정리해놓을 해시맵 생성
        Map<Character, Integer> map = new HashMap<>();
        char[] person = { 'R', 'T', 'C', 'F', 'J', 'M', 'A', 'N' };; // 성격 유형
        for(char s : person) {
            map.put(s, 0);
        }
        
        for (int i=0; i<choices.length; i++) {
            String type = survey[i];
            int choice = choices[i];
            int score = choice;
            
            if (choice <= 3) { //비동의
                char personType = type.charAt(0);
                if (choice == 1) {
                    score = 3;
                } else if (choice == 3) {
                    score = 1;
                }
                map.put(personType, map.get(personType) + score);
            }
            if (choice >=5) {
                char personType = type.charAt(1);
                if (choice == 5) {
                    score = 1;
                } else if (choice == 6) {
                    score = 2;
                } else if (choice == 7) {
                    score = 3;
                }
                map.put(personType, map.get(personType) + score);
            }
        }
        
        if (map.get('R') < map.get('T')) {
            answer += "T";
        } else {
            answer += "R";
        }
        if (map.get('C') < map.get('F')) {
            answer += "F";
        } else {
            answer += "C";
        }
        if (map.get('J') < map.get('M')) {
            answer += "M";
        } else {
            answer += "J";
        }
        if (map.get('A') < map.get('N')) {
            answer += "N";
        } else {
            answer += "A";
        }
        
        return answer;
    }
}