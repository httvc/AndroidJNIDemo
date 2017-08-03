//
// Created by 贾富杰 on 2017/8/3.
//

#include "com_httvc_androidjnidemo_NativeHelper.h"
#include <jni.h>
#include <android/log.h>
JNIEXPORT jstring JNICALL Java_com_httvc_androidjnidemo_NativeHelper_getAppKey(JNIEnv *env,jclass type){

    char* app_key="1231810810dkaddaaa";

    return (*env)->NewStringUTF(env,app_key);
}

JNIEXPORT void JNICALL Java_com_httvc_androidjnidemo_NativeHelper_printLog(JNIEnv *env,jclass type,jstring str_){
    const char *str=(*env)->GetStringChars(env,str_,0);
    const char *tag="NativeHelper";
    jboolean b=JNI_FALSE;
    const char* txt=(*env)->GetStringUTFChars(env,str_,b);

    __android_log_write(ANDROID_LOG_DEBUG,tag,txt);

    (*env)->ReleaseStringUTFChars(env,str_,str);


}

