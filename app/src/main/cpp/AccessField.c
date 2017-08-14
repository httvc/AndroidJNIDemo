//
// Created by Administrator on 2017/8/14.
//

#include <jni.h>
#include <stdio.h>

JNIEXPORT void JNICALL Java_com_httvc_androidjnidemo_AccessField_accessInstanceField(JNIEnv *env,jclass type,jobject obj){

    // 1.获取AccessField类的Class引用
    jclass clazz =(*env)->GetObjectClass(env, obj);
    if (clazz==NULL){
        return;
    }

    // 2. 获取AccessField类实例变量str的属性ID
    jfieldID fid  = (*env)->GetFieldID(env, clazz, "str", "Ljava/lang/String;");
    if (fid==NULL){
        return;
    }

    // 3. 获取实例变量str的值
    jstring j_str = (jstring)(*env)->GetObjectField(env, obj, fid);
    if (j_str==NULL){
        return;
    }

    // 4. 将unicode编码的java字符串转换成C风格字符串
    const char *c_str = (*env)->GetStringUTFChars(env, j_str, NULL);
    if (c_str==NULL){
        return;
    }

    printf("In C--->ClassField.str = %s\n", c_str);
    (*env)->ReleaseStringUTFChars(env, j_str, c_str);

    // 5. 修改实例变量str的值
    jstring j_newStr  = (*env)->NewStringUTF(env, "This is C String");
    if (j_newStr == NULL) {
        return;
    }

    (*env)->SetObjectField(env,obj,fid,j_newStr);

    // 6.删除局部引用
    (*env)->DeleteLocalRef(env, clazz);
    (*env)->DeleteLocalRef(env, j_str);
    (*env)->DeleteLocalRef(env, j_newStr);
}

JNIEXPORT void JNICALL Java_com_httvc_androidjnidemo_AccessField_accessStaticField(JNIEnv *env,jclass type){

    //1.获取ClassField类的Class引用
    jclass clazz = (*env)->FindClass(env, "com/httvc/androidjnidemo/ClassField");
    if (clazz==NULL){
        return;
    }


    //2.获取ClassField类静态变量num的属性ID
    jfieldID fid = (*env)->GetStaticFieldID(env, clazz, "num", "I");
    if (fid==NULL){
        return;
    }

    // 3.获取静态变量num的值
    jint num  = (*env)->GetStaticIntField(env, clazz, fid);
    if (num==NULL){
        return;
    }

    // 4.修改静态变量num的值
    (*env)->SetStaticIntField(env,clazz,fid,1000);

    // 删除属部引用
    (*env)->DeleteLocalRef(env,clazz);
}