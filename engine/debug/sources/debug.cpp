/*******************************************************************************
 * This file is part of the "https://github.com/trial2d/trial2d.hpp"
 * For conditions of distribution and use, see copyright notice in LICENSE.md
 * Copyright (C) 2020, by Matvey Cherevko (blackmatov@gmail.com)
 ******************************************************************************/

#include <trial2d/debug/debug.hpp>

namespace
{
    using namespace trial2d;

    class service_impl final : public debug::service {
    public:
        service_impl() {
            trace("debug::service()");
        }

        ~service_impl() {
            trace("~debug::service()");
        }

        void log(debug::level lvl, std::string_view msg) override {
            std::string_view lvl_str = enum_hpp::to_string_or_empty(lvl);
            std::printf("[%.*s]: %.*s\n",
                static_cast<int>(lvl_str.length()), lvl_str.data(),
                static_cast<int>(msg.length()), msg.data());
        }
    };
}

namespace trial2d::debug
{
    void service::trace(std::string_view msg) {
        log(level::trace, msg);
    }

    void service::warning(std::string_view msg) {
        log(level::warning, msg);
    }

    void service::error(std::string_view msg) {
        log(level::error, msg);
    }

    void service::fatal(std::string_view msg) {
        log(level::fatal, msg);
    }
}

namespace trial2d::debug
{
    void inject(di_ext::runtime_injector& injector) {
        injector.install(
            di::bind<debug::service>.to<service_impl>()
        );
    }
}
