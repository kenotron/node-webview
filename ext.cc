
#include <nan.h>
#include "node_webview.h"

NAN_MODULE_INIT(InitAll)
{
  // Passing target down to the next NAN_MODULE_INIT
  NodeWebView::Init(target);
}

NODE_MODULE(NativeExtension, InitAll)