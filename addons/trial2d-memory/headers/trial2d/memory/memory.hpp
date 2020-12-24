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
    class service final
        : public service_base<service> {
    public:
        service(debug::service& debug);
        ~service();
    private:
        debug::service& debug_;
    };

    inline service::entry the_service;
}
