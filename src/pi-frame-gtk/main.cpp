/**
 * Copyright (C) Jon Rowlett. All rights reserved.
 **/
#include "main_window.hpp"

using namespace Gtk;
using namespace std;

/**
 * Main method
 * @param argc count of arguments.
 * @param argv array of C string arguments.
 * @returns 0 for success. non-zero for failure.
 **/
int main(int argc, char* argv[])
{
  Glib::RefPtr<Application> app = Application::create(argc, argv, "org.example.pi-frame-gtk"); 
  pi_frame::main_window window;

  return app->run(window);
}
