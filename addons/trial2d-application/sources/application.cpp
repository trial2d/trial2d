/*******************************************************************************
 * This file is part of the "https://github.com/trial2d/trial2d.hpp"
 * For conditions of distribution and use, see copyright notice in LICENSE.md
 * Copyright (C) 2020, by Matvey Cherevko (blackmatov@gmail.com)
 ******************************************************************************/

#include <trial2d/application/application.hpp>

#include <sokol/sokol_app.h>
#include <sokol/sokol_gfx.h>
#include <sokol/sokol_glue.h>

namespace
{
    template < typename Value >
    struct struct_builder {
        Value value{};

        operator Value&&() && {
            return std::move(value);
        }
    };

    struct sapp_desc_builder
        : struct_builder<sapp_desc>
    {
        using self_type = sapp_desc_builder;

        self_type&& init_cb(void (*init_cb)(void)) && {
            value.init_cb = init_cb;
            return std::move(*this);
        }

        self_type&& frame_cb(void (*frame_cb)(void)) && {
            value.frame_cb = frame_cb;
            return std::move(*this);
        }

        self_type&& cleanup_cb(void (*cleanup_cb)(void)) && {
            value.cleanup_cb = cleanup_cb;
            return std::move(*this);
        }

        self_type&& event_cb(void (*event_cb)(const sapp_event*)) && {
            value.event_cb = event_cb;
            return std::move(*this);
        }

        self_type&& fail_cb(void (*fail_cb)(const char*)) && {
            value.fail_cb = fail_cb;
            return std::move(*this);
        }

        self_type&& width(int width) && {
            value.width = width;
            return std::move(*this);
        }

        self_type&& height(int height) && {
            value.height = height;
            return std::move(*this);
        }

        self_type&& window_title(const char* window_title) && {
            value.window_title = window_title;
            return std::move(*this);
        }

        self_type&& gl_force_gles2(bool gl_force_gles2) && {
            value.gl_force_gles2 = gl_force_gles2;
            return std::move(*this);
        }
    };

    struct sg_desc_builder
        : struct_builder<sg_desc>
    {
        using self_type = sg_desc_builder;

        self_type&& context(sg_context_desc context) && {
            value.context = std::move(context);
            return std::move(*this);
        }
    };

    struct sg_color_attachment_action_builder
        : struct_builder<sg_color_attachment_action>
    {
        using self_type = sg_color_attachment_action_builder;

        self_type&& action(sg_action action) && {
            value.action = std::move(action);
            return std::move(*this);
        }

        self_type&& val(float r, float g, float b, float a) && {
            value.val[0] = r;
            value.val[1] = g;
            value.val[2] = b;
            value.val[3] = a;
            return std::move(*this);
        }
    };

    struct sg_depth_attachment_action_builder
        : struct_builder<sg_depth_attachment_action>
    {
        using self_type = sg_depth_attachment_action_builder;

        self_type&& action(sg_action action) && {
            value.action = std::move(action);
            return std::move(*this);
        }

        self_type&& val(float val) && {
            value.val = val;
            return std::move(*this);
        }
    };

    struct sg_stencil_attachment_action_builder
        : struct_builder<sg_stencil_attachment_action>
    {
        using self_type = sg_stencil_attachment_action_builder;

        self_type&& action(sg_action action) && {
            value.action = std::move(action);
            return std::move(*this);
        }

        self_type&& val(float val) && {
            value.val = val;
            return std::move(*this);
        }
    };

    struct sg_pass_action_builder
        : struct_builder<sg_pass_action>
    {
        using self_type = sg_pass_action_builder;

        self_type&& color(std::size_t index, sg_color_attachment_action color) && {
            value.colors[index] = std::move(color);
            return std::move(*this);
        }

        self_type&& depth(sg_depth_attachment_action depth) && {
            value.depth = std::move(depth);
            return std::move(*this);
        }

        self_type&& stencil(sg_stencil_attachment_action stencil) && {
            value.stencil = std::move(stencil);
            return std::move(*this);
        }
    };
}

namespace
{
    struct app_context_t {
        sg_pass_action pass_action{};
    } app_context{};
}

namespace
{
    void application_init() {
        sg_setup(sg_desc_builder()
            .context(sapp_sgcontext()));

        app_context.pass_action = sg_pass_action_builder()
            .color(0, sg_color_attachment_action_builder()
                .action(SG_ACTION_CLEAR)
                .val(0.5f, 0.0f, 0.0f, 1.0f));
    }

    void application_frame() {
        sg_begin_default_pass(
            &app_context.pass_action,
            sapp_width(), sapp_height());
        sg_end_pass();
        sg_commit();
    }

    void application_cleanup() {
        sg_shutdown();
    }

    void application_event(const sapp_event* evt) {
        if ( evt->type == SAPP_EVENTTYPE_KEY_DOWN
            && evt->key_code == SAPP_KEYCODE_ESCAPE )
        {
            sapp_request_quit();
        }
    }

    void application_fail(const char* msg) {
        std::puts(msg);
    }
}

sapp_desc sokol_main(int argc, char* argv[]) {
    (void)argc; (void)argv;
    return sapp_desc_builder()
        .init_cb(application_init)
        .frame_cb(application_frame)
        .cleanup_cb(application_cleanup)
        .event_cb(application_event)
        .fail_cb(application_fail)
        .width(640)
        .height(480)
        .window_title("Trial2D")
        .gl_force_gles2(true);
}

namespace trial2d::application
{
    service::service(
        debug::service& debug,
        memory::service& memory)
    : debug_(debug)
    , memory_(memory) {
        debug_.trace("application::service()");
    }

    service::~service() {
        debug_.trace("~application::service()");
    }
}
