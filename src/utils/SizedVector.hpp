#pragma once

#include <cstddef>
#include <stdexcept>
#include <vector>

template <typename T, size_t MinSize, size_t MaxSize>
class SizedVector {
   private:
    std::vector<T> data;

   public:
    SizedVector();

    static constexpr size_t getMinSize();
    static constexpr size_t getMaxSize();

    size_t size() const;

    const T& operator[](size_t index) const;
    T& operator[](size_t index);

    void push_back(const T& value);
    void pop_back();

    void resize(size_t newSize);

    bool empty() const;

    void clear();
};
