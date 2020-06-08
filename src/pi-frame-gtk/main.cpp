#include <gtkmm/application.h>
#include <gtkmm/window.h>

using namespace Gtk;
using namespace std;

class main_window : public Window
{
public:
  main_window()
  : Window()
  {
    set_title("Pi Frame");
    resize(200, 200);
  }
};

int main(int argc, char* argv[])
{
  Glib::RefPtr<Application> app = Application::create(argc, argv, "org.example.pi-frame-gtk"); 
  main_window window;
  window.fullscreen();

  return app->run(window);
}
