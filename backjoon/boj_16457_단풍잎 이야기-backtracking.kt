/*
boj_16457_단풍잎 이야기(난이도 : 실버1)
backtracking

백트랙킹을 이용한 후보 추출 및 최적 후보 탐색
*/

import java.io.BufferedInputStream
import java.io.InputStreamReader
import kotlin.collections.ArrayList

fun main() {
    val reader = InputStreamReader(BufferedInputStream(System.`in`))
    solve(reader)
}

data class Result(var max: Int = 0)
val one = 1
var max = 0
var end = 0
var N = 0

fun solve(reader: InputStreamReader) = with(reader) {
    val nmk = readLine()!!.trim().split(" ").map { it.toInt() }

    N = nmk[0]
    val m = nmk[1]
    end = N*2

    val quests = arrayListOf<Int>()

    (1..m).forEach { _ ->
        val quest = readLine()!!.trim().split(" ").map { it.toInt() }
                .fold(0) { acc, q ->
                    acc or one.shl(q)
                }
        quests.add(quest)
    }

    backtrack(quests = quests)
    println(max)
}

fun backtrack(
        quests: ArrayList<Int>,
        selected: Int = 0,
        len: Int = 0,
        pre: Int = 0,
) {
    if(len == N) {
        val clear = quests.filter { clear ->
            selected and clear == clear
        }.size
        max = Math.max(max, clear)
        return
    }

    for(skill in (pre+1)..end) {
        backtrack(quests, selected or one.shl(skill), len + 1, pre = skill)
    }
}



