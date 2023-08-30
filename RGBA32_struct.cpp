#include "RGBA32_struct.h"

#ifndef RGBA32_STRUCT__CPP
#define RGBA32_STRUCT__CPP

// Constructors & Destructors
RGBA32::RGBA32()
{
	this->r = (byte)0;
	this->g = (byte)0;
	this->b = (byte)0;
	this->a = (byte)0;
}
RGBA32::RGBA32(const byte& _r, const byte& _g, const byte& _b, const byte& _a)
{
	this->r = _r;
	this->g = _g;
	this->b = _b;
	this->a = _a;
}
RGBA32::RGBA32(const RGBA32& source)
{
	this->r = source.r;
	this->g = source.g;
	this->b = source.b;
	this->a = source.a;
}
RGBA32::RGBA32(Color& source)
{
	this->r = *source.red();
	this->g = *source.green();
	this->b = *source.blue();
	this->a = *source.alpha();
}
RGBA32::~RGBA32()
{
	this->r = 0;
	this->g = 0;
	this->b = 0;
	this->a = 0;
}


#endif