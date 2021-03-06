template <class T, class U>
inline bool chmax(T &a, const U &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T, class U>
inline bool chmin(T &a, const U &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
