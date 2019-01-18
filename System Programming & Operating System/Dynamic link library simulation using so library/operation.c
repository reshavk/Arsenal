#include "operation.h"

JNIEXPORT jint JNICALL Java_operation_add (JNIEnv *env, jobject obj, jint a, jint b) {
	return a + b;
}

JNIEXPORT jint JNICALL Java_operation_sub (JNIEnv *env, jobject obj, jint a, jint b) {
	return a - b;
}

JNIEXPORT jint JNICALL Java_operation_mult (JNIEnv *env, jobject obj, jint a, jint b) {
	return a * b;
}

JNIEXPORT jint JNICALL Java_operation_div (JNIEnv *env, jobject obj, jint a, jint b) {
	return a / b;
}

