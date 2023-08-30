#pragma once

#ifndef RGB24_STRUCT__H
#define RGB24_STRUCT__H
/* Deps */
#include "types.h"
#include "Color_struct.h"

struct RGB24 : Color
{
	/* Static Elements */
	static const byte _channels = 3;

	/* Elements */
	byte r;
	byte g;
	byte b;

	/* Methods */

	// Constructors & Destructor
	RGB24();
	RGB24(const byte& _r, const byte& _g, const byte _b);
	RGB24(const RGB24& source);
	RGB24(Color& source);
	virtual ~RGB24();

	// Metadata
	inline const byte channels() const override
	{
		return RGB24::_channels;
	};

	// Color Access
	inline byte* red() override
	{
		return &this->r;
	};
	inline byte* green() override
	{
		return &this->g;
	};
	inline byte* blue() override
	{
		return &this->b;
	};
	inline byte* alpha() override
	{
		return 0;
	}

	// Arithematic Operators
	// ...

	// Serialization
	inline string toString() const override
	{
		return (
			"(" +
			std::to_string(this->r) + "," +
			std::to_string(this->g) + "," +
			std::to_string(this->b) +
			")"
		);
	};
};

#endif