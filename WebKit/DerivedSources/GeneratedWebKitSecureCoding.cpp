/*
 * Copyright (C) 2022-2023 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "GeneratedWebKitSecureCoding.h"

#include "ArgumentCodersCocoa.h"

namespace WebKit {

static RetainPtr<NSDictionary> dictionaryForWebKitSecureCodingTypeFromWKKeyedCoder(id object)
{
    auto archiver = adoptNS([WKKeyedCoder new]);
    [object encodeWithCoder:archiver.get()];
    return [archiver accumulatedDictionary];
}

[[maybe_unused]] static RetainPtr<NSDictionary> dictionaryForWebKitSecureCodingType(id object)
{
    if (WebKit::conformsToWebKitSecureCoding(object))
        return [object _webKitPropertyListData];

    return dictionaryForWebKitSecureCodingTypeFromWKKeyedCoder(object);
}

template<typename T> static RetainPtr<NSDictionary> dictionaryFromVector(const Vector<std::pair<String, RetainPtr<T>>>& vector)
{
    NSMutableDictionary *dictionary = [NSMutableDictionary dictionaryWithCapacity:vector.size()];
    for (auto& pair : vector)
        dictionary[pair.first] = pair.second;
    return dictionary;
}

template<typename T> static RetainPtr<NSDictionary> dictionaryFromOptionalVector(const std::optional<Vector<std::pair<String, RetainPtr<T>>>>& vector)
{
    if (!vector)
        return nil;
    return dictionaryFromVector<T>(*vector);
}

template<typename T> static Vector<std::pair<String, RetainPtr<T>>> vectorFromDictionary(NSDictionary *dictionary)
{
    if (![dictionary isKindOfClass:NSDictionary.class])
        return { };
    __block Vector<std::pair<String, RetainPtr<T>>> result;
    [dictionary enumerateKeysAndObjectsUsingBlock:^(id key, id value, BOOL*){
        if ([key isKindOfClass:NSString.class] && [value isKindOfClass:IPC::getClass<T>()])
            result.append((NSString *)key, (T)value);
    }];
    return result;
}

template<typename T> static std::optional<Vector<std::pair<String, RetainPtr<T>>>> optionalVectorFromDictionary(NSDictionary *dictionary)
{
    if (![dictionary isKindOfClass:NSDictionary.class])
        return std::nullopt;
    return vectorFromDictionary<T>(dictionary);
}

template<typename T> static RetainPtr<NSArray> arrayFromVector(const Vector<RetainPtr<T>>& vector)
{
    return createNSArray(vector, [] (auto& t) {
        return t.get();
    });
}

template<typename T> static RetainPtr<NSArray> arrayFromOptionalVector(const std::optional<Vector<RetainPtr<T>>>& vector)
{
    if (!vector)
        return nil;
    return arrayFromVector<T>(*vector);
}

template<typename T> static Vector<RetainPtr<T>> vectorFromArray(NSArray *array)
{
    if (![array isKindOfClass:NSArray.class])
        return { };
    Vector<RetainPtr<T>> result;
    for (id element in array) {
        if ([element isKindOfClass:IPC::getClass<T>()])
            result.append((T *)element);
    }
    return result;
}

template<typename T> static std::optional<Vector<RetainPtr<T>>> optionalVectorFromArray(NSArray *array)
{
    if (![array isKindOfClass:NSArray.class])
        return std::nullopt;
    return vectorFromArray<T>(array);
}

} // namespace WebKit
