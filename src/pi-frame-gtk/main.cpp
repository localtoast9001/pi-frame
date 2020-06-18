/**
 * Copyright (C) Jon Rowlett. All rights reserved.
 **/
#include "main_window.hpp"
#include "arguments.hpp"
#include "slideshow.hpp"
#include <iostream>

using namespace Gtk;
using namespace std;

const int USAGE_EXIT_CODE = 1;

/**
 * Main method
 * @param argc count of arguments.
 * @param argv array of C string arguments.
 * @returns 0 for success. non-zero for failure.
 **/
int main(int argc, char* argv[])
{
    pi_frame::arguments args;
    if (!args.try_parse(argc, const_cast<const char**>(argv)))
    {
      cerr << "Usage:" << endl;
      cerr << "pi-frame-gtk [Options] <path>" << endl;
      cerr << "Options:" << endl;
      cerr << " --fullscreen - start the program in fullscreen." << endl;
      cerr << " --interval <value> - the interval between images in ms." << endl;
      cerr << " <path> - the path to the folder with images." << endl;
      return USAGE_EXIT_CODE;
    }

    Glib::RefPtr<Application> app = Application::create(
        "org.example.pi-frame-gtk"); 
    pi_frame::main_window window(args.fullscreen());
    shared_ptr<pi_frame::slideshow> slides = pi_frame::slideshow::create(
        args.interval_msecs(),
        args.images_path());
    window.slides_drawing_area().slides(slides);

    return app->run(window);
}
