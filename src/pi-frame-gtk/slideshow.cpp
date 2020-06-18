/**
 * Copyright (C) Jon Rowlett. All rights reserved.
 **/
#include "slideshow.hpp"
#include "directory.hpp"

using namespace std;

namespace pi_frame
{
    slideshow::slideshow()
    : _interval_msecs(0)
    {
    }

    slideshow::~slideshow()
    {
    }

    bool slideshow::is_image(const string& file_name)
    {
        string::size_type i = file_name.find_last_of('.');
        if (i == string::npos)
        {
            return false;
        }

        string ext = file_name.substr(i);
        return ext == ".jpg" || ext == ".png" || ext == ".gif";
    }

    shared_ptr<slideshow> slideshow::create(
        int interval_msecs,
        const std::string& path)
    {
        shared_ptr<slideshow> result = make_shared<slideshow>();
        result->interval_msecs(interval_msecs);
        io::directory dir(path.c_str());
        for (struct dirent* ent = dir.read(); ent; ent = dir.read())
        {
            if (ent->d_type != DT_REG)
            {
                continue;
            }

            string name = ent->d_name;
            if (!is_image(name))
            {
                continue;
            }

            Glib::RefPtr<Gdk::Pixbuf> image = Gdk::Pixbuf::create_from_file(
                path + "/" + name);

            result->add_image(image);
        }   

        return result;
    }

    void slideshow::add_image(const Glib::RefPtr<Gdk::Pixbuf>& image)
    {
        _images.push_back(image);
        _current_image = _images.begin();
    }

    Glib::RefPtr<Gdk::Pixbuf> slideshow::next()
    {
        if (_images.size() == 0)
        {
            return Glib::RefPtr<Gdk::Pixbuf>();
        }

        list<Glib::RefPtr<Gdk::Pixbuf>>::iterator cur = _current_image;
        _current_image = ++_current_image;
        if (_current_image == _images.end())
        {
            _current_image = _images.begin();
        }

        return *cur;
    }
} // namespace pi_frame
