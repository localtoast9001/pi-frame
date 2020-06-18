/**
 * Copyright (C) Jon Rowlett. All rights reserved.
 **/
#pragma once
#ifndef __directory_hpp__
#define __directory_hpp__

#include <dirent.h>

namespace io
{
    /**
     * File system directory abstraction.
     **/
    class directory
    {
    public:
        /**
         * Initializes a new instance of the directory class.
         * @param path the path to the directory to open.
         **/
        directory(const char* path)
        : _d(nullptr)
        {
            _d = ::opendir(path);
        }

        /**
         * Destructs the directory class.
         **/
        ~directory()
        {
            if (_d)
            {
                ::closedir(_d);
            }
        }

        inline struct dirent* read()
        {
            if (!_d)
            {
                return nullptr;
            }
            
            return ::readdir(_d);
        }       

    private:
        directory(const directory&);
        directory& operator=(const directory&);

        DIR* _d;
    };
} // namespace io

#endif /* __directory_hpp__ */
