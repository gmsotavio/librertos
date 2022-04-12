#include "librertos_proj.h"

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

void librertos_assert(intptr_t val, const char *msg)
{
    /* Call mock. */
    mock()
        .actualCall("librertos_assert")
        .withParameter("val", val)
        .withParameter("msg", msg);

    /* Throw an exception to stop caller's execution. The test must expect both
     * the mock and the exception.
     */
    throw AssertionError(msg);
}
