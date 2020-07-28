/**
 * Copyright (C) Jon Rowlett. All rights reserved.
 **/
#include "arguments.hpp"
#include <cstring>
#include <stdlib.h>
#include <locale>

namespace pi_frame
{
    const std::chrono::milliseconds arguments::DEFAULT_INTERVAL(5000);

    arguments::arguments()
    : _interval(DEFAULT_INTERVAL), _fullscreen(false)
    {
    }

    arguments::~arguments()
    {
    }

    bool arguments::try_parse(
        int argc,
        const char* argv[])
    {
        if (argc < 2)
        {
            return false;
        }

        _program_path = argv[0];
        for (int i = 1; i < argc - 1; i++)
        {
            if (::strcmp("--fullscreen", argv[i]) == 0)
            {
                _fullscreen = true;
                continue;
            }

            if (::strcmp("--interval", argv[i]) == 0)
            {
                i++;
                if (i >= argc - 1)
                {
                    return false;
                }

                std::chrono::milliseconds iv;
                if (!try_parse_duration(argv[i], iv) ||
                    iv.count() <= 0)
                {
                    return false;
                }
                
                _interval = iv;
                continue;
            }

            return false;
        }

        _images_path = argv[argc - 1];
        return true;
    }

    bool arguments::try_parse_duration(
        const std::string& value,
        std::chrono::milliseconds& result)
    {
        std::string::const_iterator it = value.begin();
        if (it != value.end())
        {
            if (*it == '-')
            {
                ++it;
            }
        }

        while (it != value.end() && ::isdigit(*it))
        {
            ++it;
        }

        if (it != value.end() && *it == '.')
        {
            ++it;
            while (it != value.end() && ::isdigit(*it))
            {
                ++it;
            }
        }

        std::string v(value.begin(), it);
        std::string unit(it, value.end());
        double raw_duration = ::atof(v.c_str());

        const std::locale loc = std::locale();
        for (std::string::iterator uit = unit.begin();
            uit != unit.end();
            ++uit)
        {
            *uit = std::use_facet<std::ctype<char>>(loc).tolower(*uit);
        }

        double scale = 1.0;
        if (unit == "m" || unit == "min" || unit.length() == 0)
        {
            scale = 60 * 1000;
        }
        else if (unit == "h" || unit == "hr")
        {
            scale = 60 * 60 * 1000;
        }
        else if (unit == "s")
        {
            scale = 1000;
        }
        else if (unit == "d")
        {
            scale = 24 * 60 * 50 * 1000;
        }
        else if (unit == "ms")
        {
            scale = 1.0;
        }
        else
        {
            return false;
        }

        result = std::chrono::milliseconds(
            (long)(raw_duration * scale));
        return true;
    }
} // namespace pi_frame
