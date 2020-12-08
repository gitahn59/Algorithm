/*
boj_13975_파일 합치기 3 (난이도: 골드5)
우선순위 큐
매 파일을 합칠 때마다 두 개의 최솟값을 뽑아 합치는 문제
최솟값을 실시간으로 빠르게 뽑기위해 우선순위 큐를 활용
허프만 코드와 구현 원리가 같음
*/

import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String args[]) throws IOException {
        int N = Integer.parseInt(reader.readLine());
        for(int i=0;i<N;i++){
            task();
        }
        writer.close();
    }

    public static void task() throws IOException {
        int N = Integer.parseInt(reader.readLine());
        String datas = reader.readLine();
        StringTokenizer tokenizer = new StringTokenizer(datas, " ");

        PriorityQueue<Long> queue = new PriorityQueue<>();
        while(tokenizer.hasMoreTokens()){
            Long num = Long.valueOf(tokenizer.nextToken());
            queue.add(num);
        }

        long ret=0;
        while(queue.size()>1){
            long a = queue.remove();
            long b = queue.remove();

            ret += (a+b);
            queue.add(a+b);
        }
        writer.write(ret + "\n");
    }
}




