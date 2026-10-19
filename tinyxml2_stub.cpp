// Minimal stub implementations for tinyxml2 symbols referenced by netcdf
// This is a C-compatible stub that provides empty implementations
// to satisfy the linker when tinyxml2 is not available.

extern "C" {

// We need to define the mangled C++ symbols that netcdf references
// Using a trick: define them as C functions with the exact mangled names

// The following are the mangled names from the linker errors:
// ?Value@XMLNode@tinyxml2@@QEBAPEBDXZ
// ?FirstChildElement@XMLNode@tinyxml2@@QEBAPEBVXMLElement@2@PEBD@Z
// ?NextSiblingElement@XMLNode@tinyxml2@@QEBAPEBVXMLElement@2@PEBD@Z
// ?Name@XMLAttribute@tinyxml2@@QEBAPEBDXZ
// ?Value@XMLAttribute@tinyxml2@@QEBAPEBDXZ
// ?Attribute@XMLElement@tinyxml2@@QEBAPEBDPEBD0@Z
// ?GetText@XMLElement@tinyxml2@@QEBAPEBDXZ
// ??0XMLDocument@tinyxml2@@QEAA@_NW4Whitespace@1@@Z
// ?Parse@XMLDocument@tinyxml2@@QEAA?AW4XMLError@2@PEBD_K@Z

// Define stub functions with exact mangled names using asm
// For x64 MSVC

__pragma(comment(linker, "/alternatename:?Value@XMLNode@tinyxml2@@QEBAPEBDXZ=tinyxml2_stub_Value"));

// Simple approach: just define the mangled names directly via __declspec(naked)
// or use a .def file approach

}
