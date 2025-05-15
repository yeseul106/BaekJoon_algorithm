import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        StringBuilder sb = new StringBuilder();
        
        ArrayList<String> list_numbers = new ArrayList<>();
        
        for (int number : numbers) {
            list_numbers.add(Integer.toString(number));
        }
        
        Collections.sort(list_numbers, new Comparator<String>(){
            public int compare(String s1, String s2) {
                return (s2 + s1).compareTo(s1 + s2);
            }
        });
        
        if (list_numbers.get(0).equals("0")) {
            return "0";
        }
                         
        for (String num : list_numbers) {
            sb.append(num);
        }                 
        
        return sb.toString(); 
    }
}