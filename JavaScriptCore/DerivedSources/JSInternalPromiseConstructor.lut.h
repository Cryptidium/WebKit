// Automatically generated from C:/WebKit/Source/JavaScriptCore/runtime/JSInternalPromiseConstructor.cpp using C:/WebKit/Source/JavaScriptCore/create_hash_table. DO NOT EDIT!

#include "JSCBuiltins.h"
#include "Lookup.h"

namespace JSC {

static constinit const struct CompactHashIndex internalPromiseConstructorTableIndex[2] = {
    { 0, -1 },
    { -1, -1 },
};

static constinit const struct HashTableValue internalPromiseConstructorTableValues[1] = {
   { "internalAll"_s, ((static_cast<unsigned>(PropertyAttribute::DontEnum|PropertyAttribute::Function)) & ~PropertyAttribute::Function) | PropertyAttribute::Builtin, NoIntrinsic, { HashTableValue::BuiltinGeneratorType, internalPromiseConstructorInternalAllCodeGenerator, 1 } },
};

static constinit const struct HashTable internalPromiseConstructorTable =
    { 1, 1, false, nullptr, internalPromiseConstructorTableValues, internalPromiseConstructorTableIndex };

} // namespace JSC
