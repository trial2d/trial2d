/*******************************************************************************
 * This file is part of the "https://github.com/trial2d/trial2d.hpp"
 * For conditions of distribution and use, see copyright notice in LICENSE.md
 * Copyright (C) 2020, by Matvey Cherevko (blackmatov@gmail.com)
 ******************************************************************************/

#include <trial2d/image/image.hpp>

#include <trial2d/debug/debug.hpp>
#include <trial2d/memory/memory.hpp>

#include "stb/stb_base.hpp"

namespace
{
    using namespace trial2d;

    class service_impl final : public image::service {
    public:
        service_impl(debug::service& debug, memory::service& memory)
        : debug_(debug)
        , memory_(memory) {
            debug_.trace("image::service()");
        }

        ~service_impl() {
            debug_.trace("~image::service()");
        }
    private:
        debug::service& debug_;
        memory::service& memory_;
    };
}

namespace trial2d::image
{
    void inject(di_ext::runtime_injector& injector) {
        injector.install(
            di::bind<image::service>.to<service_impl>()
        );
    }
}
