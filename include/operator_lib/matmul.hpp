#pragma once

#include "operator_lib/types.hpp"

namespace operator_lib {

// Computes output = lhs * rhs for 2D Float32 views in host memory.
// Required shapes are (M, K), (K, N), and (M, N), respectively.
// For nonempty views, supply positive strides and storage for every addressed
// element. Output elements need distinct addresses in storage disjoint from
// the inputs.
// The current scaffold returns Status::NotImplemented and leaves output intact.
[[nodiscard]] Status matmul(ConstTensorView lhs, ConstTensorView rhs,
                            TensorView output) noexcept;

}  // namespace operator_lib
