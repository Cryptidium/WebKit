// Automatically generated from C:/WebKit/Source/JavaScriptCore/runtime/JSPromisePrototype.cpp using C:/WebKit/Source/JavaScriptCore/create_hash_table. DO NOT EDIT!

#include "JSCBuiltins.h"
#include "Lookup.h"

namespace JSC {

static constinit const struct CompactHashIndex promisePrototypeTableIndex[5] = {
    { -1, -1 },
    { -1, -1 },
    { -1, -1 },
    { 0, 4 },
    { 1, -1 },
};

static constinit const struct HashTableValue promisePrototypeTableValues[2] = {
   { "catch"_s, ((static_cast<unsigned>(PropertyAttribute::DontEnum|PropertyAttribute::Function)) & ~PropertyAttribute::Function) | PropertyAttribute::Builtin, NoIntrinsic, { HashTableValue::BuiltinGeneratorType, promisePrototypeCatchCodeGenerator, 1 } },
   { "finally"_s, ((static_cast<unsigned>(PropertyAttribute::DontEnum|PropertyAttribute::Function)) & ~PropertyAttribute::Function) | PropertyAttribute::Builtin, NoIntrinsic, { HashTableValue::BuiltinGeneratorType, promisePrototypeFinallyCodeGenerator, 1 } },
};

static constinit const struct HashTable promisePrototypeTable =
    { 2, 3, false, nullptr, promisePrototypeTableValues, promisePrototypeTableIndex };

} // namespace JSC
