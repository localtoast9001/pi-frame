/**
 * Copyright (C) Jon Rowlett. All rights reserved.
 **/
#include "slideshow_drawing_area.hpp"
#include <glibmm/main.h>
#include <gtkmm/window.h>
#include <gdkmm/general.h>

namespace pi_frame
{
    slideshow_drawing_area::slideshow_drawing_area()
    {
    }

    slideshow_drawing_area::~slideshow_drawing_area()
    {
    }

    void slideshow_drawing_area::slides(
        const std::shared_ptr<slideshow>& value)
    {
        _slides = value;
        _current = _slides->next();
        Glib::signal_timeout().connect(
            sigc::mem_fun(*this, &slideshow_drawing_area::on_timeout),
            _slides->interval_msecs());
    }

    bool slideshow_drawing_area::on_draw(
        const Cairo::RefPtr<Cairo::Context>& cr)
    {
        if (_current)
        {
            Gdk::Cairo::set_source_pixbuf(cr, _current, 100, 80);
            cr->rectangle(110, 90, _current->get_width()-20, _current->get_height()-20);
            cr->fill();
        }

        return true;
    }

    bool slideshow_drawing_area::on_timeout()
    {
        if (_slides)
        {
            _current = _slides->next();
        }

        Glib::RefPtr<Gdk::Window> win = get_window();
        if (win)
        {
            Gdk::Rectangle r(
                0,
                0,
                get_allocation().get_width(),
                get_allocation().get_height());
            win->invalidate_rect(r, false);
        }
    
        return true;
    }

} // namespace pi_frame
