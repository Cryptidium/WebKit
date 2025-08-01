// Automatically generated from C:/WebKit/Source/JavaScriptCore/runtime/ArrayConstructor.cpp using C:/WebKit/Source/JavaScriptCore/create_hash_table. DO NOT EDIT!

#include "JSCBuiltins.h"
#include "Lookup.h"

namespace JSC {

static constinit const struct CompactHashIndex arrayConstructorTableIndex[4] = {
    { -1, -1 },
    { -1, -1 },
    { 1, -1 },
    { 0, -1 },
};

static constinit const struct HashTableValue arrayConstructorTableValues[2] = {
   { "of"_s, ((static_cast<unsigned>(PropertyAttribute::DontEnum|PropertyAttribute::Function)) & ~PropertyAttribute::Function) | PropertyAttribute::Builtin, NoIntrinsic, { HashTableValue::BuiltinGeneratorType, arrayConstructorOfCodeGenerator, 0 } },
   { "from"_s, ((static_cast<unsigned>(PropertyAttribute::DontEnum|PropertyAttribute::Function)) & ~PropertyAttribute::Function) | PropertyAttribute::Builtin, NoIntrinsic, { HashTableValue::BuiltinGeneratorType, arrayConstructorFromCodeGenerator, 1 } },
};

static constinit const struct HashTable arrayConstructorTable =
    { 2, 3, false, nullptr, arrayConstructorTableValues, arrayConstructorTableIndex };

} // namespace JSC
