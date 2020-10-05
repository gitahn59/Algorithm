/*
boj_2224_명제 증명(난이도: 실버1)
Floyd-Warshall
플로이드 워셜 알고리즘을 통해
명제 관계의 연결 관계를 파악하는 문제

경로를 찾는것이 아니라 모든 노드 사이의 연결성의 여부만 구하면되므로
플로이드 워셜 알고리즘을 통해 O(n^3)에 탐색 가능함
*/

package com.example.Main;

import java.io.*;
import java.util.ArrayList;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = new Integer(reader.readLine());
        String [] line;

        int INF = 10000000;

        // 총 52개
        int [][] arr = new int[52][52];
        for(int i=0;i<52;i++){
            for(int j=0;j<52;j++){
                arr[i][j] = INF;
            }
        }

        for(int i=0;i<N;i++){
            line = reader.readLine().split(" => ");
            char from = line[0].charAt(0);
            char to = line[1].charAt(0);
            int f = from > 'Z' ? from-'a'+26 : from-'A';
            int t = to > 'Z' ? to-'a'+26 : to-'A';
            arr[f][t] = 1;
            arr[f][f] = 0;
            arr[t][t] = 0;
        }

        for(int k=0;k<52;k++){
            for(int i=0;i<52;i++){
                for(int j=0;j<52;j++){
                    int d = arr[i][k] + arr[k][j];
                    if(d < arr[i][j]){
                        arr[i][j] = d;
                    }
                }
            }
        }

        ArrayList<String> rst = new ArrayList<>();

        for(int i=0;i<52;i++){
            for(int j=0;j<52;j++){
                if(i==j) continue;
                if(arr[i][j] != INF){
                    int from = i<=25?'A'+i:'a' +i-26;
                    int to = j<=25?'A'+j:'a' +j-26;
                    String temp = ""+(char)from + " => " + (char)to;
                    rst.add(temp);
                }
            }
        }

        writer.write(""+rst.size()+"\n");
        for(int i=0;i<rst.size();i++){
            writer.write(rst.get(i)+"\n");
        }

        writer.close();
        reader.close();
    }
}

