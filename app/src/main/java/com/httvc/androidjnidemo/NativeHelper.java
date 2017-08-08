package com.httvc.androidjnidemo;

/**
 * Created by jiafujie on 2017/8/3.
 */

class MyClass {}

public class NativeHelper {

    static{
        System.loadLibrary("native-lib");
    }

    public static native String getAppKey();

    public static native void printLog(String str);

    public  native void testType(short s, int i, long l, float f, double d, char c,
                                 boolean z, byte b, String str, Object obj, MyClass p, int[] arr);

}
