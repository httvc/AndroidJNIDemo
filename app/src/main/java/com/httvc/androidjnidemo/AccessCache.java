package com.httvc.androidjnidemo;

/**
 * Created by Android Studio
 * Project：AndroidJNIDemo
 * Author：httvc
 * Email：jfjie2013@163.com
 * Date：2017/8/15.
 */

public class AccessCache {
    public  native void accessField(String str); // 访问str成员变量
    public native String newString(char[] chars, int len); // 根据字符数组和指定长度创建String对象

    static {
        System.loadLibrary("native-lib");
    }
}
