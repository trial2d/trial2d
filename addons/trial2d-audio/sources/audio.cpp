/*******************************************************************************
 * This file is part of the "https://github.com/trial2d/trial2d.hpp"
 * For conditions of distribution and use, see copyright notice in LICENSE.md
 * Copyright (C) 2020, by Matvey Cherevko (blackmatov@gmail.com)
 ******************************************************************************/

#include <trial2d/audio/audio.hpp>

namespace
{
}

namespace trial2d::audio
{
    service::service(
        debug::service& debug,
        memory::service& memory)
    : debug_(debug)
    , memory_(memory) {
        debug_.trace("audio::service()");
    }

    service::~service() {
        debug_.trace("~audio::service()");
    }
}
