#include <type_traits>

<typename T> concept CombinatorialGame = requires(T a) {
        std::is_arithmetic<T>::value
}