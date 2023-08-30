#pragma once

#ifndef MACROS__H
#define MACROS__H

#define SAFE_DELETE_PTR(ptr)\
	if(ptr != 0)\
	{\
		delete ptr;\
		ptr = 0;\
	}
#define SAFE_DELETE_BUFFER(ptr)\
	if(ptr != 0)\
	{\
		delete[] ptr;\
		ptr = 0;\
	}

#endif