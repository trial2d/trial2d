/*******************************************************************************
 * This file is part of the "https://github.com/trial2d/trial2d.hpp"
 * For conditions of distribution and use, see copyright notice in LICENSE.md
 * Copyright (C) 2020, by Matvey Cherevko (blackmatov@gmail.com)
 ******************************************************************************/

#include <trial2d/storage/storage.hpp>

#include <trial2d/debug/debug.hpp>

namespace
{
    using namespace trial2d;

    class service_impl final : public storage::service {
    public:
        service_impl(debug::service& debug)
        : debug_(debug) {
            debug_.trace("storage::service()");
        }

        ~service_impl() {
            debug_.trace("~storage::service()");
        }

        bool has_int(std::string_view key) override {
            return int_values_.find(key) != int_values_.end();
        }

        bool has_float(std::string_view key) override {
            return float_values_.find(key) != float_values_.end();
        }

        bool has_string(std::string_view key) override {
            return string_values_.find(key) != string_values_.end();
        }

        void set_int(std::string_view key, int value) override {
            int_values_.insert_or_assign(std::string(key), value);
        }

        void set_float(std::string_view key, float value) override {
            float_values_.insert_or_assign(std::string(key), value);
        }

        void set_string(std::string_view key, std::string value) override {
            string_values_.insert_or_assign(std::string(key), std::move(value));
        }

        std::optional<int> get_int(std::string_view key) override {
            if ( auto iter = int_values_.find(key); iter != int_values_.end() ) {
                return iter->second;
            }
            return std::nullopt;
        }

        std::optional<float> get_float(std::string_view key) override {
            if ( auto iter = float_values_.find(key); iter != float_values_.end() ) {
                return iter->second;
            }
            return std::nullopt;
        }

        std::optional<std::string> get_string(std::string_view key) override {
            if ( auto iter = string_values_.find(key); iter != string_values_.end() ) {
                return iter->second;
            }
            return std::nullopt;
        }
    private:
        debug::service& debug_;
        flat_map<std::string, int> int_values_;
        flat_map<std::string, float> float_values_;
        flat_map<std::string, std::string> string_values_;
    };
}

namespace trial2d::storage
{
    void inject(di_ext::runtime_injector& injector) {
        injector.install(
            di::bind<storage::service>.to<service_impl>()
        );
    }
}
