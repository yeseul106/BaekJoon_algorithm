public class Solution {

    public static int solution(String s) {
        int answer = s.length();

        for (int size = 1; size <= s.length() / 2; size++) {
            StringBuilder newS = new StringBuilder();
            String before = "\n";
            int cnt = 1;

            for (int idx = 0; idx < s.length(); idx += size) {
                String sTmp = s.substring(idx, Math.min(idx + size, s.length()));

                if (!before.equals("\n")) {
                    if (before.equals(sTmp)) {
                        cnt++;
                    } else {
                        if (cnt != 1)
                            newS.append(cnt);
                        newS.append(before);
                        cnt = 1;
                    }
                }

                if (idx + size >= s.length()) {
                    if (cnt != 1)
                        newS.append(cnt);
                    newS.append(sTmp);
                }

                before = sTmp;
            }

            if (answer > newS.length()) {
                answer = newS.length();
            }
        }

        return answer;
    }
}

