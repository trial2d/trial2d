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
    audio_service::audio_service(
        debug::debug_service& debug,
        memory::memory_service& memory)
    : debug_(debug)
    , memory_(memory) {
        debug_.trace("audio_service()");
    }

    audio_service::~audio_service() {
        debug_.trace("~audio_service()");
    }
}
