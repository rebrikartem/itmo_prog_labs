#ifndef ALGS_H
#define ALGS_H

#include <numeric>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <functional>

using namespace std;

// Begin
// Any_of, All_of, None_of, One_of 
//

template<class InputIt, class UnaryPredicate>
constexpr InputIt Find_if(InputIt first, InputIt last, UnaryPredicate predicate)
{
    for (; first != last; ++first) {
        if (predicate(*first)) {
            return first;
        }
    }
    return last;
}


template<class InputIt, class UnaryPredicate>
constexpr InputIt Find_if_not(InputIt first, InputIt last, UnaryPredicate q)
{
    for (; first != last; ++first) {
        if (!q(*first)) {
            return first;
        }
    }
    return last;
}


template< class InputIt, class UnaryPredicate >
constexpr bool All_of(InputIt first, InputIt last, UnaryPredicate predicate)
{
    return Find_if_not(first, last, predicate) == last;
}


template< class InputIt, class UnaryPredicate >
constexpr bool Any_of(InputIt first, InputIt last, UnaryPredicate predicate)
{
    return Find_if(first, last, predicate) != last;
}


template< class InputIt, class UnaryPredicate >
constexpr bool None_of(InputIt first, InputIt last, UnaryPredicate predicate)
{
    return Find_if(first, last, predicate) == last;
}


template< class InputIt, class UnaryPredicate >
constexpr bool One_of(InputIt first, InputIt last, UnaryPredicate predicate)
{
    int c = 0;
    for(; first != last; ++first){
        if(predicate(*first)){
            c++;
        }
    }

    return c == 1;
}

// End
// Any_of, All_of, None_of, One_of 
//

//--------------------------------

// Begin
// Is_sorted
//

template <class ForwardIt, class Compare>
ForwardIt Is_sorted_until(ForwardIt first, ForwardIt last, Compare comp) 
{
    if (first != last) {
        ForwardIt next = first;
        while (++next != last) {
            if (comp(*next, *first))
                return next;
            first = next;
        }
    }
    return last;
}


template<class ForwardIt>
ForwardIt Is_sorted_until(ForwardIt first, ForwardIt last)
{
    return Is_sorted_until(first, last, less<>());
}


template<class ForwardIt>
bool Is_sorted(ForwardIt first, ForwardIt last)
{
    return Is_sorted_until(first, last) == last;
}


template<class ForwardIt, class Compare>
bool Is_sorted(ForwardIt first, ForwardIt last, Compare comp)
{
    return Is_sorted_until(first, last, comp) == last;
}

// End
// Is_sorted
//

//--------------------------------

// Begin
// Is_partitioned
//

template<class ForwardIt, class UnaryPredicate>
ForwardIt Partition(ForwardIt first, ForwardIt last, UnaryPredicate predicate)
{
    first = Find_if_not(first, last, predicate);
    if (first == last) return first;
 
    for (ForwardIt i = std::next(first); i != last; ++i) {
        if (predicate(*i)) {
            std::iter_swap(i, first);
            ++first;
        }
    }
    return first;
}


template< class InputIt, class UnaryPredicate >
bool Is_partitioned(InputIt first, InputIt last, UnaryPredicate predicate)
{
    for (; first != last; ++first)
        if (!predicate(*first))
            break;
    for (; first != last; ++first)
        if (predicate(*first))
            return false;
    return true;
}

// End
// Is_partitioned
// 

//--------------------------------

// Begin
// Find_not, Find_backward
//

template<class InputIt, class T>
constexpr InputIt Find_not(InputIt first, InputIt last, const T& value)
{
    for (; first != last; ++first) {
        if (*first != value) {
            return first;
        }
    }
    return last;
}


template<class InputIt, class T>
constexpr InputIt Find_backward(InputIt first, InputIt last, const T& value)
{
    --last;
    for(; last != first; --last){
        if(*last == value){
            return last;
        }
    }
    return first;
}

//

template<class InputIt>
bool check_if_true(InputIt first, InputIt last, InputIt avg)
{
    while(first != avg)
    {
        if(*first != *last)
        {
            return false;
        }

        ++first;
        --last;
    }

    return true;
}

template<class InputIt, class UnaryPredicate>
bool check_if_true_with_predicate(InputIt first, InputIt last, InputIt avg, UnaryPredicate predicate)
{
    while(first != avg)
    {
        if(predicate(*first) != predicate(*last))
        {
            return false;
        }

        ++first;
        --last;
    }

    return true;
}




template<class InputIt, class UnaryPredicate>
bool Is_palindrome(InputIt first, InputIt last, UnaryPredicate predicate)
{
    int count = last - first;
    --last;
    if(count <= 1){
        return true;
    }

    InputIt avg = first + count / 2;
    if(count % 2 == 0){
        avg -= 1;
    }

    return check_if_true_with_predicate(first, last, avg, predicate);
}

template<class InputIt>
bool Is_palindrome(InputIt first, InputIt last)
{
    return Is_palindrome(first, last, [](auto& e){return e;});
}

#endif