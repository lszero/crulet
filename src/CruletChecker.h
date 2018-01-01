#ifndef LLVM_CLANG_TOOLS_EXTRA_CRULET_CHECKER_H
#define LLVM_CLANG_TOOLS_EXTRA_CRULET_CHECKER_H

#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "CruletContext.h"

namespace clang {
namespace crulet {

class CruletChecker : public ast_matchers::MatchFinder::MatchCallback {
public:
  CruletChecker(CruletContext *Context, StringRef CheckerName, StringRef ReportMsg);
  virtual ~CruletChecker();
  
  virtual void registerMatchers(ast_matchers::MatchFinder *Finder) = 0;
  virtual void run(const ast_matchers::MatchFinder::MatchResult &Result) = 0;

  StringRef getName();

protected:
  std::string CheckerName;
  std::string ReportMsg;
  CruletContext *Context;
};

} // namespace crulet
} // namespace clang

#endif