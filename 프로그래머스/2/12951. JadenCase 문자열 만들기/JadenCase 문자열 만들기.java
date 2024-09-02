import java.lang.*;
import java.io.*;
import java.util.*;

class Solution {
    public String solution(String s) {
        StringBuilder sb = new StringBuilder();
        //StringTokenizer st = new StringTokenizer(s);
        boolean beforeBlank = true;
        
        for (int i=0; i<s.length(); i++) {
            
            char ch = s.charAt(i);
            
            if (ch == ' ') {
                sb.append(ch);
                beforeBlank = true;
            } else if (Character.isDigit(ch)) {
                sb.append(ch);
                beforeBlank = false;
            } else {
                if (beforeBlank) {
                    sb.append(Character.toUpperCase(ch));
                    beforeBlank = false;
                } else {
                    sb.append(Character.toLowerCase(ch));
                }
            }
        }
        
        return sb.toString();
    }
}