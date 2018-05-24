#pragma once

template <typename ValT, typename AvgT, typename SizeT>
AvgT update_average(ValT new_value, AvgT old_avg, SizeT new_num_values) {
  return old_avg + ((new_value - old_avg) / new_num_values);
}
