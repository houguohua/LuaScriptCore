//
// Created by 冯鸿杰 on 16/10/31.
//

#include "LuaJavaObjectDescriptor.h"
#include "LuaExportTypeDescriptor.hpp"
#include "LuaJavaEnv.h"
#include "LuaDefine.h"
#include "LuaJavaType.h"
#include "LuaPointer.h"
#include "lua.hpp"

LuaJavaObjectDescriptor::LuaJavaObjectDescriptor(JNIEnv *env, jobject object)
    : LuaObjectDescriptor((void *)(env -> NewGlobalRef(object)))
{

}

LuaJavaObjectDescriptor::LuaJavaObjectDescriptor(JNIEnv *env, jobject object, LuaExportTypeDescriptor *typeDescriptor)
    : LuaObjectDescriptor((void *)(env -> NewGlobalRef(object)), typeDescriptor)
{

}

LuaJavaObjectDescriptor::~LuaJavaObjectDescriptor()
{
    JNIEnv *env = LuaJavaEnv::getEnv();
    //移除引用
    env -> DeleteGlobalRef((jobject)getObject());
    LuaJavaEnv::resetEnv(env);
}

jobject LuaJavaObjectDescriptor::getJavaObject()
{
    return (jobject)getObject();
}