/*******************************************************************************
 * This file is part of the "https://github.com/trial2d/trial2d.hpp"
 * For conditions of distribution and use, see copyright notice in LICENSE.md
 * Copyright (C) 2020, by Matvey Cherevko (blackmatov@gmail.com)
 ******************************************************************************/

#include "leaderboard.hpp"

namespace
{
    using namespace trial2d;
    using namespace sample::services;

    class service_impl final : public leaderboard::service {
    public:
        service_impl(debug::service& debug, storage::service& storage)
        : debug_(debug)
        , storage_(storage) {
            debug_.trace("leaderboard::service()");
        }

        ~service_impl() {
            debug_.trace("~leaderboard::service()");
        }

        void post_score(std::string_view username, int scores) override {
            storage_.set_int(username, scores);
        }
    private:
        debug::service& debug_;
        storage::service& storage_;
    };
}

namespace sample::services::leaderboard
{
    void inject(di_ext::runtime_injector& injector) {
        injector.install(
            di::bind<leaderboard::service>.to<service_impl>()
        );
    }
}
