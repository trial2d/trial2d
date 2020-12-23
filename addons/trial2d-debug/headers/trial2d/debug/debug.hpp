/*******************************************************************************
 * This file is part of the "https://github.com/trial2d/trial2d.hpp"
 * For conditions of distribution and use, see copyright notice in LICENSE.md
 * Copyright (C) 2020, by Matvey Cherevko (blackmatov@gmail.com)
 ******************************************************************************/

#pragma once

#include <trial2d/trial2d.hpp>

namespace trial2d::debug
{
    ENUM_HPP_CLASS_DECL(level, std::uint8_t,
        (trace)
        (warning)
        (error)
        (fatal))
    ENUM_HPP_REGISTER_TRAITS(level)

    class debug_service final
        : public service<debug_service> {
    public:
        debug_service();
        ~debug_service();

        debug_service& trace(std::string_view msg);
        debug_service& warning(std::string_view msg);
        debug_service& error(std::string_view msg);
        debug_service& fatal(std::string_view msg);

        debug_service& log(level lvl, std::string_view msg);
    };

    inline debug_service::entry the_debug_service;
}
