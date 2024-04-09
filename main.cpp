#include "diplomApp.h"

using namespace std;

int main()
{
	Image first("images/a.jpg");
	first.grayscale();
	first.write("images/b.jpg");
	Image second(first);
	second.write("images/c.jpg");

	return 0;
}
