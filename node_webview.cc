#include <nan.h>
#include <iostream>
#include "node_webview.h"

using namespace std;

Nan::Persistent<v8::Function> NodeWebView::constructor;

NAN_MODULE_INIT(NodeWebView::Init) {
  v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
  tpl->SetClassName(Nan::New("NodeWebView").ToLocalChecked());
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  Nan::SetPrototypeMethod(tpl, "run", Run);

  constructor.Reset(Nan::GetFunction(tpl).ToLocalChecked());
  Nan::Set(target, Nan::New("NodeWebView").ToLocalChecked(), Nan::GetFunction(tpl).ToLocalChecked());
}

NodeWebView::NodeWebView() {
  wv = webview::webview(false, nullptr);
  wv.set_title("Example");
  wv.set_size(480, 320, WEBVIEW_HINT_NONE);
  wv.navigate("https://google.com");
}

NodeWebView::~NodeWebView() {
  wv.terminate();
}

NAN_METHOD(NodeWebView::New) {
  if (info.IsConstructCall()) {
    NodeWebView *obj = new NodeWebView();
    obj->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
  } else {
    const int argc = 1;
    v8::Local<v8::Value> argv[argc] = {};
    v8::Local<v8::Function> cons = Nan::New(constructor);
    info.GetReturnValue().Set(Nan::NewInstance(cons, argc, argv).ToLocalChecked());
  }
}

NAN_METHOD(NodeWebView::Run) {
  NodeWebView* obj = Nan::ObjectWrap::Unwrap<NodeWebView>(info.This());
  obj->wv.run();
}
