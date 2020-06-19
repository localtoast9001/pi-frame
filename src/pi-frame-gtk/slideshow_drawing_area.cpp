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
        double width = get_allocated_width();
        double height = get_allocated_height();

        Gdk::RGBA bg;
        bg.set_rgba(0.0, 0.0, 0.0);
        Gdk::Cairo::set_source_rgba(cr, bg);
        cr->rectangle(0, 0, (int)width, (int)height);
        cr->fill();
        if (_current)
        {
            cr->save();

            // scale the image.
            double image_width = (double)_current->get_width();
            double image_height = (double)_current->get_height();
            double x_scale = width / image_width;
            double y_scale = height / image_height;
            double scale = x_scale < y_scale ? x_scale : y_scale;
            cr->scale(scale, scale);
            
            int x = (width - image_width * scale) / (2.0 * scale);
            int y = (height - image_height * scale) / (2.0 * scale);
            Gdk::Cairo::set_source_pixbuf(cr, _current, x, y);
            cr->rectangle(
                x,
                y,
                image_width * scale,
                image_height * scale);
            cr->fill();

            // put back the normal scale.
            cr->restore();
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
