template<typename T>
struct BinaryIndexedTree {
private:
  std::vector<T> node;

public:
  BinaryIndexedTree(int n_) { node.resize(n_, 0); }
  void add(int k, T x) {
    for (int j = k + 1; j <= node.size(); j += j & -j) node[j-1] += x;
  }
  T sum(int k) { // [0, k)
    T acc = 0;
    for (int j = k; j > 0; j -= j & -j) acc += node[j-1];
    return acc;
  }
};