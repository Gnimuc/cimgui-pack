// this file was auto-generated by wrapit v1.4.0
#include "Wrapper.h"

#include "jlImGuiTestEngine.h"
#include "dbg_msg.h"
#include "jlcxx/functions.hpp"
#include "jlcxx/stl.hpp"

namespace jlcxx {
  template<> struct IsMirroredType<ImVec2> : std::false_type { };
  template<> struct DefaultConstructible<ImVec2> : std::false_type { };
}

// Class generating the wrapper for type ImVec2
// signature to use in the veto file: ImVec2
struct JlImVec2: public Wrapper {

  JlImVec2(jlcxx::Module& jlModule): Wrapper(jlModule){
    DEBUG_MSG("Adding wrapper for type ImVec2 (" __HERE__ ")");
    // defined in ../cimgui/imgui/imgui.h:299:8
    jlcxx::TypeWrapper<ImVec2>  t = jlModule.add_type<ImVec2>("ImVec2");
    type_ = std::unique_ptr<jlcxx::TypeWrapper<ImVec2>>(new jlcxx::TypeWrapper<ImVec2>(jlModule, t));
  }

  void add_methods() const{
    auto& t = *type_;
    t.template constructor<>(/*finalize=*/jlcxx::finalize_policy::yes);
  }

private:
  std::unique_ptr<jlcxx::TypeWrapper<ImVec2>> type_;
};
std::shared_ptr<Wrapper> newJlImVec2(jlcxx::Module& module){
  return std::shared_ptr<Wrapper>(new JlImVec2(module));
}
