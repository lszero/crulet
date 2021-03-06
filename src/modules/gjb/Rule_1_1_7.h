#ifndef CRULET_GJB_RULE_1_1_7_H
#define CRULET_GJB_RULE_1_1_7_H

#include "../../CruletChecker.h"

namespace clang {
namespace crulet {
namespace GJB {

class Rule_1_1_7 : public CruletChecker {
public:
  Rule_1_1_7(CruletContext *Context, StringRef CheckerName, StringRef ReportMsg, 
      DiagnosticIDs::Level DiagLevel = DiagnosticIDs::Warning)
      : CruletChecker(Context, CheckerName, ReportMsg, DiagLevel) {}
};

} // namespace GJB
} // namespace crulet
} // namespace clang

#endif