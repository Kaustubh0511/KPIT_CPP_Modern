#include "Smart.cpp"
#include <utility>

template <typename T, typename... pck>
Smart<T> make_smart(pck &&...p)
{
    T *tmp = new T(std::forward<pck>(p)...);
    return Smart<T>(tmp);
}