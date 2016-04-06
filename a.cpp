#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <wchar.h>

#include <random>
#include <type_traits>
#include <unistd.h>
#include <string.h>


using namespace std;

extern "C"
size_t stdlib_fwrite_stdout(const void *ptr,
                            size_t size) {
    return fwrite(ptr, size, 1, stdout);
}


int main() {
    
    std::u16string s = u"aa🤔aa";
    auto data = reinterpret_cast<const void*>(s.data());
    auto u = s.size();
    printf("%li\n", u);
    stdlib_fwrite_stdout(data, u);
    printf("\n");
    
    return 0;
}


