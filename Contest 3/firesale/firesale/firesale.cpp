
/*

find an array where max- min <= k
	then move the index outwards

max-min > k
	decrease max-min
	cant do so by moving the end points
	instead, do a sweep
		start at i = 0, j = 1;   [i, j)
		
keep tree map of value to frequency. maxKey - minKey

multiset in C++!

*/