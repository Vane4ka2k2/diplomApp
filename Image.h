#include <cstdio>
#include <stdint.h>

enum ImageType { PNG, JPG };

struct Image
{
	uint8_t* data = NULL;
	size_t size = 0;
	int width = 0;
	int height = 0;
	int channels = 0;

	Image(const char* filename);
	Image(int width, int height, int channels);
	Image(const Image& img);
	~Image();

	bool read(const char* filename);
	bool write(const char* filename);

	ImageType getFileType(const char* filename);

	Image& grayscale();
	Image& bitReverse();
};