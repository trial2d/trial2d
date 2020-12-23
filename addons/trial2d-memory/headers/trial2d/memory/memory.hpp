/*******************************************************************************
 * This file is part of the "https://github.com/trial2d/trial2d.hpp"
 * For conditions of distribution and use, see copyright notice in LICENSE.md
 * Copyright (C) 2020, by Matvey Cherevko (blackmatov@gmail.com)
 ******************************************************************************/

#pragma once

#include <trial2d/trial2d.hpp>
#include <trial2d/debug/debug.hpp>

namespace trial2d::memory
{
    class memory_service final
        : public service<memory_service> {
    public:
        memory_service(debug::debug_service& debug);
        ~memory_service();
    private:
        debug::debug_service& debug_;
    };

    inline memory_service::entry the_memory_service;
}
