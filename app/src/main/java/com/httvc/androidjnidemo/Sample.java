package com.httvc.androidjnidemo;

/**
 * Created by Android Studio
 * Project：AndroidJNIDemo
 * Author：httvc
 * Email：jfjie2013@163.com
 * Date：2017/8/8.
 */

public class Sample {
    public static native String sayHello(String text);

    public static native String sayHellos(String text);

    static {
        System.loadLibrary("native-lib");
    }
}
