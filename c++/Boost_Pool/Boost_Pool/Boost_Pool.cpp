// Boost_Pool.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <chrono>
#include <boost/pool/pool_alloc.hpp>
int main()
{

	{

		std::vector<int> v;


		auto begin = std::chrono::system_clock::now();

		for (int i = 0; i < 1000000; i++) {
			v.push_back(i);
		}

		auto end = std::chrono::system_clock::now();


		std::cout << "1-elapse : " << (end - begin).count() << std::endl;

		v.clear();

	}
	std::vector<int, boost::pool_allocator<int>> v2;
	for (int i = 0; i < 1000; ++i)
		v2.push_back(i);


	auto end2 = std::chrono::system_clock::now();


	//std::cout << "2-elapse : " << (end2 - end).count() << std::endl;

	v2.clear();
	boost::singleton_pool<boost::pool_allocator_tag, sizeof(int)>::
		purge_memory();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
