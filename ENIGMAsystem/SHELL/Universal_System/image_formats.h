/** Copyright (C) 2008 Josh Ventura
*** Copyright (C) 2013-2014 Robert B. Colton
***
*** This file is a part of the ENIGMA Development Environment.
***
*** ENIGMA is free software: you can redistribute it and/or modify it under the
*** terms of the GNU General Public License as published by the Free Software
*** Foundation, version 3 of the license or any later version.
***
*** This application and its source code is distributed AS-IS, WITHOUT ANY
*** WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
*** FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
*** details.
***
*** You should have received a copy of the GNU General Public License along
*** with this code. If not, see <http://www.gnu.org/licenses/>
**/

#ifndef ENIGMA_IMAGEFORMATS_H
#define ENIGMA_IMAGEFORMATS_H

#include <string>
using std::string;

/// NOTE: These image formats expect the data to be un-aligned and always reads and writes with BGRA full color

namespace enigma {
	/// Color formats
	enum {
		color_fmt_rgba,
		color_fmt_rgb,
		color_fmt_bgra,
		color_fmt_bgr
	};

	/// Gets the image format, eg. ".bmp", ".png", etc.
	string image_get_format(string filename);
	/// Reverses the scan-lines from top to bottom or vice verse, this is not actually to be used, you should load and save the data correctly to avoid duplicating it
	unsigned char* image_flip(const unsigned char* data, unsigned width, unsigned height, unsigned bytesperpixel);
	
	/// Generic all-purpose image loading call.
	unsigned char* image_load(string filename, string format, unsigned int* width, unsigned int* height, unsigned int* fullwidth, unsigned int* fullheight, bool flipped);
	/// Generic all-purpose image loading call that will regexp the filename for the format and call the appropriate function.
	unsigned char* image_load(string filename, unsigned int* width, unsigned int* height, unsigned int* fullwidth, unsigned int* fullheight, bool flipped);
	/// Generic all-purpose image saving call.
	int image_save(string filename, const unsigned char* data, string format, unsigned width, unsigned height, unsigned fullwidth, unsigned fullheight, bool flipped);
	/// Generic all-purpose image saving call that will regexp the filename for the format and call the appropriate function.
	int image_save(string filename, const unsigned char* data, unsigned width, unsigned height, unsigned fullwidth, unsigned fullheight, bool flipped);
	
	unsigned char* image_load_bmp(string filename, unsigned int* width, unsigned int* height, unsigned int* fullwidth, unsigned int* fullheight, bool flipped);
	unsigned char* image_load_png(string filename, unsigned int* width, unsigned int* height, unsigned int* fullwidth, unsigned int* fullheight, bool flipped);
	int image_save_bmp(string filename, const unsigned char* data, unsigned width, unsigned height, unsigned fullwidth, unsigned fullheight, bool flipped);
	int image_save_png(string filename, const unsigned char* data, unsigned width, unsigned height, unsigned fullwidth, unsigned fullheight, bool flipped);
}

#endif //ENIGMA_IMAGEFORMATS_H
