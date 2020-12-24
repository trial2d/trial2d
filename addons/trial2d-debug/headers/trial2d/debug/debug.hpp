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

    class service final
        : public service_base<service> {
    public:
        service();
        ~service();

        service& trace(std::string_view msg);
        service& warning(std::string_view msg);
        service& error(std::string_view msg);
        service& fatal(std::string_view msg);

        service& log(level lvl, std::string_view msg);
    };

    inline service::entry the_service;
}
