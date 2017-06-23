#pragma once
#include <system_error>
#include <windows.h>

namespace winpp {

std::system_error last_error() {
    return std::system_error(::GetLastError(), std::system_category());
}
}