/*
 * FTGL - OpenGL font library
 *
 * Copyright (c) 2001-2004 Henry Maddocks <ftgl@opengl.geek.nz>
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * Alternatively, you can redistribute and/or modify this software under
 * the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License,
 * or (at your option) any later version.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this software; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA.
 */

#ifndef __FTGLExtrdFontImpl__
#define __FTGLExtrdFontImpl__

#include "FTGLExtrdFont.h"
#include "FTFontImpl.h"

class FTGlyph;

class FTGLExtrdFontImpl : public FTFontImpl
{
    friend class FTGLExtrdFont;

    public:
        FTGLExtrdFontImpl(const char* fontFilePath);

        FTGLExtrdFontImpl(const unsigned char *pBufferBytes,
                          size_t bufferSizeInBytes);

        ~FTGLExtrdFontImpl();

        /**
         * Set the extrusion distance for the font.
         *
         * @param d  The extrusion distance.
         */
        void Depth(float d) { depth = d; }

        /**
         * Set the outset distance for the font. Only implemented by
         * FTGLOutlineFont, FTGLPolygonFont and FTGLExtrdFont
         *
         * @param f  The front outset distance.
         */
        void Outset(float f) { front = f; }

        /**
         * Set the outset distance for the font. Only implemented by
         * FTGLExtrdFont
         *
         * @param f  The front outset distance.
         * @param b  The back outset distance.
         */
        void Outset(float f, float b) { front = f; back = b; }

    private:
        /**
         * Construct a FTPolyGlyph.
         *
         * @param glyphIndex The glyph index NOT the char code.
         * @return An FTExtrdGlyph or <code>null</code> on failure.
         */
        inline virtual FTGlyph* MakeGlyph(unsigned int glyphIndex);

        /**
         * The extrusion distance for the font.
         */
        float depth;

        /**
         * The outset distance (front and back) for the font.
         */
        float front, back;
};

#endif // __FTGLExtrdFontImpl__
