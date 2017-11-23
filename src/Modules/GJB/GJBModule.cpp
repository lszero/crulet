#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "GJBModule.h"
#include "../../CruletChecker.h"
#include "Rule_4_3_1_4.h"
#include "Rule_4_3_1_5.h"
#include "Rule_4_3_1_6.h"
#include "Rule_4_3_1_7.h"
#include "Rule_4_3_1_8.h"

using namespace clang;
using namespace clang::ast_matchers;

namespace clang {
namespace crulet {
namespace GJB {

void GJBModule::registerCheckers(MatchFinder *Finder){
  this->registerChecker<Rule_4_3_1_4>("GJB-Rule-4.3.1.4")->registerMatchers(Finder);
  this->registerChecker<Rule_4_3_1_5>("GJB-Rule-4.3.1.5")->registerMatchers(Finder);
  this->registerChecker<Rule_4_3_1_6>("GJB-Rule-4.3.1.6")->registerMatchers(Finder);
  this->registerChecker<Rule_4_3_1_7>("GJB-Rule-4.3.1.7")->registerMatchers(Finder);
  this->registerChecker<Rule_4_3_1_8>("GJB-Rule-4.3.1.8")->registerMatchers(Finder);
}

} // namespace GJB
} // namespace crulet
} // namespace clang