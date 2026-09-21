#include "frequency.h"

#include <stdexcept>
#include <unordered_map>

namespace algorithm_lab {

int mostFrequentNaive(const std::vector<int>& values) {
    if (values.empty()) {
        throw std::invalid_argument("values must not be empty");
    }

    int best_value = values.front();
    int best_count = 0;

    for (std::size_t i = 0; i < values.size(); ++i) {
        int current = values[i];
        int count = 0;
        for (std::size_t j = 0; j < values.size(); ++j) {
            if (values[j] == current) {
                ++count;
            }
        }

        if (count > best_count || (count == best_count && current < best_value)) {
            best_count = count;
            best_value = current;
        }
    }

    return best_value;
}

int mostFrequentEfficient(const std::vector<int>& values) {
    if (values.empty()) {
        throw std::invalid_argument("values must not be empty");
    }

    std::unordered_map<int, int> counts;
    counts.reserve(values.size());
    for (int value : values) {
        ++counts[value];
    }

    int best_value = values.front();
    int best_count = 0;
    for (const auto& entry : counts) {
        if (entry.second > best_count ||
            (entry.second == best_count && entry.first < best_value)) {
            best_count = entry.second;
            best_value = entry.first;
        }
    }

    return best_value;
}

}