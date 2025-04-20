#include "SizedVector.hpp"

template <typename T, size_t MinSize, size_t MaxSize>
SizedVector<T, MinSize, MaxSize>::SizedVector() {
    if (MinSize > MaxSize) {
        throw std::invalid_argument("Minimum size cannot be greater than maximum size.");
    } else if (MinSize == MaxSize) {
        throw std::invalid_argument(
            "Minimum size and maximum size are the same, use std::array instead.");
    }

    data.reserve(MaxSize);
    data.resize(MinSize);
}

template <typename T, size_t MinSize, size_t MaxSize>
constexpr size_t SizedVector<T, MinSize, MaxSize>::getMinSize() {
    return MinSize;
}

template <typename T, size_t MinSize, size_t MaxSize>
constexpr size_t SizedVector<T, MinSize, MaxSize>::getMaxSize() {
    return MaxSize;
}

template <typename T, size_t MinSize, size_t MaxSize>
size_t SizedVector<T, MinSize, MaxSize>::size() const {
    return data.size();
}

template <typename T, size_t MinSize, size_t MaxSize>
const T& SizedVector<T, MinSize, MaxSize>::operator[](size_t index) const {
    if (index >= data.size()) {
        throw std::out_of_range("Index out of bounds.");
    }

    return data[index];
}

template <typename T, size_t MinSize, size_t MaxSize>
T& SizedVector<T, MinSize, MaxSize>::operator[](size_t index) {
    if (index >= data.size()) {
        throw std::out_of_range("Index out of bounds.");
    }

    return data[index];
}

template <typename T, size_t MinSize, size_t MaxSize>
void SizedVector<T, MinSize, MaxSize>::push_back(const T& value) {
    if (data.size() < MaxSize) {
        data.push_back(value);
    } else {
        throw std::overflow_error("SizedVector reached maximum size.");
    }
}

template <typename T, size_t MinSize, size_t MaxSize>
void SizedVector<T, MinSize, MaxSize>::pop_back() {
    if (data.size() > MinSize) {
        data.pop_back();
    } else {
        throw std::underflow_error("SizedVector is at its minimum size.");
    }
}

template <typename T, size_t MinSize, size_t MaxSize>
void SizedVector<T, MinSize, MaxSize>::resize(size_t newSize) {
    if (newSize < MinSize || newSize > MaxSize) {
        throw std::out_of_range("New size is outside the allowed range.");
    }

    data.resize(newSize);
}

template <typename T, size_t MinSize, size_t MaxSize>
bool SizedVector<T, MinSize, MaxSize>::empty() const {
    return data.empty();
}

template <typename T, size_t MinSize, size_t MaxSize>
void SizedVector<T, MinSize, MaxSize>::clear() {
    data.clear();
    data.resize(MinSize);
}
