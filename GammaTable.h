#pragma once
#ifndef EMBEDDEDUTILS_GAMMA_H
#define EMBEDDEDUTILS_GAMMA_H

#ifdef __AVR__
#include "RingBuffer.h"
#else
#include <cmath>
#include <array>
#endif

template <typename TYPE, size_t SIZE>
class GammaTable
{
#ifdef __AVR__
    using ArrayType = RingBuffer<TYPE, SIZE>;
#else
    using ArrayType = std::array<TYPE, SIZE>;
#endif

public:

    GammaTable(const float gamma, const size_t scale = static_cast<float>(SIZE))
    : gamma_(gamma), scale_(scale)
    {
        create();
    }

    void gamma(const float g) { gamma_ = g; create(); }
    float gamma() const { return gamma_; }

    void scale(const float s) { scale_ = s; create(); }
    float scale() const { return scale_; }

    const TYPE& operator [](const size_t index) const { return gamma_array[index]; }
    const TYPE& at(const size_t index) const { return gamma_array.at(index); }
    size_t size() const { return gamma_array.size(); }

private:

    void create()
    {
        for (size_t i = 0; i < SIZE; ++i)
        {
#ifdef __AVR__
            gamma_array.push(static_cast<TYPE>(pow(static_cast<float>(i) / static_cast<float>(SIZE), gamma_) * scale_));
#else
            gamma_array[i] = static_cast<TYPE>(pow(static_cast<float>(i) / static_cast<float>(SIZE), gamma_) * scale_);
#endif
        }
    }

    float gamma_;
    float scale_;
    ArrayType gamma_array;
};

#endif // EMBEDDEDUTILS_GAMMA_H
