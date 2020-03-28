
#include <nan.h>
#include <iostream>
#include "webview.h"

using v8::FunctionTemplate;
using v8::String;

NAN_METHOD(callback)
{
    webview::webview w(true, nullptr);
    w.set_title("Example");
    //w.set_size(480, 320, WEBVIEW_HINT_NONE);
    w.set_size(180, 120, WEBVIEW_HINT_MIN);
    w.bind("noop", [](std::string s) -> std::string {
        std::cout << s << std::endl;
        return s;
    });
    w.bind("add", [](std::string s) -> std::string {
        auto a = std::stoi(webview::json_parse(s, "", 0));
        auto b = std::stoi(webview::json_parse(s, "", 1));
        return std::to_string(a + b);
    });
    w.navigate("http://outlook-sdf.office.com/mail/");
    w.run();
}

NAN_METHOD(navigate)
{
    if (info.Length() != 1)
    {
        Nan::ThrowTypeError("Wrong number of arguments");
        return;
    }

    Nan::Utf8String urlInput(info[0]);
    std::string url(*urlInput, urlInput.length());

    webview::webview w(true, nullptr);
    w.set_title("Example");
    //w.set_size(480, 320, WEBVIEW_HINT_NONE);
    w.set_size(180, 120, WEBVIEW_HINT_MIN);
    w.bind("noop", [](std::string s) -> std::string {
        std::cout << s << std::endl;
        return s;
    });
    w.bind("add", [](std::string s) -> std::string {
        auto a = std::stoi(webview::json_parse(s, "", 0));
        auto b = std::stoi(webview::json_parse(s, "", 1));
        return std::to_string(a + b);
    });
    w.navigate(url);
    w.run();
}

NAN_MODULE_INIT(InitAll)
{
    Nan::Set(target, Nan::New("test").ToLocalChecked(),
             Nan::GetFunction(Nan::New<FunctionTemplate>(callback)).ToLocalChecked());

    Nan::Set(target, Nan::New("navigate").ToLocalChecked(),
             Nan::GetFunction(Nan::New<FunctionTemplate>(navigate)).ToLocalChecked());
}

NODE_MODULE(NativeExtension, InitAll)