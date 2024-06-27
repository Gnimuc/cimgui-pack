// this file was auto-generated by wrapit v1.3.3
#include "Wrapper.h"

#include "jlImGuiTestEngine.h"
#include "dbg_msg.h"
#include "jlcxx/functions.hpp"
#include "jlcxx/stl.hpp"

namespace jlcxx {
  template<> struct IsMirroredType<ImGuiCaptureArgs> : std::false_type { };
  template<> struct DefaultConstructible<ImGuiCaptureArgs> : std::false_type { };
}

// Class generating the wrapper for type ImGuiCaptureArgs
// signature to use in the veto file: ImGuiCaptureArgs
struct JlImGuiCaptureArgs: public Wrapper {

  JlImGuiCaptureArgs(jlcxx::Module& jlModule): Wrapper(jlModule){
    DEBUG_MSG("Adding wrapper for type ImGuiCaptureArgs (" __HERE__ ")");
    // defined in ./imgui_test_engine/imgui_test_engine/imgui_capture_tool.h:59:8
    jlcxx::TypeWrapper<ImGuiCaptureArgs>  t = jlModule.add_type<ImGuiCaptureArgs>("ImGuiCaptureArgs");
    type_ = std::unique_ptr<jlcxx::TypeWrapper<ImGuiCaptureArgs>>(new jlcxx::TypeWrapper<ImGuiCaptureArgs>(jlModule, t));
  }

  void add_methods() const{
    auto& t = *type_;
    t.template constructor<>(/*finalize=*/jlcxx::finalize_policy::yes);
  }

private:
  std::unique_ptr<jlcxx::TypeWrapper<ImGuiCaptureArgs>> type_;
};
std::shared_ptr<Wrapper> newJlImGuiCaptureArgs(jlcxx::Module& module){
  return std::shared_ptr<Wrapper>(new JlImGuiCaptureArgs(module));
}
