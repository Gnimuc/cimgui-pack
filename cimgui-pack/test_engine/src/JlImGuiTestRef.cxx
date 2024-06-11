// this file was auto-generated by wrapit v1.3.3
#include "Wrapper.h"

#include "jlImGuiTestEngine.h"
#include "dbg_msg.h"
#include "jlcxx/functions.hpp"
#include "jlcxx/stl.hpp"

namespace jlcxx {
  template<> struct IsMirroredType<ImGuiTestRef> : std::false_type { };
  template<> struct DefaultConstructible<ImGuiTestRef> : std::false_type { };
}

// Class generating the wrapper for type ImGuiTestRef
// signature to use in the veto file: ImGuiTestRef
struct JlImGuiTestRef: public Wrapper {

  JlImGuiTestRef(jlcxx::Module& jlModule): Wrapper(jlModule){
    DEBUG_MSG("Adding wrapper for type ImGuiTestRef (" __HERE__ ")");
    // defined in ./imgui_test_engine/imgui_test_engine/imgui_te_context.h:75:18
    jlcxx::TypeWrapper<ImGuiTestRef>  t = jlModule.add_type<ImGuiTestRef>("ImGuiTestRef");
    type_ = std::unique_ptr<jlcxx::TypeWrapper<ImGuiTestRef>>(new jlcxx::TypeWrapper<ImGuiTestRef>(jlModule, t));
  }

  void add_methods() const{
    auto& t = *type_;
    t.template constructor<>(/*finalize=*/jlcxx::finalize_policy::yes);


    DEBUG_MSG("Adding wrapper for void ImGuiTestRef::ImGuiTestRef(ImGuiID) (" __HERE__ ")");
    // defined in ./imgui_test_engine/imgui_test_engine/imgui_te_context.h:81:5
    t.constructor<ImGuiID>(/*finalize=*/jlcxx::finalize_policy::yes);


    DEBUG_MSG("Adding wrapper for void ImGuiTestRef::ImGuiTestRef(const char *) (" __HERE__ ")");
    // defined in ./imgui_test_engine/imgui_test_engine/imgui_te_context.h:82:5
    t.constructor<const char *>(/*finalize=*/jlcxx::finalize_policy::yes);

    DEBUG_MSG("Adding wrapper for bool ImGuiTestRef::IsEmpty() (" __HERE__ ")");
    // signature to use in the veto list: bool ImGuiTestRef::IsEmpty()
    // defined in ./imgui_test_engine/imgui_test_engine/imgui_te_context.h:83:10
    t.method("IsEmpty", static_cast<bool (ImGuiTestRef::*)()  const>(&ImGuiTestRef::IsEmpty));

    DEBUG_MSG("Adding ID methods  to provide read access to the field ID (" __HERE__ ")");
    // defined in ./imgui_test_engine/imgui_test_engine/imgui_te_context.h:77:21
    // signature to use in the veto list: ImGuiTestRef::ID
    t.method("ID", [](const ImGuiTestRef& a) -> ImGuiID { return a.ID; });
    t.method("ID", [](ImGuiTestRef& a) -> ImGuiID { return a.ID; });
    t.method("ID", [](const ImGuiTestRef* a) -> ImGuiID { return a->ID; });
    t.method("ID", [](ImGuiTestRef* a) -> ImGuiID { return a->ID; });
    // defined in ./imgui_test_engine/imgui_test_engine/imgui_te_context.h:77:21
    // signature to use in the veto list: ImGuiTestRef::ID
    // with ! suffix to veto the setter only.
    DEBUG_MSG("Adding ID! methods to provide write access to the field ID (" __HERE__ ")");
    t.method("ID!", [](ImGuiTestRef& a, ImGuiID val) -> ImGuiID { return a.ID = val; });

    DEBUG_MSG("Adding ID! methods to provide write access to the field ID (" __HERE__ ")");
    t.method("ID!", [](ImGuiTestRef* a, ImGuiID val) -> ImGuiID { return a->ID = val; });

    DEBUG_MSG("Adding Path methods  to provide read access to the field Path (" __HERE__ ")");
    // defined in ./imgui_test_engine/imgui_test_engine/imgui_te_context.h:78:21
    // signature to use in the veto list: ImGuiTestRef::Path
    t.method("Path", [](const ImGuiTestRef& a) -> const char * { return a.Path; });
    t.method("Path", [](const ImGuiTestRef* a) -> const char * { return a->Path; });
  }

private:
  std::unique_ptr<jlcxx::TypeWrapper<ImGuiTestRef>> type_;
};
std::shared_ptr<Wrapper> newJlImGuiTestRef(jlcxx::Module& module){
  return std::shared_ptr<Wrapper>(new JlImGuiTestRef(module));
}
