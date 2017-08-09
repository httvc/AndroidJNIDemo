//
// Created by Administrator on 2017/8/8.
//

#include <jni.h>
#include <string.h>
#include <stdlib.h>
#include <android/log.h>
#define TAG "intarry"
#define  LDEV(...) __android_log_print(ANDROID_LOG_DEBUG,TAG,__VA_ARGS__)
JNIEXPORT jstring JNICALL Java_com_httvc_androidjnidemo_IntArray_sumArray(JNIEnv *env,jobject job,jintArray arr_){
    jint i,sum=0,sum1=0;
    jint *c_array;
    jint arr_len;
    //1.获取数组长度
    arr_len=(*env)->GetArrayLength(env,arr_);
    //2.根据数组长度和数组元素的数据类型申请存放Java数组元素的缓冲区
    //malloc 只管分配内存，并不能对所得的内存进行初始化，所以得到的一片新内存中，其值将是随机的
    //如果分配成功则返回指向被分配内存的指针(此存储区中的初始值不确定)，否则返回空指针NULL。当内存不再使用时，
    // 应使用free()函数将内存块释放。函数返回的指针一定要适当对齐，使其可以用于任何数据对象。
    //分配arr_len个（可根据实际需要替换该数值）整型存储单元，
    //并将这arr_len个连续的整型存储单元的首地址存储到指针变量c_array中
    c_array=(jint*)malloc(sizeof(jint) *arr_len);
    //3.初始化缓冲区
    //将env中当前位置后面的c_array个字节 （typedef unsigned int size_t ）用 arr_len 替换并返回 s
    memset(c_array,0, sizeof(jint)*arr_len);
    LDEV("arr_len=%d",arr_len);
    //4.拷贝Java数组中的所有元素到缓冲区中
    (*env)->GetIntArrayRegion(env,arr_,0,arr_len,c_array);


    jintArray jarr=(*env)->NewIntArray(env,arr_len);
    (*env)->SetIntArrayRegion(env,jarr,0,arr_len,arr_);
    jint *pInt = (*env)->GetIntArrayElements(env, jarr, NULL);
    for ( i = 0; i <arr_len ;i++) {
        sum +=c_array[i];//5.累加数组元素的和
        sum1+=pInt[i];
    }

    (*env)->ReleaseIntArrayElements(env,jarr,pInt,0);
    jstring ss=sum+","+sum1;
    jsize len = (*env)->GetStringLength(env, ss);
    char buff[128]="";
    char *pBuff=buff+6;
    (*env)->GetStringUTFRegion(env,ss,0,len,pBuff);
    free(c_array);//6.释放存储数组元素的缓冲区
    return (*env)->NewStringUTF(env,buff);
}

JNIEXPORT jint JNICALL Java_com_httvc_androidjnidemo_IntArray_sumArray2(JNIEnv *env,jclass type,jintArray array_){


}


