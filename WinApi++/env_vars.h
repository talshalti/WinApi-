#pragma once
#include <type_traits>
#include <windows.h>
#include <string>
#include "macros.hpp"

namespace winpp {
namespace env {
namespace detail {

CharFunction(getEnviromentVariable, GetEnvironmentVariableA, GetEnvironmentVariableW);

template<typename T>
std::basic_string<T> get(const std::basic_string<T>& value) {
    const auto requiredSize = call_winapi(getEnviromentVariable<T>(), value.c_str(), nullptr, 0);
    auto retValue = std::basic_string<T>(requiredSize, 0);
    const auto writtenData = call_winapi(getEnviromentVariable<T>(), value.data(), &retValue[0], requiredSize);
    _Assert(writtenData == requiredSize);
    return retValue;
}

class Vars {
  public:
    constexpr Vars() {}

    std::string operator[](const std::string& value) const {
        return get(value);
    }

    std::wstring operator[](const std::wstring& value) const {
        return get(value);
    }
};
}
constexpr auto vars = detail::Vars {};
}
}