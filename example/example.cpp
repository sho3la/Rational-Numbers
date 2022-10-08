#include <iostream>
#include <chrono>

using namespace std;

#include <exact_double.h>

int main()
{
	Rational::exact_double a;
	exact_double_new(a, (1 / 2));

	Rational::exact_double b;
	exact_double_new(b, (1 / 3));

	Rational::exact_double res;
	exact_double_new(res, 0);

	auto start = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < 1000000; ++i)
	{
		exact_double_div(a, b, res);
	}

	auto end = std::chrono::high_resolution_clock::now();
	auto dur = end - start;
	auto i_millis = std::chrono::duration_cast<std::chrono::milliseconds>(dur);

	cout << "time = " << i_millis.count() << endl;

	return 0;
}