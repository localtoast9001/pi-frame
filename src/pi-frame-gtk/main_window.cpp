/**
 * Copyright (C) Jon Rowlett. All rights reserved.
 **/
#include "main_window.hpp"

using namespace Gtk;

namespace pi_frame
{
    main_window::main_window(bool fullscreen)
    : Window(), _fullscreen(fullscreen)
    {
        set_title("Pi Frame");
        resize(640, 480);
        add(_slides_drawing_area);
        _slides_drawing_area.show();

        add_events(Gdk::KEY_PRESS_MASK);
        if (_fullscreen)
        {
            this->fullscreen();
        }
    }

    main_window::~main_window()
    {
    }

    bool main_window::on_key_press_event(GdkEventKey* event)
    {
        if (event->keyval == GDK_KEY_F11)
        {
            toggle_fullscreen();
            return true;
        }

        return false;
    }

    void main_window::toggle_fullscreen()
    {
        if (_fullscreen)
        {
            unfullscreen();
        }
        else
        {
            fullscreen();
        }

        _fullscreen = !_fullscreen;
    }
} // namespace pi_frame
