/*******************************************************************************
 * This file is part of the "https://github.com/trial2d/trial2d.hpp"
 * For conditions of distribution and use, see copyright notice in LICENSE.md
 * Copyright (C) 2020, by Matvey Cherevko (blackmatov@gmail.com)
 ******************************************************************************/

#pragma once

#include <boost/di.hpp>
#include <boost/di/extension/providers/runtime_provider.hpp>

#include <defer.hpp/defer.hpp>
#include <enum.hpp/enum.hpp>
#include <flat.hpp/flat.hpp>
#include <idgen.hpp/idgen.hpp>
#include <vmath.hpp/vmath.hpp>

namespace trial2d
{
    namespace di = boost::di;
    namespace di_ext = boost::di::extension;
}

namespace trial2d
{
    template < typename Key
             , typename Compare = std::less<>
             , typename Container = std::vector<Key> >
    using flat_set = flat_hpp::flat_set<Key, Compare, Container>;

    template < typename Key
             , typename Compare = std::less<>
             , typename Container = std::vector<Key> >
    using flat_multiset = flat_hpp::flat_multiset<Key, Compare, Container>;

    template < typename Key
             , typename Value
             , typename Compare = std::less<>
             , typename Container = std::vector<std::pair<Key, Value>> >
    using flat_map = flat_hpp::flat_map<Key, Value, Compare, Container>;

    template < typename Key
             , typename Value
             , typename Compare = std::less<>
             , typename Container = std::vector<std::pair<Key, Value>> >
    using flat_multimap = flat_hpp::flat_multimap<Key, Value, Compare, Container>;
}
