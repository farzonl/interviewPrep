#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "linkedList.hpp"
#include "ch1.hpp"
#include "ch2.hpp"
#include "ch3.hpp"
#include "ch8.hpp"
#include "ch16.hpp"


TEST_CASE( "test stack template int push and pop" ) {
    Stack<int> s(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    REQUIRE( s.peek() == 1 );
    REQUIRE( s.Size() == 5 );
    s.pop();
    REQUIRE( s.peek() == 2 );
    REQUIRE( s.Size() == 4 );
    s.pop();
    REQUIRE( s.peek() == 3 );
    REQUIRE( s.Size() == 3 );
}

TEST_CASE( "test stack template char push and pop" ) {
    Stack<char> s('e');
    s.push('d');
    s.push('c');
    s.push('b');
    s.push('a');
    REQUIRE( s.peek() == 'a' );
    REQUIRE( s.Size() == 5 );
    s.pop();
    REQUIRE( s.peek() == 'b' );
    REQUIRE( s.Size() == 4 );
    s.pop();
    REQUIRE( s.peek() == 'c' );
    REQUIRE( s.Size() == 3 );
}

TEST_CASE( "test stack delete" ) {
    Stack<int> *s = new Stack<int>();
    s->push(5);
    REQUIRE( s->Size() == 1 );
    s->pop();
    REQUIRE( s->Size() == 0 );
    delete s;
}

TEST_CASE( "test queue template int push and pop" ) {
    Queue<int> q(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    REQUIRE( q.peek() == 1 );
    REQUIRE( q.Size() == 5 );
    q.pop();
    REQUIRE( q.peek() == 2 );
    REQUIRE( q.Size() == 4 );
    q.pop();
    REQUIRE( q.peek() == 3 );
    REQUIRE( q.Size() == 3 );
    q.pop();
    REQUIRE( q.peek() == 4 );
    REQUIRE( q.Size() == 2 );
}

TEST_CASE( "test  1.1 is unique table" ) {
    REQUIRE(ch1::isUniqueSort("") == true );
    REQUIRE(ch1::isUniqueSort("1") == true );
    REQUIRE(ch1::isUniqueSort("12") == true );
    REQUIRE(ch1::isUniqueSort("121") == false );
}

TEST_CASE( "test  1.1 is unique sorted" ) {
    REQUIRE(ch1::isUnique("") == true );
    REQUIRE(ch1::isUnique("1") == true );
    REQUIRE(ch1::isUnique("12") == true );
    REQUIRE(ch1::isUnique("121") == false );
}

TEST_CASE( "test  1.2 is perm table" ) {
    REQUIRE(ch1::isPermTable("","") == true );
    REQUIRE(ch1::isPermTable("1","1") == true );
    REQUIRE(ch1::isPermTable("12","21") == true );
    REQUIRE(ch1::isPermTable("12","1") == false );
    REQUIRE(ch1::isPermTable("12","13") == false );
    REQUIRE(ch1::isPermTable("abcd","badc") == true );
}

TEST_CASE( "test  1.2 is perm search" ) {
    REQUIRE(ch1::isPermSearch("","") == true );
    REQUIRE(ch1::isPermSearch("1","1") == true );
    REQUIRE(ch1::isPermSearch("12","21") == true );
    REQUIRE(ch1::isPermSearch("12","1") == false );
    REQUIRE(ch1::isPermSearch("12","13") == false );
    REQUIRE(ch1::isPermSearch("abcd","badc") == true );
}

TEST_CASE( "test  1.2 is perm sorted" ) {
    REQUIRE(ch1::isPermSort("","") == true );
    REQUIRE(ch1::isPermSort("1","1") == true );
    REQUIRE(ch1::isPermSort("12","21") == true );
    REQUIRE(ch1::isPermSort("12","1") == false );
    REQUIRE(ch1::isPermSort("12","13") == false );
    REQUIRE(ch1::isPermSort("abcd","badc") == true);
}

TEST_CASE( "test  1.4 is Palindrome perm table" ) {
    REQUIRE(ch1::isPalindromePerm("") == true);
    REQUIRE(ch1::isPalindromePerm("1") == true);
    REQUIRE(ch1::isPalindromePerm("11") == true);
    REQUIRE(ch1::isPalindromePerm("112") == true);
    REQUIRE(ch1::isPalindromePerm("tactcoa") == true);
    REQUIRE(ch1::isPalindromePerm("nursesrun") == true);
    REQUIRE(ch1::isPalindromePerm("maamd") == true);
    REQUIRE(ch1::isPalindromePerm("mamd") == false);
}

TEST_CASE( "test  1.5 one away" ) {
    REQUIRE(ch1::isOneAway("pale","pa") == false);
    REQUIRE(ch1::isOneAway("small","smaller") == false);
    REQUIRE(ch1::isOneAway("big","bigest") == false);
    REQUIRE(ch1::isOneAway("pale","ple") == true);
    REQUIRE(ch1::isOneAway("ple","pale") == true);
    REQUIRE(ch1::isOneAway("pales","pale") == true);
    REQUIRE(ch1::isOneAway("pale","bale") == true);
    REQUIRE(ch1::isOneAway("pale","bake") == false);
    REQUIRE(ch1::isOneAway("pale","bales") == false);
    REQUIRE(ch1::isOneAway("ball","falls") == false);
    REQUIRE(ch1::isOneAway("ball","bails") == false);
    REQUIRE(ch1::isOneAway("fail","falls") == false);
}

TEST_CASE( "test  1.6" ) {
    REQUIRE(ch1::compressString("aabcccccaaa") == "a2b1c5a3");
    REQUIRE(ch1::compressString("abca") == "abca");
    REQUIRE(ch1::compressString("abbca") == "abbca"); //!= "a1b2c1a1"
}
TEST_CASE( "test  2.3" ) {
    Queue<char> q1;
    q1.push('a');  q1.push('b');  q1.push('c');
    q1.push('d');  q1.push('e');  q1.push('f');
    char arr[] = {'a','b','d','e','f'};
    ch2::deleteMiddleNodeUsingSize(&q1);
    Node<char>* curr = q1.getHead();
    for(int i = 0; i < sizeof(arr); i++) {
        REQUIRE(curr->data == arr[i]);
        curr = curr->Next;
    }
}

TEST_CASE( "test  2.5" ) {
    Queue<int> q1;
    q1.push(7);  q1.push(1);  q1.push(6);
    Queue<int> q2;
    q2.push(5);  q2.push(9);  q2.push(2);
    REQUIRE(ch2::sumLists(&q1,&q2) == 912); //617+295
}

TEST_CASE( "test  2.5 check list" ) {
    Queue<int> q1;
    q1.push(7);  q1.push(1);  q1.push(6);
    Queue<int> q2;
    q2.push(5);  q2.push(9);  q2.push(2);
    Queue<int>* q3 = ch2::sumListsQueue(&q1,&q2);
    int arr[] = {2,1,9};
    Node<int>* curr = q3->getHead();
    for(int i = 0; i < q3->Size(); i++) {
        REQUIRE(curr->data == arr[i]);
        curr = curr->Next;
    }
    delete q3;
}

TEST_CASE( "test  2.5 reverse order" ) {
    Queue<int> q1;
    q1.push(6);  q1.push(1);  q1.push(7);
    Queue<int> q2;
    q2.push(2);  q2.push(9);  q2.push(5);
    REQUIRE(ch2::sumListsReverse(&q1,&q2) == 912); //617+295
}

TEST_CASE( "test  2.5 check reverse list" ) {
    Queue<int> q1;
    q1.push(6);  q1.push(1);  q1.push(7);
    Queue<int> q2;
    q2.push(2);  q2.push(9);  q2.push(5);

    Stack<int>* s1 = ch2::sumListsReverseStack(&q1,&q2);
    //s1->print();
    int arr[] = {9,1,2};
    Node<int>* curr = s1->getHead();
    for(int i = 0; i < s1->Size(); i++) {
        REQUIRE(curr->data == arr[i]);
        curr = curr->Next;
    }
    delete s1;
}

TEST_CASE( "test  3.2" ) {
    minStack ms;
    ms.push(5);
    ms.push(6);
    ms.push(7);
    ms.push(4);
    ms.push(8);
    ms.push(3);
    ms.push(9);
    REQUIRE(ms.min() == 3);
    REQUIRE(ms.peek() == 9);
    ms.pop();
    REQUIRE(ms.min() == 3);
    REQUIRE(ms.peek() == 3);
    ms.pop();
    REQUIRE(ms.min() == 4);
    REQUIRE(ms.peek() == 8);
    ms.pop();
    REQUIRE(ms.min() == 4);
    REQUIRE(ms.peek() == 4);
    ms.pop();
    REQUIRE(ms.min() == 5);
    REQUIRE(ms.peek() == 7);
    ms.pop();
    REQUIRE(ms.min() == 5);
    REQUIRE(ms.peek() == 6);
    ms.pop();
    REQUIRE(ms.min() == 5);
    REQUIRE(ms.peek() == 5);
} 

TEST_CASE( "8.5 recursive multiply") {
    REQUIRE(20 == ch8::iterativeMultiply(4,5));
    REQUIRE(20 == ch8::recursiveMultiply(4,5));
}
TEST_CASE("16.1 swap no temp") {
    int a = 6;
    int b = 15;
    ch16::swapNoTemp(a, b);
    REQUIRE(b == 6);
    REQUIRE(a == 15);
    int c = 6;
    ch16::swapNoTemp(b, c);
    REQUIRE(b == 6);
    REQUIRE(c == 6);
}

TEST_CASE("16.1 swap by subtraction") {
    int a = 6;
    int b = 15;
    ch16::swapSub(a, b);
    REQUIRE(b == 6);
    REQUIRE(a == 15);
    int c = 6;
    ch16::swapSub(b, c);
    REQUIRE(b == 6);
    REQUIRE(c == 6);
}

TEST_CASE("16.2 Word Freq") {
    wordFreq wf("It was the best of times, it was the worst of times.");
    REQUIRE(wf.getFreq("it") == 2);
    REQUIRE(wf.getFreq("was") == 2);
    REQUIRE(wf.getFreq("the") == 2);
    REQUIRE(wf.getFreq("best") == 1);
    REQUIRE(wf.getFreq("times") == 2);
    REQUIRE(wf.getFreq("worst") == 1);
    REQUIRE(wf.getFreq("ball") == 0);
}

TEST_CASE("16.3 intersection") {
    Vec2 A(1.0, 1.0); Vec2 B(4.0, 4.0);
    Vec2 C(1.0, 8.0); Vec2 D(2.0, 4.0);
    Line l1(A,B); Line l2(C,D);
    REQUIRE(true == l1.isIntersected(l2));
}

TEST_CASE("16.3 intersection parallel") {
    Vec2 A(0.0, 1.0); Vec2 B(0.0, 4.0);
    Vec2 C(1.0, 8.0); Vec2 D(1.0, 4.0);
    Line l1(A,B); Line l2(C,D);
    REQUIRE(false == l1.isIntersected(l2));
}

TEST_CASE("16.6 smallest diff brute") {
    int a[] = {1,3,15,11,2};         
    int b[] = {23, 127, 235, 19, 8};
    std::pair<int,int> p = ch16::smallestDiffBrute(a, sizeof(a)/sizeof(int), b, sizeof(b)/sizeof(int));
    REQUIRE(p.first == 11);
    REQUIRE(p.second == 8);
}

TEST_CASE("16.6 smallest diff sort") {
    int a[] = {1,3,15,11,2};         // 1,  2,  3, 11 , 15
    int b[] = {23, 127, 235, 19, 8}; // 8, 19, 23, 127, 235
    std::pair<int,int> p = ch16::smallestDiffSort(a, sizeof(a)/sizeof(int), b, sizeof(b)/sizeof(int));
    REQUIRE(p.first == 11);
    REQUIRE(p.second == 8);

    int a2[] = {1,3,15};
    int b2[] = {20, 8}; 
    std::pair<int,int> p2 = ch16::smallestDiffSort(a2, sizeof(a2)/sizeof(int), b2, sizeof(b2)/sizeof(int));
    REQUIRE(p2.first == 3);
    REQUIRE(p2.second == 8);
}

TEST_CASE("16.7 max no compare") {
    REQUIRE(5 == ch16::maxNoCompare(5,4));
    REQUIRE(5 == ch16::maxNoCompare(4,5));
    REQUIRE(4 == ch16::maxNoCompare(4,-5));
    REQUIRE(4 == ch16::maxNoCompare(-5,4));
}