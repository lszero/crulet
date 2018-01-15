#ifndef CRULET_GJB_RULE_1_1_16_H
#define CRULET_GJB_RULE_1_1_16_H

#include "../../CruletChecker.h"
#include <unordered_set>

namespace clang {
namespace crulet {
namespace GJB {

class Rule_1_1_16 : public CruletChecker {
public:
  Rule_1_1_16(CruletContext *Context, StringRef CheckerName, StringRef ReportMsg)
    : CruletChecker(Context, CheckerName, ReportMsg) {}

  virtual void registerMatchers(ast_matchers::MatchFinder *Finder) override;
  virtual void run(const ast_matchers::MatchFinder::MatchResult &Result) override;

private:
  std::unordered_set<std::string> VarNameSet;
};

} // namespace GJB
} // namespace crulet
} // namespace clang

#endif