#include "Rule_11_1_1.h"
#include "clang/AST/Expr.h"
#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/Basic/Diagnostic.h"

using namespace clang::ast_matchers;

namespace clang {
namespace crulet {
namespace GJB {

void Rule_11_1_1::registerMatchers(MatchFinder *Finder) {
  StatementMatcher Matcher1 = forStmt(hasCondition(binaryOperator(
                                anyOf(hasOperatorName("<"), hasOperatorName(">"), 
                                  hasOperatorName("<="), hasOperatorName(">="), 
                                  hasOperatorName("=="), hasOperatorName("!=")),
                                anyOf(
                                  hasLHS(ignoringParenImpCasts(declRefExpr(
                                    to(varDecl(hasType(realFloatingPointType())))).bind("gjb1111_forLoop_condVar"))),
                                  hasRHS(ignoringParenImpCasts(declRefExpr(
                                    to(varDecl(hasType(realFloatingPointType())))).bind("gjb1111_forLoop_condVar"))))
                              )));
  StatementMatcher Matcher2 = forStmt(hasCondition(forEachDescendant(binaryOperator(
                                anyOf(hasOperatorName("<"), hasOperatorName(">"), 
                                  hasOperatorName("<="), hasOperatorName(">="), 
                                  hasOperatorName("=="), hasOperatorName("!=")),
                                eachOf(
                                  hasLHS(ignoringParenImpCasts(declRefExpr(
                                    to(varDecl(hasType(realFloatingPointType())))).bind("gjb1111_forLoop_condVar"))),
                                  hasRHS(ignoringParenImpCasts(declRefExpr(
                                    to(varDecl(hasType(realFloatingPointType())))).bind("gjb1111_forLoop_condVar"))))
                              ))));
  Finder->addMatcher(Matcher1, this);
  Finder->addMatcher(Matcher2, this);
}

void Rule_11_1_1::run(const MatchFinder::MatchResult &Result) {
  if(const DeclRefExpr *DRE = Result.Nodes.getNodeAs<DeclRefExpr>("gjb1111_forLoop_condVar")){
    SourceManager &SM = Result.Context->getSourceManager();
    SourceLocation SL = DRE->getExprLoc();
    if(!SL.isValid() || SM.isInSystemHeader(SL)){
      return;
    }

    DiagnosticsEngine &DE = Result.Context->getDiagnostics();
    Context->report(this->CheckerName, this->ReportMsg, DE, SL, this->DiagLevel);
    Context->getJsonBugReporter().report(this->CheckerName, this->ReportMsg, SM, SL, this->DiagLevel);
  }
}

} // namespace GJB
} // namespace crulet
} // namespace clang
