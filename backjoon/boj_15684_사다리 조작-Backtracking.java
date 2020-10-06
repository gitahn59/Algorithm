/*
boj_15684_사다리 조작(난이도: 골드5)
backtracking
사다리를 설치할 후보를 backtracking을 통해 선정

후보 선정 시 앞 뒤에 연속된 사다리가 있는지 확인해 주어야 함
*/

import java.io.*;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

public class Main {
    static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

    static int N, M, H;
    static int [][] arr;
    static int [][] path;
    static ArrayList<com.example.Main.Pair> candidate = new ArrayList<>();
    static boolean rst;

    public static void main(String args[]) throws IOException {
        String [] line = reader.readLine().split(" ");
        N = Integer.parseInt(line[0]);
        M = Integer.parseInt(line[1]);
        H = Integer.parseInt(line[2]);

        arr = new int[H+1][N+2];
        path = new int[H+1][N+2];
        for(int i=1;i<=N;i++){
            path[0][i] = i;
        }

        for(int i=0;i<M;i++){
            line = reader.readLine().split(" ");
            int a = Integer.parseInt(line[0]);
            int b = Integer.parseInt(line[1]);
            arr[a][b] = 1;
        }

        for(int i=1;i<=H;i++){
            for(int j=1;j<=N-1;j++){
                if(arr[i][j]==0 && arr[i][j-1] == 0 && arr[i][j+1]==0){ // 연속되면 안됌
                    candidate.add(new com.example.Main.Pair(i,j));
                }
            }
        }

        task();

        writer.close();
        reader.close();
    }
    public static void task() throws IOException {
        for(int i=0;i<=3;i++){
            rst = false;
            backtracking(0,0, i);
            if(rst){
                writer.write(""+ i + "\n");
                return;
            }
        }
        writer.write("-1\n");
    }

    public static boolean isSolved(){
        for(int h=1;h<=H;h++) {
            for (int j = 1; j <= N; j++) {
                if(arr[h][j]==1){
                    path[h][j+1] = path[h-1][j];
                    continue;
                }
                if(arr[h][j-1]==1){
                    path[h][j-1] = path[h-1][j];
                    continue;
                }
                path[h][j] = path[h-1][j];
            }
        }
        for(int j=1;j<=N;j++){
            if(j==path[H][j]) continue;
            else return false;
        }

        return true;
    }

    public static void backtracking(int now, int cnt, int target){
        if(cnt==target){
            if(isSolved()){
                rst = true;
            }
            return;
        }
        if(rst) return;
        if(now < candidate.size()){
            com.example.Main.Pair pos = candidate.get(now);
            if(arr[pos.h][pos.w-1] == 0 && arr[pos.h][pos.w+1] == 0) { // 연속 여부 확인
                arr[pos.h][pos.w] = 1;
                backtracking(now + 1, cnt + 1, target);
                arr[pos.h][pos.w] = 0;
            }

            backtracking(now+1, cnt, target);
        }
    }

}

class Pair{
    int h,w;

    public Pair(int h, int w) {
        this.h = h;
        this.w = w;
    }
}

