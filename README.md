# Image Library (C++)

## What is it?
A very simple library providing helper functions and object-oriented 
wrapping around part of the stb_image library.

## Status
This repository is work-in-progress. I've implemented the logic with tests in an internal-only library, but moving that out to this library in a succinct form has been put on the back-burner for now. Update to a fully-working implement is expected in November 2023.

## Features
* Importing images of *.png, *.jpg and *.bmp formats.
* Exporting images to various formats.
* A Color class with RGB24 and RGBA32 implementations.
* An Image class for object oriented image operations.

## How to use?
1. Download this repo.
2. Extract to where you want the files to be.
3. Add `#include "Image_struct.h"` and `#include "Colors.h"` to the 
files where you want to include this library.
4. All done!

## Author
Joseph M. Juma

## Credit
[1] stb_image: https://github.com/nothings/stb/blob/master/stb_image.h

## License
This work is provided as-is under the MIT license. To see more, please 
look at the `LICENSE.md` file.
