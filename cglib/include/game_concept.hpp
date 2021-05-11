#include <type_traits>

template <typename T> concept CombinatorialGame = std::is_arithmetic<T>::value;