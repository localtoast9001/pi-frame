# pi-frame-gtk
This is an app that uses GTK 3.0 for UI and runs on Raspian.

## Build
Follow these steps to install libraries. Then use GNU Make to build the app.

### Install GTK on Raspian
` sudo apt-get install libgtk-3-dev `
` sudo apt-get install libgtkmm-3.0-dev `

### Install GTK on Fedora
` sudo dnf install gtk3-devel clutter-devel webkit2gtk3-devel libgda-devel gobject-introspection-devel `
` sudo dnf install gtkmm30-devel `

## Coding Conventions
* snake_case. 
* 4 spaces instead of tabs.
* Document public and protected methods as part of declaration.
* Classes are defined in the pi_frame namespace.
* Opening braces are on a new line.
* non-static private member variables start with _.
* constants and static members should be ALL_CAPS.
* Use inline functions and not macros.
* Use nullptr, not NULL.
* Don't use the auto keyword. The default compiler on the Pi does not handle it.
* header file extension should be .hpp. C++ file extension should be .cpp
* header files should not have any `using namespace ...;` lines.
* header file structure:
 *  Start with copyright.
 *  next line is `#pragma once`
 *  next line is `#ifndef __header_file_name_hpp__`
 *  next line is `#define __header_file_name_hpp__`
 *  last line is `#endif /* __header_file_name_hpp__ */`