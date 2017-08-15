#include <jni.h>
#include <stdio.h>

//
// Created by Administrator on 2017/8/15.
//
JNIEXPORT void JNICALL Java_com_httvc_androidjnidemo_AccessSuperMethod_callSuperInstanceMethod(JNIEnv *env,jclass type){

    // 1、获取Cat类的class引用
    jclass cls_cat = (*env)->FindClass(env, "com/httvc/androidjnidemo/Cat");
    if (cls_cat==NULL){
        return;
    }

    // 2、获取Cat的构造方法ID(构造方法的名统一为：<init>)
    jmethodID mid_cat_init = (*env)->GetMethodID(env, cls_cat, "<init>", "(Ljava/lang/String;)V");
    if (mid_cat_init==NULL){
        return;
    }

     // 3、创建一个String对象，作为构造方法的参数
    jstring c_str_name = (*env)->NewStringUTF(env, "汤姆猫");
    if (c_str_name==NULL){
        return;
    }

    //4、创建Cat对象的实例(调用对象的构造方法并初始化对象)
    jobject obj_cat = (*env)->NewObject(env, cls_cat, mid_cat_init, c_str_name);
    if (obj_cat==NULL){
        return;
    }

    //-------------- 5、调用Cat父类Animal的run和getName方法 --------------
    jclass cls_animal = (*env)->FindClass(env, "com/httvc/androidjnidemo/Animal");
    if (cls_animal==NULL){
        return;
    }

    // 例1： 调用父类的run方法
    jmethodID mid_run = (*env)->GetMethodID(env, cls_animal, "run", "()V");// 获取父类Animal中run方法的id
    if (mid_run==NULL){
        return;
    }

    // 注意：obj_cat是Cat的实例，cls_animal是Animal的Class引用，mid_run是Animal类中的方法ID
    (*env)->CallNonvirtualVoidMethod(env,obj_cat,cls_animal,mid_run);

    // 例2：调用父类的getName方法
    // 获取父类Animal中getName方法的id

    jmethodID mid_getName = (*env)->GetMethodID(env, cls_animal, "getName", "()Ljava/lang/String;");
    if (mid_getName==NULL){
        return;
    }

     c_str_name  = (*env)->CallNonvirtualObjectMethod(env, obj_cat, cls_animal, mid_getName);


    const char *name = (*env)->GetStringUTFChars(env, c_str_name, NULL);
    printf("In C: Animal Name is %s\n", name);

    // 释放从java层获取到的字符串所分配的内存
    (*env)->ReleaseStringUTFChars(env, c_str_name, name);


    // 删除局部引用（jobject或jobject的子类才属于引用变量），允许VM释放被局部变量所引用的资源
    (*env)->DeleteLocalRef(env, cls_cat);
    (*env)->DeleteLocalRef(env, cls_animal);
    (*env)->DeleteLocalRef(env, c_str_name);
    (*env)->DeleteLocalRef(env, obj_cat);
}
