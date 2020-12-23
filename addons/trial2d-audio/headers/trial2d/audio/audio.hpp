/*******************************************************************************
 * This file is part of the "https://github.com/trial2d/trial2d.hpp"
 * For conditions of distribution and use, see copyright notice in LICENSE.md
 * Copyright (C) 2020, by Matvey Cherevko (blackmatov@gmail.com)
 ******************************************************************************/

#pragma once

#include <trial2d/trial2d.hpp>
#include <trial2d/debug/debug.hpp>
#include <trial2d/memory/memory.hpp>

namespace trial2d::audio
{
    class audio_service final
        : public service<audio_service> {
    public:
        audio_service(
            debug::debug_service& debug,
            memory::memory_service& memory);
        ~audio_service();
    private:
        debug::debug_service& debug_;
        memory::memory_service& memory_;
    };

    inline audio_service::entry the_audio_service;
}
