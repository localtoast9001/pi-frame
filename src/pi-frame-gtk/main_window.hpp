/**
 * Copyright (C) Jon Rowlett. All rights reserved.
 **/
#pragma once
#ifndef __main_window_hpp__
#define __main_window_hpp__

#include <gtkmm/application.h>
#include <gtkmm/window.h>
#include "slideshow_drawing_area.hpp"

namespace pi_frame
{
    /**
     * Application main window.
     **/
    class main_window : public Gtk::Window
    {
    public:
        /**
         * Initializes a new instance of the main_window class.
         * @param fullscreen true to show the window in fullscreen mode initially.
         **/
        main_window(bool fullscreen = false);

        /**
         * Destructor for main_window.
         **/
        virtual ~main_window();

        /**
         * Gets the slideshow drawing area.
         * @returns A reference to the slideshow drawing area.
         **/
        inline slideshow_drawing_area& slides_drawing_area()
        {
            return _slides_drawing_area;
        }

    protected:
        /**
         * Override from the Window class to handle key press events.
         * @param event A pointer to the key press event.
         * @returns true if the event is handled; otherwise, false.
         **/
        bool on_key_press_event(GdkEventKey* event) override;

        /**
         * Called on the F11 key press event to toggle fullscreen.
         **/
        void toggle_fullscreen();

    private:
        bool _fullscreen;
        slideshow_drawing_area _slides_drawing_area;
    };
} // namespace pi_frame

#endif /* __main_window_hpp__ */
