/*
boj_19583_싸이버개강총회(난이도: 실버1)
Set
두 조건을 만족하는 이름의 개수를 찾는 문제
시간을 초로 변환하면, int타입으로 간단하게 비교 가능함
*/

package com.example.Main;

import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String args[]) throws IOException {
        //reader = new BufferedReader(new InputStreamReader(Main.class.getResourceAsStream("input.txt")));

        String [] strings = reader.readLine().split(" ");

        int start = timeToInt(strings[0]);
        int end = timeToInt(strings[1]);
        int close = timeToInt(strings[2]);

        Set<String> enter = new HashSet<>();
        Set<String> exit = new HashSet<>();

        String line;
        while((line=reader.readLine())!=null){
            strings = line.split(" ");
            int second = timeToInt(strings[0]);
            String name = strings[1];

            if(second <= start){
                enter.add(name);
            }
            if(second>=end && second<=close){
                exit.add(name);
            }
        }

        int ret = 0;
        for(String name : enter){
            if(exit.contains(name)){
                ret++;
            }
        }
        System.out.println(ret);
    }

    public static int timeToInt(String time){
        String [] times = time.split(":");
        return Integer.parseInt(times[0])*60 + Integer.parseInt(times[1]);
    }
}



