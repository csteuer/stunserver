#include "unittest.h"

class CTestRateLimiter : public IUnitTest
{
public:
    HRESULT Run();

    HRESULT Test1();

    HRESULT Test2();

    UT_DECLARE_TEST_NAME("CTestRateLimiter");
};
