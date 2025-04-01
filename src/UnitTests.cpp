#include <string>
#include "ringBuffer.h"
#include "catch.hpp"


TEST_CASE("test 01", "check Ring Bufer when it is empty") 
{
    RingBuffer<int, 50> ringBuff;
    
	REQUIRE(ringBuff.getCurrElement() == int());
    REQUIRE(ringBuff.geOldestElement() == int());
    REQUIRE(ringBuff.size() == 0);
}

TEST_CASE("test 02", "check Ring Buffer when it gets full") 
{
    RingBuffer<int, 10> ringBuff;
    
	for(int i=0;i<15; ++ i)
    {
        ringBuff.insert(i*2);
        REQUIRE(ringBuff.getCurrElement() == i*2);
        if(i/10 == 0)
        {
            REQUIRE(ringBuff.geOldestElement() == 0);
            REQUIRE(ringBuff.size() == i+1);
        }
        else if(i == 10)
        {
            REQUIRE(ringBuff.geOldestElement() == 2);
            REQUIRE(ringBuff.size() == 10);
        }
        else if(i== 11)
        {
            REQUIRE(ringBuff.geOldestElement() == 4);
            REQUIRE(ringBuff.size() == 10);
        }
        else if(i== 14)
        {
            REQUIRE(ringBuff.geOldestElement() == 10);
            REQUIRE(ringBuff.size() == 10);
        }
        
    }
    
}


