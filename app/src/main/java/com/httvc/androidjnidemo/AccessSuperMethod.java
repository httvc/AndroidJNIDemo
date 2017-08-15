package com.httvc.androidjnidemo;

/**
 * Created by Android Studio
 * Project：AndroidJNIDemo
 * Author：httvc
 * Email：jfjie2013@163.com
 * Date：2017/8/15
 */

public class AccessSuperMethod {
    public static native void callSuperInstanceMethod();
    static {
        System.loadLibrary("native-lib");
    }
}
