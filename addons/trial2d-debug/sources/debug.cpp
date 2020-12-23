/*******************************************************************************
 * This file is part of the "https://github.com/trial2d/trial2d.hpp"
 * For conditions of distribution and use, see copyright notice in LICENSE.md
 * Copyright (C) 2020, by Matvey Cherevko (blackmatov@gmail.com)
 ******************************************************************************/

#include <trial2d/debug/debug.hpp>

#include <iostream>

namespace
{
}

namespace trial2d::debug
{
    debug_service::debug_service() {
        trace("debug_service()");
    }

    debug_service::~debug_service() {
        trace("~debug_service()");
    }

    debug_service& debug_service::trace(std::string_view msg) {
        return log(level::trace, msg);
    }

    debug_service& debug_service::warning(std::string_view msg) {
        return log(level::warning, msg);
    }

    debug_service& debug_service::error(std::string_view msg) {
        return log(level::error, msg);
    }

    debug_service& debug_service::fatal(std::string_view msg) {
        return log(level::fatal, msg);
    }

    debug_service& debug_service::log(level lvl, std::string_view msg) {
        std::cout << "LOG[" << enum_hpp::to_string_or_empty(lvl) << "]: " << msg << std::endl;
        return *this;
    }
}
