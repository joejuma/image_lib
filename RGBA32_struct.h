#pragma once

#ifndef RGBA32_STRUCT__H
#define RGBA32_STRUCT__H
/* Deps */
#include "types.h"
#include "Color_struct.h"

struct RGBA32 : Color
{

	/* Static Elements */
	static const byte _channels = 4;

	/* Elements */
	byte r;
	byte g;
	byte b;
	byte a;

	/* Methods */

	// Constructors & Destructor
	RGBA32();
	RGBA32(const byte& _r, const byte& _g, const byte& _b, const byte& _a);
	RGBA32(const RGBA32& source);
	RGBA32(Color& source);
	virtual ~RGBA32();

	// Metadata
	inline const byte channels() const override
	{
		return RGBA32::_channels;
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
		return &this->a;
	};

	// Arithematic Operators
	// RGBA32 operator+(const RGBA32& B);
	// RGBA32 operator-(const RGBA32& B);

	// Serialization
	inline string toString() const override
	{
		return (
			"(" +
			std::to_string(this->r) + "," +
			std::to_string(this->g) + "," +
			std::to_string(this->b) + "," +
			std::to_string(this->a) +
			")"
			);
	};
};

#endif