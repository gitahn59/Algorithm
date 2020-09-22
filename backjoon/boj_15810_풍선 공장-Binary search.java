/*
boj_15810_풍선 공장(난이도 : 실버2)
이진탐색
이진탐색을 통해 조건을 만족하는 최소값 탐색
*/

import java.io.*;
import java.util.Arrays;

public class Main {
    static int N, M;
    static long arr[];
    static long myMin;

    public static boolean check(long t){
        long cnt = 0;
        for(int i=0;i<N;i++){
            cnt += (t/arr[i]);
            if(cnt>=M) break;
        }

        if(cnt>=M) return true;
        return false;
    }

    public static void binSearch(long i, long j){
        if(i>j) return;
        long mid = (i+j)>>1;
        if(check(mid)){
            myMin = Math.min(myMin, mid);
            binSearch(i, mid-1);
        }else{
            binSearch(mid+1, j);
        }
    }

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String temp [] = br.readLine().split(" ");
        N = Integer.parseInt(temp[0]);
        M = Integer.parseInt(temp[1]);

        temp = br.readLine().split(" ");
        arr = new long[N];
        for(int i=0;i<N;i++){
            arr[i] = Long.parseLong(temp[i]);
        }

        myMin = 1000000l * 1000001l;
        Arrays.sort(arr);
        binSearch(1, myMin);
        bw.write(""+myMin +"\n");

        br.close();
        bw.close();
    }
}
