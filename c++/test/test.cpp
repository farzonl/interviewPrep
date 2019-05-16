#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "linkedList.hpp"
#include "ch1.hpp"
#include "ch2.hpp"
#include "ch3.hpp"


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