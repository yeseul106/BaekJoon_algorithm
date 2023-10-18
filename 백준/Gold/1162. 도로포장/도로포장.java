import java.io.*;
import java.util.*;
public class Main {
    static final long INF = Long.MAX_VALUE;
    static ArrayList<Road>[] graph;
    static long[][] dist;
    static int N, M, K;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        graph = new ArrayList[N + 1];
        dist = new long[N + 1][K + 1];

        for (int i = 0; i <= N; i++) {
            graph[i] = new ArrayList<>();
            Arrays.fill(dist[i], INF);
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            long cost = Long.parseLong(st.nextToken());
            graph[from].add(new Road(to, cost, 0));
            graph[to].add(new Road(from, cost, 0));
        }

        dijkstra();

        long answer = INF;
        for (int k = 0; k <= K; k++) {
            if (dist[N][k] != INF) {
                answer = Math.min(answer, dist[N][k]);
            }
        }

        System.out.println(answer);
    }

    static void dijkstra() {
        PriorityQueue<Road> pq = new PriorityQueue<>();
        pq.add(new Road(1, 0, 0));
        dist[1][0] = 0;

        while (!pq.isEmpty()) {
            Road cur = pq.poll();
            int curNode = cur.to;
            long curCost = cur.cost;
            int curCnt = cur.cnt;

            if (dist[curNode][curCnt] < curCost) continue;

            for (Road nextRoad : graph[curNode]) {
                int nextNode = nextRoad.to;
                long nextCost = nextRoad.cost;

                if (curCnt < K && dist[nextNode][curCnt + 1] > dist[curNode][curCnt]) {
                    dist[nextNode][curCnt + 1] = dist[curNode][curCnt];
                    pq.add(new Road(nextNode, dist[nextNode][curCnt + 1], curCnt + 1));
                }
                if (dist[nextNode][curCnt] > dist[curNode][curCnt] + nextCost) {
                    dist[nextNode][curCnt] = dist[curNode][curCnt] + nextCost;
                    pq.add(new Road(nextNode, dist[nextNode][curCnt], curCnt));
                }
            }
        }
    }

    static class Road implements Comparable<Road> {
        int to; //다음 지점
        long cost; //현재 지점에서 다음 지점까지의 비용
        int cnt; //현재까지 포장한 도로의 개수

        public Road(int to, long cost, int cnt) {
            this.to = to;
            this.cost = cost;
            this.cnt = cnt;
        }

        /**
         * compareTo 메소드는 Comparable 인터페이스를 구현한 메소드로, 다른 Road 객체와 비교하여 비용(cost)에 따른 우선순위를 정의한다.
         * 이 메소드는 우선순위 큐에서 요소를 정렬할 때 사용되며, 비용이 작은 순서대로 요소가 정렬된다.
         */
        @Override
        public int compareTo(Road o) {
            return (int) (this.cost - o.cost);
        }
    }
}
