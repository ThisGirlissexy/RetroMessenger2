# Frequently Asked Questions

**Q**: How do I build RetroMessenger?

**A**: Read these [detailed instructions](https://retromessenger.svn.sourceforge.net/svnroot/retromessenger/docs/building.html) to get a good idea how to build RetroMessenger. Make sure to note all of the links in the **Prerequisites** section.

---

**Q**: How can I help after I have successfully built RetroMessenger?

**A**: You need to have an IDE ([CodeLite](http://codelite.org), [Code::Blocks](http://codeblocks.org), or any editor that can use makefiles(Vim, Emacs)), [wxWidgets](http://wxwidgets.org), [wxFormBuilder](http://wxformbuilder.org), GDB, and GCC installed and functioning 100%.

Now you should work through the tutorials on the [wxFormBuilder Wiki](http://wiki.wxformbuilder.org). After this you should understand the general way that it generates cpp/h and the way wxFormBuilder uses inheritance.

Now I have done most of that GUI design work and have generated the needed files. When you compile RM you should notice there are some warnings about unused variables and those are actually the event handler stub functions. They are written but just need to be filled in with the correct code to carry out the event. The evens should be pretty straight forward to figure out what they should be doing by there name. We should write all the GUI code that we can until we need to actually call the libretroshare code. Then just put a messagebox/comment to hold the place of that function. Does this make sense?

---

**Q**: How do I use wxFormBuilder?

**A**: Please visit the [wxFormBuilder Wiki](http://wiki.wxformbuilder.org) and read the tutorials that are available. A couple of good ones to read are the ["Getting Started Guide"](http://wiki.wxformbuilder.org/Tutorials/UsingWxFormBuilder) and the ["Why Cant I Edit The Generated Code"](http://wiki.wxformbuilder.org/Tutorials/WhyCantIEditTheGeneratedCode) article.

---

**Q**: How do I use Subversion?

**A**: The [Subversion book](http://svnbook.red-bean.com/nightly/en/index.html) offers a really good source to learn all that Subversion has to offer. Please read through the [Basic Usage](http://svnbook.red-bean.com/nightly/en/svn.tour.html) section as a bare minimum.

[Back](index.html)