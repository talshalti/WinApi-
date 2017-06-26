#pragma once
#include <type_traits>
#include <windows.h>
#include <string>
#include "macros.hpp"

namespace winpp {
namespace env {
namespace detail {

CharFunction(getEnviromentVariable, GetEnvironmentVariableA, GetEnvironmentVariableW);
CharFunction(setEnviromentVariable, SetEnvironmentVariableA, SetEnvironmentVariableW);

template<typename T>
std::basic_string<T> get(const std::basic_string<T>& value) {
    const auto requiredSize = call_winapi(getEnviromentVariable<T>(), value.c_str(), nullptr, 0);
    auto retValue = std::basic_string<T>(requiredSize, 0);
    const auto writtenData = call_winapi(getEnviromentVariable<T>(), value.data(), &retValue[0], requiredSize);
    _Assert(writtenData == requiredSize);
    return retValue;
}

template<typename T>
void set(const std::basic_string<T>& name, const std::basic_string<T>& key) {
    call_winapi(setEnviromentVariable<T>(), name.c_str(), key.c_str());
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
    void set(const std::wstring& key, const std::wstring& value) const {
        winpp::env::detail::set(key, value);
    }
    void set(const std::string& key, const std::string& value) const {
        winpp::env::detail::set(key, value);
    }
};
}
constexpr auto vars = detail::Vars {};
}
}