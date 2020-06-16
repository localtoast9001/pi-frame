/**
 * Copyright (C) Jon Rowlett. All rights reserved.
 **/
#pragma once
#ifndef __main_window_hpp__
#define __main_window_hpp__

#include <gtkmm/application.h>
#include <gtkmm/window.h>

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

    protected:
        /**
         * Override from the Window class to handle key press events.
         * @param event A pointer to the key press event.
         * @returns true if the event is handled; otherwise, false.
         **/
        virtual bool on_key_press_event(GdkEventKey* event);

        /**
         * Called on the F11 key press event to toggle fullscreen.
         **/
        void toggle_fullscreen();

    private:
        bool _fullscreen;
    };
} // namespace pi_frame

#endif /* __main_window_hpp__ */
