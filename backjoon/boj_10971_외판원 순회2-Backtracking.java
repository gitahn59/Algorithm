/*
boj_10971_외판원 순회2(난이도: 실버2)
Backtracking
순열을 통해 중간 경로를 모두 탐색
탐색된 중간 경로 중에서
가능한 최단 경로 계산
*/

package com.example.Main;

import java.io.*;

public class Main {
    static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

    static int [][] arr;
    static int N;
    static boolean [] visited;
    static int [] selected;
    static int INF = 100000000;
    static int myMin = INF;

    public static void main(String args[]) throws IOException {
        N = Integer.parseInt(reader.readLine());
        arr = new int[N][N];
        visited = new boolean[N];
        selected = new int[N+1];

        String [] line;

        for(int i=0;i<N;i++){
            line = reader.readLine().split(" ");
            for(int j=0;j<N;j++){
                arr[i][j] = Integer.parseInt(line[j]);
            }
        }

        selected[0] = 0;
        selected[N] = 0;
        permutation(1);

        writer.write(""+myMin + "\n");

        writer.close();
        reader.close();
    }

    public static void permutation(int cnt){
        if(cnt==N){
            myMin = Math.min(myMin, calculate());
            return;
        }
        for(int i=1;i<N;i++){
            if(visited[i]) continue;
            visited[i] = true;
            selected[cnt] = i;
            permutation(cnt+1);
            visited[i] = false;
        }
    }

    public static int calculate(){
        int cost=0;
        for(int i=0;i<N;i++){
            int from = selected[i];
            int to = selected[i+1];

            if(arr[from][to] == 0) return INF;
            else cost+=arr[from][to];
        }
        return cost;
    }
}
