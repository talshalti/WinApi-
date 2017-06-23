#pragma once

namespace winpp {

template<typename F, typename ...Args>
auto call_winapi(F fn, Args &&...args) {
    auto result = fn(std::forward<Args>(args)...);
    if(!result)
        throw last_error();
    return result;
}

}