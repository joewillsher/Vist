#include <iostream>
#include <locale>
#include <codecvt>
#include <string>

using namespace std;

void vist_printUTF16_top(const void *str, size_t size) {
    auto base = reinterpret_cast<const char*> (str);
    
    wstring_convert<codecvt_utf16<wchar_t, 0x10ffff, little_endian>, wchar_t> conv;
    wstring ws = conv.from_bytes(base,
                                 base + size);
    
    setlocale(LC_ALL, "");
    wprintf(L"%ls", ws.data());
};

int main() {
    
    std::u16string s = u"aaaγaaaaaa🤔aa🙃🤗aaaaa";
    auto data = reinterpret_cast<const void*>(s.data());
    vist_print_top(data, s.size()*2);
    
    return 0;
}


