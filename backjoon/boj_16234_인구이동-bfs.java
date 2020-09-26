/*
boj_16234_인구이동(난이도 : 골드5)
bfs
매 시행 마다
    연결 요소들을 찾아 조건에 맞게 값을 변환
        변환에 성공하면 다음 시행
        변환 실패하면 루프 종료
*/

import java.io.*;
import java.util.*;

public class Main {
    static int N, L, R;
    static int arr[][];
    static int nxt[][];

    static int ni[] = {1,-1,0,0};
    static int nj[] = {0,0,1,-1};

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String temp [] = br.readLine().split(" ");
        N = Integer.parseInt(temp[0]);
        L = Integer.parseInt(temp[1]);
        R = Integer.parseInt(temp[2]);

        arr = new int[N][N];
        nxt = new int[N][N];

        for(int i=0;i<N;i++) {
            temp = br.readLine().split(" ");
            for (int j = 0; j < N; j++) {
                arr[i][j] = Integer.parseInt(temp[j]);
                nxt[i][j] = arr[i][j];
            }
        }

        int myMax = 0;
        for(int i=1;i<=2000;i++){
            boolean moved = false;
            boolean visited[][] = new boolean[50][50];

            for(int a=0;a<N;a++){
                for(int b=0;b<N;b++){
                    if(visited[a][b]) continue;
                    else{
                        ArrayList<com.example.Main.Pii> rst = bfs(a, b, visited);
                        if(rst.size()==1) continue;
                        else{
                            moved = true;
                            int sum=0;
                            for(com.example.Main.Pii now : rst){
                                sum += arr[now.h][now.w];
                            }
                            sum /= rst.size();
                            for(com.example.Main.Pii now : rst){
                                nxt[now.h][now.w] = sum;
                            }
                        }
                    }
                }
            }

            for(int a=0;a<N;a++){
                for(int b=0;b<N;b++) {
                    arr[a][b] = nxt[a][b];
                }
            }

            if(moved == false){
                break;
            }else{
                myMax++;
            }
        }

        bw.write(""+myMax +"\n");

        br.close();
        bw.close();
    }

    public static ArrayList<com.example.Main.Pii> bfs(int a, int b, boolean visited[][]){
        Queue<com.example.Main.Pii> q = new LinkedList<>();
        q.add(new com.example.Main.Pii(a,b));
        visited[a][b] = true;
        ArrayList<com.example.Main.Pii> rst = new ArrayList(N*2);
        rst.add(new com.example.Main.Pii(a,b));

        while(q.size()!=0){
            com.example.Main.Pii now = q.poll();
            int v =arr[now.h][now.w];

            for(int k=0;k<4;k++){
                int i = now.h + ni[k];
                int j = now.w + nj[k];

                if(i<0 || i==N || j<0 || j==N ) continue;
                int gap = Math.abs(v - arr[i][j]);
                if(gap>=L && gap<=R && visited[i][j]==false){
                    visited[i][j] = true;
                    q.add(new com.example.Main.Pii(i,j));
                    rst.add(new com.example.Main.Pii(i,j));
                }
            }
        }

        return rst;
    }
}

class Pii{
    public int h,w;

    public Pii(int h, int w) {
        this.h = h;
        this.w = w;
    }
}