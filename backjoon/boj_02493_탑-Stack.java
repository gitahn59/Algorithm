/*
boj_2493_탑(난이도: 골드5)
Stack
스택을 이용해 이전까지 출현했던 탑을 관리

더 이상 출현할 수 앖는 탑은 제거하고(현재 탑보다 낮은 탑)
다시 출현할 수 있는 탑은 계속 보유(현재 탑보다 높은 탑)
*/

import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String args[]) throws IOException {
        //reader = new BufferedReader(new InputStreamReader(Main.class.getResourceAsStream("input.txt")));

        int N = Integer.parseInt(reader.readLine());
        String data = reader.readLine();
        StringTokenizer tokenizer = new StringTokenizer(data," ");

        LinkedList<com.example.Main.Pair> stack = new LinkedList<>();
        for(int i=1;i<=N;i++){
            int now = Integer.parseInt(tokenizer.nextToken());
            if(stack.isEmpty()){
                writer.write("0 ");
                stack.addLast(new com.example.Main.Pair(i, now));
            }else{
                while(true){
                    if(stack.isEmpty()){
                        writer.write("0 ");
                        stack.addLast(new com.example.Main.Pair(i, now));
                        break;
                    }
                    int height = stack.getLast().second;
                    if(height<now){
                        stack.removeLast();
                    }else{
                        writer.write(stack.getLast().first + " ");
                        stack.addLast(new com.example.Main.Pair(i, now));
                        break;
                    }
                }
            }
        }
        writer.close();
        System.out.println();
    }
}

class Pair{
    int first;
    int second;

    public Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}



