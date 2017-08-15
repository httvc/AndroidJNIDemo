package com.httvc.androidjnidemo;

/**
 * Created by Android Studio
 * Project：AndroidJNIDemo
 * Author：httvc
 * Email：jfjie2013@163.com
 * Date：2017/8/15.
 */

public class Animal {
    protected String name;

    public Animal(String name) {
        this.name = name;
        System.out.println("Animal Construct call...");
    }

    public String getName() {
        System.out.println("Animal.getName Call...");
        return this.name;
    }

    public void run(){
        System.out.print("Animal.run...");
    }
}
