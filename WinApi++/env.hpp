#pragma once
#include <string>

#include <windows.h>

#include "call_winapi.hpp"
#include "macros.hpp"

namespace winpp {
namespace env {
namespace detail {

CharFunction(expandEnvStringsFunc, ExpandEnvironmentStringsA, ExpandEnvironmentStringsW);

template<typename T>
std::basic_string<T> expend(const std::basic_string<T>& value) {
    if(value.empty())
        return value;
    const auto requiredSize = call_winapi(expandEnvStringsFunc<T>(), value.c_str(), nullptr, 0);
    auto retValue = std::basic_string<T>(requiredSize, 0);
    const auto writtenData = call_winapi(expandEnvStringsFunc<T>(), value.data(), &retValue[0], requiredSize);
    _Assert(writtenData == requiredSize);
    return retValue;
}
}

std::string expend(const std::string& value) {
    return detail::expend(value);
}

std::wstring expend(const std::wstring& value) {
    return detail::expend(value);
}

}
}