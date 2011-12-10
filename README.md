PyGObject Example
=================

Originally written by Tal Liron in December 2011. License: public domain.

While there are many PyGObject tutorials out there that show how to use GTK+3, there are none at the
moment that show the complete loop of writing your own GObject code in C or Vala specifically for use
in Python. It took me many hours to piece everything together, so I hope this simple example code will
help avoid the pain for you. You're very lucky to have stumbled upon this example. :)

The "build" script will both build the code and run the tests. It's a straightforward script, not a
makefile, specifically written as such in order to demystify the toolset. There are a lot of little notes
in there that can save you many hours of frustration... the build script may be the most important part!

If you run the script without any arguments, "./build", it will build a shared library written in C, and
then run two test applications: one written in C and one written in Python.

If run as "./build vala", it will build an equivalent library written in Vala, and then run the same
Python application. This is meant to show how you can use Vala instead of C to the exact same effect.

The script was tested on Ubuntu 11.10. It was written for a presentation on PyGObject for the Chicago
Python group (ChiPy) on December 8th, 2011. A recording of this presentation is available here:

	http://www.youtube.com/watch?v=6QrGmA_RR4E

It was tested on Ubuntu 11.10. The following packages are necessary there (see notes in the build script
for explanations):

	sudo apt-get install gcc-4.4 valac-0.14 gobject-introspection libgirepository1.0-dev

For an example using autotools and Vala, see the libgda-vala branch of http://git.gnome.org/browse/libgda
