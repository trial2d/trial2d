/*******************************************************************************
 * This file is part of the "https://github.com/trial2d/trial2d.hpp"
 * For conditions of distribution and use, see copyright notice in LICENSE.md
 * Copyright (C) 2020, by Matvey Cherevko (blackmatov@gmail.com)
 ******************************************************************************/

#pragma once

#include <trial2d/core/core.hpp>

namespace trial2d
{
    inline di_ext::runtime_injector& main_injector() {
        static di_ext::runtime_injector the_injector;
        return the_injector;
    }
}
