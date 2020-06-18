/**
 * Copyright (C) Jon Rowlett. All rights reserved.
 **/
#include "arguments.hpp"
#include <cstring>

namespace pi_frame
{
    arguments::arguments()
    : _interval_msecs(0), _fullscreen(false)
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

                const char* raw_interval = argv[i];
                _interval_msecs = ::atoi(raw_interval);
                continue;
            }

            return false;
        }

        _images_path = argv[argc - 1];
        return true;
    }
} // namespace pi_frame