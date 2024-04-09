#include "diplomApp.h"

using namespace std;

int main()
{
	Image first("images/a.jpg");
	first.grayscale();
	first.write("images/b.jpg");
	first.bitReverse();
	first.write("images/c.jpg");

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

	first.write("images/d.jpg");

	Image second(first);
	second.bitReverse();
	second.write("images/e.jpg");

	return 0;
}
