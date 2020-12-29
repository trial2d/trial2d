/*******************************************************************************
 * This file is part of the "https://github.com/trial2d/trial2d.hpp"
 * For conditions of distribution and use, see copyright notice in LICENSE.md
 * Copyright (C) 2020, by Matvey Cherevko (blackmatov@gmail.com)
 ******************************************************************************/

#pragma once

#include <trial2d/core/core.hpp>

namespace trial2d::debug
{
    ENUM_HPP_CLASS_DECL(level, std::uint8_t,
        (trace)
        (warning)
        (error)
        (fatal))
    ENUM_HPP_REGISTER_TRAITS(level)

    class service {
    public:
        virtual ~service() = default;

        virtual void log(level lvl, std::string_view msg) = 0;

        void trace(std::string_view msg);
        void warning(std::string_view msg);
        void error(std::string_view msg);
        void fatal(std::string_view msg);
    };

    void inject(di_ext::runtime_injector& injector);
}
