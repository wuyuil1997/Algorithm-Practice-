#pragma once
int sum(int start, int end) {
	static int sum = 0;
	for (int i = start; i <= end; ++i) {
		sum += i;
	}
	return sum;
}