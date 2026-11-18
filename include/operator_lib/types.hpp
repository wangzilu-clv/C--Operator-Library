#pragma once

#include <cstddef>
#include <cstdint>

namespace operator_lib {

enum class DType : std::uint8_t {
    Unknown,
    Float32,
    Int8,
};

enum class Status : std::uint8_t {
    Ok,
    InvalidArgument,
    UnsupportedDataType,
    NotImplemented,
};

struct Shape {
    std::size_t rows = 0;
    std::size_t cols = 0;
};

// Element offsets for advancing one row or one column in a 2D view.
struct Stride {
    std::size_t row = 0;
    std::size_t col = 0;
};

// Borrows read-only storage. Keep it alive while an operator uses the view.
struct ConstTensorView {
    const void* data = nullptr;
    Shape shape{};
    Stride stride{};
    DType dtype = DType::Unknown;
};

// Borrows writable storage with the same layout and lifetime rules.
struct TensorView {
    void* data = nullptr;
    Shape shape{};
    Stride stride{};
    DType dtype = DType::Unknown;

    constexpr operator ConstTensorView() const noexcept {
        return {data, shape, stride, dtype};
    }
};

}  // namespace operator_lib
