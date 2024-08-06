VSCode configuration:

```json
// Autoformatting
  "editor.formatOnSave": true,

  "[cpp]": {
// Use clang formatter
    "editor.defaultFormatter": "xaver.clang-format"
  },

  "cmake.options.statusBarVisibility": "visible",

// Set clangd as default provider
  "C_Cpp.default.configurationProvider": "clangd",
// Disable Microsoft's intelli sense
  "C_Cpp.intelliSenseEngine": "disabled",

// clang-tidy config
  "C_Cpp.codeAnalysis.clangTidy.enabled": true,
  "C_Cpp.codeAnalysis.clangTidy.path": "/usr/bin/clang-tidy",
  "C_Cpp.codeAnalysis.clangTidy.useBuildPath": true,
  "C_Cpp.codeAnalysis.clangTidy.args": [
      "-p ./build/"
  ]

// Find your executables for these programs (which command)
  "clang-format.executable": "/usr/bin/clang-format",
  "clangd.path": "/usr/bin/clangd",
  "cmakeFormat.exePath": "/usr/bin/cmake-format",

  "[cmake]": {
// Use cmake formatter
    "editor.defaultFormatter": "cheshirekow.cmake-format"
  },
```