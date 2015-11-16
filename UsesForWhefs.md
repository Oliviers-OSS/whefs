Here are some potential uses for whefs clients:

  * Storage for application resources (icons/images, help files, etc.). whefs can be used as a flexible storage solution for such a framework, e.g. a generic app resource system or an embedded HTTP server which serves files from an EFS. See [Whefs2c](Whefs2c.md) for an example of how to create an in-memory EFS holding application resources.
  * A game could use whefs as a type of application data archive bundle. e.g. shipping new "game sets" in the form of an EFS file which could then be imported by the application.
  * "Encryption through obfuscation" (i.e. data hiding). That said, anyone with the proper skills can get at the data.
  * Improve (and simplify) security and isolation of networked and CGI applications by sandboxing their file access inside of an EFS. This also helps eliminate problems related to incorrect file ownership for files created on a web server where the web server user and account holder differ. In this case, only the EFS needs to be writable, and new psuedofiles are not owned by the web server account. (There are currently problems with concurrent access to an EFS from multiple processes, however! See [WhefsConcurrency](WhefsConcurrency.md) for details.)
  * If an application must set a hard limit on generated output amounts, an EFS is one way to do it.
  * In embedded electronics, so long as a whio\_dev implementation is feasible for that platform. The ability to compile out most or all malloc() calls may be helpful here.
  * Using a RAM-based EFS as a memory buffer can help protect against memory overruns and provides a simple way to dump the buffer to/from other storage.
  * It has been shown that we can convert an EFS from binary form to C code (as a big char array), compile that array into an application, and open the EFS (in read/write mode) in the application (see [Whefs2c](Whefs2c.md)). In short, we can completely embed a pre-generated EFS into an application's static memory.
  * Once we get some SWIG bindings in place, we may have some very interesting possibilities for script-side access to an EFS. e.g. languages which don't have "native" i/o routines, like JavaScript, could benefit from this. That said, SWIG can't generate JavaScript bindings, but [i can](http://code.google.com/p/v8-juice/wiki/PluginWhefs) :).