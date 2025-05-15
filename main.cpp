#include "sum_array.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std::chrono;

int main()
{
	const int array_size = 1000;
	const int numb_threads = 5;
	SumArray summa(array_size, numb_threads);
    
    auto t_start = system_clock::now();
    int s = summa.calc_using_threads();
    auto t_end = system_clock::now();
    long diff = duration_cast<milliseconds>(t_end - t_start).count();
    std::cout << "SUM (using threads: " << numb_threads << "): " << s << "  Time: " << diff << std::endl;

    t_start = system_clock::now();
    s = summa.calc_without_threads();
    t_end = system_clock::now();
    diff = duration_cast<milliseconds>(t_end - t_start).count();
    std::cout << "SUM (main thread): " << s << "  Time: " << diff << std::endl;

    return 0;
}