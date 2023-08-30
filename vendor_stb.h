#pragma once

#ifndef VENDOR_STB_LIBRARY__H
#define VENDOR_STB_LIBRARY__H

#define STB_IMAGE_IMPLEMENTATION
#include "vendors/stb/stb_image.h"

#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "vendors/stb/stb_image_write.h"

#define DEPENDENCY_STB_LIBRARY_SATISFIED true

#endif