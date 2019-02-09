package com.book.problems.chapter1;

public class Problem1dot1 {

    private Problem1dot1() {}

    static Boolean isUnqueOn2(String str) {
        for (int i = 0; i < str.length(); i++) {
            for (int j = 0; j < str.length(); j++) {
                if (i == j) {
                    continue;
                }
                if (str.charAt(i) == str.charAt(j)) {
                    return false;
                }
            }
        }
        return true;
    }
}