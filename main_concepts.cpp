#include <stdio.h>

// Constraints
template<int N> concept BaseCase = N == 1;
template<int N> concept Fizzable = N % 3 == 0;
template<int N> concept Buzzable = N % 5 == 0;

template<int N> void print() requires BaseCase<N>;
template<int N> void print() requires Fizzable<N> && Buzzable<N>;
template<int N> void print() requires Fizzable<N>;
template<int N> void print() requires Buzzable<N>;
template<int N> void print();

template<int N> void print() {
	print<N - 1>();
	printf("%d\n", N);
}

template<int N> void print() requires Fizzable<N> && Buzzable<N> {
	print<N - 1>();
	printf("FizzBuzz\n");
}

template<int N> void print() requires Buzzable<N> {
	print<N - 1>();
	printf("Buzz\n", N);
}

template<int N> void print() requires Fizzable<N> {
	print<N - 1>();
	printf("Fizz\n", N);
}

template<int N> void print() requires BaseCase<N> {
	printf("%d\n", N);
}

int main(int argn, char** argv) {
	print<100>();

	return 0;
}