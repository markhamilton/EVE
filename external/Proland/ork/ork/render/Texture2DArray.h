/*
 * Ork: a small object-oriented OpenGL Rendering Kernel.
 * Copyright (c) 2008-2010 INRIA
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or (at
 * your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA.
 */

/*
 * Authors: Eric Bruneton, Antoine Begault, Guillaume Piolat.
 */

#ifndef _ORK_TEXTURE_2D_ARRAY_H_
#define _ORK_TEXTURE_2D_ARRAY_H_

#include "ork/render/Buffer.h"
#include "ork/render/Texture2D.h"

namespace ork
{

/**
 * A 2D array texture.
 * @ingroup render
 */
class ORK_API Texture2DArray : public Texture
{
public:
    /**
     * Creates a new 2D texture array.
     *
     * @param w the width of this texture in pixels.
     * @param h the height of this texture in pixels.
     * @param l the number of layers of this texture.
     * @param tf texture data format on GPU.
     * @param f the texture components in 'pixels'.
     * @param t the type of each component in 'pixels'.
     * @param params optional additional texture parameters.
     * @param s optional pixel storage parameters for 'pixels'.
     * @param pixels the pixels to be written into this texture.
     */
    Texture2DArray(int w, int h, int l, TextureInternalFormat tf, TextureFormat f, PixelType t,
        const Parameters &params, const Buffer::Parameters &s, const Buffer &pixels);

    /**
     * Destroys this 2D texture.
     */
    virtual ~Texture2DArray();

    /**
     * Returns the width of this texture.
     */
    int getWidth();

    /**
     * Returns the height of this texture.
     */
    int getHeight();

    /**
     * Returns the number of layers of this texture.
     */
    int getLayers();

    /**
     * Replaces a part of the content of this texture.
     *
     * @param level the LOD level to be changed.
     * @param x lower left corner of the part to be replaced, in pixels.
     * @param y lower left corner of the part to be replaced, in pixels.
     * @param l first layer of the part to be replaced.
     * @param w the width of the part to be replaced, in pixels.
     * @param h the height of the part to be replaced, in pixels.
     * @param d number of layers of the part to be replaced.
     * @param f the texture components in 'pixels'.
     * @param t the type of each component in 'pixels'.
     * @param s optional pixel storage parameters for 'pixels'.
     * @param pixels the pixels to be written into this texture LOD level.
     */
    void setSubImage(int level, int x, int y, int l, int w, int h, int d, TextureFormat f, PixelType t, const Buffer::Parameters &s, const Buffer &pixels);

    /**
     * Replaces a part of the content of this texture.
     *
     * @param level the LOD level to be changed.
     * @param x lower left corner of the part to be replaced, in pixels.
     * @param y lower left corner of the part to be replaced, in pixels.
     * @param l first layer of the part to be replaced.
     * @param w the width of the part to be replaced, in pixels.
     * @param h the height of the part to be replaced, in pixels.
     * @param d number of layers of the part to be replaced.
     * @param s the size of 'pixels' in bytes.
     * @param pixels the pixels to be written into this texture LOD level.
     */
    void setCompressedSubImage(int level, int x, int y, int l, int w, int h, int d, int s, const Buffer &pixels);

    /**
     * Returns the maximum number of layers for array textures.
     */
    static int getMaxLayers();

protected:
    /**
     * The width of this texture.
     */
    int w;

    /**
     * The height of this texture.
     */
    int h;

    /**
     * The number of this layers of this texture.
     */
    int l;

    /**
     * Creates a new unitialized 2DArray texture.
     */
    Texture2DArray();

    /**
     * Initializes this texture.
     *
     * @param w the width of this texture in pixels.
     * @param h the height of this texture in pixels.
     * @param l the number of layers of this texture.
     * @param tf texture data format on GPU.
     * @param f the texture components in 'pixels'.
     * @param t the type of each component in 'pixels'.
     * @param params optional additional texture parameters.
     * @param s optional pixel storage parameters for 'pixels'.
     * @param pixels the pixels to be written into this texture.
     */
    void init(int w, int h, int l, TextureInternalFormat tf, TextureFormat f, PixelType t,
        const Parameters &params, const Buffer::Parameters &s, const Buffer &pixels);

    virtual void swap(ptr<Texture> t);
};

}

#endif
