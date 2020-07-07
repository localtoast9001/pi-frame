/**
 * Copyright (C) Jon Rowlett. All rights reserved.
 **/
#pragma once
#ifndef __arguments_hpp__
#define __arguments_hpp__

#include <string>
#include <chrono>

namespace pi_frame
{
    /**
     * Parsed program arguments.
     **/
    class arguments
    {
    public:
        /**
         * The default value for the interval if not specified.
         **/
        static const std::chrono::milliseconds DEFAULT_INTERVAL;

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
        inline std::chrono::milliseconds interval() const
        {
            return _interval;
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
        /**
         * Tries to parse a duration from a string.
         * @param value the text to parse.
         * @param result on success, receives the parsed value.
         * @return true if the value can be parsed; otherwise, false.
         * @remarks
         * The duration is expressed as a rational number followed
         * immediately by an optional unit. The default unit is minutes.
         * Other units are:
         * ms - milliseconds.
         * m or min - minutes.
         * s - seconds.
         * h or hr - hours.
         * d - days.
         **/
        static bool try_parse_duration(
            const std::string& value,
            std::chrono::milliseconds& result);

        std::string _program_path;
        std::string _images_path;
        std::chrono::milliseconds _interval;
        bool _fullscreen;
    };
} // namespace pi_frame

#endif /* __arguments_hpp__ */
