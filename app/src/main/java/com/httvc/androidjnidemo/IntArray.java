package com.httvc.androidjnidemo;

/**
 * Created by Android Studio
 * Project：AndroidJNIDemo
 * Author：httvc
 * Email：jfjie2013@163.com
 * Date：2017/8/8.
 */

// 访问基本类型数组
public class IntArray {
    public  native int sumArray(int[] arr);
    public native int sumArray2(int[] arr);
    public native int[][] initInt2DArray(int size);

    static {
        System.loadLibrary("native-lib");
    }
}
