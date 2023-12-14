import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Set;

class Solution {
    private static int N, M, oilIdx;
    private static int[][] oils;
    private static boolean[][] isVisited;
    private static HashMap<Integer, Integer> map;
    private static int[] dirX = {0, 0, -1, 1};
    private static int[] dirY = {-1, 1, 0, 0};

    private static class Coordinate {
        int x;
        int y;

        public Coordinate(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public int solution(int[][] land) {
        int ans = 0;
        N = land.length;
        M = land[0].length;
        oilIdx = 1;

        map = new HashMap<>();
        oils = new int[N][M];
        isVisited = new boolean[N][M];

        for (int i = 0; i < N; i++) {
            System.arraycopy(land[i], 0, oils[i], 0, M);
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (isVisited[i][j] || oils[i][j] == 0) continue;

                BFS(i, j);
            }
        }

        for (int i = 0; i < M; i++) {
            int temp = 0;
            Set<Integer> set = new HashSet<>();

            for (int j = 0; j < N; j++) {
                if (oils[j][i] > 0) {
                    set.add(oils[j][i]);
                }
            }

            for (int t : set) {
                temp += map.get(t);
            }

            ans = Math.max(ans, temp);
        }

        return ans;
    }

    private void BFS(int x, int y) {
        LinkedList<Coordinate> que = new LinkedList<>();
        isVisited[x][y] = true;
        que.offer(new Coordinate(x, y));
        oils[x][y] = oilIdx;
        int size = 0;

        while (!que.isEmpty()) {
            Coordinate now = que.poll();
            size++;

            for (int i = 0; i < 4; i++) {
                int nextX = dirX[i] + now.x;
                int nextY = dirY[i] + now.y;

                if (!isValid(nextX, nextY)) continue;

                que.offer(new Coordinate(nextX, nextY));
                isVisited[nextX][nextY] = true;
                oils[nextX][nextY] = oilIdx;
            }
        }

        map.put(oilIdx++, size);
    }

    private boolean isValid(int nextX, int nextY) {
        return nextX >= 0 && nextX < N && nextY >= 0 &&
            nextY < M && oils[nextX][nextY] == 1 && !isVisited[nextX][nextY];
    }

}
