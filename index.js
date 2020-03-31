var NativeExtension = require('bindings')('NativeExtension');

// const url = `https://app.vssps.visualstudio.com/oauth2/authorize` +
//         `?client_id=2D0A1127-B0F3-46C5-B524-FF4310B0C68E` +
//         `&response_type=Assertion` +
//         `&state=something` +
//         `&scope=vso.packaging_write` +
//         `&redirect_uri=https://localhost/callback/oauth`;

// NativeExtension.navigate(url)

const wv = new NativeExtension.NodeWebView();
wv.run()

// module.exports = NodeWebView;
