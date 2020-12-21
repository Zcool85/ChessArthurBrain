#ifndef _UNUSED_HPP_
#define _UNUSED_HPP_

// Just to avoid warning for unused variables...
template <typename... Args>
constexpr
void unused(Args&&...) {
}

#endif // _UNUSED_H_
