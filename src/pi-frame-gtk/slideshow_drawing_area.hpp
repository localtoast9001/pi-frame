/**
 * Copyright (C) Jon Rowlett. All rights reserved.
 **/
#pragma once
#ifndef __slideshow_drawing_area_hpp__
#define __slideshow_drawing_area_hpp__

#include <gtkmm/drawingarea.h>
#include "slideshow.hpp"

namespace pi_frame
{
    /**
     * Drawing area that displays the slideshow.
     **/
    class slideshow_drawing_area : public Gtk::DrawingArea
    {
    public:
        /**
         * Initializes a new instance of the slideshow_drawing_area class.
         **/
        slideshow_drawing_area();

        /**
         * Destructor for the slideshow_drawing_area class.
         **/
        virtual ~slideshow_drawing_area();

        /**
         * Sets the slideshow and starts displaying it.
         * @param value the new value of the slideshow.
         **/
        void slides(const std::shared_ptr<slideshow>& value);

    protected:
        /**
         * draws the current image of the slideshow.
         * @param cr The context.
         * @returns true if the event was handled; otherwise, false.
         **/
        bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;

        /**
         * Called on the interval to cycle the image displayed.
         * @returns true to continue the timeout; false to stop.
         **/
        virtual bool on_timeout();

    private:
        std::shared_ptr<slideshow> _slides;
        Glib::RefPtr<Gdk::Pixbuf> _current;
    };
} // namespace pi_frame

#endif /* __slideshow_drawing_area_hpp__ */