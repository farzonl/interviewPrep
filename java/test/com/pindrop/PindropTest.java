package com.pindrop;

import org.junit.Test;
import static org.junit.Assert.*;
import java.util.Arrays;

public class PindropTest {

    @Test
    public void testItinerary() {
       String[] list = {"DCA-SFO", "DFW-DCA", "JFK-SJC", "LAX-ATL", "SFO-LAX", "ATL-JFK"};
       assertEquals("[DFW, DCA, SFO, LAX, ATL, JFK, SJC]", Arrays.toString(Pindrop.itinerary(list)));
    }
}
