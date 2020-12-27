/*******************************************************************************
 * This file is part of the "https://github.com/trial2d/trial2d.hpp"
 * For conditions of distribution and use, see copyright notice in LICENSE.md
 * Copyright (C) 2020, by Matvey Cherevko (blackmatov@gmail.com)
 ******************************************************************************/

#include <trial2d/storage/storage.hpp>

namespace
{
}

namespace trial2d::storage
{
    service::service(
        debug::service& debug)
    : debug_(debug) {
        debug_.trace("storage::service()");
    }

    service::~service() {
        debug_.trace("~storage::service()");
    }
}
