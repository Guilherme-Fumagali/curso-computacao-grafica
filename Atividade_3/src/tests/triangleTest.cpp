#include <gtest/gtest.h>
#include "../Triangle.h"

/* ------------------ */
/* Triangle Functions */
/* ------------------ */

/* Constructor and accessor test */
TEST(trianglePublicMethods, Constructor) {
    Triangle t1;

    EXPECT_DOUBLE_EQ(t1[0].x(), 0);
}