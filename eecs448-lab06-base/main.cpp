/**
*	@author
*	@date
*	@file main.cpp
*	@brief driver for LinkedList demo
*/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "LinkedListOfInts.h"

TEST_CASE( "create a new list" ) {

	LinkedListOfInts list;

	SECTION( "new list is empty" ) {
		REQUIRE( list.isEmpty() == true );
	}

	SECTION( "new list has size 0" ) {
		REQUIRE( list.size() == 0 );
	}
}

TEST_CASE( "adding to the front of the list" )
{

	LinkedListOfInts list;

	for ( int i = 4; i >=0 ; i-- ) {
		list.addFront( i );
	}
	std::vector<int> vec = list.toVector();
	std::vector<int> vec2 = { 0, 1, 2, 3, 4 };

	SECTION( "items added appropriately" ) {
		REQUIRE( vec == vec2 );
	}

	SECTION( "size updates correctly" ) {
		REQUIRE( list.size() == 5 );
	}

	SECTION( "list is no longer empty" ) {
		REQUIRE( list.isEmpty() == false );
	}
}

TEST_CASE( "adding to the back of the list" ) {

	LinkedListOfInts list;

	for ( int i = 0; i < 5; i++ ) {
		list.addBack(i);
	}
	std::vector<int> vec = list.toVector();
	std::vector<int> vec2 = { 0, 1, 2, 3, 4 };

	SECTION( "items added appropriately" ) {
		REQUIRE( vec == vec2 );
	}

	SECTION( "size updates correctly" ) {
		REQUIRE( list.size() == 5 );
	}

	SECTION( "list is no longer empty" ) {
		REQUIRE( list.isEmpty() == false );
	}
}

TEST_CASE( "searching the list" ) {

	LinkedListOfInts list;

	for ( int i = 4; i >= 0; i-- ) {
		list.addFront(i); //testing suggests addFront works correctly, so assuming that's the case
	}

	SECTION( "search for items in the list" ) {
		for (int i = 0; i < 5; i++ ) {
			REQUIRE( list.search(i) == true );
		}
	}

	SECTION( "search for item not in the list" ) {
		REQUIRE (list.search(5) == false );
	}
}

TEST_CASE( "removing from the front of the list" ) {

    LinkedListOfInts list;
    LinkedListOfInts list2;

    for ( int i = 4; i >= 0; i-- ) {
		list.addFront(i); //testing suggests addFront works correctly, so assuming that's the case
	}

    bool test = list.removeFront();
    bool test2 = list2.removeFront();

    std::vector<int> vec = list.toVector();
	std::vector<int> vec2 = { 1, 2, 3, 4 };

    SECTION( "successful removal returns true" ) {
        REQUIRE( test == true );
    }

    SECTION( "removal from an empty list returns false" ) {
        REQUIRE( test2 == false );
    }

    SECTION( "item removed appropriately" ) {
        REQUIRE( vec == vec2 );
    }

    SECTION( "size updates correctly" ) {
        REQUIRE( list.size() == 4 );
    }
}

TEST_CASE( "removing from the back of the list" ) {

    LinkedListOfInts list;
    LinkedListOfInts list2;

    for ( int i = 4; i >= 0; i-- ) {
		list.addFront(i); //testing suggests addFront works correctly, so assuming that's the case
	}

    bool test = list.removeBack();
    bool test2 = list2.removeBack();

    std::vector<int> vec = list.toVector();
	std::vector<int> vec2 = { 0, 1, 2, 3 };

    SECTION( "successful removal returns true" ) {
        REQUIRE( test == true );
    }

    SECTION( "removal from an empty list returns false" ) {
        REQUIRE( test2 == false );
    }

    SECTION( "item removed appropriately" ) {
        REQUIRE( vec == vec2 );
    }

    SECTION( "size updates correctly" ) {
        REQUIRE( list.size() == 4 );
    }
}
