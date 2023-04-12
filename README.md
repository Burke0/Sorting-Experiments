# Sorting Experiments
 Compares running times of four sorting algorithms

QS The standard Quick Sort using the smaller of the first and last elements as the pivot.

MS The standard Merge Sort.

QI A variation of Quick Sort where a sub-array of size ten or less is sorted using insertion
sort, i.e., the recursion stops when a sub-array size reaches ten or less.

QM A combination of Quick Sort and Merge Sort, where the original array of size 𝑛 is split
into ⌈√𝑛⌉ sub-arrays of size √𝑛 (except for the last sub-array, which can have less than
√𝑛 elements), each sub-array is sorted using standard Quick Sort, then the sorted
sub-arrays are merged using a linear merge (as used in merge sort).