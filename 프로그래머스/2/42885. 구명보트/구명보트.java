import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

class Solution {
    public int solution(int[] people, int limit) {
        int answer = 0;
        
        // people 배열을 먼저 정렬
        Arrays.sort(people);
        
        // 정렬된 배열을 Deque로 변환
        Deque<Integer> peopleArr = IntStream.of(people)
                .boxed()
                .collect(Collectors.toCollection(ArrayDeque::new));

        // 두 끝을 검사하며 보트에 태우기
        while(!peopleArr.isEmpty()) {
            if (peopleArr.peekFirst() + peopleArr.peekLast() <= limit) {
                peopleArr.pollFirst();
                peopleArr.pollLast();
            } else {
                peopleArr.pollLast();
            }
            answer++;
        }
        
        return answer;
    }
}