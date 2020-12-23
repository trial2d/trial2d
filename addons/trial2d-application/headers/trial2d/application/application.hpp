/*******************************************************************************
 * This file is part of the "https://github.com/trial2d/trial2d.hpp"
 * For conditions of distribution and use, see copyright notice in LICENSE.md
 * Copyright (C) 2020, by Matvey Cherevko (blackmatov@gmail.com)
 ******************************************************************************/

#pragma once

#include <trial2d/trial2d.hpp>
#include <trial2d/debug/debug.hpp>
#include <trial2d/memory/memory.hpp>

namespace trial2d::application
{
    class application_service final
        : public service<application_service> {
    public:
        application_service(
            debug::debug_service& debug,
            memory::memory_service& memory);
        ~application_service();
    private:
        debug::debug_service& debug_;
        memory::memory_service& memory_;
    };

    inline application_service::entry the_application_service;
}
