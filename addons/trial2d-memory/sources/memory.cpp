/*******************************************************************************
 * This file is part of the "https://github.com/trial2d/trial2d.hpp"
 * For conditions of distribution and use, see copyright notice in LICENSE.md
 * Copyright (C) 2020, by Matvey Cherevko (blackmatov@gmail.com)
 ******************************************************************************/

#include <trial2d/memory/memory.hpp>

#include <trial2d/debug/debug.hpp>

namespace
{
    using namespace trial2d;

    class service_impl final : public memory::service {
    public:
        service_impl(debug::service& debug)
        : debug_(debug) {
            debug_.trace("memory::service()");
        }

        ~service_impl() {
            debug_.trace("~memory::service()");
        }
    private:
        debug::service& debug_;
    };
}

namespace trial2d::memory
{
    void inject(di_ext::runtime_injector& injector) {
        injector.install(
            di::bind<memory::service>.to<service_impl>()
        );
    }
}
