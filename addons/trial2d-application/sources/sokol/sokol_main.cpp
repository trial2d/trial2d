/*******************************************************************************
 * This file is part of the "https://github.com/trial2d/trial2d.hpp"
 * For conditions of distribution and use, see copyright notice in LICENSE.md
 * Copyright (C) 2020, by Matvey Cherevko (blackmatov@gmail.com)
 ******************************************************************************/

#include "sokol_base.hpp"

namespace
{
    using namespace trial2d;
    using namespace trial2d::sokol;

    void main_init() {
        sg_setup(sg_desc_builder()
            .context(sapp_sgcontext()));
    }

    void main_frame() {
        const sg_pass_action pass_action = sg_pass_action_builder()
            .color(0, sg_color_attachment_action_builder()
                .action(SG_ACTION_CLEAR)
                .val(0.5f, 0.0f, 0.0f, 1.0f));
        sg_begin_default_pass(pass_action, sapp_width(), sapp_height());
        sg_end_pass();
        sg_commit();
    }

    void main_cleanup() {
        sg_shutdown();
    }

    void main_event(const sapp_event* evt) {
        if ( evt->type == SAPP_EVENTTYPE_KEY_DOWN
            && evt->key_code == SAPP_KEYCODE_ESCAPE )
        {
            sapp_request_quit();
        }
    }

    void main_fail(const char* msg) {
        (void)msg;
    }
}

sapp_desc sokol_main(int argc, char* argv[]) {
    (void)argc; (void)argv;
    return sapp_desc_builder()
        .init_cb(main_init)
        .frame_cb(main_frame)
        .cleanup_cb(main_cleanup)
        .event_cb(main_event)
        .fail_cb(main_fail)
        .width(640)
        .height(480)
        .window_title("Trial2D")
        .gl_force_gles2(true);
}
