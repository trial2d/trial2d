/*******************************************************************************
 * This file is part of the "https://github.com/trial2d/trial2d.hpp"
 * For conditions of distribution and use, see copyright notice in LICENSE.md
 * Copyright (C) 2020, by Matvey Cherevko (blackmatov@gmail.com)
 ******************************************************************************/

#pragma once

#include <trial2d/core/core.hpp>

namespace trial2d::storage
{
    class service {
    public:
        virtual ~service() = default;

        virtual bool has_int(std::string_view key) = 0;
        virtual bool has_float(std::string_view key) = 0;
        virtual bool has_string(std::string_view key) = 0;

        virtual void set_int(std::string_view key, int value) = 0;
        virtual void set_float(std::string_view key, float value) = 0;
        virtual void set_string(std::string_view key, std::string value) = 0;

        virtual std::optional<int> get_int(std::string_view key) = 0;
        virtual std::optional<float> get_float(std::string_view key) = 0;
        virtual std::optional<std::string> get_string(std::string_view key) = 0;
    };

    void inject(di_ext::runtime_injector& injector);
}
