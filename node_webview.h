#ifndef NATIVE_EXTENSION_GRAB_H
#define NATIVE_EXTENSION_GRAB_H

#include <nan.h>
#include "webview.h"

// class NodeWebView : public Nan::ObjectWrap
// {
// private:
//   webview::webview wv;
// // public:
// //   NodeWebView();
// //   create();
// //   run();
// //   destroy();
// //   terminate();
// //   getWindow();
// //   setTitle();
// //   setSize();
// //   navigate();
// //   init();
// //   eval();
// //   bind();
// //   return();  
//   NodeWebView();
// };


// Example with node ObjectWrap
// Based on https://nodejs.org/api/addons.html#addons_wrapping_c_objects but using NAN
class NodeWebView : public Nan::ObjectWrap {
  public:
    static NAN_MODULE_INIT(Init);

  private:
    explicit NodeWebView();
    ~NodeWebView();

    static NAN_METHOD(New);
    static NAN_METHOD(Run);
    static Nan::Persistent<v8::Function> constructor;

    webview::webview wv;
};

#endif