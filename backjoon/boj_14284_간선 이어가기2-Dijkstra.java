/*
boj_14284_간선 이어가기2(난이도: 골드5)
다익스트라
최소 경로의 길이를 구하는 문제
*/

import java.io.*;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.PriorityQueue;

public class Main {

    static ArrayList<com.example.Main.Pair> adj[] = new ArrayList[5000];

    public static int dijkstra(int s, int t, int N){
        boolean [] visited = new boolean[N];
        int [] dist = new int[N];
        int INF = 600000000;

        for(int i=0;i<N;i++){
            dist[i] = INF;
        }

        PriorityQueue<com.example.Main.Pair> q = new PriorityQueue<>();
        q.add(new com.example.Main.Pair(0,s));
        dist[s] = 0;

        while(!q.isEmpty()){
            com.example.Main.Pair now = q.poll();

            if(visited[now.to]) continue;
            visited[now.to] = true;
            Iterator<com.example.Main.Pair> it = adj[now.to].iterator();
            while(it.hasNext()){
                com.example.Main.Pair to = it.next();
                com.example.Main.Pair next = new com.example.Main.Pair(now.cost + to.cost, to.to);
                if(next.cost < dist[next.to]){
                    dist[next.to] = next.cost;
                    q.add(next);
                    visited[next.to] = false;
                }
            }
        }

        return dist[t];
    }

    public static void main(String args[]) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        String [] line;
        line = reader.readLine().split(" ");
        int N = new Integer(line[0]);
        int M = new Integer(line[1]);

        for(int i=0;i<N;i++){
            adj[i] = new ArrayList<com.example.Main.Pair>();
        }

        for(int i=0;i<M;i++){
            line = reader.readLine().split(" ");
            int from = new Integer(line[0])-1;
            int to = new Integer(line[1])-1;
            int c = new Integer(line[2]);

            adj[from].add(new com.example.Main.Pair(c,to));
            adj[to].add(new com.example.Main.Pair(c,from));
        }

        line = reader.readLine().split(" ");
        int S = new Integer(line[0])-1;
        int T = new Integer(line[1])-1;

        writer.write(""+dijkstra(S, T, N) + "\n");

        writer.close();
        reader.close();
    }
}

class Pair implements Comparable<com.example.Main.Pair>{
    int cost, to;

    public Pair(int cost, int to) {
        this.cost = cost;
        this.to = to;
    }

    @Override
    public int compareTo(com.example.Main.Pair o) {
        if(cost<o.cost) return -1;
        else if(cost == o.cost){
            return to - o.to;
        }else{
            return 1;
        }
    }
}