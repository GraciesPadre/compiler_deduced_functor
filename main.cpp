#include <iostream>
#include <vector>

struct dog_t {
    std::string name;
    bool isEskimo;
};

template<typename FilterFunction>
std::vector<dog_t> filterDogs(const std::vector<dog_t> &dogs, FilterFunction filter) {
    std::vector<dog_t> result;

    std::copy_if(dogs.cbegin(), dogs.cend(), std::back_inserter(result), filter);

    return result;
}

int main() {
    auto eskimos = filterDogs({{"Trixie", false},
                               {"Shasta", true},
                               {"Gracie", true}},
                              [](const dog_t &dog) { return dog.isEskimo; });

    for (const dog_t &eskimo : eskimos) {
        std::cout << eskimo.name << std::endl;
    }

    return 0;
}
