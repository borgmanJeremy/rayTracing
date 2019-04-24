#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do
                           // this in one cpp file
#include "../../lib/include/vec_4f.hpp"
#include "catch.hpp"

TEST_CASE("Vector Functions", "[vector 4f]")
{
  rtl::vec_4f testVec_1(1, 2, 3);
  rtl::vec_4f testVec_2(4, 5, 6);

  SECTION("Constructor")
  {
    REQUIRE(testVec_1[0] == 1);
    REQUIRE(testVec_1[1] == 2);
    REQUIRE(testVec_1[2] == 3);
  }

  SECTION("const operator+=")
  {
    testVec_1 += testVec_2;
    REQUIRE(testVec_1[0] == 5);
    REQUIRE(testVec_1[1] == 7);
    REQUIRE(testVec_1[2] == 9);

    REQUIRE(testVec_2[0] == 4);
    REQUIRE(testVec_2[1] == 5);
    REQUIRE(testVec_2[2] == 6);
  }

  SECTION("const operator-=")
  {
    testVec_1 -= testVec_2;
    REQUIRE(testVec_1[0] == -3);
    REQUIRE(testVec_1[1] == -3);
    REQUIRE(testVec_1[2] == -3);

    REQUIRE(testVec_2[0] == 4);
    REQUIRE(testVec_2[1] == 5);
    REQUIRE(testVec_2[2] == 6);
  }

  SECTION("const operator*=")
  {
    testVec_1 *= testVec_2;
    REQUIRE(testVec_1[0] == 4);
    REQUIRE(testVec_1[1] == 10);
    REQUIRE(testVec_1[2] == 18);

    REQUIRE(testVec_2[0] == 4);
    REQUIRE(testVec_2[1] == 5);
    REQUIRE(testVec_2[2] == 6);
  }

  SECTION("const operator/=")
  {
    testVec_1 /= testVec_2;
    REQUIRE(testVec_1[0] == 1.0 / 4.0);
    REQUIRE(testVec_1[1] == 2.0 / 5.0);
    REQUIRE(testVec_1[2] == 3.0 / 6.0);

    REQUIRE(testVec_2[0] == 4);
    REQUIRE(testVec_2[1] == 5);
    REQUIRE(testVec_2[2] == 6);
  }

  SECTION(" operator+")
  {
    rtl::vec_4f result = testVec_1 + testVec_2;
    REQUIRE(result[0] == 5);
    REQUIRE(result[1] == 7);
    REQUIRE(result[2] == 9);

    REQUIRE(testVec_1[0] == 1);
    REQUIRE(testVec_1[1] == 2);
    REQUIRE(testVec_1[2] == 3);

    REQUIRE(testVec_2[0] == 4);
    REQUIRE(testVec_2[1] == 5);
    REQUIRE(testVec_2[2] == 6);
  }

  SECTION(" operator-")
  {
    rtl::vec_4f result = testVec_1 - testVec_2;
    REQUIRE(result[0] == -3);
    REQUIRE(result[1] == -3);
    REQUIRE(result[2] == -3);

    REQUIRE(testVec_1[0] == 1);
    REQUIRE(testVec_1[1] == 2);
    REQUIRE(testVec_1[2] == 3);

    REQUIRE(testVec_2[0] == 4);
    REQUIRE(testVec_2[1] == 5);
    REQUIRE(testVec_2[2] == 6);
  }

  SECTION(" operator*")
  {
    rtl::vec_4f result = testVec_1 * testVec_2;
    REQUIRE(result[0] == 4);
    REQUIRE(result[1] == 10);
    REQUIRE(result[2] == 18);

    REQUIRE(testVec_1[0] == 1);
    REQUIRE(testVec_1[1] == 2);
    REQUIRE(testVec_1[2] == 3);

    REQUIRE(testVec_2[0] == 4);
    REQUIRE(testVec_2[1] == 5);
    REQUIRE(testVec_2[2] == 6);
  }

  SECTION(" operator/")
  {
    rtl::vec_4f result = testVec_1 / testVec_2;
    REQUIRE(result[0] == 1.0 / 4.0);
    REQUIRE(result[1] == 2.0 / 5.0);
    REQUIRE(result[2] == 3.0 / 6.0);

    REQUIRE(testVec_1[0] == 1);
    REQUIRE(testVec_1[1] == 2);
    REQUIRE(testVec_1[2] == 3);

    REQUIRE(testVec_2[0] == 4);
    REQUIRE(testVec_2[1] == 5);
    REQUIRE(testVec_2[2] == 6);
  }

  SECTION("vec * double ")
  {
    testVec_1 *= 3;
    REQUIRE(testVec_1[0] == 3);
    REQUIRE(testVec_1[1] == 6);
    REQUIRE(testVec_1[2] == 9);
  }

  SECTION("vec / double ")
  {
    testVec_1 /= 3;
    REQUIRE(testVec_1[0] == 1.0 / 3.0);
    REQUIRE(testVec_1[1] == 2.0 / 3.0);
    REQUIRE(testVec_1[2] == 3.0 / 3.0);
  }

  SECTION("new vec = vec * double ")
  {
    rtl::vec_4f temp = testVec_1 * 3;
    REQUIRE(temp[0] == 3);
    REQUIRE(temp[1] == 6);
    REQUIRE(temp[2] == 9);

    REQUIRE(testVec_1[0] == 1);
    REQUIRE(testVec_1[1] == 2);
    REQUIRE(testVec_1[2] == 3);

    REQUIRE(testVec_2[0] == 4);
    REQUIRE(testVec_2[1] == 5);
    REQUIRE(testVec_2[2] == 6);
  }

  SECTION("new vec = vec / double ")
  {
    rtl::vec_4f temp = testVec_1 / 3;
    REQUIRE(temp[0] == 1.0 / 3.0);
    REQUIRE(temp[1] == 2.0 / 3.0);
    REQUIRE(temp[2] == 3.0 / 3.0);

    REQUIRE(testVec_1[0] == 1);
    REQUIRE(testVec_1[1] == 2);
    REQUIRE(testVec_1[2] == 3);

    REQUIRE(testVec_2[0] == 4);
    REQUIRE(testVec_2[1] == 5);
    REQUIRE(testVec_2[2] == 6);
  }

  SECTION("length")
  {
    REQUIRE(testVec_1.length() == sqrt(14.0));
    REQUIRE(testVec_1[0] == 1);
    REQUIRE(testVec_1[1] == 2);
    REQUIRE(testVec_1[2] == 3);
  }

  SECTION("squared length")
  {
    REQUIRE(testVec_1.squared_length() == 14.0);
    REQUIRE(testVec_1[0] == 1);
    REQUIRE(testVec_1[1] == 2);
    REQUIRE(testVec_1[2] == 3);
  }

  SECTION("Unit Vector")
  {
    testVec_1.makeUnitVector();

    REQUIRE(testVec_1[0] == 1.0 / sqrt(14.0));
    REQUIRE(testVec_1[1] == 2.0 / sqrt(14.0));
    REQUIRE(testVec_1[2] == 3.0 / sqrt(14.0));
  }

  SECTION("dot product")
  {
    REQUIRE(testVec_1.dot(testVec_2) == 32);

    REQUIRE(testVec_1[0] == 1);
    REQUIRE(testVec_1[1] == 2);
    REQUIRE(testVec_1[2] == 3);

    REQUIRE(testVec_2[0] == 4);
    REQUIRE(testVec_2[1] == 5);
    REQUIRE(testVec_2[2] == 6);
  }

  SECTION("cross multiply")
  {
    rtl::vec_4f result = testVec_1.cross(testVec_2);

    REQUIRE(result[0] == -3);
    REQUIRE(result[1] == 6);
    REQUIRE(result[2] == -3);

    rtl::vec_4f temp(5, 1, 5);
    rtl::vec_4f result_2 = testVec_1.cross(temp);

    REQUIRE(result_2[0] == 7);
    REQUIRE(result_2[1] == 10);
    REQUIRE(result_2[2] == -9);

    REQUIRE(testVec_1[0] == 1);
    REQUIRE(testVec_1[1] == 2);
    REQUIRE(testVec_1[2] == 3);

    REQUIRE(testVec_2[0] == 4);
    REQUIRE(testVec_2[1] == 5);
    REQUIRE(testVec_2[2] == 6);
  }
}
