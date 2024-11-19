// this file was auto-generated by wrapit v1.4.0
#include "Wrapper.h"

#include "jlImGuiTestEngine.h"
#include "dbg_msg.h"
#include "jlcxx/functions.hpp"
#include "jlcxx/stl.hpp"

namespace jlcxx {
  template<> struct IsMirroredType<ImGuiTestLogLineInfo> : std::false_type { };
  template<> struct DefaultConstructible<ImGuiTestLogLineInfo> : std::false_type { };
}

// Class generating the wrapper for type ImGuiTestLogLineInfo
// signature to use in the veto file: ImGuiTestLogLineInfo
struct JlImGuiTestLogLineInfo: public Wrapper {

  JlImGuiTestLogLineInfo(jlcxx::Module& jlModule): Wrapper(jlModule){
    DEBUG_MSG("Adding wrapper for type ImGuiTestLogLineInfo (" __HERE__ ")");
    // defined in ./imgui_test_engine/imgui_test_engine/imgui_te_engine.h:339:18
    jlcxx::TypeWrapper<ImGuiTestLogLineInfo>  t = jlModule.add_type<ImGuiTestLogLineInfo>("ImGuiTestLogLineInfo");
    type_ = std::unique_ptr<jlcxx::TypeWrapper<ImGuiTestLogLineInfo>>(new jlcxx::TypeWrapper<ImGuiTestLogLineInfo>(jlModule, t));
  }

  void add_methods() const{
    auto& t = *type_;
    t.template constructor<>(/*finalize=*/jlcxx::finalize_policy::yes);

    DEBUG_MSG("Adding Level methods  to provide read access to the field Level (" __HERE__ ")");
    // defined in ./imgui_test_engine/imgui_test_engine/imgui_te_engine.h:341:37
    // signature to use in the veto list: ImGuiTestLogLineInfo::Level
    t.method("Level", [](const ImGuiTestLogLineInfo& a) -> ImGuiTestVerboseLevel { return a.Level; });
    t.method("Level", [](ImGuiTestLogLineInfo& a) -> ImGuiTestVerboseLevel { return a.Level; });
    t.method("Level", [](const ImGuiTestLogLineInfo* a) -> ImGuiTestVerboseLevel { return a->Level; });
    t.method("Level", [](ImGuiTestLogLineInfo* a) -> ImGuiTestVerboseLevel { return a->Level; });
    // defined in ./imgui_test_engine/imgui_test_engine/imgui_te_engine.h:341:37
    // signature to use in the veto list: ImGuiTestLogLineInfo::Level
    // with ! suffix to veto the setter only.
    DEBUG_MSG("Adding Level! methods to provide write access to the field Level (" __HERE__ ")");
    t.method("Level!", [](ImGuiTestLogLineInfo& a, ImGuiTestVerboseLevel val) -> ImGuiTestVerboseLevel { return a.Level = val; });

    DEBUG_MSG("Adding Level! methods to provide write access to the field Level (" __HERE__ ")");
    t.method("Level!", [](ImGuiTestLogLineInfo* a, ImGuiTestVerboseLevel val) -> ImGuiTestVerboseLevel { return a->Level = val; });

    DEBUG_MSG("Adding LineOffset methods  to provide read access to the field LineOffset (" __HERE__ ")");
    // defined in ./imgui_test_engine/imgui_test_engine/imgui_te_engine.h:342:37
    // signature to use in the veto list: ImGuiTestLogLineInfo::LineOffset
    t.method("LineOffset", [](const ImGuiTestLogLineInfo& a) -> int { return a.LineOffset; });
    t.method("LineOffset", [](ImGuiTestLogLineInfo& a) -> int { return a.LineOffset; });
    t.method("LineOffset", [](const ImGuiTestLogLineInfo* a) -> int { return a->LineOffset; });
    t.method("LineOffset", [](ImGuiTestLogLineInfo* a) -> int { return a->LineOffset; });
    // defined in ./imgui_test_engine/imgui_test_engine/imgui_te_engine.h:342:37
    // signature to use in the veto list: ImGuiTestLogLineInfo::LineOffset
    // with ! suffix to veto the setter only.
    DEBUG_MSG("Adding LineOffset! methods to provide write access to the field LineOffset (" __HERE__ ")");
    t.method("LineOffset!", [](ImGuiTestLogLineInfo& a, int val) -> int { return a.LineOffset = val; });

    DEBUG_MSG("Adding LineOffset! methods to provide write access to the field LineOffset (" __HERE__ ")");
    t.method("LineOffset!", [](ImGuiTestLogLineInfo* a, int val) -> int { return a->LineOffset = val; });
  }

private:
  std::unique_ptr<jlcxx::TypeWrapper<ImGuiTestLogLineInfo>> type_;
};
std::shared_ptr<Wrapper> newJlImGuiTestLogLineInfo(jlcxx::Module& module){
  return std::shared_ptr<Wrapper>(new JlImGuiTestLogLineInfo(module));
}
