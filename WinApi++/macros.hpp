#pragma once

#define _Assert(...)

#define CharFunction(name, only_char, only_wchar)																						\
template<typename T>																													\
struct name;																															\
																																		\
template<>																																\
struct name<char> : std::integral_constant<decltype(&only_char), &only_char> {															\
};																																		\
																																		\
template<>																																\
struct name<wchar_t> : std::integral_constant<decltype(&only_wchar), &only_wchar> {														\
}
