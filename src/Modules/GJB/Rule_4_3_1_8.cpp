#include "Rule_4_3_1_8.h"
#include "clang/AST/Expr.h"
#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/Basic/Diagnostic.h"

using namespace clang::ast_matchers;

namespace clang {
namespace crulet {
namespace GJB {

void Rule_4_3_1_8::registerMatchers(MatchFinder *Finder) {
  StatementMatcher Matcher = switchStmt(forEachSwitchCase(caseStmt().bind("switch_case")));
  Finder->addMatcher(Matcher, this);
}

void Rule_4_3_1_8::run(const MatchFinder::MatchResult &Result) {
  if(const CaseStmt *CS = Result.Nodes.getNodeAs<CaseStmt>("switch_case")){
    auto SubStmt = CS->getSubStmt();
    bool OK = true;
    if(isa<CaseStmt>(SubStmt)){
      OK = false;
    }

    if(!OK){
      DiagnosticsEngine &DE = Result.Context->getDiagnostics();
      std::string msg = "[" + CheckerName + "] " + "禁止switch的case语句中无任何可执行的语句";
      unsigned DiagID = DE.getDiagnosticIDs()->getCustomDiagID(DiagnosticIDs::Warning, msg);
      DE.Report(CS->getCaseLoc(), DiagID);
    }
  }
}

} // namespace GJB
} // namespace crulet
} // namespace clang
