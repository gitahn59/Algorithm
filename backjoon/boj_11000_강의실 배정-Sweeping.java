/*
boj_11000_강의실 배정(난이도: 골드5)
Sweeping
강의 시간의 시작과 끝을
건물이 시작하고 끝나는 문제로 모델링하면
출현하는 스카이라인의 최대 높이를 구하는 문제로 치환가능함
*/

import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String args[]) throws IOException {
        //reader = new BufferedReader(new InputStreamReader(com.example.Main.Main.class.getResourceAsStream("input.txt")));

        int N = Integer.parseInt(reader.readLine());
        List<com.example.Main.Pair> pairs = new ArrayList<>(N<<1);

        for(int i=0;i<N;i++){
            String [] line = reader.readLine().split(" ");
            int start = Integer.parseInt(line[0]);
            pairs.add(new com.example.Main.Pair(start,1));
            int end = Integer.parseInt(line[1]);
            pairs.add(new com.example.Main.Pair(end,-1));
        }
        Collections.sort(pairs);

        int time = 0;
        int height = 0;
        int ret=1;

        for(com.example.Main.Pair pair : pairs){
            time = pair.time;
            height += pair.type;
            ret = Math.max(ret, height);
        }

        System.out.println(ret);
    }
}

class Pair implements Comparable<com.example.Main.Pair>{
    int time;
    int type;

    public Pair(int time, int type) {
        this.time = time;
        this.type = type;
    }

    @Override
    public int compareTo(com.example.Main.Pair obj) {
        if(time == obj.time){
            if(type < obj.type)
                return -1;
            else if(type==obj.type)
                return 0;
            else return 1;
        }else{
            return time - obj.time;
        }
    }
}



