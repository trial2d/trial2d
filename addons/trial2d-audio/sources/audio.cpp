/*******************************************************************************
 * This file is part of the "https://github.com/trial2d/trial2d.hpp"
 * For conditions of distribution and use, see copyright notice in LICENSE.md
 * Copyright (C) 2020, by Matvey Cherevko (blackmatov@gmail.com)
 ******************************************************************************/

#include <trial2d/audio/audio.hpp>

#include <trial2d/debug/debug.hpp>
#include <trial2d/memory/memory.hpp>

namespace
{
    using namespace trial2d;

    class service_impl final : public audio::service {
    public:
        service_impl(debug::service& debug, memory::service& memory)
        : debug_(debug)
        , memory_(memory) {
            debug_.trace("audio::service()");
        }

        ~service_impl() {
            debug_.trace("~audio::service()");
        }
    private:
        debug::service& debug_;
        memory::service& memory_;
    };
}

namespace trial2d::audio
{
    void inject(di_ext::runtime_injector& injector) {
        injector.install(
            di::bind<audio::service>.to<service_impl>()
        );
    }
}
