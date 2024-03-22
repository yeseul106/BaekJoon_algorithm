import java.util.*;

class RelationMatrix {
    private int[][] relations;
    private String[] users;

    // 생성자
    public RelationMatrix(String[] users) {
        this.users = users;
        this.relations = new int[users.length][users.length];
        
        for (int i = 0; i < users.length; i++) {
            for (int j = 0; j < users.length; j++) {
                relations[i][j] = 0;
            }
        }
    }

    // 사용자 간의 관계 추가
    public void addRelation(String user1, String user2) { //user1이 user2한테 선물주기
        int index1 = getIndex(user1);
        int index2 = getIndex(user2);
        relations[index1][index2] += 1;
    }

    // 사용자 이름으로부터 인덱스 찾기
    private int getIndex(String user) {
        for (int i = 0; i < users.length; i++) {
            if (users[i].equals(user)) {
                return i;
            }
        }
        return -1; // 사용자를 찾지 못한 경우
    }

    // 특정 사용자 간의 관계 반환
    public int getRelation(String user1, String user2) {
        int index1 = getIndex(user1);
        int index2 = getIndex(user2);
        return relations[index1][index2];
    }

}

class Solution {
    public int solution(String[] friends, String[] gifts) {
        
        // 2차원 배열 만들기
        RelationMatrix matrix = new RelationMatrix(friends);
        HashMap<String, Integer> giftResult = new HashMap<String, Integer>();
        for (String friend : friends) {
            giftResult.put(friend, 0);
        }
        HashMap<String, Integer> giftScore = new HashMap<String, Integer>();
        
        for (String giftInfo : gifts) {
            // 공백을 기준으로 문자열을 분할하여 배열에 저장
            String[] info = giftInfo.split(" ");
            String sender = info[0];
            String receiver = info[1];
            
            matrix.addRelation(sender, receiver);
        }
        
        
        //먼저 선물 지수 구해놓기
        for (int i=0 ; i<friends.length; i++) {
            int sendNum = 0;
            int receiveNum = 0;
            for (int j=0; j<friends.length; j++) {
                sendNum += matrix.getRelation(friends[i], friends[j]);
                receiveNum += matrix.getRelation(friends[j], friends[i]);
            }
            giftScore.put(friends[i], sendNum - receiveNum);
        }
        
        //주고 받은 선물을 저장해둔 2차원 배열 탐색
        for (int i=0 ; i<friends.length; i++) {
            String sender = friends[i];
            for (int j=i+1; j<friends.length; j++) {
                String receiver = friends[j];
                
                int senderGiftNum = matrix.getRelation(sender, receiver);
                int receiverGiftNum = matrix.getRelation(receiver, sender);
                
                if (senderGiftNum > receiverGiftNum) {
                    giftResult.put(sender, giftResult.get(sender) + 1);
                } else if ((senderGiftNum==receiverGiftNum) || (receiverGiftNum==0 && senderGiftNum==0)) {
                    int senderGiftScore = giftScore.get(sender);
                    int receiverGiftScore = giftScore.get(receiver);
                    
                    if (senderGiftScore > receiverGiftScore) {
                        giftResult.put(sender, giftResult.get(sender) + 1);
                    } else if (senderGiftScore < receiverGiftScore) {
                        giftResult.put(receiver, giftResult.get(receiver) + 1);
                    }
                } else if (senderGiftNum < receiverGiftNum) {
                    giftResult.put(receiver, giftResult.get(receiver) + 1);
                }
        
            }
        }
        
        int answer = Collections.max(giftResult.values()); 
        
        return answer;
    }

}