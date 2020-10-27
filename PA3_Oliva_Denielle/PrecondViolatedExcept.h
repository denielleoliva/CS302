#ifndef PRECOND_VIOLATED_EXCEPT__
#define PRECOND_VIOLATED_EXCEPT_

#include <stdexcept>
#include <string>


/** @class PrecondViolatedExcep PrecondViolatedExcep.h "PrecondViolatedExcep.h"
 *
 *  Specification for an object thrown on violation of precondition. */
class PrecondViolatedExcept : public std::logic_error {
public:
    explicit PrecondViolatedExcept(const std::string& message = "");
    
    virtual ~PrecondViolatedExcept() noexcept = default; //throw();
};


#endif