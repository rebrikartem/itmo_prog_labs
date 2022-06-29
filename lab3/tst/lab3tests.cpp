#include <gtest/gtest.h>
#include "CircularBuffer.h"
#include "Alghorithms.h"
#include "CRational.h"

template<class T>
void assert_buffer(CircularBuffer<T>& cb, vector<T>& v)
{
  int i = 0;
  for(auto e : cb){
    ASSERT_EQ(e, v[i]);
    i++;
  }
}

TEST(CircularBufferTest, test1)
{
  CircularBuffer<int> cb(5);
  cb.push_back(1);
  cb.push_back(3);
  cb.push_back(3);
  cb.push_back(1);

  ASSERT_TRUE(Is_palindrome(cb.begin(), cb.end()));
}

TEST(CircularBufferTest, test2) 
{
  CircularBuffer<int> cb(5);
  cb.push_back(1);
  cb.push_back(3);
  cb.push_back(3);
  cb.push_back(4);

  ASSERT_FALSE(Is_palindrome(cb.begin(), cb.end(), [](int i){return i % 2 == 0;}));
}

TEST(CircularBufferTest, test3)
{
  CircularBuffer<int> cb(5);
  cb.push_back(1);
  cb.push_back(3);
  cb.push_back(3);
  cb.push_back(4);

  auto itr = std::find(cb.begin(), cb.end(), 4);

  ASSERT_EQ(*itr, 4);
}

TEST(CircularBufferTest, test4)
{
  CircularBuffer<int> cb(5);
  cb.push_back(4);
  cb.push_back(3);
  cb.push_back(2);
  cb.push_back(1);

  sort(cb.begin(), cb.end());

  vector<int> v = {1, 2, 3, 4};
  for(int i = 0; i < cb.get_size(); i++){
    ASSERT_EQ(cb[i], v[i]);
  }

}

TEST(CircularBufferTest, test5)
{
  CircularBuffer<int> cb(5);
  cb.push_back(1);
  cb.push_back(2);
  cb.push_back(3);
  cb.push_back(4);
  cb.push_back(5);

  vector<int> v = {1, 2, 3, 4, 5};

  assert_buffer(cb, v);
}

TEST(CircularBufferTest, test6)
{
  CircularBuffer<int> cb(5);
  cb.push_back(1);
  cb.push_back(2);
  cb.push_back(3);
  cb.push_back(4);
  cb.push_back(5);

  CircularBuffer<int>::Iterator it = cb.begin();

  auto it1 = it;
  auto it2 = it;
  it = it + 3;
  it1  = 3 + it1;
  ++it1;
  it2 += 2;

  ASSERT_EQ(*it, 4);
  ASSERT_EQ(*it1, 5);
  ASSERT_EQ(*it2, 3);

  auto it3 = it2 - 2;
  ASSERT_EQ(*it3, 1);

  int n1 = it1 - it1;
  ASSERT_EQ(n1, 0);

  it1 = cb.begin();
  it2 = cb.begin();

  ASSERT_EQ(it1 - it2, 0);
  ASSERT_EQ(it2 - it1, 0);

  it1 += 2;
  ASSERT_EQ(it1 - it2, 2);
  ASSERT_EQ(it2 - it1, -2);
}

TEST(aboba, test1)
{
  CircularBuffer<int> cb(5);
  cb.push_back(1);
  cb.push_back(2);
  cb.push_back(3);
  cb.push_back(4);
  cb.push_back(5);

  auto it1 = cb.begin();
  ASSERT_EQ(it1[2], 3);
}

TEST(CircularBufferPushIntTest, test1)
{
  CircularBuffer<int> cb(7);
  for(int i = 1; i < 8; i++){
    cb.push_back(i);
  }
  
  vector<int> v1 = {1, 2, 3, 4, 5, 6, 7}; // expected cb: 1 2 3 4 5 6 7
  assert_buffer(cb, v1);

  cb.push_back(8);
  vector<int> v2 = {2, 3, 4, 5, 6, 7, 8}; // expected cb: 2 3 4 5 6 7 8
  assert_buffer(cb, v2);

  cb.pop_back();
  cb.push_back(9);
  cb.push_back(10);
  vector<int> v3 = {3, 4, 5, 6, 7, 9, 10}; // expected cb: 3 4 5 6 7 9 10
  assert_buffer(cb, v3);

  cb.pop_front();
  vector<int> v4 = {4, 5, 6, 7, 9, 10}; // expected cb: 4 5 6 7 9 10
  assert_buffer(cb, v4);

  cb.pop_back();
  vector<int> v5 = {4, 5, 6, 7, 9}; // expected cb: 4 5 6 7 9
  assert_buffer(cb, v5);
}

TEST(CircularBufferPushDoubleTest, test1)
{
  CircularBuffer<double> cb(7);
  for(int i = 1; i < 8; i++){
    cb.push_back(i + 0.5);
  }
  
  vector<double> v1 = {1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5}; // expected cb: 1.5 2.5 3.5 4.5 5.5 6.5 7.5
  assert_buffer(cb, v1);

  cb.push_back(8.5);
  vector<double> v2 = {2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5}; // expected cb: 2.5 3.5 4.5 5.5 6.5 7.5 8.5
  assert_buffer(cb, v2);

  cb.pop_back();
  cb.push_back(9.5);
  cb.push_back(10.5);
  vector<double> v3 = {3.5, 4.5, 5.5, 6.5, 7.5, 9.5, 10.5}; // expected cb: 3.5 4.5 5.5 6.5 7.5 9.5 10.5
  assert_buffer(cb, v3);

  cb.pop_front();
  vector<double> v4 = {4.5, 5.5, 6.5, 7.5, 9.5, 10.5}; // expected cb: 4.5 5.5 6.5 7.5 9.5 10.5
  assert_buffer(cb, v4);

  cb.pop_back();
  vector<double> v5 = {4.5, 5.5, 6.5, 7.5, 9.5}; // expected cb: 4.5 5.5 6.5 7.5 9.5
  assert_buffer(cb, v5);
}

TEST(CircularBufferPushStringTest, test1)
{
  CircularBuffer<string> cb(7);
  cb.push_back("A");
  cb.push_back("B");
  cb.push_back("C");
  cb.push_back("D");
  cb.push_back("E");
  cb.push_back("F");
  cb.push_back("G");
  
  vector<string> v1 = {"A", "B", "C", "D", "E", "F", "G"}; // expected cb: A B C D E F G
  assert_buffer(cb, v1);

  cb.push_back("H");
  vector<string> v2 = {"B", "C", "D", "E", "F", "G", "H"}; // expected cb: B C D E F G H
  assert_buffer(cb, v2);

  cb.pop_back();
  cb.push_back("I");
  cb.push_back("J");
  vector<string> v3 = {"C", "D", "E", "F", "G", "I", "J"}; // expected cb: C D E F G I J
  assert_buffer(cb, v3);

  cb.pop_front();
  vector<string> v4 = {"D", "E", "F", "G", "I", "J"}; // expected cb: D E F G I J
  assert_buffer(cb, v4);

  cb.pop_back();
  vector<string> v5 = {"D", "E", "F", "G", "I"}; // expected cb: D E F G I
  assert_buffer(cb, v5);
}

template<class U>
void assert_buffer(CircularBuffer<CRational>& cb, vector<U>& v)
{
  int i = 0;
  for(auto e : cb){
    ASSERT_EQ(float(e), v[i]);
    i++;
  }
}

TEST(CircularBufferCRational, test1)
{
  CircularBuffer<CRational> cb(5);
  CRational cr1 = CRational(3,2);
  CRational cr2 = CRational(5,2);
  CRational cr3 = CRational(7,2);
  CRational cr4 = CRational(9,2);
  CRational cr5 = CRational(11,2);

  cb.push_back(cr1);
  cb.push_back(cr2);
  cb.push_back(cr3);
  cb.push_back(cr4);
  cb.push_back(cr5);

  vector<float> v = {1.5, 2.5, 3.5, 4.5, 5.5}; // expected cb: 1.5 2.5 3.5 4.5 5.5

  assert_buffer(cb, v);

  cb.push_back(CRational(13,2));
  vector<float> v2 = {2.5, 3.5, 4.5, 5.5, 6.5}; // expected cb: 2.5 3.5 4.5 5.5 6.5
  assert_buffer(cb, v2);

  cb.pop_back();
  cb.push_back(CRational(15,2));
  cb.push_back(CRational(17,2));
  vector<float> v3 = {3.5, 4.5, 5.5, 7.5, 8.5}; // expected cb: 3.5 4.5 5.5 7.5 8.5
  assert_buffer(cb, v3);

  cb.pop_front();
  vector<float> v4 = {4.5, 5.5, 7.5, 8.5}; // expected cb: 4.5 5.5 7.5 8.5
  assert_buffer(cb, v4);

  cb.pop_back();
  vector<float> v5 = {4.5, 5.5, 7.5}; // expected cb: 4.5 5.5 7.5
  assert_buffer(cb, v5);
}

TEST(CircularBufferIntAlg, test1)
{
  CircularBuffer<int> cb(5);
  cb.push_back(1);
  cb.push_back(2);
  cb.push_back(3);
  cb.push_back(4);
  cb.push_back(5);

  ASSERT_TRUE(All_of(cb.begin(), cb.end(), [](int i){return i <= 5;})); // all elements <= 5

  ASSERT_TRUE(Any_of(cb.begin(), cb.end(), [](int i){return i <= 2;})); // two elems <= 2;

  ASSERT_TRUE(None_of(cb.begin(), cb.end(), [](int i){return i > 5;})); // no elems that > 5

  ASSERT_TRUE(One_of(cb.begin(), cb.end(), [](int i){return i == 2;})); // only 1 elem == 2;

  ASSERT_TRUE(Is_sorted(cb.begin(), cb.end())); // sorted ascending

  ASSERT_FALSE(Is_sorted(cb.begin(), cb.end(), [](int i, int j){return i > j;})); // not sorted descending

  Partition(cb.begin(), cb.end(), [](int i){return i % 2;});

  vector<int> v = {1,3,5,4,2}; // expected cb: 1 3 5 4 2

  assert_buffer(cb, v);

  ASSERT_TRUE(Is_partitioned(cb.begin(), cb.end(), [](int i){return i % 2;})); // partitioned by odd and even

  ASSERT_EQ(*Find_not(cb.begin(), cb.end(), 1), 3); // first elem != 1 is 3

  ASSERT_EQ(Find_backward(cb.begin(), cb.end(), 5), cb.begin() + 2);

  ASSERT_FALSE(Is_palindrome(cb.begin(), cb.end())); // not palindrome 

  sort(cb.begin(), cb.end()); // now cb: 1 2 3 4 5 
  vector<int> v2 = {1, 2, 3, 4, 5};
  assert_buffer(cb, v2);

  ASSERT_TRUE(Is_palindrome(cb.begin(), cb.end(), [](int i){return i * 0;})); 

  ASSERT_EQ(distance(cb.begin(), cb.end()), 5);

  ASSERT_EQ(distance(cb.end(), cb.begin()), -5);

}

TEST(CircularBufferStringAlg, test1)
{
  CircularBuffer<string> cb(5);
  cb.push_back("A");
  cb.push_back("B");
  cb.push_back("C");
  cb.push_back("B");
  cb.push_back("A");

  ASSERT_TRUE(All_of(cb.begin(), cb.end(), [](string i){return i != "D";})); // all of elements != D

  ASSERT_TRUE(Any_of(cb.begin(), cb.end(), [](string i){return i == "C";})); // at least 1 elem == C

  ASSERT_TRUE(None_of(cb.begin(), cb.end(), [](string i){return i.length() > 1;})); // none of elem length > 1

  ASSERT_TRUE(One_of(cb.begin(), cb.end(), [](string i){return i == "C";})); // only 1 elem == C

  ASSERT_FALSE(One_of(cb.begin(), cb.end(), [](string i){return i == "B";})); // more than 1 elem == B

  ASSERT_FALSE(Is_sorted(cb.begin(), cb.end())); // not sorted

  ASSERT_EQ(Find_not(cb.begin(), cb.end(), "A"), cb.begin() + 1);

  ASSERT_EQ(Find_backward(cb.begin(), cb.end(), "B"), cb.begin() + 3);

  ASSERT_TRUE(Is_palindrome(cb.begin(), cb.end()));

  sort(cb.begin(), cb.end()); // expected cb: A A B B C
  vector<string> v = {"A", "A", "B", "B", "C"};

  assert_buffer(cb, v);
}

TEST(CircularBufferCRationalAlg, test1)
{
  CircularBuffer<CRational> cb(5);
  cb.push_back(CRational(1,1));
  cb.push_back(CRational(2,1));
  cb.push_back(CRational(3,1));
  cb.push_back(CRational(4,1));
  cb.push_back(CRational(5,1));

  ASSERT_TRUE(All_of(cb.begin(), cb.end(), [](CRational i){return float(i) <= 5;})); // all elements <= 5

  ASSERT_TRUE(Any_of(cb.begin(), cb.end(), [](CRational i){return float(i) <= 2;})); // two elems <= 2;

  ASSERT_TRUE(None_of(cb.begin(), cb.end(), [](CRational i){return float(i) > 5;})); // no elems that > 5

  ASSERT_TRUE(One_of(cb.begin(), cb.end(), [](CRational i){return float(i) == 2;})); // only 1 elem == 2;

  ASSERT_TRUE(Is_sorted(cb.begin(), cb.end())); // sorted ascending

  ASSERT_FALSE(Is_sorted(cb.begin(), cb.end(), [](CRational i, CRational j){return i > j;})); // not sorted descending

  ASSERT_EQ(float(*Find_not(cb.begin(), cb.end(), 1)), 2); // first elem != 1 is 3

  ASSERT_EQ(Find_backward(cb.begin(), cb.end(), 5), cb.begin() + 4);

  ASSERT_FALSE(Is_palindrome(cb.begin(), cb.end())); // not palindrome 

  sort(cb.begin(), cb.end()); // expected cb: 1 2 3 4 5 
  vector<int> v2 = {1, 2, 3, 4, 5};
  assert_buffer(cb, v2);

  ASSERT_TRUE(Is_palindrome(cb.begin(), cb.end(), [](CRational i){return float(i) * 0;})); 
}

TEST(stl, test1)
{
  vector<int> v = {1, 2, 3};
  ASSERT_EQ(Find_if(v.begin(), v.end(), [](int i){return i == 2;}), v.begin() + 1);
}