package com.httvc.androidjnidemo;


/**
 * Created by Android Studio
 * Project：AndroidJNIDemo
 * Author：httvc
 * Email：jfjie2013@163.com
 * Date：2017/8/15.
 */

public class Cat extends Animal {
    public Cat(String name) {
        super(name);
        System.out.println("Cat Construct call....");
    }

    @Override
    public String getName() {
        return "My name is " + this.name;
    }

    @Override
    public void run() {
        System.out.println(name + " Cat.run...");
    }
}
