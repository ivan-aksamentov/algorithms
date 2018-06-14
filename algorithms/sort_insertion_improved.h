#pragma once

template <typename T>
void sort_insertion_improved(T* a, int size) {
  for (int i = 0; i < size; ++i) {
    int j = i;
    T move_me = a[j];  // save current value
    for (; (j > 0) && (move_me < a[j - 1]); --j) {
      a[j] = a[j - 1];  // shift left neighbours that are less to the right
    }
    a[j] = move_me;  // insert current value in right place
  }
}
