#include <iostream>
#include <vector>
#include <random>
#include <memory>
#include <algorithm>
#include <functional>
#include <type_traits> // for std::is_same_v

std::vector<int> get_random_int_vector(const std::size_t n_elements, const int min, const int max)
{
    // First create an instance of an engine.
    std::random_device rnd_device;
    // Specify the engine and distribution.
    std::mt19937 mersenne_engine {rnd_device()};  // Generates random integers
    std::uniform_int_distribution<> dist {min, max};

    auto gen = [&dist, &mersenne_engine](){
        return dist(mersenne_engine);
    };

    std::vector<int> vec(n_elements);
    std::generate(begin(vec), end(vec), gen);

    return vec;
}

std::vector<int> get_random_int_vector_example()
{
    return {12,9,3,7,14,
            11,6,2,10,5};
}

template<typename T>
void print_vector(const std::vector<T> &vec)
{
    if (std::is_same_v<T, std::uint8_t>) {
        for (auto i : vec) {
            std::cout << static_cast<std::uint16_t>(i) << " ";
        }
    } else {
        for (auto i : vec) {
            std::cout << i << " ";
        }
    }
    std::cout << "\n";
}

int main()
{
    std::size_t N = 10;
    std::vector<int> vec = get_random_int_vector(N, -100, 100); // get_random_int_vector_example();
    print_vector(vec);
}
