//
// Created by Administrator on 2017/8/15.
//

#include <jni.h>
#include <stdio.h>

JNIEXPORT void JNICALL Java_com_httvc_androidjnidemo_AccessCache_accessField(JNIEnv *env,jobject obj){

    // 第一次访问时将字段存到内存数据区，直到程序结束才会释放，可以起到缓存的作用
    static jfieldID  fid_str=NULL;
    jclass cls_AccessCache = (*env)->GetObjectClass(env, obj);// 获取该对象的Class引用
    if (cls_AccessCache==NULL){
        return;
    }

    // 先判断字段ID之前是否已经缓存过，如果已经缓存过则不进行查找
    if (fid_str==NULL){
        fid_str=(*env)->GetFieldID(env,cls_AccessCache,"str","Ljava/lang/String;");
        // 再次判断是否找到该类的str字段
        if (fid_str==NULL){
            return;
        }
    }

    jstring  j_str = (*env)->GetObjectField(env, obj, fid_str);//获取字段的值
    const char *c_str = (*env)->GetStringUTFChars(env, j_str, NULL);
    if (c_str==NULL){
        return;//内存不够
    }
    printf("In C:\n str=\"%s\"\n",c_str);
    (*env)->ReleaseStringChars(env,j_str,c_str); // 释放从从JVM新分配字符串的内存空间

    //修改字段的值
    j_str = (*env)->NewStringUTF(env, "12345");
    if (j_str == NULL) {
        return;
    }
    (*env)->SetObjectField(env,obj,fid_str,j_str);
    // 释放本地引用
    (*env)->DeleteLocalRef(env,cls_AccessCache);
    (*env)->DeleteLocalRef(env,j_str);
}

JNIEXPORT jstring JNICALL Java_com_httvc_androidjnidemo_AccessCache_newString(JNIEnv *env,jclass type,jcharArray j_char_arr, jint len ){

    static jclass cls_string = NULL;
    static jmethodID cid_string = NULL;


}

