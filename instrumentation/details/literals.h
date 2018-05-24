#pragma once

constexpr long long operator"" _k(unsigned long long val) {
  return val * 1024ll;
}

constexpr long long operator"" _M(unsigned long long val) {
  return val * 1024ll * 1024ll;
}

constexpr long long operator"" _G(unsigned long long val) {
  return val * 1024ll * 1024ll * 1024ll;
}
