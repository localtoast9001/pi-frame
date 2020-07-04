/**
 * Copyright (C) Jon Rowlett. All rights reserved.
 **/
#include "main_window.hpp"

using namespace Gtk;

namespace pi_frame
{
    main_window::main_window(bool fullscreen)
    : Window(),
      _fullscreen(fullscreen)
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

    void main_window::on_realize()
    {
        Window::on_realize();
        if (!_blank_cursor)
        {
            _blank_cursor = Gdk::Cursor::create(get_display(), "none");
        }

        if (_fullscreen)
        {
            gdk_window_set_cursor(
                get_window()->gobj(),
                _blank_cursor->gobj());
        }
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

        Glib::RefPtr<Gdk::Window> window = get_window();
        if (window)
        {
            gdk_window_set_cursor(
                window->gobj(),
                _fullscreen ? nullptr : _blank_cursor->gobj());
        }

        _fullscreen = !_fullscreen;
    }
} // namespace pi_frame
