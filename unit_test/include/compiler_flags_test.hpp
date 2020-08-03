#ifndef	COMPILER_FLAG_TEST_HPP
#define	COMPILER_FLAG_TEST_HPP

//////////////////////////////////////////////////////////////////////////////
// Test fixture class: compiler flags
//////////////////////////////////////////////////////////////////////////////

class CompileFlagTest : public ::testing::Test
{
 protected:

  CompileFlagTest()
  { }
};

//////////////////////////////////////////////////////////////////////////////
// Test macros:

TEST_F(CompileFlagTest, AllFlags)
{
  std::cout << "             |----------------------------|----------|\n"
            << "             |        Compiler Flag       | defined? |\n"
            << "             |----------------------------|----------|\n";
#ifdef USE_MKL
  std::cout << "             |                    USE_MKL |    X     |\n";
#else
  std::cout << "             |                    USE_MKL |          |\n";
#endif
//
#ifdef _OPENMP
  std::cout << "             |                    _OPENMP |    X     |\n";
#else
  std::cout << "             |                    _OPENMP |          |\n";
#endif
//
#ifdef __INTEL_COMPILER
  std::cout << "             |           __INTEL_COMPILER |    X     |\n";
#else
  std::cout << "             |           __INTEL_COMPILER |          |\n";
#endif
//
#ifdef __ICC
  std::cout << "             |                      __ICC |    X     |\n";
#else
  std::cout << "             |                      __ICC |          |\n";
#endif
//
#ifdef USE_MM_MALLOC
  std::cout << "             |              USE_MM_MALLOC |    X     |\n";
#else
  std::cout << "             |              USE_MM_MALLOC |          |\n";
#endif
//
#ifdef NDEBUG
  std::cout << "             |                     NDEBUG |    X     |\n";
#else
  std::cout << "             |                     NDEBUG |          |\n";
#endif
//
  std::cout << "             |----------------------------|----------|\n";
}

//////////////////////////////////////////////////////////////////////////////

#endif	// header guard COMPILER_FLAG_TEST_HPP
