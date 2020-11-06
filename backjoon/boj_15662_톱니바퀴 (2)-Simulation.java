/*
boj_15662_톱니바퀴(2)(난이도: 실버2)
Simulation
문제에 조건에 맞에 시뮬레이션
*/

package com.example.Main;

import java.io.*;
import java.util.*;


public class Main {
    static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String args[]) throws IOException {
        int T;
        int K;

        T = Integer.parseInt(reader.readLine());
        List<com.example.Main.Gear> gears = new ArrayList<>(T);

        String status;
        for(int t=0;t<T;t++){
            status = reader.readLine();
            gears.add(new com.example.Main.Gear(status));
        }

        K = Integer.parseInt(reader.readLine());
        for(int k=0;k<K;k++){
            String [] line = reader.readLine().split(" ");
            int target = Integer.parseInt(line[0]) - 1;
            int d = Integer.parseInt(line[1]);
            boolean dir = d > 0 ? true : false;
            moveLeft(target, gears, dir);
            move(target, !dir, gears.get(target));
            moveRight(target, T, gears, dir);
        }

        int result = 0;
        for(int t=0;t<T;t++){
            com.example.Main.Gear now = gears.get(t);
            if(now.getValue()[now.getNum()] == 1)
                result++;
        }
        System.out.println(result);
    }

    public static void move(int k, boolean dir, com.example.Main.Gear now){
        if(dir==false){
            int num = (now.getNum() + 1) % 8;
            now.setNum(num);
        }else{
            int num = (now.getNum() - 1 + 8) % 8;
            now.setNum(num);
        }
    }

    public static void moveLeft(int t, List<com.example.Main.Gear> list, boolean dir){
        com.example.Main.Gear now = list.get(t);
        if(t>0){
            com.example.Main.Gear left = list.get(t-1);
            int l = left.getValue()[(left.getNum() + 2) % 8 ];
            int r = now.getValue()[(now.getNum() + 6) % 8];
            if(l!=r){
                moveLeft(t-1, list, !dir);
            }
        }
        move(t,dir,now);
    }

    public static void moveRight(int t, int T, List<com.example.Main.Gear> list, boolean dir){
        com.example.Main.Gear now = list.get(t);
        if(t<T-1){
            com.example.Main.Gear right = list.get(t+1);
            int l = now.getValue()[(now.getNum() + 2) % 8];
            int r = right.getValue()[(right.getNum() + 6) % 8];
            if(l!=r){
                moveRight(t+1, T, list, !dir);
            }
        }
        move(t,dir,now);
    }
}

class Gear{
    int [] value = new int[8];
    int num = 0;

    public Gear(String status) {
        for(int i=0;i<8;i++)
            value[i] = status.charAt(i)-'0';
    }

    public int[] getValue() {
        return value;
    }

    public int getNum() {
        return num;
    }

    public void setNum(int num) {
        this.num = num;
    }
}
