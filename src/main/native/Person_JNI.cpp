#include <jni.h>
#include <memory>
#include "Person.h"
#include "include/PersonNative.h"  // Include the generated JNI header file
//#include "Person.cpp"  // Include the C++ implementation of Person

// Helper functions to set and get the native handle
void setHandle(JNIEnv *env, jobject obj, std::shared_ptr<Person> person) {
    jlong handle = reinterpret_cast<jlong>(new std::shared_ptr<Person>(person));
    env->SetLongField(obj, env->GetFieldID(env->GetObjectClass(obj), "nativeHandle", "J"), handle);
}

std::shared_ptr<Person> getHandle(JNIEnv *env, jobject obj) {
    jlong handle = env->GetLongField(obj, env->GetFieldID(env->GetObjectClass(obj), "nativeHandle", "J"));
    return *(reinterpret_cast<std::shared_ptr<Person> *>(handle));
}

extern "C" {

JNIEXPORT void JNICALL Java_PersonNative_initNativeObject(JNIEnv *env, jobject obj, jstring firstName, jstring lastName, jstring address, jint age) {
    const char *firstNameCStr = env->GetStringUTFChars(firstName, nullptr);
    const char *lastNameCStr = env->GetStringUTFChars(lastName, nullptr);
    const char *addressCStr = env->GetStringUTFChars(address, nullptr);

    std::shared_ptr<Person> person = std::make_shared<Person>(firstNameCStr, lastNameCStr, addressCStr, age);

    setHandle(env, obj, person);

    env->ReleaseStringUTFChars(firstName, firstNameCStr);
    env->ReleaseStringUTFChars(lastName, lastNameCStr);
    env->ReleaseStringUTFChars(address, addressCStr);
}

JNIEXPORT void JNICALL Java_PersonNative_disposeNativeObject(JNIEnv *env, jobject obj) {
    std::shared_ptr<Person> person = getHandle(env, obj);
    delete reinterpret_cast<std::shared_ptr<Person> *>(env->GetLongField(obj, env->GetFieldID(env->GetObjectClass(obj), "nativeHandle", "J")));
}

JNIEXPORT jstring JNICALL Java_PersonNative_getFirstName(JNIEnv *env, jobject obj) {
    std::shared_ptr<Person> person = getHandle(env, obj);
    return env->NewStringUTF(person->getFirstName().c_str());
}

JNIEXPORT jstring JNICALL Java_PersonNative_getLastName(JNIEnv *env, jobject obj) {
    std::shared_ptr<Person> person = getHandle(env, obj);
    return env->NewStringUTF(person->getLastName().c_str());
}

JNIEXPORT jstring JNICALL Java_PersonNative_getAddress(JNIEnv *env, jobject obj) {
    std::shared_ptr<Person> person = getHandle(env, obj);
    return env->NewStringUTF(person->getAddress().c_str());
}

JNIEXPORT jint JNICALL Java_PersonNative_getAge(JNIEnv *env, jobject obj) {
    std::shared_ptr<Person> person = getHandle(env, obj);
    return (jint)person->getAge();
}

JNIEXPORT jstring JNICALL Java_PersonNative_toString(JNIEnv *env, jobject obj) {
    std::shared_ptr<Person> person = getHandle(env, obj);
    return env->NewStringUTF(person->ToString().c_str());
}

// Implement other JNI methods similarly...

}
