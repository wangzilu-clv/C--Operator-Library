#include "operator_lib/types.hpp"
#include "operator_lib/matmul.hpp"

#include <type_traits>

namespace ol = operator_lib;

static_assert(std::is_convertible_v<ol::TensorView, ol::ConstTensorView>);
static_assert(!std::is_convertible_v<ol::ConstTensorView, ol::TensorView>);

int main() {
    float lhs_data[] = {10.0f, 20.0f, 30.0f, 0.0f, 40.0f, 50.0f, 60.0f, 0.0f};
    const ol::TensorView lhs{lhs_data, {2, 3}, {4, 1}, ol::DType::Float32};
    const ol::ConstTensorView input = lhs;
    if (input.data != lhs_data || input.shape.rows != 2 || input.shape.cols != 3 ||
        input.stride.row != 4 || input.stride.col != 1 || input.dtype != ol::DType::Float32) {
        return 1;
    }

    const float rhs_data[] = {1.0f, 1.0f, 1.0f};
    const ol::ConstTensorView rhs{rhs_data, {3, 1}, {1, 1}, ol::DType::Float32};
    float output_data[] = {7.0f, 8.0f};
    const ol::TensorView output{output_data, {2, 1}, {1, 1}, ol::DType::Float32};

    if (ol::matmul(input, rhs, output) != ol::Status::NotImplemented ||
        output_data[0] != 7.0f || output_data[1] != 8.0f) {
        return 1;
    }

    return 0;
}
