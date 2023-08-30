#include "Image_struct.h"

#ifndef IMAGE_STRUCT__CPP
#define IMAGE_STRUCT__CPP
/* Deps */
#include "macros.h"
#include "vendor_stb.h"

/* Macros */
#define IMAGE_ZERO_INIT_STRUCT \
	this->width = 0;\
	this->height = 0;\
	this->size = 0;\
	this->channels = 0;\
	this->pixels = 0

/* Helper Functions */
Color* initialize_pixel_buffer(const uint64& size, const byte& channels)
{
	switch (channels)
	{
	case 3:
		return new RGB24[size];
		break; // @note: technically unreachable.
	case 4:
		return new RGBA32[size];
		break; // @note: technically unreachable.
	default:
		return 0;
		break; // @note: technically unreachable.
	};
};
Color* initialize_blank_pixel( const byte& channels )
{
	switch (channels)
	{
	case 3:
		return new RGB24();
	case 4:
		return new RGBA32();
	default:
		return 0;
	};
};

inline bool importImage(const string& path, int& width, int& height, int& channels, unsigned char** data)
{
#ifdef DEPENDENCY_STB_LIBRARY_SATISFIED
	(*data) = stbi_load(path.c_str(), &width, &height, &channels, 0);
	return true;
#else
	#error "The dependency stb_image doesn't appear to be included."
	return false;
#endif
};

inline bool exportPNG(const string& path, const uint64& width, const uint64& height, const byte& channels, byte* data)
{
#ifdef DEPENDENCY_STB_LIBRARY_SATISFIED
	stbi_write_png(path.c_str(), width, height, channels, data, (width * channels));
	return true;
#else
	#error "The dependency stb_image doesn't appear to be included."
	return false;
#endif
};
inline bool exportJPG(const string& path, const uint64& width, const uint64& height, byte* data, const uint64& quality)
{
#ifdef DEPENDENCY_STB_LIBRARY_SATISFIED
	stbi_write_jpg(path.c_str(), width, height, 3, data, quality); // 3 channels is mandatory for JPG.
	return true;
#else
#error "The dependency stb_image doesn't appear to be included."
	return false;
#endif
};
inline bool exportBMP(const string& path, const uint64& width, const uint64& height, const byte& channels, byte* data)
{
#ifdef DEPENDENCY_STB_LIBRARY_SATISFIED
	stbi_write_bmp(path.c_str(), width, height, channels, data);
	return true;
#else
#error "The dependency stb_image doesn't appear to be included."
	return false;
#endif
};

/* Methods */
// Constructors & Destructor
Image::Image()
{
	this->width = 0;
	this->height = 0;
	this->size = 0;
	this->channels = 0;
	this->pixels = 0;
}
Image::Image(const Image& source)
{
	this->width = source.width;
	this->height = source.height;
	this->size = this->width * this->height;
	this->channels = source.channels;

	Color* blankPixel = initialize_blank_pixel(this->channels);
	this->pixels = initialize_pixel_buffer(this->size, this->channels);
	Image& src = (Image&)source;
	for (uint64 i = 0; i < this->size; i++)
	{
		if (src[i] != 0)
		{
			this->pixels[i] = *(src[i]);
		}
		else
		{
			this->pixels[i] = *blankPixel;
		};
	};
}
Image::Image(const uint64 w, const uint64 h, const byte channels, const Color* pixels)
{
	if (!this->fromPixels(w, h, channels, pixels))
	{
		IMAGE_ZERO_INIT_STRUCT;
	};
}
Image::Image(const uint64 w, const uint64 h, const byte channels, const byte* buffer)
{
	if (!this->fromBytes(w, h, channels, buffer))
	{
		IMAGE_ZERO_INIT_STRUCT;
	};
}
Image::Image(const string& path)
{
	if (!this->fromFile(path))
	{
		IMAGE_ZERO_INIT_STRUCT;
	};
}
Image::~Image()
{
	this->width = 0;
	this->height = 0;
	this->size = 0;
	this->channels = 0;

	SAFE_DELETE_BUFFER(this->pixels);
}

// Serialization
bool Image::toBytes(uint64& width, uint64& height, byte& channels, byte*& buffer) const
{
	return false; // @todo
}

// Importing
bool Image::fromPixels(const uint64& width, const uint64& height, const byte& channels, const Color* pixels)
{
	return false; // @todo
}
bool Image::fromBytes(const uint64& width, const uint64& height, const byte& channels, const byte* buffer)
{
	return false; // @todo
}
bool Image::fromFile(const string& path)
{
	return false; // @todo
}

// Exporting
bool Image::toPNG(const string& path) const
{
	#ifdef DEPENDENCY_STB_LIBRARY_SATISFIED
		return false; //@todo
	#else
	#error "The dependency stb_image doesn't appear to be included."
		return false;
	#endif
}
bool Image::toJPG(const string& path, const uint64& quality) const
{
	#ifdef DEPENDENCY_STB_LIBRARY_SATISFIED
		return false; //@todo
	#else
		#error "The dependency stb_image doesn't appear to be included."
		return false;
	#endif
}
bool Image::toBMP(const string& path) const
{
	#ifdef DEPENDENCY_STB_LIBRARY_SATISFIED
		return false; //@todo
	#else
	#error "The dependency stb_image doesn't appear to be included."
		return false;
	#endif
}
#endif