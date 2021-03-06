#include "sbmlsim/internal/wrapper/InitialAssignmentWrapper.h"
#include "sbmlsim/internal/util/ASTNodeUtil.h"

InitialAssignmentWrapper::InitialAssignmentWrapper(const InitialAssignment *initialAssignment) {
  this->symbol = initialAssignment->getSymbol();
  this->math = ASTNodeUtil::rewriteFunctionDefinition(
      initialAssignment->getMath(),
      initialAssignment->getModel()->getListOfFunctionDefinitions());
}

InitialAssignmentWrapper::InitialAssignmentWrapper(const InitialAssignmentWrapper &initialAssignment) {
  this->symbol = initialAssignment.symbol;
  this->math = initialAssignment.math->deepCopy();
}

InitialAssignmentWrapper::~InitialAssignmentWrapper() {
  delete this->math;
}

const std::string &InitialAssignmentWrapper::getSymbol() const {
  return this->symbol;
}

const ASTNode *InitialAssignmentWrapper::getMath() const {
  return this->math;
}
