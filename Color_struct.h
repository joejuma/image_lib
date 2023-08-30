#pragma once

#ifndef COLOR_STRUCT__H
#define COLOR_STRUCT__H
/* Deps */
#include "types.h"

struct Color
{
	/* Methods */

	// Metadata Getters
	virtual const byte channels() const = 0;

	// Color Access
	virtual byte* red() = 0;
	virtual byte* green() = 0;
	virtual byte* blue() = 0;
	virtual byte* alpha() = 0;

	// Serialization
	virtual string toString() const = 0;
};
#endif