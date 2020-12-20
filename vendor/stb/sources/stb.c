/*******************************************************************************
 * This file is part of the "https://github.com/trial2d/trial2d.hpp"
 * For conditions of distribution and use, see copyright notice in LICENSE.md
 * Copyright (C) 2020, by Matvey Cherevko (blackmatov@gmail.com)
 ******************************************************************************/

//
// stb_image
//

#define STBI_ONLY_PNG
#define STBI_ONLY_TGA
#define STBI_ONLY_JPEG

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

//
// stb_image_write
//

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb/stb_image_write.h>
