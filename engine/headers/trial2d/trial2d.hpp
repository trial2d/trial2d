/*******************************************************************************
 * This file is part of the "https://github.com/trial2d/trial2d.hpp"
 * For conditions of distribution and use, see copyright notice in LICENSE.md
 * Copyright (C) 2020, by Matvey Cherevko (blackmatov@gmail.com)
 ******************************************************************************/

#pragma once

#include <boost/di.hpp>
#include <defer.hpp/defer.hpp>
#include <enum.hpp/enum.hpp>
#include <flat.hpp/flat.hpp>
#include <idgen.hpp/idgen.hpp>
#include <vmath.hpp/vmath.hpp>

namespace trial2d
{
    template < typename Service >
    class service {
    public:
        class entry final {
        public:
            entry() {
                auto injector = boost::di::make_injector();
                service_ = injector.create<std::shared_ptr<Service>>();
            }
        private:
            std::shared_ptr<Service> service_;
        };
    };
}
