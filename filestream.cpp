/* This file is part of mortar.
 *
 * mortar is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * mortar is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with mortar.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "filestream.hpp"

FileStream::FileStream(const char *path, const char *mode) : Stream::Stream() {
	this->fp = fopen(path, mode);
}

FileStream::~FileStream() {
	fclose(fp);
}

void FileStream::seek(long offset, int whence) {
	fseek(this->fp, offset, whence);
}

long FileStream::tell() {
	return ftell(this->fp);
}

void *FileStream::read(size_t size) {
	uint8_t *ptr = new uint8_t[size];

	fread(ptr, 1, size, this->fp);

	return (void *)ptr;
}
