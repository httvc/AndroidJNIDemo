//
// Created by 贾富杰 on 2017/8/3.
//

#include "NativeHelper.h"
#include <jni.h>
#include <android/log.h>
#include <stdio.h>

#define TAG "nate"
#define LOGV(...)   __android_log_write(ANDROID_LOG_DEBUG,TAG,__VA_ARGS__)

#define LOG(...)    __android_log_print(ANDROID_LOG_DEBUG,TAG,__VA_ARGS__)


JNIEXPORT jstring JNICALL Java_com_httvc_androidjnidemo_NativeHelper_getAppKey(JNIEnv *env,jclass type){

    char* app_key="1231810810dkaddaaa";

    return (*env)->NewStringUTF(env,app_key);
}

JNIEXPORT void JNICALL Java_com_httvc_androidjnidemo_NativeHelper_printLog(JNIEnv *env,jclass type,jstring str_){
    const char *str=(*env)->GetStringChars(env,str_,0);
    const char *tag="NativeHelper";
    jboolean b=JNI_FALSE;
    const char* txt=(*env)->GetStringUTFChars(env,str_,b);

    LOGV(txt);
    __android_log_write(ANDROID_LOG_DEBUG,tag,txt);


    (*env)->ReleaseStringUTFChars(env,str_,str);
}


JNIEXPORT void JNICALL Java_com_httvc_androidjnidemo_NativeHelper_testType(JNIEnv *env,jobject jobj,jshort s, jint i, jlong l, jfloat f,
                                                                            jdouble d, jchar c, jboolean z, jbyte b, jstring j_str, jobject jobj1,
                                                                            jobject job2, jintArray j_int_arr){
    __android_log_print(ANDROID_LOG_DEBUG,"ssssssssss","s=%hd, i=%d, l=%ld ", s, i, l);
    __android_log_print(ANDROID_LOG_DEBUG,"ssssssssss","f=%f", f);
    __android_log_print(ANDROID_LOG_DEBUG,"ssssssssss","d=%lf, c=%c, z=%c, b=%d",d, c, z, b);


    const char *c_str = NULL;

    c_str=(*env)->GetStringUTFChars(env,j_str,NULL);

    if (c_str==NULL){
        return;
    }

    (*env)->ReleaseStringUTFChars(env,j_str,c_str);

    __android_log_print(ANDROID_LOG_DEBUG,"ssssssssss","c_str: %s\n", (char*)c_str);


}


