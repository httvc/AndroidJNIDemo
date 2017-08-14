package com.httvc.androidjnidemo;

/**
 * Created by Android Studio
 * Project：AndroidJNIDemo
 * Author：httvc
 * Email：jfjie2013@163.com
 * Date：2017/8/14.
 */

public class AccessMethod {
    public static native void callJavaStaticMethod();
    public static native void callJavaInstanceMethod();

    static {
        System.loadLibrary("native-lib");
    }
}
