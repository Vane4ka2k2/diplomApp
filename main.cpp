#include "diplomApp.h"

using namespace std;

int main()
{
	clock_t mainStart = clock();
	Image first("images/a.jpg");
	first.grayscale();
	first.write("images/b.jpg");
	clock_t start1 = clock();
	first.bitReverse();
	clock_t end1 = clock();
	printf_s("Time bit reverse: %f seconds\n", (double)(end1 - start1) / CLOCKS_PER_SEC);

	first.write("images/c.jpg");

	clock_t start2 = clock();
	for (size_t i = 0; i < first.height; ++i)
	{
		for (size_t j = 0; j < first.width; ++j)
		{
			if ((i < (first.height / 2)) || (j < (first.width / 2)))
			{
				first.data[i * first.width + j] = 0;
			}
		}
	}
	clock_t end2 = clock();
	printf_s("Time add noise: %f seconds\n", (double)(end2 - start2) / CLOCKS_PER_SEC);

	first.write("images/d.jpg");

	Image second(first);
	clock_t start3 = clock();
	second.bitReverse();
	clock_t end3 = clock();
	printf_s("Time bit reverse: %f seconds\n", (double)(end3 - start3) / CLOCKS_PER_SEC);
	second.write("images/e.jpg");
	clock_t mainEnd = clock();
	printf_s("Total time: %f seconds\n", (double)(mainEnd - mainStart) / CLOCKS_PER_SEC);

	system("pause");

	return 0;
}
