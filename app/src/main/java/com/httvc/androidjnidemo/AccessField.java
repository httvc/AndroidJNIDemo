package com.httvc.androidjnidemo;

/**
 * Created by Android Studio
 * Project：AndroidJNIDemo
 * Author：httvc
 * Email：jfjie2013@163.com
 * Date：2017/8/14.
 */

public class AccessField {
    public static native void accessInstanceField(ClassField obj);
    public static native void accessStaticField();

    static {
        System.loadLibrary("native-lib");
    }
}
