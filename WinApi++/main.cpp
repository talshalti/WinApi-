#include <Windows.h>
#include <string>
#include <iostream>
#include <system_error>
#include <memory>

#include "last_error.hpp"
#include "call_winapi.hpp"
#include "macros.hpp"
#include "env.hpp"
#include "env_vars.h"

namespace winpp {

using HandleDataType = void;

struct HandleCloser {
    void operator()(HANDLE h) {
        ::CloseHandle(h);
    }
};


// FUTURE:  What about shared handle? Does everything that have a handle doesn't want to be copyable? How do you choose
//			between the two? Templates?
using UniqueHandle = std::unique_ptr<HandleDataType, HandleCloser>;
using SharedHandle = std::shared_ptr<HandleDataType>;
using byte = char;

class File {
    UniqueHandle m_fileHandle;

  public:
    File(UniqueHandle fileHandle) : m_fileHandle(std::move(fileHandle)) {
    }

    template<size_t size>
    std::array<std::byte, size> read() {
        std::array<std::byte, size> data;
        return data;
    }
};

}


int main() {
    std::cout << winpp::env::expend("%USERPROFILE%") << std::endl;
    std::cout << winpp::env::vars["USERPROFILE"] << std::endl;
    system("pause");
    return 0;
}