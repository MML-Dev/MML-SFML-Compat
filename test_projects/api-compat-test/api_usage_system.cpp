
// Including all files to make sure we don't delete some by mistake
#include <SFML/Config.hpp>
#include <SFML/GpuPreference.hpp>
#include <SFML/Main.hpp>
#include <SFML/OpenGL.hpp>

#include <SFML/System.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Err.hpp>
#include <SFML/System/Export.hpp>
#include <SFML/System/FileInputStream.hpp>
#include <SFML/System/InputStream.hpp>
#include <SFML/System/MemoryInputStream.hpp>
#ifdef SFML_SYSTEM_ANDROID
#include <SFML/System/NativeActivity.hpp>
#endif
#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Sleep.hpp>
#include <SFML/System/String.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Utf.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>
// The following headers are gone: use standard STL classes from C++11 instead
//#include <SFML/System/Lock.hpp>
//#include <SFML/System/Mutex.hpp>
//#include <SFML/System/Thread.hpp>
//#include <SFML/System/ThreadLocal.hpp>
//#include <SFML/System/ThreadLocalPtr.hpp>

#include <array>

void test_config_hpp() {
    sf::Int8 i8;
    sf::Uint8 u8;
    sf::Int16 i16;
    sf::Uint16 u16;
    sf::Int32 i32;
    sf::Uint32 u32;
    sf::Int64 i64;
    sf::Uint64 u64;
}

void test_system_clock_hpp() {
    sf::Clock c;
    sf::Time t = c.getElapsedTime();
    sf::Time r = c.restart();
}

void test_system_err_hpp() {
    std::ostream& os = sf::err();
}

void test_system_fileinputstream_hpp() {
    sf::FileInputStream fis;
    bool r = fis.open("null");
    sf::Int64 d = fis.read(nullptr, sf::Int64(42));
    sf::Int64 s = fis.seek(sf::Int64(42));
    sf::Int64 t = fis.tell();
    sf::Int64 sz = fis.getSize();
}

void test_system_memoryinputstream_hpp() {
    sf::MemoryInputStream mis;
    std::array<unsigned char, 32> data;
    mis.open(data.data(), data.size());
    sf::Int64 d = mis.read(nullptr, sf::Int64(42));
    sf::Int64 s = mis.seek(sf::Int64(42));
    sf::Int64 t = mis.tell();
    sf::Int64 sz = mis.getSize();
}

void test_system_noncopyable_hpp() {
    class Dummy : sf::NonCopyable {
    };
    
    static_assert(! std::is_copy_assignable<Dummy>::value, "");
    static_assert(! std::is_copy_constructible<Dummy>::value, "");
}

void test_system_sleep_hpp() {
    sf::sleep(sf::milliseconds(32));
}

void test_system_string_hpp() {
    sf::String::Iterator it;
    sf::String::ConstIterator cit;
    std::size_t ip = sf::String::InvalidPos;
    
    sf::String s;
    sf::String sa('u', std::locale());
    sf::String sw(L'u');
    sf::String s32(sf::Uint32(42));
    sf::String sc("ansi", std::locale());
    sf::String stds(std::string("ansi"), std::locale());
    sf::String ws(L"wide");
    sf::String wstd(std::wstring(L"wide"));
    sf::String s32s(std::array<sf::Uint32, 4>{ 1, 2, 3, 4 }.data());
    sf::String s32std((std::basic_string<sf::Uint32>()));
    sf::String scp(s);
    std::array<sf::Uint8, 4> utf8{ 1, 2, 3, 4 };
    sf::String futf8 = sf::String::fromUtf8(std::begin(utf8), std::end(utf8));
    std::array<sf::Uint16, 4> utf16{ 1, 2, 3, 4 };
    sf::String futf16 = sf::String::fromUtf16(std::begin(utf16), std::end(utf16));
    std::array<sf::Uint32, 4> utf32{ 1, 2, 3, 4 };
    sf::String futf32 = sf::String::fromUtf32(std::begin(utf32), std::end(utf32));
    std::string stds2 = s;
    std::wstring stdws2 = s;
    std::string stds3 = s.toAnsiString();
    std::wstring stdws3 = s.toWideString();
    std::basic_string<sf::Uint8> stdu8 = s.toUtf8();
    std::basic_string<sf::Uint16> stdu16 = s.toUtf16();
    std::basic_string<sf::Uint32> stdu32 = s.toUtf32();
    sf::String copyc(s);
    copyc += s;
    sf::Uint32 chr = s[3];
    s.clear();
    std::size_t sz = s.getSize();
    bool em = s.isEmpty();
    s.erase(std::size_t(3), std::size_t(2));
    s.insert(std::size_t(3), s);
    std::size_t fi = s.find(s, std::size_t(3));
    s.replace(std::size_t(3), std::size_t(4), s);
    s.replace(s, s);
    sf::String ss = s.substring(std::size_t(3), std::size_t(4));
    const sf::Uint32* data = s.getData();
    
    it = s.begin();
    cit = static_cast<const sf::String>(s).begin();
    it = s.end();
    cit = static_cast<const sf::String>(s).end();
    
    bool eq = s == s;
    bool neq = s != s;
    bool inf = s < s;
    bool sup = s > s;
    bool infeq = s <= s;
    bool supeq = s >= s;
    sf::String add = s + s;
}

template <typename UtfClass, typename DataType>
void test_system_utf()
{
    std::array<DataType, 3> inputArray = { 1, 2, 3};
    std::array<wchar_t, 3> wideInput = {};
    std::array<DataType, 3> outputArray = {};
    sf::Uint32 input = 0, output = 0;
    typename decltype(inputArray)::iterator decoded = UtfClass::decode(std::begin(inputArray), std::end(inputArray), output, sf::Uint32(42));
    
    DataType* endIt = UtfClass::encode(input, outputArray.data(), sf::Uint32(42));
    typename decltype(inputArray)::iterator nextIt = UtfClass::next(std::begin(inputArray), std::end(inputArray));
    std::size_t count = UtfClass::count(std::begin(inputArray), std::end(inputArray));
    typename decltype(outputArray)::iterator ansiIt = UtfClass::fromAnsi(std::begin(inputArray), std::end(inputArray),
                                          std::begin(outputArray), std::locale());
	typename decltype(outputArray)::iterator fromWide = UtfClass::fromWide(std::begin(wideInput), std::end(wideInput),
                                            std::begin(outputArray));
	typename decltype(outputArray)::iterator fromLatin1 = UtfClass::fromLatin1(std::begin(inputArray), std::end(inputArray),
                                            std::begin(outputArray));
	typename decltype(outputArray)::iterator toAnsi = UtfClass::toAnsi(std::begin(inputArray), std::end(inputArray),
                                            std::begin(outputArray), 'z', std::locale());
	typename decltype(outputArray)::iterator toWide = UtfClass::toWide(std::begin(inputArray), std::end(inputArray),
                                            std::begin(outputArray), wchar_t(13));
	typename decltype(outputArray)::iterator toLatin1 = UtfClass::toLatin1(std::begin(inputArray), std::end(inputArray),
                                            std::begin(outputArray));
	typename decltype(outputArray)::iterator toUtf8 = UtfClass::toUtf8(std::begin(inputArray), std::end(inputArray),
                                        std::begin(outputArray));
	typename decltype(outputArray)::iterator toUtf16 = UtfClass::toUtf16(std::begin(inputArray), std::end(inputArray),
                                          std::begin(outputArray));
	typename decltype(outputArray)::iterator toUtf32 = UtfClass::toUtf32(std::begin(inputArray), std::end(inputArray),
                                          std::begin(outputArray));
}

void test_system_utf_hpp() {
    test_system_utf<sf::Utf8, sf::Int8>();
    test_system_utf<sf::Utf16, sf::Int16>();
    test_system_utf<sf::Utf32, sf::Int32>();
    
    std::array<sf::Int32, 3> inputArray = { 1, 2, 3};
    std::array<wchar_t, 3> wideInput = {};
    std::array<sf::Int32, 3> outputArray = {};
    sf::Uint32 input = 0, output = 0;
    
    sf::Uint32 decodedAnsi = sf::Utf32::decodeAnsi(input, std::locale());
    sf::Uint32 decodeWide = sf::Utf32::decodeWide(wchar_t(42));
    decltype(outputArray)::iterator encodeAnsi = sf::Utf32::encodeAnsi(sf::Uint32(42), std::begin(outputArray), 'z', std::locale());
	decltype(outputArray)::iterator endIt = sf::Utf32::encodeWide(sf::Uint32(42), std::begin(outputArray), wchar_t(42));
}

void test_vector2_hpp() {
    sf::Vector2<wchar_t> customVec, initialized(wchar_t(41), wchar_t(42));
    sf::Vector2u uintVec(1, 2);
    sf::Vector2i intVec(uintVec);
    sf::Vector2f floatVec;
    sf::Vector2i v1, v2;
    auto v3 = -v1;
    v1 += v2;
    v1 -= v2;
    v3 = v1 + v2;
    v3 = v1 - v2;
    v3 = v1 * 2;
    v3 = 2 * v1;
    v3 *= 2;
    v3 = v1 / 2;
    v3 /= 2;
    bool r = v1 == v2;
    r = v1 != v2;
    v3.x;
    v3.y;
}

void test_vector3_hpp() {
    sf::Vector3<wchar_t> customVec, initialized(wchar_t(41), wchar_t(42), wchar_t(43));
    sf::Vector3i intVec(customVec);
    sf::Vector3f floatVec;
    sf::Vector3i v1, v2;
    auto v3 = -v1;
    v1 += v2;
    v1 -= v2;
    v3 = v1 + v2;
    v3 = v1 - v2;
    v3 = v1 * 2;
    v3 = 2 * v1;
    v3 *= 2;
    v3 = v1 / 2;
    v3 /= 2;
    bool r = v1 == v2;
    r = v1 != v2;
    v3.x;
    v3.y;
    v3.z;
}
