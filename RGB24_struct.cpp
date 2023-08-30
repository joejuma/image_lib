#include "RGB24_struct.h"

#ifndef RGB24_STRUCT__CPP
#define RGB24_STRUCT__CPP

// Constructors & Destructor
RGB24::RGB24()
{
	this->r = 0;
	this->g = 0;
	this->b = 0;
}
RGB24::RGB24(const byte& _r, const byte& _g, const byte _b)
{
	this->r = _r;
	this->g = _g;
	this->b = _b;
}
RGB24::RGB24(const RGB24& source) // Maybe turn this into a Color* and use the getters?
{
	this->r = source.r;
	this->g = source.g;
	this->b = source.b;
}
RGB24::RGB24(Color& source)
{
	this->r = *source.red();
	this->g = *source.green();
	this->b = *source.blue();
}
RGB24::~RGB24()
{
	this->r = 0;
	this->g = 0;
	this->b = 0;
}

#endif