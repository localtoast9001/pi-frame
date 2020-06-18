/**
 * Copyright (C) Jon Rowlett. All rights reserved.
 **/
#pragma once
#ifndef __arguments_hpp__
#define __arguments_hpp__

#include <string>

namespace pi_frame
{
    /**
     * Parsed program arguments.
     **/
    class arguments
    {
    public:
        /**
         * Initializes a new instance of the arguments class.
         **/
        arguments();

        /**
         * Destructor for the arguments class.
         **/
        ~arguments();

        /**
         * Tries to parse program arguments
         * @param argc count of arguments.
         * @param argv array of arguments.
         * @returns true if the arguments can be parsed; otherwise, false.
         **/
        bool try_parse(
            int argc,
            const char* argv[]);

        /**
         * Gets the program path.
         * @returns the program path.
         **/
        inline const std::string& program_path() const
        {
            return _program_path;
        }

        /**
         * Gets the images path.
         * @returns the images path.
         **/
        inline const std::string& images_path() const
        {
            return _images_path;
        }

        /**
         * Gets the interval.
         * @returns the interval in ms.
         **/
        inline int interval_msecs() const
        {
            return _interval_msecs;
        }

        /**
         * Gets whether or not to display in fullscreen.
         * @returns true to display fullscreen; otherwise, false.
         **/
        inline bool fullscreen() const
        {
            return _fullscreen;
        }
    
    private:
        std::string _program_path;
        std::string _images_path;
        int _interval_msecs;
        bool _fullscreen;
    };
} // namespace pi_frame

#endif /* __arguments_hpp__ */
