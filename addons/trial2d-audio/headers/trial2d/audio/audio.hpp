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
    class service final
        : public service_base<service> {
    public:
        service(
            debug::service& debug,
            memory::service& memory);
        ~service();
    private:
        debug::service& debug_;
        memory::service& memory_;
    };

    inline service::entry the_service;
}
