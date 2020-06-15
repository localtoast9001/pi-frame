#include <gtkmm/application.h>
#include <gtkmm/window.h>

using namespace Gtk;
using namespace std;

class main_window : public Window
{
public:
  main_window(bool fullscreen = false)
  : Window(), _fullscreen(fullscreen)
  {
    set_title("Pi Frame");
    resize(200, 200);

    add_events(Gdk::KEY_PRESS_MASK);
    if (_fullscreen)
    {
      this->fullscreen();
    }
  }

  virtual ~main_window()
  {
  }

protected:
  virtual bool on_key_press_event(GdkEventKey* event)
  {
    if (event->keyval == GDK_KEY_F11)
    {
      on_toggle_fullscreen();
      return true;
    }

    return false;
  }

  virtual void on_toggle_fullscreen()
  {
    if (_fullscreen)
    {
      unfullscreen();
    }
    else
    {
      fullscreen();
    }

    _fullscreen = !_fullscreen;
  }

private:
  bool _fullscreen;
};

int main(int argc, char* argv[])
{
  Glib::RefPtr<Application> app = Application::create(argc, argv, "org.example.pi-frame-gtk"); 
  main_window window;

  return app->run(window);
}
