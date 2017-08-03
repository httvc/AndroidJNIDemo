package com.httvc.androidjnidemo;

/**
 * Created by jiafujie on 2017/8/3.
 */

public class NativeHelper {

    static{
        System.loadLibrary("native-lib");
    }

    public static native String getAppKey();

    public static native void printLog(String str);


}
