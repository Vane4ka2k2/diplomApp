#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "stb_image.h"
#include "stb_image_write.h"
#include "Image.h"

Image::Image(const char* filename)
{
	if (read(filename))
		size = width * height * channels;
}

Image::Image(int width, int height, int channels) :
	width(width), height(height), channels(channels)
{
	size = width * height * channels;
	data = new uint8_t[size];
}

Image::Image(const Image& img) :
	Image(img.width, img.height, img.channels)
{
	memcpy(data, img.data, size);
}

Image::~Image()
{
	stbi_image_free(data);
}

bool Image::read(const char* filename)
{
	data = stbi_load(filename, &width, &height, &channels, 0);
	return data != NULL;
}

bool Image::write(const char* filename)
{
	ImageType type = getFileType(filename);
	int success = JPG;

	switch (type)
	{
	case PNG:
		success = stbi_write_png(filename, width, height, channels, data, width * height);
		break;
	case JPG:
		success = stbi_write_jpg(filename, width, height, channels, data, 100);
		break;
	}

	if (success != 0)
		return true;
	else
		return false;
}

ImageType Image::getFileType(const char* filename)
{
	const char* ext = strrchr(filename, '.');

	if (ext != nullptr)
	{
		if (strcmp(ext, ".png") == 0)
			return PNG;
		else if (strcmp(ext, ".jpg") == 0)
			return JPG;
	}

	return PNG;
}

Image& Image::grayscale()
{
	if (channels < 3)
	{

	}
	else
	{
		uint8_t* newData = new uint8_t[width * height];
		size_t j = 0;
		for (size_t i = 0; i < size; i += channels)
		{
			int gray = (data[i] + data[i + 1] + data[i + 2]) / 3;
			memset(data + i, gray, 3);
			newData[j] = gray;
			++j;
		}
		delete[] data;

		channels = 1;
		size = width * height * channels;
		data = new uint8_t[size];
		for (size_t i = 0; i < size; ++i)
		{
			data[i] = newData[i];
		}

		delete[] newData;
	}

	return *this;
}

Image& Image::bitReverse()
{


	return *this;
}
