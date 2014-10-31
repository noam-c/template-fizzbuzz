#include <iostream>
#include <type_traits>

template<int N, typename std::enable_if<N == 1, bool>::type = true> void  print();
template<int N, typename std::enable_if<N % 5 != 0 && N % 3 == 0, bool>::type = true> void print();
template<int N, typename std::enable_if<N % 5 == 0 && N % 3 != 0, bool>::type = true> void print();
template<int N, typename std::enable_if<N % 15 == 0, bool>::type = true> void print();
template<int N, typename std::enable_if<N % 5 != 0 && N % 3 != 0 && N != 1, bool>::type = true> void print();

template<int N, typename std::enable_if<N % 5 != 0 && N % 3 == 0, bool>::type> void print()
{
   print<N-1>();
   std::cout << "Fizz" << std::endl;
}

template<int N, typename std::enable_if<N % 5 == 0 && N % 3 != 0, bool>::type> void print()
{
   print<N-1>();
   std::cout << "Buzz" << std::endl;
}

template<int N, typename std::enable_if<N % 15 == 0, bool>::type> void print()
{
   print<N-1>();
   std::cout << "Fizzbuzz" << std::endl;
}

template<int N, typename std::enable_if<N == 1, bool>::type> void  print()
{
   std::cout << 1 << std::endl;
}

template<int N, typename std::enable_if<N % 5 != 0 && N % 3 != 0 && N != 1, bool>::type> void print()
{
   print<N-1>();
   std::cout << N << std::endl;
}

int main (int argc, char *argv[])
{  
   print<100>();
}

