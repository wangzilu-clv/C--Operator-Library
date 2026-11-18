#include "operator_lib/matmul.hpp"

namespace operator_lib {

Status matmul(ConstTensorView, ConstTensorView, TensorView) noexcept {
    return Status::NotImplemented;
}

}  // namespace operator_lib
