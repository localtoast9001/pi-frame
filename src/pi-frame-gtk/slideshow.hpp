/**
 * Copyright (C) Jon Rowlett. All rights reserved.
 **/
#pragma once
#ifndef __slideshow_hpp__
#define __slideshow_hpp__

#include <list>
#include <string>
#include <memory>
#include <gdkmm/pixbuf.h>

namespace pi_frame
{
    /**
     * Repeating sequence of images to display.
     **/
    class slideshow
    {
    public:
        /**
         * Initializes a new instance of the slideshow class.
         **/
        slideshow();

        /**
         * Destructor for the slideshow class.
         **/
        ~slideshow();

        /**
         * Creates a new slideshow given an interval and a path to a folder containing images.
         * @param interval_msecs The interval in ms.
         * @param path The path to the folder with the images.
         * @returns A shared pointer to the new slideshow.
         **/
        static std::shared_ptr<slideshow> create(
            long interval_msecs,
            const std::string& path);

        /**
         * Gets the interval between images.
         * @returns the interval between images in ms.
         **/
        inline long interval_msecs() const
        {
            return _interval_msecs;
        }

        /**
         * Gets the next image to show.
         * @returns A shared pointer to the next image.
         **/
        Glib::RefPtr<Gdk::Pixbuf> next();

    protected:
        /**
         * Sets the interval.
         * @param value the interval in ms.
         **/
        inline void interval_msecs(long value)
        {
            _interval_msecs = value;
        }

        /**
         * Adds an image at the end of the sequence.
         * @param image a shared pointer to the image.
         **/
        void add_image(const Glib::RefPtr<Gdk::Pixbuf>& image);

    private:
        slideshow(const slideshow&);
        slideshow& operator=(const slideshow&);

        /**
         * Tests if the file name is a supported image type.
         * @param file_name the file name.
         * @returns true if the file type is a supported image type.
         **/
        static bool is_image(const std::string& file_name);

        long _interval_msecs;
        std::list<Glib::RefPtr<Gdk::Pixbuf>> _images;
        std::list<Glib::RefPtr<Gdk::Pixbuf>>::iterator _current_image;
    };
} // namespace pi_frame

#endif /* __slideshow_hpp__ */
