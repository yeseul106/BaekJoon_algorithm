import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int solution(int[] bandage, int health, int[][] attacks) {
        Map<Integer, Integer> attackInfo = new HashMap<>();
        int endTime = 0;
        int curHealth = health;
        int continuousAttackCount = 0;

        for (int[] attack : attacks) {
            attackInfo.put(attack[0], attack[1]);
            endTime = attack[0];
        }

        for (int i = 1; i <= endTime; i++) {
            if (attackInfo.containsKey(i)) {
                curHealth -= attackInfo.get(i);
                continuousAttackCount = 0;
            } else {
                curHealth += bandage[1];
                continuousAttackCount++;

                if (continuousAttackCount == bandage[0]) {
                    curHealth += bandage[2];
                    continuousAttackCount = 0;
                }

                if (curHealth > health) {
                    curHealth = health;
                }
            }

            if (curHealth <= 0) {
                return -1;
            }
        }

        return curHealth;
    }
}
