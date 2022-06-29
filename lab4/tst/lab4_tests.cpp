#include <gtest/gtest.h>
#include "Cube.h"
#include <string>

using namespace std;

TEST(CubikSolve, test1)
{
    Cube right = Cube();
    Cube kub = Cube();
	
	string s = "L2 R U2 L2 R' U D' L U' L2 D' B2 F2 U2 B2 U L D' L' U L' F' D R' F2";
	kub.scramble(s);

    string scr = kub.solve();

    ASSERT_TRUE(kub.isCorrect());
    ASSERT_EQ(right, kub);

    kub.scramble("L2 R U2 L2 R' U D' L U' L2 D' B2 F2 U2 B2 U L D' L' U L' F' D R' F2");
    kub.scramble(scr);


    ASSERT_EQ(right, kub);
}

TEST(CubikSolve, test2)
{
    Cube right = Cube();
    Cube kub = Cube();
	
	string s = "U2 R2 D2 B2 L2 U L2 R' F2 R F' B L B U' L' R2 D' F2 L U' B' R' L' B2";
	kub.scramble(s);

    string scr = kub.solve();

    ASSERT_TRUE(kub.isCorrect());
    ASSERT_EQ(right, kub);

    kub.scramble(s);
    kub.scramble(scr);


    ASSERT_EQ(right, kub);
}

TEST(CubikSolve, test3)
{
    Cube right = Cube();
    Cube kub = Cube();
	
	string s = "R2 L B2 U D2 R U' D B2 F2 D B2 U D' R' L2 D B2 D2 U2 R L2 F' U2 B2";
	kub.scramble(s);

    string scr = kub.solve();

    ASSERT_TRUE(kub.isCorrect());
    ASSERT_EQ(right, kub);

    kub.scramble(s);
    kub.scramble(scr);


    ASSERT_EQ(right, kub);
}

TEST(CubikSolve, test4)
{
    Cube right = Cube();
    Cube kub = Cube();
	
	string s = "D' L' D2 R2 D F' R2 B R2 F' D' R B2 D R' D2 R' U L D' B R D2 U F2";
	kub.scramble(s);

    string scr = kub.solve();

    ASSERT_TRUE(kub.isCorrect());
    ASSERT_EQ(right, kub);

    kub.scramble(s);
    kub.scramble(scr);


    ASSERT_EQ(right, kub);
}

TEST(CubikSolve, test5)
{
    Cube right = Cube();
    Cube kub = Cube();
	
	string s = "U D2 B F2 D2 U B' L D2 B2 R D U' L2 D' F' B' D2 F R B F' R2 L' U2";
	kub.scramble(s);

    string scr = kub.solve();

    ASSERT_TRUE(kub.isCorrect());
    ASSERT_EQ(right, kub);

    kub.scramble(s);
    kub.scramble(scr);


    ASSERT_EQ(right, kub);
}

TEST(CubikSolve, test6)
{
    Cube right = Cube();
    Cube kub = Cube();
	
	string s = "B' U' B2 L2 B2 U2 L' R U2 B2 U2 R B' R2 L' B L' D U L' B F' R' U D2";
	kub.scramble(s);

    string scr = kub.solve();

    ASSERT_TRUE(kub.isCorrect());
    ASSERT_EQ(right, kub);

    kub.scramble(s);
    kub.scramble(scr);


    ASSERT_EQ(right, kub);
}

TEST(CubikSolve, test7)
{
    Cube right = Cube();
    Cube kub = Cube();
	
	string s = "U2 B' L2 R2 D L D2 R B' L2 F R D' R2 D L2 U F R L' U2 B' F' U R";
	kub.scramble(s);

    string scr = kub.solve();

    ASSERT_TRUE(kub.isCorrect());
    ASSERT_EQ(right, kub);

    kub.scramble(s);
    kub.scramble(scr);


    ASSERT_EQ(right, kub);
}

TEST(CubikSolve, test8)
{
    Cube right = Cube();
    Cube kub = Cube();
	
	string s = "L U L' D' F R B2 U2 F B2 R B D2 L B' U F' D F D R2 D U2 R2 L";
	kub.scramble(s);

    string scr = kub.solve();

    ASSERT_TRUE(kub.isCorrect());
    ASSERT_EQ(right, kub);

    kub.scramble(s);
    kub.scramble(scr);


    ASSERT_EQ(right, kub);
}

TEST(CubikSolve, test9)
{
    Cube right = Cube();
    Cube kub = Cube();
	
	string s = "D' B2 D' B' R2 B2 D' R2 L F L' F' D' F' L D' F' R D' B U R2 F' R2 F";
	kub.scramble(s);

    string scr = kub.solve();

    ASSERT_TRUE(kub.isCorrect());
    ASSERT_EQ(right, kub);

    kub.scramble(s);
    kub.scramble(scr);


    ASSERT_EQ(right, kub);
}

TEST(CubikSolve, test10)
{
    Cube right = Cube();
    Cube kub = Cube();
	
	string s = "F2 U D2 L2 B2 F D2 R' U' B' D2 B2 L2 R2 U R' B2 D2 U2 L F D' B2 U F2";
	kub.scramble(s);

    string scr = kub.solve();

    ASSERT_TRUE(kub.isCorrect());
    ASSERT_EQ(right, kub);

    kub.scramble(s);
    kub.scramble(scr);


    ASSERT_EQ(right, kub);
}

TEST(CubikSolve, test11)
{
    Cube right = Cube();
    Cube kub = Cube();
	
	string s = "F' L R F' L U' L U2 D R D B U R' D' U L' F L R' B2 F' D2 U' L2";
	kub.scramble(s);

    string scr = kub.solve();

    ASSERT_TRUE(kub.isCorrect());
    ASSERT_EQ(right, kub);

    kub.scramble(s);
    kub.scramble(scr);


    ASSERT_EQ(right, kub);
}

TEST(CubikSolve, test12)
{
    Cube right = Cube();
    Cube kub = Cube();
	
	string s = "B R F U2 R B2 D U L B' U2 D2 R F2 U R' L F2 D2 L2 D2 F L2 B U2";
	kub.scramble(s);

    string scr = kub.solve();

    ASSERT_TRUE(kub.isCorrect());
    ASSERT_EQ(right, kub);

    kub.scramble(s);
    kub.scramble(scr);


    ASSERT_EQ(right, kub);
}

TEST(CubikSolve, test13)
{
    Cube right = Cube();
    Cube kub = Cube();
	
	string s = "F2 L F2 B2 U2 L' R' U2 B2 R2 B L2 D' R D' B' R2 F B' D2 L' D2 F' L' R";
	kub.scramble(s);

    string scr = kub.solve();

    ASSERT_TRUE(kub.isCorrect());
    ASSERT_EQ(right, kub);

    kub.scramble(s);
    kub.scramble(scr);


    ASSERT_EQ(right, kub);
}

TEST(CubikSolve, test14)
{
    Cube right = Cube();
    Cube kub = Cube();
	
	string s = "B' R L U F2 B' D' L D U2 L R F' R2 U' B2 F D2 U F' B R B2 L2 R2";
	kub.scramble(s);

    string scr = kub.solve();

    ASSERT_TRUE(kub.isCorrect());
    ASSERT_EQ(right, kub);

    kub.scramble(s);
    kub.scramble(scr);


    ASSERT_EQ(right, kub);
}

TEST(CubikSolve, test15)
{
    Cube right = Cube();
    Cube kub = Cube();
	
	string s = "L D' L R B R' U L2 B U L U R L B2 L2 B' U B L' U D2 B' F2 U";
	kub.scramble(s);

    string scr = kub.solve();

    ASSERT_TRUE(kub.isCorrect());
    ASSERT_EQ(right, kub);

    kub.scramble(s);
    kub.scramble(scr);


    ASSERT_EQ(right, kub);
}