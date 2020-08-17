#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "docktests.h"
#include <CurrentLines/CurrentLineGenerator.hpp>

TEST_CASE("testing the calc function") {
    auto *clg = new CurrentLineGenerator();
            CHECK(clg->calc(1, 0) == 1);
            CHECK(clg->calc(1, 1) == 2);
            CHECK(clg->calc(2, 4) == 6);
            CHECK(clg->calc(1, 9) == 10);
}