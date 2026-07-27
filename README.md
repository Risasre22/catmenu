# CatMenu (API Build)

This is a modified build of [Pentalimbed/catmenu](https://github.com/Pentalimbed/catmenu), forked and maintained here for use with [Risa's All In One Menu](https://github.com/Risasre22/Risas-All-In-One-Menu). All credit for the original mod goes to the original author. See the [`api-build`](https://github.com/Risasre22/catmenu/tree/api-build) branch for the exact changes from upstream.

Changes from upstream:

- Added three exported C functions, defined outside `APIBase` so its vtable and existing consumers are unaffected: `CatMenu_OpenMenu`, `CatMenu_CloseMenu`, `CatMenu_SetHotkeyEnabled`. These let external plugins open, close, and manage the native hotkey listener directly, without simulating key presses or editing the config file. `SetHotkeyEnabled` only gates the native toggle-key check; no other input handling is affected.
- Refreshed `xmake-requires.lock` to current dependency versions.

Distributed under the same MIT license as the original.

---

Unified imgui backend for Skyrim Special Edition.

### Requirements
* [XMake](https://xmake.io) [2.8.2+]
* C++23 Compiler (MSVC, Clang?)

### Build
To build the project, run the following command:
```bat
xmake build
```

> ***Note:*** *This will generate a `build/windows/` directory in the **project's root directory** with the build output.*
