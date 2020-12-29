/*******************************************************************************
 * This file is part of the "https://github.com/trial2d/trial2d.hpp"
 * For conditions of distribution and use, see copyright notice in LICENSE.md
 * Copyright (C) 2020, by Matvey Cherevko (blackmatov@gmail.com)
 ******************************************************************************/

#pragma once

#include <sample/common/common.hpp>

namespace sample::services::leaderboard
{
    class service {
    public:
        virtual ~service() = default;

        virtual void post_score(std::string_view username, int scores) = 0;
    };

    void inject(di_ext::runtime_injector& injector);
}
