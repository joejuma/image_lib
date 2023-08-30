#pragma once

#ifndef IMAGE_STRUCT__H
#define IMAGE_STRUCT__H
/* Deps */
#include "types.h"
#include "Colors.h"

struct Image
{
	/* Elements */
	uint64 width;
	uint64 height;
	uint64 size;

	byte channels;
	Color* pixels;

	/* Methods */

	// Constructors & Destructor
	Image();
	Image(const Image& source);
	Image(const uint64 w, const uint64 h, const byte channels, const Color* pixels);
	Image(const uint64 w, const uint64 h, const byte channels, const byte* buffer);
	Image(const string& path);
	virtual ~Image();

	// Pixel Access
	inline Color* operator[](const uint64& i)
	{
		if (i < this->size)
		{
			return &this->pixels[i];
		}
		else
		{
			return 0;
		};
	};
	inline Color* get(const uint64& x, const uint64& y)
	{
		return (*this)[((this->width * y) + x)];
	};

	// Serialization
	bool toBytes(uint64& width, uint64& height, byte& channels, byte*& buffer) const;

	// Importing
	bool fromPixels(const uint64& width, const uint64& height, const byte& channels, const Color* pixels);
	bool fromBytes(const uint64& width, const uint64& height, const byte& channels, const byte* buffer);
	bool fromFile(const string& path);

	// Exporting
	bool toPNG(const string& path) const;
	bool toJPG(const string& path, const uint64& quality) const;
	bool toBMP(const string& path) const;

};
#endif