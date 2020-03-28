{
    "targets": [
        {
            "target_name": "NativeExtension",
            "sources": [
                "ext.cc"
            ],
            "include_dirs": [
                "<!(node -e \"require('nan')\")",
                "<(module_root_dir)/webview/script/Microsoft.Web.WebView2.0.8.355/build/native/include",
                "<(module_root_dir)/webview"
            ],
            "libraries": [
                "<(module_root_dir)/webview/script/Microsoft.Web.WebView2.0.8.355/build/native/x64/WebView2Loader.dll.lib"
            ],
            "msvs_settings": {
                "VCCLCompilerTool": {
                    "AdditionalOptions": [
                        "-std:c++17"
                    ]
                }
            },
            "cflags_cc": [
                "-std=c++17"
            ]
        }
    ]
}