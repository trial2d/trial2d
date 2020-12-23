/*******************************************************************************
 * This file is part of the "https://github.com/trial2d/trial2d.hpp"
 * For conditions of distribution and use, see copyright notice in LICENSE.md
 * Copyright (C) 2020, by Matvey Cherevko (blackmatov@gmail.com)
 ******************************************************************************/

#include <trial2d/memory/memory.hpp>

namespace
{
}

namespace trial2d::memory
{
    memory_service::memory_service(
        debug::debug_service& debug)
    : debug_(debug) {
        debug_.trace("memory_service()");
    }

    memory_service::~memory_service() {
        debug_.trace("~memory_service()");
    }
}
