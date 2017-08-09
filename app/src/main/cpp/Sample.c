//
// Created by 贾富杰 on 2017/8/3.
//
#include <stdio.h>
#include <jni.h>
#include <android/log.h>
#include "com_httvc_androidjnidemo_Sample.h"

JNIEXPORT jstring JNICALL Java_com_httvc_androidjnidemo_Sample_sayHello(JNIEnv *env,jclass type,jstring jstr_){

    const char *c_str=NULL;
    char buff[128]={0};
    jboolean isCopy;    // 返回JNI_TRUE表示原字符串的拷贝，返回JNI_FALSE表示返回原字符串的指针

    c_str=(*env)->GetStringUTFChars(env,jstr_,NULL);
    //__android_log_print(ANDROID_LOG_DEBUG,"ssss",isCopy);

    if (c_str==NULL){
        return NULL;
    }
    __android_log_print(ANDROID_LOG_DEBUG,"ssss","C_str: %s \n", c_str);

    sprintf(buff,"hello %s",c_str);
    //(*env)->ReleaseStringChars(env,jstr_,c_str);
    (*env)->ReleaseStringUTFChars(env, jstr_, c_str);
    return (*env)->NewStringUTF(env,buff);
}

JNIEXPORT jstring JNICALL Java_com_httvc_androidjnidemo_Sample_sayHellos(JNIEnv *env,jclass type,jstring jstr_){
    jsize len = (*env)->GetStringLength(env, jstr_);//获取unicode字符串的长度
    __android_log_print(ANDROID_LOG_DEBUG,"SSSS","str_len:%d\n",len);
    char buff[128]="hello ";
    char *pBuff=buff+6;
    //将jvm中的字符串以utf-8编码考入C缓冲区，该函数内部不会分配内存空间
    (*env)->GetStringUTFRegion(env,jstr_,0,len,pBuff);
    return (*env)->NewStringUTF(env,buff);
    
}
