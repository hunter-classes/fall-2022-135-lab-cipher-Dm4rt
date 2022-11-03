#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
#include "caesar.h"

// add your tests here
TEST_CASE("Solve"){	
  CHECK(solve("YQJU Dqjpan Zwazwhqo Lnkcnwi")=="CUNY Hunter Daedalus Program");
  CHECK(solve("Uv, ubj ner lbh?")=="Hi, how are you?");
  CHECK(solve("Vjh cqn Oxaln kn frcq hxd!")=="May the Force be with you!");
}


