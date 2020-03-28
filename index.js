var NativeExtension = require('bindings')('NativeExtension');

NativeExtension.navigate("https://github.com/kenotron/node-webview")

module.exports = NativeExtension;
