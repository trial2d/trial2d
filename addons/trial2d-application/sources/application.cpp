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
    struct app_context_t {
        sg_pass_action pass_action{};
    } app_context{};
}

namespace
{
    void application_init() {
        sg_setup((sg_desc){
            .context = sapp_sgcontext()
        });

        app_context.pass_action = (sg_pass_action){
            .colors = {
                (sg_color_attachment_action){
                    .action = SG_ACTION_CLEAR,
                    .val = {0.5f, 0.0f, 0.0f, 1.0f},
                }
            }
        };
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
    return (sapp_desc){
        .init_cb = application_init,
        .frame_cb = application_frame,
        .cleanup_cb = application_cleanup,
        .event_cb = application_event,
        .fail_cb = application_fail,
        .width = 640,
        .height = 480,
        .window_title = "Trial2D",
        .gl_force_gles2 = true,
    };
}

namespace trial2d::application
{
}
