// QuickSort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>

#include "Sorts.h"
#include "BetterQuickSort.h"

template <class _RandomAccessIterator>
int32_t countTime(_RandomAccessIterator first, _RandomAccessIterator last, void (*sort)(_RandomAccessIterator, _RandomAccessIterator))
{
    auto begin = std::chrono::high_resolution_clock::now();
    sort(first, last);
    auto end = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
}

int main()
{
    std::mt19937 gen(time(nullptr));
    std::uniform_int_distribution<int> dist_n(1000, 10000);
    std::uniform_int_distribution<int> dist(-100000, 100000);
    
    size_t t;
    std::cout << "Input number of tests: ";
    std::cin >> t;

    for (size_t _ = 0; _ < t; ++_) {
        size_t n = dist_n(gen);
        std::vector<int> arr(n);
        std::generate_n(arr.begin(), n, [&dist, &gen]() { return dist(gen); });
        std::vector<int> arr0(arr), arr1(arr), arr2(arr);

        std::cout << "\nArray size: " << n;
        std::cout << "\nstd::sort time: " << countTime(arr0.begin(), arr0.end(), std::sort);
        std::cout << "\nquickSort time: " << countTime(arr1.begin(), arr1.end(), quickSort);
        std::cout << "\nbetterQuickSort time: " << countTime(arr2.begin(), arr2.end(), betterQuickSort);
        std::cout << '\n';
    }

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
