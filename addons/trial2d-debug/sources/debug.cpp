/*******************************************************************************
 * This file is part of the "https://github.com/trial2d/trial2d.hpp"
 * For conditions of distribution and use, see copyright notice in LICENSE.md
 * Copyright (C) 2020, by Matvey Cherevko (blackmatov@gmail.com)
 ******************************************************************************/

#include <trial2d/debug/debug.hpp>

namespace
{
}

namespace trial2d::debug
{
    service::service() {
        trace("debug::service()");
    }

    service::~service() {
        trace("~debug::service()");
    }

    service& service::trace(std::string_view msg) {
        return log(level::trace, msg);
    }

    service& service::warning(std::string_view msg) {
        return log(level::warning, msg);
    }

    service& service::error(std::string_view msg) {
        return log(level::error, msg);
    }

    service& service::fatal(std::string_view msg) {
        return log(level::fatal, msg);
    }

    service& service::log(level lvl, std::string_view msg) {
        std::string_view lvl_str = enum_hpp::to_string_or_empty(lvl);
        std::printf("[%.*s]: %.*s\n",
            static_cast<int>(lvl_str.length()), lvl_str.data(),
            static_cast<int>(msg.length()), msg.data());
        return *this;
    }
}
